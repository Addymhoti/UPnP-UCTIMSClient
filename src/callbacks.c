#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif


#include "includes.h"
#include "callbacks.h"


// start dave edit 6 dec 2006
void
on_register2_activate                  (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{

	ims_send_register();
}
// end dave edit 6 nov 2006

// start edit by dave - 8 dec
void
on_preferences1_activate               (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{

	preferences_set_preferences_dialog();

}
// end edit by dave - 8 dec


void
on_help_activate                       (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{
	GtkWidget *help = create_help ();
  	gtk_widget_show (help);
}


void
on_about_activate                      (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{


	GtkWidget *about = create_aboutdialog ();
  	gtk_widget_show (about);
}

void
on_close_help_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *dialog = lookup_widget(GTK_WIDGET(button), "help");
	gtk_widget_destroy(dialog);
}



// start edit by dave - 8 dec
void
on_preferences_ok_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{

	preferences_get_preferences_dialog(button);

}
// end edit by dave - 9 november



void
on_call_button_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
	if (state == IDLE)
	{	
		ims_call_initiate();
	}
	else if(state == LOCAL_RINGING)
	{
		ims_call_answer();
	}
	else if(state == IN_CALL)
	{		
		ims_call_reinvite();
	}
}



void
on_hangup_button_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
	terminate_call();
	gtk_widget_hide_all (videoWin);
	/*
	if (state == LOCAL_RINGING)
		terminate_call();
	else if (state == REMOTE_RINGING)
		terminate_call();
	else if(state == IN_CALL)
		terminate_call();
	*/
}


//start richard edit december 8
void
on_send_im_button_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
	ims_send_instant_message ();

}
//end richard edit december 8


//start richard edit december 8
gboolean
on_im_text_input_key_press_event       (GtkWidget       *widget,
                                        GdkEventKey     *event,
                                        gpointer         user_data)
{
	
	GtkWidget *im_text_entry = lookup_widget(GTK_WIDGET(im_window), "im_text_input");
	const gchar *im_input;
	im_input = gtk_entry_get_text(GTK_ENTRY(im_text_entry));
	int length = strlen(im_input);
	
	if(length == 0 && !(event-> keyval == 0xFF0D || event-> keyval == 0xFF8D)) //first key press
	{
		ims_send_instant_message_status (1);
	}


	//If enter is pressed without alt or control send message
	//NOTE the keyval codes can be found in gdkkeysyms.h
	//If enter is pressed without alt or control
	if ((event-> keyval == 0xFF0D || event-> keyval == 0xFF8D)&&(!(event->state & GDK_CONTROL_MASK)&&!(event->state & GDK_SHIFT_MASK)&&!(event->state & GDK_MOD1_MASK) ))	
	{
		ims_send_instant_message (GTK_WIDGET(widget));
		
	}
  return FALSE;
}
//end richard edit december 8


//start edit richard november 8
gboolean
on_imsUA_delete_event                  (GtkWidget       *widget,
                                        GdkEvent        *event,
                                        gpointer         user_data)
{
	gtk_main_quit();
	return FALSE;
}

void
on_quit1_activate                      (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{
	gtk_main_quit();
	
}
//end edit richard november 8


// start dave edit 7 dec
void
on_deregister1_activate                (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{
	ims_send_deregister_message ();
	
	
}
// end dave edit 7 dec


//started edit richard december 8
void
on_start_chat_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
		ims_open_im_window();
}
//edit edit richard december 8


void
on_mode_sip_activate                   (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{
	

}
// end add by dave 9 november

//add by dave 9 november
void
on_mode_ims_activate                   (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{

	

}
// end add by dave 9 november

//started edit richard december 8
gboolean
on_im_window_delete_event              (GtkWidget       *widget,
                                        GdkEvent        *event,
                                        gpointer         user_data)
{
   im_window_open = 0;
   num_im_tabs=0;
  return FALSE;
}
//end edit richard december 8


gboolean
on_preferences_delete_event            (GtkWidget       *widget,
                                        GdkEvent        *event,
                                        gpointer         user_data)
{
	preferences_open = 0;
  	return FALSE;
}



void
on_dtmf_3_button_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
	common_send_dtmf(3);
}


void
on_dtmf_4_button_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
	common_send_dtmf(4);
}


void
on_dtmf_5_button_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
	common_send_dtmf(5);
}


