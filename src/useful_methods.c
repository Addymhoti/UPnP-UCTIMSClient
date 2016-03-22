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

#include "includes.h"
#include "useful_methods.h"

char* add_quotes(char *in)
{
	char *response = malloc(128);
	strcpy(response, "\"");
	strcat(response, in);
	strcat(response, "\"");
	return response;	
}


char *imsua_remove_quotes(char *text)
{
	char *response = strtok(text, "\"");
	return osip_strdup(response);
}


char* add_sip_scheme(char *in)
{
	char *response = malloc(128);

	/* add sip: to URI if it is not there already */
	if (strstr(in, "sip:") || strstr(in, "sips:"))
	{
		strcpy(response, in);
		return response;
	}
	else
	{
		strcpy(response, "sip:");
		strcat(response, in);
		return response;
	}
}


char *imsua_add_lr_to_route(char *route)
{
	
	char *response = malloc(128);

	osip_route_t *rt;
	osip_route_init(&rt);

	if (osip_route_parse(rt,route) != 0)
	{
		printf("Route does not parse!\n");
		return NULL;
	}
	else
	{
		osip_uri_uparam_add(rt->url,osip_strdup("lr"),NULL);
		osip_route_to_str(rt,&response);
	}

	osip_route_free(rt);

	return response;
}



char *get_uuid(uuid_t u)
{
	int i;
	char *response = malloc(128);
/*
	printf("%8.8x-%4.4x-%4.4x-%2.2x%2.2x-", u.time_low, u.time_mid,
	u.time_hi_and_version, u.clock_seq_hi_and_reserved,
	u.clock_seq_low);
*/

	sprintf(response, "%8.8x-%4.4x-%4.4x-%2.2x%2.2x-%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x", (unsigned int)u.time_low, (unsigned int)u.time_mid,
		(unsigned int)u.time_hi_and_version, (unsigned int)u.clock_seq_hi_and_reserved, (unsigned int)u.clock_seq_low,
		(unsigned int)u.node[0], (unsigned int)u.node[1], (unsigned int)u.node[2], (unsigned int)u.node[3], (unsigned int)u.node[4], (unsigned int)u.node[5]);

/*
	for (i = 0; i < 6; i++)
	printf("%2.2x", u.node[i]);
*/

	return response;
}


void set_display(char *text)
{
	GtkWidget *label = lookup_widget(GTK_WIDGET(imsUA), "display");

	if (label == NULL)
		return ;

	gtk_label_set_text(GTK_LABEL(label), text);
}


void set_reg_event_display(char *text)
{
	GtkWidget *label = lookup_widget(GTK_WIDGET(imsUA), "reg_event_display");
	gtk_label_set_text(GTK_LABEL(label), text);
}

void set_xdms_upload_display(char *text)
{
	
	GtkWidget *message_output_text_view = lookup_widget(GTK_WIDGET(xdms_upload_window), "xdms_upload_display");
	GtkTextBuffer *message_output_buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW(message_output_text_view));
	
	//This clears the XDMS upload display
	GtkTextIter start_message_iter;
	gtk_text_buffer_get_start_iter(message_output_buffer, &start_message_iter);
	GtkTextIter end_message_iter;
	gtk_text_buffer_get_end_iter(message_output_buffer, &end_message_iter);
	gtk_text_buffer_delete(message_output_buffer,&start_message_iter,&end_message_iter);
	
	// scroll to bottom of display
	//GtkTextIter output_end_iter;
	//gtk_text_buffer_get_end_iter(message_output_buffer, &output_end_iter);
	//GtkTextMark *last_pos = gtk_text_buffer_create_mark (message_output_buffer, "last_pos", &output_end_iter, FALSE);	
	//gtk_text_view_scroll_mark_onscreen (GTK_TEXT_VIEW(message_output_text_view), last_pos);
	
	gtk_text_buffer_get_end_iter(message_output_buffer, &start_message_iter);
	GtkTextMark *start_message_mark = gtk_text_buffer_create_mark(message_output_buffer,"start_message_mark",&start_message_iter,TRUE);
	
	gtk_text_buffer_insert(message_output_buffer,&start_message_iter,text,strlen(text));
	gtk_text_buffer_get_end_iter(message_output_buffer, &end_message_iter);
	gtk_text_buffer_get_iter_at_mark(message_output_buffer,&start_message_iter,start_message_mark);
	
}

