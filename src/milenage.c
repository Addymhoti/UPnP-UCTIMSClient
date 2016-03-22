/*
  The UCT IMS Client
  Copyright (C) 2006 - University of Cape Town
  David Waiting <david@crg.ee.uct.ac.za>
  Richard Good <rgood@crg.ee.uct.ac.za>

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/
 
/**
 * \file
 * 
 * SIP-to-IMS Gateway - Milenage
 * 
 *  \note Taken from 3GPP's TS 35.206
 * 
 *          Example algorithms f1, f1*, f2, f3, f4, f5, f5*
 *
 *  A sample implementation of the example 3GPP authentication and
 *  key agreement functions f1, f1*, f2, f3, f4, f5 and f5*.  This is
 *  a byte-oriented implementation of the functions, and of the block
 *  cipher kernel function Rijndael.
 *
 *  This has been coded for clarity, not necessarily for efficiency.
 *
 *  The functions f2, f3, f4 and f5 share the same inputs and have
 *  been coded together as a single function.  f1, f1* and f5* are
 *  all coded separately.
 *
 */
 

#include "rijndael.c"
#include "milenage.h"


/** Operator Variant Algorithm Configuration Field */

            /*------- Insert your value of OP here -------*/
//u8 OP[16] = {0x63, 0xbf, 0xa5, 0x0e, 0xe6, 0x52, 0x33, 0x65,
//             0xff, 0x14, 0xc1, 0xf4, 0x5f, 0x88, 0x73, 0x7d};
u8 OP[16] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
             0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

            /*------- Insert your value of OP here -------*/


/*--------------------------- prototypes --------------------------*/



/**
 *                            Algorithm f1
 *
 *  Computes network authentication code MAC-A from key K, random
 *  challenge RAND, sequence number SQN and authentication management
 *  field AMF.
 *
 */

void f1    ( u8 k[16], u8 rand[16], u8 sqn[6], u8 amf[2], 
             u8 mac_a[8] )
{
  u8 op_c[16];
  u8 temp[16];
  u8 in1[16];
  u8 out1[16];
  u8 rijndaelInput[16];
  u8 i;

  RijndaelKeySchedule( k );

  ComputeOPc( op_c );

  for (i=0; i<16; i++)
    rijndaelInput[i] = rand[i] ^ op_c[i];
  RijndaelEncrypt( rijndaelInput, temp );

  for (i=0; i<6; i++)
  {
    in1[i]    = sqn[i];
    in1[i+8]  = sqn[i];
  }
  for (i=0; i<2; i++)
  {
    in1[i+6]  = amf[i];
    in1[i+14] = amf[i];
  }

  /* XOR op_c and in1, rotate by r1=64, and XOR *
   * on the constant c1 (which is all zeroes)   */

  for (i=0; i<16; i++)
    rijndaelInput[(i+8) % 16] = in1[i] ^ op_c[i];

  /* XOR on the value temp computed before */

  for (i=0; i<16; i++)
    rijndaelInput[i] ^= temp[i];
  
  RijndaelEncrypt( rijndaelInput, out1 );
  for (i=0; i<16; i++)
    out1[i] ^= op_c[i];

  for (i=0; i<8; i++)
    mac_a[i] = out1[i];

  return;
} /* end of function f1 */


  
/**
 *                            Algorithms f2-f5
 *
 *  Takes key K and random challenge RAND, and returns response RES,
 *  confidentiality key CK, integrity key IK and anonymity key AK.
 *
 */