void
on_dtmf_7_button_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
	common_send_dtmf(7);
}


void
on_dtmf_8_button_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
	common_send_dtmf(8);
}


void
on_dtmf_9_button_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
	common_send_dtmf(9);
}


void
on_dtmf_asterisk_button_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
	common_send_dtmf(10);
}


void
on_dtmf_0_button_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
	common_send_dtmf(0);
}


void
on_dtmf_hash_button_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
	common_send_dtmf(11);
}


void
on_dtmf_6_button_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
	common_send_dtmf(6);
}


void
on_dtmf_2_button_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
	common_send_dtmf(2);
}


void
on_dtmf_1_button_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
	common_send_dtmf(1);
}


//start richard edit december 8
void
on_im_quit_activate                    (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{
	im_window_open = 0;
 	num_im_tabs=0;
	GtkWidget *im_window = lookup_widget(GTK_WIDGET(menuitem), "im_window");
	gtk_widget_destroy(im_window);
}
//end richard edit december 8


//start richard edit december 8
void
on_show_timestamps_activate            (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{
	if(time_stamps == VISIBLE)
	{
		time_stamps = NOT_VISIBLE;
	}
	else
	{
		time_stamps = VISIBLE;
	}
}

//end richard edit december 8


//start richard edit december 8
void
on_close_tab_button_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
	if( num_im_tabs == 1)
	{
		im_window_open = 0;
 		num_im_tabs=0;
		GtkWidget *im_window = lookup_widget(GTK_WIDGET(button), "im_window");
		GtkWidget *notebook = lookup_widget(GTK_WIDGET(button), "im_notebook");
		int page_num = gtk_notebook_get_current_page(GTK_NOTEBOOK(notebook));
		gtk_notebook_remove_page(GTK_NOTEBOOK(notebook),page_num);
		gtk_widget_destroy(im_window);
	}
	else
	{
		num_im_tabs--;
		GtkWidget *notebook = lookup_widget(GTK_WIDGET(button), "im_notebook");
		int page_num = gtk_notebook_get_current_page(GTK_NOTEBOOK(notebook));
		gtk_notebook_remove_page(GTK_NOTEBOOK(notebook),page_num);
		
	}
}
//end richard edit december 8

void
on_register_as_alice_activate          (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{

	strcpy(pref->name, "Alice");
	strcpy(pref->impu, "sip:alice@");
	strcat(pref->impu, pref->realm);
	strcpy(pref->impi, "alice@");
	strcat(pref->impi, pref->realm);
	strcpy(pref->password, "alice");

	strcpy(pref->xdms_username, "alice");
	strcpy(pref->xdms_password, "alice");
	ims_send_register();
}


void
on_register_as_bob_activate            (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{
	strcpy(pref->name, "Bob");
	strcpy(pref->impu, "sip:bob@");
	strcat(pref->impu, pref->realm);
	strcpy(pref->impi, "bob@");
	strcat(pref->impi, pref->realm);
	strcpy(pref->password, "bob");

	strcpy(pref->xdms_username, "bob");
	strcpy(pref->xdms_password, "bob");
	ims_send_register();

}


void
on_change_presentity_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

	presence_change_presentity();

}


void
on_add_buddy_button_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
	char new_buddy[50];

	pref->presence_enabled = 1;

	GtkWidget *new_presentity_widget = lookup_widget(GTK_WIDGET(button), "add_buddy_entry");
	strcpy(new_buddy, gtk_entry_get_text(GTK_ENTRY(new_presentity_widget)));

	presence_add_buddy(new_buddy);

}


void
on_remove_buddy_button_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
	char new_buddy[50];

	GtkWidget *new_presentity_widget = lookup_widget(GTK_WIDGET(button), "add_buddy_entry");
	strcpy(new_buddy, gtk_entry_get_text(GTK_ENTRY(new_presentity_widget)));

	presence_remove_buddy(new_buddy);
}