void set_xdms_download_display(char *text)
{
	GtkWidget *message_output_text_view = lookup_widget(GTK_WIDGET(xdms_download_window), "xdms_download_display");
	GtkTextBuffer *message_output_buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW(message_output_text_view));
	
	//This clears the XDMS upload display
	GtkTextIter start_message_iter;
	gtk_text_buffer_get_start_iter(message_output_buffer, &start_message_iter);
	GtkTextIter end_message_iter;
	gtk_text_buffer_get_end_iter(message_output_buffer, &end_message_iter);
	gtk_text_buffer_delete(message_output_buffer,&start_message_iter,&end_message_iter);
	
	// scroll to bottom of display
	//GtkTextIter output_end_iter;
	//gtk_text_buffer_get_end_iter(message_output_buffer, &output_end_iter);
	//GtkTextMark *last_pos = gtk_text_buffer_create_mark (message_output_buffer, "last_pos", &output_end_iter, FALSE);	
	//gtk_text_view_scroll_mark_onscreen (GTK_TEXT_VIEW(message_output_text_view), last_pos);

	gtk_text_buffer_get_end_iter(message_output_buffer, &start_message_iter);
	GtkTextMark *start_message_mark = gtk_text_buffer_create_mark(message_output_buffer,"start_message_mark",&start_message_iter,TRUE);
	
	gtk_text_buffer_insert(message_output_buffer,&start_message_iter,text,strlen(text));
	gtk_text_buffer_get_end_iter(message_output_buffer, &end_message_iter);
	gtk_text_buffer_get_iter_at_mark(message_output_buffer,&start_message_iter,start_message_mark);
}

void imsua_append_text_to_display(char *text)
{	
	char display[500];
	GtkWidget *label = lookup_widget(GTK_WIDGET(imsUA), "display");
	strcpy(display, gtk_label_get_text(GTK_LABEL(label)));
	strcat(display, text);
	gtk_label_set_text(GTK_LABEL(label), display);
}

void imsua_append_text_to_reg_event_display(char *text)
{	
	char display[500];
	GtkWidget *label = lookup_widget(GTK_WIDGET(imsUA), "reg_event_display");
	strcpy(display, gtk_label_get_text(GTK_LABEL(label)));
	strcat(display, text);
	gtk_label_set_text(GTK_LABEL(label), display);
}

/*
void imsua_append_text_to_assoc_uri_display(char *text)
{	
	char display[500];
	GtkWidget *label = lookup_widget(GTK_WIDGET(imsUA), "assoc_uri_display");
	strcpy(display, gtk_label_get_text(GTK_LABEL(label)));
	strcat(display, text);
	gtk_label_set_text(GTK_LABEL(label), display);
}
*/

void imsua_set_presentity_display(char *new_presentity)
{
	GtkWidget *label = lookup_widget(GTK_WIDGET(imsUA), "presentity");
	gtk_label_set_text(GTK_LABEL(label), new_presentity);
}

void imsua_clear_buddy_list_display()
{
	char buf[500];
	GtkWidget *buddy_list_text_view = lookup_widget(GTK_WIDGET(imsUA), "buddy_list");

	if (buddy_list_text_view == NULL)
		return ;

	GtkTextBuffer *buddy_list_buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW(buddy_list_text_view));

	//This clears the buddy list display
	GtkTextIter start_window_iter;
	gtk_text_buffer_get_start_iter(buddy_list_buffer, &start_window_iter);
	GtkTextIter end_window_iter;
	gtk_text_buffer_get_end_iter(buddy_list_buffer, &end_window_iter);
	gtk_text_buffer_delete(buddy_list_buffer,&start_window_iter,&end_window_iter);
	
	// scroll to bottom of display
	GtkTextIter output_end_iter;
	gtk_text_buffer_get_end_iter(buddy_list_buffer, &output_end_iter);
	GtkTextMark *last_pos = gtk_text_buffer_create_mark (buddy_list_buffer, "last_pos", &output_end_iter, FALSE);	
	gtk_text_view_scroll_mark_onscreen (GTK_TEXT_VIEW(buddy_list_text_view), last_pos);
}

