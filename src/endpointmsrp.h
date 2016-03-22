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

#ifndef ENDPOINTMSRP_H
#define ENDPOINTMSRP_H


/*
#include <gtk/gtk.h>
#include <stdlib.h>
#include <eXosip2/eXosip.h>
#include "imsUA.h"
#include "interface.h"
#include "support.h"
#include "useful_methods.h"
#include "common_exosip_event_handler.h"
*/


/**
 * Callbacks from MSRP Library
 * 
 */
int send_msrp_message(char *message);
int endpointmsrp_start_session(eXosip_event_t *je, char *path, int active);
void endpointmsrp_end_session(int active);
MsrpEndpoint* endpointmsrp_create_endpoint(int call_id_number,char *address,int port, int active);
void callback_msrp(int event, MsrpEndpoint *endpoint, int content, void *data, int bytes);
void events_msrp(int event, void *info);

#endif