void
on_watcher1_approve_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{

	GList *li;
	watcherdata *current;
	li = g_list_nth(watcher_list, 0);
	current = (watcherdata *)li->data;
	xcap_allow_user(current->watcher);
	
}

void
on_watcher2_approve_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
	
	GList *li;
	watcherdata *current;
	li = g_list_nth(watcher_list, 1);
	current = (watcherdata *)li->data;
	xcap_allow_user(current->watcher);

}




void
on_watcher3_approve_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{

	GList *li;
	watcherdata *current;
	li = g_list_nth(watcher_list, 2);
	current = (watcherdata *)li->data;
	xcap_allow_user(current->watcher);

}


void
on_watcher4_approve_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{

	GList *li;
	watcherdata *current;
	li = g_list_nth(watcher_list, 3);
	current = (watcherdata *)li->data;
	xcap_allow_user(current->watcher);

}


void
on_watcher5_approve_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{

	GList *li;
	watcherdata *current;
	li = g_list_nth(watcher_list, 4);
	current = (watcherdata *)li->data;
	xcap_allow_user(current->watcher);

}

void
on_watcher1_reject_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{

	GList *li;
	watcherdata *current;
	li = g_list_nth(watcher_list, 0);
	current = (watcherdata *)li->data;
	xcap_block_user(current->watcher);

}


void
on_watcher2_reject_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
	GList *li;
	watcherdata *current;
	li = g_list_nth(watcher_list, 1);
	current = (watcherdata *)li->data;
	xcap_block_user(current->watcher);


}


void
on_watcher3_reject_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
	GList *li;
	watcherdata *current;
	li = g_list_nth(watcher_list, 2);
	current = (watcherdata *)li->data;
	xcap_block_user(current->watcher);

}


void
on_watcher4_reject_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
	GList *li;
	watcherdata *current;
	li = g_list_nth(watcher_list, 3);
	current = (watcherdata *)li->data;
	xcap_block_user(current->watcher);

}


void
on_watcher5_reject_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
	GList *li;
	watcherdata *current;
	li = g_list_nth(watcher_list, 4);
	current = (watcherdata *)li->data;
	xcap_block_user(current->watcher);

}



gboolean
on_uri_entry_key_press_event           (GtkWidget       *widget,
                                        GdkEventKey     *event,
                                        gpointer         user_data)
{

	if ((event-> keyval == 0xFF0D || event-> keyval == 0xFF8D)&&(!(event->state & GDK_CONTROL_MASK)&&!(event->state & GDK_SHIFT_MASK)&&!(event->state & 	GDK_MOD1_MASK) ))	
	{
		if (state == IDLE)
		{
			ims_call_initiate();
		}
	}


  return FALSE;
}


void
on_download_presrules_button_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{
	xcap_get_presrules_from_server();
}


void
on_upload_presrules_button_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
	xcap_put_presrules_to_server();
}


void
on_reset_pressrules_button_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
	xcap_reset_presrules_doc();

}


void
on_xdms_upload_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
	xcap_open_xdms_upload_window();
}


void
on_xdms_download_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
	xcap_open_xdms_download_window();
}


gboolean
on_xdms_download_window_delete_event   (GtkWidget       *widget,
                                        GdkEvent        *event,
                                        gpointer         user_data)
{

  	xdms_download_open = 0;
	return FALSE;
}