void imsua_append_text_to_buddy_list_display(char *buddy, char* basic, char* note)
{	
	char buf[500];
	GtkWidget *buddy_list_text_view = lookup_widget(GTK_WIDGET(imsUA), "buddy_list");

	if (buddy_list_text_view == NULL)
		return ;

	GtkTextBuffer *buddy_list_buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW(buddy_list_text_view));

	GtkTextTagTable *tag_table = gtk_text_buffer_get_tag_table(buddy_list_buffer);
	if(gtk_text_tag_table_lookup(tag_table,"bold") == NULL)
	{
		// Tag with weight bold and tag name "bold"
		gtk_text_buffer_create_tag (buddy_list_buffer,"bold","weight", PANGO_WEIGHT_BOLD, NULL);
	}
	if(gtk_text_tag_table_lookup(tag_table,"font") == NULL)
	{
		// Tag with font fixed and tag name "font". 
		gtk_text_buffer_create_tag (buddy_list_buffer, "font", "font", "fixed", NULL);
	}
	if(gtk_text_tag_table_lookup(tag_table,"italic") == NULL)
	{
		// Tag with font fixed and tag name "italic". 
		gtk_text_buffer_create_tag (buddy_list_buffer, "italic", "style", PANGO_STYLE_ITALIC, NULL);
	}

	//This writes the buddy in bold for display on the screen
	GtkTextIter start_message_iter;
	gtk_text_buffer_get_end_iter(buddy_list_buffer, &start_message_iter);
	GtkTextMark *start_message_mark = gtk_text_buffer_create_mark(buddy_list_buffer,"start_message_mark",&start_message_iter,TRUE);
	sprintf(buf, "%s", buddy);
	gtk_text_buffer_insert(buddy_list_buffer,&start_message_iter,buf,strlen(buf));
	GtkTextIter end_message_iter;
	gtk_text_buffer_get_end_iter(buddy_list_buffer, &end_message_iter);
	gtk_text_buffer_get_iter_at_mark(buddy_list_buffer,&start_message_iter,start_message_mark);
	//Apply the BOLD tag to the selected text.
	gtk_text_buffer_apply_tag_by_name (buddy_list_buffer, "bold", &start_message_iter, &end_message_iter);	
	
	//This writes Basic: in bold font normal font for display on the screen
	gtk_text_buffer_get_end_iter(buddy_list_buffer, &start_message_iter);
	start_message_mark = gtk_text_buffer_create_mark(buddy_list_buffer,"start_message_mark",&start_message_iter,TRUE);
	sprintf(buf, "\t\tBasic: ");
	gtk_text_buffer_insert(buddy_list_buffer,&start_message_iter,buf,strlen(buf));
	gtk_text_buffer_get_end_iter(buddy_list_buffer, &end_message_iter);
	gtk_text_buffer_get_iter_at_mark(buddy_list_buffer,&start_message_iter,start_message_mark);
	//Apply the normal FONT tag to the selected text.
	gtk_text_buffer_apply_tag_by_name (buddy_list_buffer, "bold", &start_message_iter, &end_message_iter);

	//This writes the basic in normal font for display on the screen
	gtk_text_buffer_get_end_iter(buddy_list_buffer, &start_message_iter);
	start_message_mark = gtk_text_buffer_create_mark(buddy_list_buffer,"start_message_mark",&start_message_iter,TRUE);
	sprintf(buf, "%s", basic);
	gtk_text_buffer_insert(buddy_list_buffer,&start_message_iter,buf,strlen(buf));
	gtk_text_buffer_get_end_iter(buddy_list_buffer, &end_message_iter);
	gtk_text_buffer_get_iter_at_mark(buddy_list_buffer,&start_message_iter,start_message_mark);
	//Apply the normal FONT tag to the selected text.
	gtk_text_buffer_apply_tag_by_name (buddy_list_buffer, "font", &start_message_iter, &end_message_iter);

	//This writes Note: in bold font for display on the screen
	gtk_text_buffer_get_end_iter(buddy_list_buffer, &start_message_iter);
	start_message_mark = gtk_text_buffer_create_mark(buddy_list_buffer,"start_message_mark",&start_message_iter,TRUE);
	sprintf(buf, "\t\tNote: ");
	gtk_text_buffer_insert(buddy_list_buffer,&start_message_iter,buf,strlen(buf));
	gtk_text_buffer_get_end_iter(buddy_list_buffer, &end_message_iter);
	gtk_text_buffer_get_iter_at_mark(buddy_list_buffer,&start_message_iter,start_message_mark);
	//Apply the normal FONT tag to the selected text.
	gtk_text_buffer_apply_tag_by_name (buddy_list_buffer, "bold", &start_message_iter, &end_message_iter);

	//This writes the note message in normal font for display on the screen
	gtk_text_buffer_get_end_iter(buddy_list_buffer, &start_message_iter);
	start_message_mark = gtk_text_buffer_create_mark(buddy_list_buffer,"start_message_mark",&start_message_iter,TRUE);
	sprintf(buf, "%s\n", note);
	gtk_text_buffer_insert(buddy_list_buffer,&start_message_iter,buf,strlen(buf));
	gtk_text_buffer_get_end_iter(buddy_list_buffer, &end_message_iter);
	gtk_text_buffer_get_iter_at_mark(buddy_list_buffer,&start_message_iter,start_message_mark);
	//Apply the normal FONT tag to the selected text.
	gtk_text_buffer_apply_tag_by_name (buddy_list_buffer, "font", &start_message_iter, &end_message_iter);

	// scroll to bottom of display
	GtkTextIter output_end_iter;
	gtk_text_buffer_get_end_iter(buddy_list_buffer, &output_end_iter);
	GtkTextMark *last_pos = gtk_text_buffer_create_mark (buddy_list_buffer, "last_pos", &output_end_iter, FALSE);	
	gtk_text_view_scroll_mark_onscreen (GTK_TEXT_VIEW(buddy_list_text_view), last_pos);
}


