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

#ifndef CALLBACKS_H
#define CALLBACKS_H

#define VERSION "1.0.14"

/*
#include <gtk/gtk.h>
#include "imsUA.h"
#include "callbacks.h"
#include "interface.h"
#include "support.h"
*/

void
on_save_history1_activate              (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_quit1_activate                      (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_register2_activate                  (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_subscribe2_activate                 (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_preferences1_activate               (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_about1_activate                     (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_close_about_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_preferences_ok_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_call_button_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_sip_mode_activate                   (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_log_display1_activate               (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_hangup_button_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_send_im_button_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_im_text_input_realize               (GtkWidget       *widget,
                                        gpointer         user_data);

void
on_send_im_button_clicked              (GtkButton       *button,
                                        gpointer         user_data);

gboolean
on_im_text_input_key_press_event       (GtkWidget       *widget,
                                        GdkEventKey     *event,
                                        gpointer         user_data);

gboolean
on_imsUA_delete_event                  (GtkWidget       *widget,
                                        GdkEvent        *event,
                                        gpointer         user_data);

void
on_quit1_activate                      (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_deregister1_activate                (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_save1_activate                      (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_quit2_activate                      (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_cut1_activate                       (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_copy1_activate                      (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_paste1_activate                     (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_delete1_activate                    (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_about2_activate                     (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_start_chat_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_sip_mode_activate                   (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_ims_mode_activate                   (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_mode_sip_activate                   (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_mode_ims_activate                   (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

gboolean
on_im_window_delete_event              (GtkWidget       *widget,
                                        GdkEvent        *event,
                                        gpointer         user_data);

gboolean
on_preferences_delete_event            (GtkWidget       *widget,
                                        GdkEvent        *event,
                                        gpointer         user_data);

gboolean
on_preferences_delete_event            (GtkWidget       *widget,
                                        GdkEvent        *event,
                                        gpointer         user_data);

gboolean
on_im_window_delete_event              (GtkWidget       *widget,
                                        GdkEvent        *event,
                                        gpointer         user_data);

void
on_dtmf_3_button_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_dtmf_4_button_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_dtmf_5_button_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_dtmf_7_button_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_dtmf_8_button_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_dtmf_9_button_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_dtmf_asterisk_button_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_dtmf_0_button_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_dtmf_hash_button_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_dtmf_6_button_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_dtmf_2_button_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_dtmf_1_button_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_im_quit_activate                    (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_show_timestamps_activate            (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_close_tab_button_clicked            (GtkButton       *button,
                                        gpointer         user_data);

#endif

void
on_register_as_alice_activate          (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_register_as_bob_activate            (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_item2_activate                      (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_help_activate                       (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_about_activate                      (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_close_help_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_about_close                         (GtkDialog       *dialog,
                                        gpointer         user_data);

gboolean
on_about_button_press_event            (GtkWidget       *widget,
                                        GdkEventButton  *event,
                                        gpointer         user_data);

void
on_change_presentity_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_add_buddy_button_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_remove_buddy_button_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_watcher1_approve_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_watcher1_reject_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_watcher3_approve_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_watcher4_approve_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_watcher5_approve_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_watcher2_reject_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_watcher3_reject_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_watcher4_reject_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_watcher5_reject_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_watcher2_approve_clicked            (GtkButton       *button,
                                        gpointer         user_data);

gboolean
on_label119_button_press_event         (GtkWidget       *widget,
                                        GdkEventButton  *event,
                                        gpointer         user_data);

gboolean
on_uri_entry_key_press_event           (GtkWidget       *widget,
                                        GdkEventKey     *event,
                                        gpointer         user_data);

void
on_download_presrules_button_clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_upload_presrules_button_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_reset_pressrules_button_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_xdms_upload_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_xdms_download_clicked               (GtkButton       *button,
                                        gpointer         user_data);

gboolean
on_xdms_download_window_delete_event   (GtkWidget       *widget,
                                        GdkEvent        *event,
                                        gpointer         user_data);

gboolean
on_xdms_upload_window_delete_event     (GtkWidget       *widget,
                                        GdkEvent        *event,
                                        gpointer         user_data);

void
on_xdms_upload_xml_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_xdms_download_xml_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_browse_clicked                      (GtkButton       *button,
                                        gpointer         user_data);

gboolean
on_xml_file_dialog_delete_event        (GtkWidget       *widget,
                                        GdkEvent        *event,
                                        gpointer         user_data);

void
on_xdms_upload_browse_button_clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_xml_file_dialog_cancel_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_xml_file_dialog_open_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_call_alice_activate                 (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_call_bob_activate                   (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_aboutdialog_destroy                 (GtkObject       *object,
                                        gpointer         user_data);

void
on_aboutdialog_close                   (GtkDialog       *dialog,
                                        gpointer         user_data);

void
on_aboutdialog_response                (GtkDialog       *dialog,
                                        gint             response_id,
                                        gpointer         user_data);

void
on_channel_1_activate                  (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_channel_2_activate                  (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_channel_3_activate                  (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_full_screen1_activate               (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

gboolean
on_videoWin_delete_event               (GtkWidget       *widget,
                                        GdkEvent        *event,
                                        gpointer         user_data);

gboolean
on_videoWin_key_press_event            (GtkWidget       *widget,
                                        GdkEventKey     *event,
                                        gpointer         user_data);

gboolean
on_videoWin_button_press_event         (GtkWidget       *widget,
                                        GdkEventButton  *event,
                                        gpointer         user_data);

gboolean
on_im_text_input_key_release_event     (GtkWidget       *widget,
                                        GdkEventKey     *event,
                                        gpointer         user_data);

gboolean
on_im_text_input_key_release_event     (GtkWidget       *widget,
                                        GdkEventKey     *event,
                                        gpointer         user_data);

void
on_IM_alice_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_IM_bob_clicked                      (GtkButton       *button,
                                        gpointer         user_data);

void
on_play_button_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_pause_button_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_stop_button_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_previous_button_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_rewind_button_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_forward_button_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_next_button_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_volume_control_changed              (GtkEditable     *editable,
                                        gpointer         user_data);

gboolean
on_vod_window_delete_event             (GtkWidget       *widget,
                                        GdkEvent        *event,
                                        gpointer         user_data);

void
on_volume_control_change_value         (GtkSpinButton   *spinbutton,
                                        GtkScrollType    scroll,
                                        gpointer         user_data);

void
on_volume_control_value_changed        (GtkSpinButton   *spinbutton,
                                        gpointer         user_data);

gboolean
on_vod_out_button_press_event          (GtkWidget       *widget,
                                        GdkEventButton  *event,
                                        gpointer         user_data);

void
on_iptv_tv_epg_button_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_iptv_vod_epg_button_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_iptv_show_all_button_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_iptv_show_movies_button_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_iptv_show_tvseries_buttons_clicked  (GtkButton       *button,
                                        gpointer         user_data);

void
on_iptv_vod_epg_treeview_row_activated (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_iptv_vod_epg_treeview_cursor_changed
                                        (GtkTreeView     *treeview,
                                        gpointer         user_data);

void
on_iptv_epg_treeview_cursor_changed    (GtkTreeView     *treeview,
                                        gpointer         user_data);

void
on_iptv_epg_treeview_row_activated     (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

gboolean
on_iptv_vod_epg_window_delete_event    (GtkWidget       *widget,
                                        GdkEvent        *event,
                                        gpointer         user_data);

gboolean
on_iptv_epg_window_delete_event        (GtkWidget       *widget,
                                        GdkEvent        *event,
                                        gpointer         user_data);

void
on_iptv_select_channel_button_clicked  (GtkButton       *button,
                                        gpointer         user_data);