gboolean
on_xdms_upload_window_delete_event     (GtkWidget       *widget,
                                        GdkEvent        *event,
                                        gpointer         user_data)
{

 	xdms_upload_open = 0;
	return FALSE;
}


void
on_xdms_upload_xml_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
	xcap_put_xml_to_server();
}


void
on_xdms_download_xml_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
	xcap_get_xml_from_server();
}


gboolean
on_xml_file_dialog_delete_event        (GtkWidget       *widget,
                                        GdkEvent        *event,
                                        gpointer         user_data)
{

  	xml_file_dialog_open = 0;
	return FALSE;
}


void
on_xdms_upload_browse_button_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{
	xdms_xml_file_dialog_open();
}


void
on_xml_file_dialog_cancel_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
	gtk_widget_destroy (xml_file_dialog);
	xml_file_dialog_open = 0;
}


void
on_xml_file_dialog_open_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
	xcap_get_xml_filename();
}


void
on_call_alice_activate                 (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{
	if (state == IDLE)
	{
		/* Set the URI bar to alice's address */
		char uri[100];
		sprintf(uri, "sip:alice@%s", pref->realm);
		GtkWidget *uri_entry_widget = lookup_widget(GTK_WIDGET(imsUA), "uri_entry");
		gtk_entry_set_text(GTK_ENTRY(uri_entry_widget), uri);

		ims_call_initiate();
	}
	else
	{
		set_display("Already in a call");
	}

}


void
on_call_bob_activate                   (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{
	if (state == IDLE)
	{
		/* Set the URI bar to bob's address */
		char uri[100];
		sprintf(uri, "sip:bob@%s", pref->realm);	
		GtkWidget *uri_entry_widget = lookup_widget(GTK_WIDGET(imsUA), "uri_entry");
		gtk_entry_set_text(GTK_ENTRY(uri_entry_widget), uri);

		ims_call_initiate();
	}
	else
	{
		set_display("Already in a call");
	}
}


void
on_aboutdialog_destroy                 (GtkObject       *object,
                                        gpointer         user_data)
{

}


void
on_aboutdialog_close                   (GtkDialog       *dialog,
                                        gpointer         user_data)
{

}


void
on_aboutdialog_response                (GtkDialog       *dialog,
                                        gint             response_id,
                                        gpointer         user_data)
{
	GtkWidget *aboutdialog = lookup_widget(GTK_WIDGET(dialog), "aboutdialog");
	gtk_widget_destroy(aboutdialog);

}


void
on_channel_1_activate                  (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{

	if (state == IDLE)
	{
		/* Set the URI bar to the channel address */
		char uri[100];
		sprintf(uri, "sip:channel1@%s", pref->iptv_server);	
		GtkWidget *uri_entry_widget = lookup_widget(GTK_WIDGET(imsUA), "uri_entry");
		gtk_entry_set_text(GTK_ENTRY(uri_entry_widget), uri);

		ims_call_initiate();
	}
	else
	{
		set_display("Already in a call");
	}

}


void
on_channel_2_activate                  (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{

	if (state == IDLE)
	{
		/* Set the URI bar to the channel address */
		char uri[100];
		sprintf(uri, "sip:channel2@%s", pref->iptv_server);	
		GtkWidget *uri_entry_widget = lookup_widget(GTK_WIDGET(imsUA), "uri_entry");
		gtk_entry_set_text(GTK_ENTRY(uri_entry_widget), uri);

		ims_call_initiate();
	}
	else
	{
		set_display("Already in a call");
	}

}


void
on_channel_3_activate                  (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{

	if (state == IDLE)
	{
		/* Set the URI bar to the channel address */
		char uri[100];
		sprintf(uri, "sip:channel3@%s", pref->iptv_server);	
		GtkWidget *uri_entry_widget = lookup_widget(GTK_WIDGET(imsUA), "uri_entry");
		gtk_entry_set_text(GTK_ENTRY(uri_entry_widget), uri);

		ims_call_initiate();
	}
	else
	{
		set_display("Already in a call");
	}

}


void
on_full_screen1_activate               (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{
	if (full_screen == 0)
	{
		//maximise window and undecorate
		//gtk_window_set_decorated(GTK_WINDOW(videoWin),0);
		gtk_window_fullscreen(GTK_WINDOW(videoWin));
		full_screen = 1;
	}
	else if (full_screen == 1)
	{
		//minimise window and decorate
		//gtk_window_set_decorated(GTK_WINDOW(videoWin),1);
		gtk_window_unfullscreen(GTK_WINDOW(videoWin));
		full_screen = 0;
	}

}


gboolean
on_videoWin_delete_event               (GtkWidget       *widget,
                                        GdkEvent        *event,
                                        gpointer         user_data)
{
	terminate_call();
	gtk_widget_hide_all (videoWin);
	full_screen = 0;
  return FALSE;
}


gboolean
on_videoWin_key_press_event            (GtkWidget       *widget,
                                        GdkEventKey     *event,
                                        gpointer         user_data)
{
	if((event-> keyval == 0xFF0D || event-> keyval == 0xFF8D)&&(event->state & GDK_MOD1_MASK))
	{
		if(full_screen == 0)
		{
			//maximise window and undecorate
			//gtk_window_set_decorated(GTK_WINDOW(videoWin),0);
			gtk_window_fullscreen(GTK_WINDOW(videoWin));
			
			full_screen = 1;
		}
		else
		{
			//minimise window and decorate
			//gtk_window_set_decorated(GTK_WINDOW(videoWin),1);
			gtk_window_unfullscreen(GTK_WINDOW(videoWin));
			full_screen = 0;
		}
	}
  return FALSE;
}


gboolean
on_videoWin_button_press_event         (GtkWidget       *widget,
                                        GdkEventButton  *event,
                                        gpointer         user_data)
{

	


/* Maximise the window if we detect a double-click */
	if (event->type == GDK_2BUTTON_PRESS)
	{
		if(full_screen == 0)
		{
			//maximise window and undecorate
			//gtk_window_set_decorated(GTK_WINDOW(videoWin),0);
			gtk_window_fullscreen(GTK_WINDOW(videoWin));
			
			full_screen = 1;
		}
		else
		{
			//minimise window and decorate
			//gtk_window_set_decorated(GTK_WINDOW(videoWin),1);
			gtk_window_unfullscreen(GTK_WINDOW(videoWin));
			full_screen = 0;
		}


	}
  return FALSE;
}


gboolean
on_im_text_input_key_release_event     (GtkWidget       *widget,
                                        GdkEventKey     *event,
                                        gpointer         user_data)
{

	GtkWidget *im_text_entry = lookup_widget(GTK_WIDGET(im_window), "im_text_input");
	const gchar *im_input;
	im_input = gtk_entry_get_text(GTK_ENTRY(im_text_entry));
	int length = strlen(im_input);
	
	if (length  == 0 && !(event-> keyval == 0xFF0D || event-> keyval == 0xFF8D)) //text entry empty
	{
		ims_send_instant_message_status (0);
	}
  return FALSE;
}


void
on_IM_alice_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
	/* Set the URI bar to bob's address */
	char uri[100];
	sprintf(uri, "sip:alice@%s", pref->realm);	
	GtkWidget *chat_uri_entry = lookup_widget(GTK_WIDGET(imsUA), "chat_uri_entry");
	gtk_entry_set_text(GTK_ENTRY(chat_uri_entry), uri);
	ims_open_im_window();
}


void
on_IM_bob_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{
	
	/* Set the URI bar to bob's address */
	char uri[100];
	sprintf(uri, "sip:bob@%s", pref->realm);	
	GtkWidget *chat_uri_entry = lookup_widget(GTK_WIDGET(imsUA), "chat_uri_entry");
	gtk_entry_set_text(GTK_ENTRY(chat_uri_entry), uri);
	ims_open_im_window();
}


void
on_play_button_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
 	rtsp_resume_playback();
}


void
on_pause_button_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
	rtsp_pause_playback();
}


void
on_stop_button_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
	rtsp_stop_playback();
}


void
on_previous_button_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
	printf("Functionality still under construction\n");
	//under construction
}


void
on_rewind_button_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
	printf("Functionality still under construction\n");
	//under construction
	//rtsp_rewind_playback();
}