void imsua_set_message_display(char *text, int color)
{
	char buf[500];

	GtkWidget *message_output_text_view = lookup_widget(GTK_WIDGET(imsUA), "message_display");

	if (message_output_text_view == NULL)
		return ;

	GtkTextBuffer *message_output_buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW(message_output_text_view));
	GtkTextTag *tag;

	GtkTextTagTable *tag_table = gtk_text_buffer_get_tag_table(message_output_buffer);
	if(gtk_text_tag_table_lookup(tag_table,"bold") == NULL)
	{
		// Tag with weight bold and tag name "bold"
		gtk_text_buffer_create_tag (message_output_buffer,"bold","weight", PANGO_WEIGHT_BOLD, NULL);
	}
	if(gtk_text_tag_table_lookup(tag_table,"font") == NULL)
	{
		// Tag with font fixed and tag name "font". 
		gtk_text_buffer_create_tag (message_output_buffer, "font", "font", "fixed", NULL);
	}
	if(gtk_text_tag_table_lookup(tag_table,"italic") == NULL)
	{
		// Tag with font fixed and tag name "italic". 
		gtk_text_buffer_create_tag (message_output_buffer, "italic", "style", PANGO_STYLE_ITALIC, NULL);
	}
	if(gtk_text_tag_table_lookup(tag_table,"red") == NULL)
	{
		// Tag with font fixed and tag name "italic". 
		gtk_text_buffer_create_tag (message_output_buffer, "red", "foreground", "darkred", NULL);
	}
	if(gtk_text_tag_table_lookup(tag_table,"green") == NULL)
	{
		// Tag with font fixed and tag name "italic". 
		gtk_text_buffer_create_tag (message_output_buffer, "green", "foreground", "darkgreen", NULL);
	}


	//This writes the time stamp in bold for display on the screen
	GtkTextIter start_message_iter;
	gtk_text_buffer_get_end_iter(message_output_buffer, &start_message_iter);
	GtkTextMark *start_message_mark = gtk_text_buffer_create_mark(message_output_buffer,"start_message_mark",&start_message_iter,TRUE);
	
	sprintf(buf, "%s> ", imsua_get_time());
	gtk_text_buffer_insert(message_output_buffer,&start_message_iter,buf,strlen(buf));
	GtkTextIter end_message_iter;
	gtk_text_buffer_get_end_iter(message_output_buffer, &end_message_iter);
	gtk_text_buffer_get_iter_at_mark(message_output_buffer,&start_message_iter,start_message_mark);
	//Apply the BOLD tag to the selected text.
	gtk_text_buffer_apply_tag_by_name (message_output_buffer, "bold", &start_message_iter, &end_message_iter);
	
	//This writes the message portion is normal font for display on the screen
	gtk_text_buffer_get_end_iter(message_output_buffer, &start_message_iter);
	start_message_mark = gtk_text_buffer_create_mark(message_output_buffer,"start_message_mark",&start_message_iter,TRUE);
	sprintf(buf, "%s\n", text);
	gtk_text_buffer_insert(message_output_buffer,&start_message_iter,buf,strlen(buf));
	gtk_text_buffer_get_end_iter(message_output_buffer, &end_message_iter);
	gtk_text_buffer_get_iter_at_mark(message_output_buffer,&start_message_iter,start_message_mark);
	//Apply the normal FONT tag to the selected text.
	gtk_text_buffer_apply_tag_by_name (message_output_buffer, "font", &start_message_iter, &end_message_iter);

	if (color == 1)
		gtk_text_buffer_apply_tag_by_name (message_output_buffer, "red", &start_message_iter, &end_message_iter);
	else if (color == 2)
		gtk_text_buffer_apply_tag_by_name (message_output_buffer, "green", &start_message_iter, &end_message_iter);	
	
	// scroll to bottom of display
	GtkTextIter output_end_iter;
	gtk_text_buffer_get_end_iter(message_output_buffer, &output_end_iter);
	GtkTextMark *last_pos = gtk_text_buffer_create_mark (message_output_buffer, "last_pos", &output_end_iter, FALSE);	
	gtk_text_view_scroll_mark_onscreen (GTK_TEXT_VIEW(message_output_text_view), last_pos);


}