void f2345 ( u8 k[16], u8 rand[16],
             u8 res[8], u8 ck[16], u8 ik[16], u8 ak[6] )
{
  u8 op_c[16];
  u8 temp[16];
  u8 out[16];
  u8 rijndaelInput[16];
  u8 i;

  RijndaelKeySchedule( k );

  ComputeOPc( op_c );

  for (i=0; i<16; i++)
    rijndaelInput[i] = rand[i] ^ op_c[i];
  RijndaelEncrypt( rijndaelInput, temp );

  /* To obtain output block OUT2: XOR OPc and TEMP,    *
   * rotate by r2=0, and XOR on the constant c2 (which *
   * is all zeroes except that the last bit is 1).     */

  for (i=0; i<16; i++)
    rijndaelInput[i] = temp[i] ^ op_c[i];
  rijndaelInput[15] ^= 1;

  RijndaelEncrypt( rijndaelInput, out );
  for (i=0; i<16; i++)
    out[i] ^= op_c[i];

  for (i=0; i<8; i++)
    res[i] = out[i+8];
  for (i=0; i<6; i++)
    ak[i]  = out[i];

  /* To obtain output block OUT3: XOR OPc and TEMP,        *
   * rotate by r3=32, and XOR on the constant c3 (which    *
   * is all zeroes except that the next to last bit is 1). */

  for (i=0; i<16; i++)
    rijndaelInput[(i+12) % 16] = temp[i] ^ op_c[i];
  rijndaelInput[15] ^= 2;

  RijndaelEncrypt( rijndaelInput, out );
  for (i=0; i<16; i++)
    out[i] ^= op_c[i];

  for (i=0; i<16; i++)
    ck[i] = out[i];

  /* To obtain output block OUT4: XOR OPc and TEMP,         *
   * rotate by r4=64, and XOR on the constant c4 (which     *
   * is all zeroes except that the 2nd from last bit is 1). */

  for (i=0; i<16; i++)
    rijndaelInput[(i+8) % 16] = temp[i] ^ op_c[i];
  rijndaelInput[15] ^= 4;

  RijndaelEncrypt( rijndaelInput, out );
  for (i=0; i<16; i++)
    out[i] ^= op_c[i];

  for (i=0; i<16; i++)
    ik[i] = out[i];

  return;
} /* end of function f2345 */

  
/**
 *                            Algorithm f1*
 *
 *  Computes resynch authentication code MAC-S from key K, random
 *  challenge RAND, sequence number SQN and authentication management
 *  field AMF.
 *
 */

void f1star( u8 k[16], u8 rand[16], u8 sqn[6], u8 amf[2], 
             u8 mac_s[8] )
{
  u8 op_c[16];
  u8 temp[16];
  u8 in1[16];
  u8 out1[16];
  u8 rijndaelInput[16];
  u8 i;

  RijndaelKeySchedule( k );

  ComputeOPc( op_c );

  for (i=0; i<16; i++)
    rijndaelInput[i] = rand[i] ^ op_c[i];
  RijndaelEncrypt( rijndaelInput, temp );

  for (i=0; i<6; i++)
  {
    in1[i]    = sqn[i];
    in1[i+8]  = sqn[i];
  }
  for (i=0; i<2; i++)
  {
    in1[i+6]  = amf[i];
    in1[i+14] = amf[i];
  }

  /* XOR op_c and in1, rotate by r1=64, and XOR *
   * on the constant c1 (which is all zeroes)   */

  for (i=0; i<16; i++)
    rijndaelInput[(i+8) % 16] = in1[i] ^ op_c[i];

  /* XOR on the value temp computed before */

  for (i=0; i<16; i++)
    rijndaelInput[i] ^= temp[i];
  
  RijndaelEncrypt( rijndaelInput, out1 );
  for (i=0; i<16; i++)
    out1[i] ^= op_c[i];

  for (i=0; i<8; i++)
    mac_s[i] = out1[i+8];

  return;
} /* end of function f1star */

  
/**
 *                            Algorithm f5*
 *
 *  Takes key K and random challenge RAND, and returns resynch
 *  anonymity key AK.
 *
 */

void f5star( u8 k[16], u8 rand[16],
             u8 ak[6] )
{
  u8 op_c[16];
  u8 temp[16];
  u8 out[16];
  u8 rijndaelInput[16];
  u8 i;

  RijndaelKeySchedule( k );

  ComputeOPc( op_c );

  for (i=0; i<16; i++)
    rijndaelInput[i] = rand[i] ^ op_c[i];
  RijndaelEncrypt( rijndaelInput, temp );

  /* To obtain output block OUT5: XOR OPc and TEMP,         *
   * rotate by r5=96, and XOR on the constant c5 (which     *
   * is all zeroes except that the 3rd from last bit is 1). */

  for (i=0; i<16; i++)
    rijndaelInput[(i+4) % 16] = temp[i] ^ op_c[i];
  rijndaelInput[15] ^= 8;

  RijndaelEncrypt( rijndaelInput, out );
  for (i=0; i<16; i++)
    out[i] ^= op_c[i];

  for (i=0; i<6; i++)
    ak[i] = out[i];

  return;
} /* end of function f5star */

  
/**
 *  Function to compute OPc from OP and K.  Assumes key schedule has
 *   already been performed.
 */

void ComputeOPc( u8 op_c[16] )
{
  u8 i;
  
  RijndaelEncrypt( OP, op_c );
  for (i=0; i<16; i++)
    op_c[i] ^= OP[i];

  return;
} /* end of function ComputeOPc */