void
on_forward_button_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
	rtsp_forward_playback();
}


void
on_next_button_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
	printf("Functionality still under construction\n");
	//under construction
}

gboolean
on_vod_window_delete_event             (GtkWidget       *widget,
                                        GdkEvent        *event,
                                        gpointer         user_data)
{
  rtsp_end_session();
  terminate_call();
  vod_window_open = 0;
  return FALSE;
}


// void
// on_volume_control_change_value         (GtkSpinButton   *spinbutton,
//                                         GtkScrollType    scroll,
//                                         gpointer         user_data)
// {
// 	rtsp_change_volume();
// }


void
on_volume_control_value_changed        (GtkSpinButton   *spinbutton,
                                        gpointer         user_data)
{
	rtsp_change_volume();
}


gboolean
on_vod_out_button_press_event          (GtkWidget       *widget,
                                        GdkEventButton  *event,
                                        gpointer         user_data)
{

	/* Maximise the window if we detect a double-click */
	if (event->type == GDK_2BUTTON_PRESS)
	{
		//toggle maximised window
		if(vod_full_screen == 0)
		{
			gtk_window_fullscreen(GTK_WINDOW(vod_window));
			vod_full_screen = 1;
		}
		else
		{
			gtk_window_unfullscreen(GTK_WINDOW(vod_window));
			vod_full_screen = 0;
		}


	}
  return FALSE;

}