void imsua_clear_presrules_display()
{
	char buf[500];
	GtkWidget *buddy_list_text_view = lookup_widget(GTK_WIDGET(imsUA), "presrules_display");
	GtkTextBuffer *buddy_list_buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW(buddy_list_text_view));

	//This clears the buddy list display
	GtkTextIter start_window_iter;
	gtk_text_buffer_get_start_iter(buddy_list_buffer, &start_window_iter);
	GtkTextIter end_window_iter;
	gtk_text_buffer_get_end_iter(buddy_list_buffer, &end_window_iter);
	gtk_text_buffer_delete(buddy_list_buffer,&start_window_iter,&end_window_iter);
	
}


void imsua_set_presrules_display(char *text)
{

	GtkWidget *message_output_text_view = lookup_widget(GTK_WIDGET(imsUA), "presrules_display");
	GtkTextBuffer *message_output_buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW(message_output_text_view));
	
	//This writes the time stamp in bold for display on the screen
	GtkTextIter start_message_iter;
	gtk_text_buffer_get_end_iter(message_output_buffer, &start_message_iter);
	GtkTextMark *start_message_mark = gtk_text_buffer_create_mark(message_output_buffer,"start_message_mark",&start_message_iter,TRUE);
	
	gtk_text_buffer_insert(message_output_buffer,&start_message_iter,text,strlen(text));
	GtkTextIter end_message_iter;
	gtk_text_buffer_get_end_iter(message_output_buffer, &end_message_iter);
	gtk_text_buffer_get_iter_at_mark(message_output_buffer,&start_message_iter,start_message_mark);
	
	// scroll to bottom of display
	GtkTextIter output_end_iter;
	gtk_text_buffer_get_end_iter(message_output_buffer, &output_end_iter);
	GtkTextMark *last_pos = gtk_text_buffer_create_mark (message_output_buffer, "last_pos", &output_end_iter, FALSE);	
	gtk_text_view_scroll_mark_onscreen (GTK_TEXT_VIEW(message_output_text_view), last_pos);	
}


void imsua_display_event_info(eXosip_event_t *je)
{

	char output[500];

	if (je->type == EXOSIP_REGISTRATION_FAILURE)
	{
		if (je->request && je->response)
			sprintf(output, "%s (for %s)", osip_message_get_reason_phrase(je->response), osip_message_get_method(je->request));
		else if(je->request)
			sprintf(output, "Registration Failure (for %s)", osip_message_get_method(je->request));
	}
	else if (je->type == EXOSIP_CALL_CLOSED)
	{
		return ;
		// sprintf(output, "%s", osip_message_get_method(je->request));
	}
	else if ((je->type == EXOSIP_CALL_MESSAGE_NEW) && (MSG_IS_BYE(je->request)))
	{
		sprintf(output, "%s", osip_message_get_method(je->request));
	}
	else if ((je->type == EXOSIP_CALL_INVITE) || (je->type == EXOSIP_CALL_REINVITE))
	{
		sprintf(output, "%s", osip_message_get_method(je->request));
	}
	else if ((je->type == EXOSIP_CALL_SERVERFAILURE) || (je->type == EXOSIP_CALL_GLOBALFAILURE) || (je->type == EXOSIP_CALL_REQUESTFAILURE))
	{
		sprintf(output, "%s (for %s)", osip_message_get_reason_phrase(je->response), osip_message_get_method(je->request));
	}
	else if (je->ack)
	{
		sprintf(output, "%s", osip_message_get_method(je->ack));

	}
	else if (je->request && je->response)
	{	
		sprintf(output, "%s (for %s)", osip_message_get_reason_phrase(je->response), osip_message_get_method(je->request));
	}
	else if (je->request)
	{
		sprintf(output, "%s", osip_message_get_method(je->request));
	}	
	else
		return	;
	
	imsua_set_message_display(output, 2);


}