//Edit Robert Marston July 2008
void
on_iptv_tv_epg_button_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
	iptv_epg_show_guide();
}


void
on_iptv_vod_epg_button_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
	iptv_vod_epg_show_guide();
}


void
on_iptv_show_all_button_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
	iptv_vod_filter(0);
}


void
on_iptv_show_movies_button_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
	iptv_vod_filter(1);
}


void
on_iptv_show_tvseries_buttons_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{
	iptv_vod_filter(2);
}


void
on_iptv_vod_epg_treeview_row_activated (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	iptv_epg_row_activated(treeview, path, 1);
}


void
on_iptv_vod_epg_treeview_cursor_changed
                                        (GtkTreeView     *treeview,
                                        gpointer         user_data)
{
	iptv_epg_row_selected(treeview, 1);
}


void
on_iptv_epg_treeview_cursor_changed    (GtkTreeView     *treeview,
                                        gpointer         user_data)
{
	iptv_epg_row_selected(treeview, 0);
}


void
on_iptv_epg_treeview_row_activated     (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	iptv_epg_row_activated(treeview, path, 0);
}


gboolean
on_iptv_vod_epg_window_delete_event    (GtkWidget       *widget,
                                        GdkEvent        *event,
                                        gpointer         user_data)
{
	iptv_vod_epg_window_open = 0;
    	g_object_unref(iptv_vod_treestore);
 	return FALSE;
}


gboolean
on_iptv_epg_window_delete_event        (GtkWidget       *widget,
                                        GdkEvent        *event,
                                        gpointer         user_data)
{
	iptv_epg_window_open = 0;
	return FALSE;
}


void
on_iptv_select_channel_button_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{
    gint chan_number;
    gchar *channel;
    GtkWidget *iptv_channel_spin_button = lookup_widget(GTK_WIDGET(imsUA), "iptv_channel_spin_button");
    chan_number = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(iptv_channel_spin_button));
    channel = g_strdup_printf("channel%d", chan_number);
    iptv_invite_iptvAS((char *)channel);
}
//End edit Rob July 2008