int imsua_is_associated_uri(char *uri)
{
	int i;
	int found = 0;

	for (i = 0; i < num_associated_uris; i++)
	{
		if (strstr(ims_associated_uris[i], uri))
			found = 1;

	}

	return found;
}

void imsua_add_service_routes(osip_message_t **message)
{

	int j;
	for (j = num_service_routes; j > 0; j--)
	{
		osip_message_set_route(*message, ims_service_route[j-1]);
	}

}



void set_status_bar(char *text)
{
	GtkWidget *label = lookup_widget(GTK_WIDGET(imsUA), "status_bar");

	if (label == NULL)
		return ;

	gtk_label_set_text(GTK_LABEL(label), text);
}


char* imsua_get_time()
{
	char hour[50];
	char min[50];
	char sec[50];
	char time_str[200];
	char *return_val;
	
	struct tm *now = NULL;
	time_t time_value = 0;
	time_value = time(NULL);
	
	now = localtime(&time_value);
	if(now->tm_hour < 10)
	{
		sprintf(hour,"0%d",now->tm_hour);
	}
	else
	{
		sprintf(hour,"%d",now->tm_hour);
	}
	if(now->tm_min < 10)
	{
		sprintf(min,"0%d",now->tm_min);
	}
	else
	{
		sprintf(min,"%d",now->tm_min);
	}
	if(now->tm_sec < 10)
	{
		sprintf(sec,"0%d",now->tm_sec);
	}
	else
	{
		sprintf(sec,"%d",now->tm_sec);
	}

	
	sprintf(time_str, "%s:%s:%s",hour, min,sec);
	return_val = strdup(time_str);

	return return_val;
}


int timeval_subtract (result, x, y) 
struct timeval *result, *x, *y;
{
	/* Perform the carry for the later subtraction by updating y. */
	if (x->tv_usec < y->tv_usec) 
	{
		int nsec = (y->tv_usec - x->tv_usec) / 1000000 + 1;
		y->tv_usec -= 1000000 * nsec;
		y->tv_sec += nsec;
	}
	if (x->tv_usec - y->tv_usec > 1000000) 
	{
		int nsec = (y->tv_usec - x->tv_usec) / 1000000;
		y->tv_usec += 1000000 * nsec;
		y->tv_sec -= nsec;
	}
	
	/* Compute the time remaining to wait.
	tv_usec  is certainly positive. */
	result->tv_sec = x->tv_sec - y->tv_sec;
	result->tv_usec = x->tv_usec - y->tv_usec;
	
	/* Return 1 if result is negative. */
	return x->tv_sec < y->tv_sec;
}


char *imsua_addpath(char *filename)
{

	char fullpath[100];
	char *return_val;
	
	sprintf(fullpath, "%s%s", filepath, filename);
	return_val = strdup(fullpath);

	return return_val;

}

int imsua_regex_match(char *string, char *pattern)
{
	int    status;
	regex_t re;

	if (regcomp(&re, pattern, REG_EXTENDED|REG_NOSUB) != 0) {
	        return(0);      /* Report error. */
	}

	status = regexec(&re, string, (size_t) 0, NULL, 0);	
 	regfree(&re);
	
	if (status != 0) 
	{
		return(0);      /* Report error. */
	}

	return(1);
}


void imsua_log(char *message)
{

	if (DEBUG)
	{
		char debugMessage[200];

		sprintf(debugMessage, "%s - UCTIMSCLIENT: %s\n", imsua_get_time(), message);

		fprintf(stderr,"%s", debugMessage);
	}

}
