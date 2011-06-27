/*
 * Copyright (C) 2011 Jacob Israel Cervantes Luevano <jacobnix@gmail.com>
 *
 * This sample is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This sample is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#include <string.h>
#include <gtk/gtk.h>
#include <webkit/webkit.h>

void show_Usage()
{
	
	g_printf("Copyright (C) 2011 Jacob Israel Cervantes Luevano <jacobnix@gmail.com>.\n");
	g_printf("This is free software; see the source for copying conditions.\nThere is NO  warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.\n");
	g_printf("Super Simple Facebook Browser for GNOME Desktop\n");
	g_printf("Usage: getfacebook --facebook-profile [your-real-profile]\n");

}

const gchar* myStrCat(const gchar *furl,const gchar *fprof)
{
  gchar *p,*q,*res;
  int num_chars;
	
   for (num_chars = 0, p = furl; *p != '\0'; num_chars++, p++)
      ;
   for (p = fprof; *p != '\0'; num_chars++, p++);
      ;   
   res = (char *) malloc(num_chars + 1);   
   for (p =res, q = furl; (*p = *q) != '\0'; p++, q++) ;
   for (q = fprof; (*p = *q) != '\0'; p++, q++) ;
   
   return res;
   free(res); 
}

int main(int argc,char *argv[])
{

	GtkWidget *facebookWin;
	GtkWidget *facebookWin_scrollw;
	GtkWidget *facebookWin_webview;

	gtk_init(&argc,&argv);

	const gchar *fbookWinTitle = "my FaceBook";
	const gchar *facebook_url = "http://www.facebook.com/";
	const gchar *facebook_profile, *my_profile;

	facebook_profile = (strcmp(argv[1],"--facebook-profile") == 0) ? argv[2] : 0;

	if(facebook_profile == 0) {show_Usage();return 0;}

	my_profile = myStrCat(facebook_url,facebook_profile);
		
	facebookWin = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	facebookWin_scrollw = gtk_scrolled_window_new (NULL,NULL);
	facebookWin_webview = webkit_web_view_new();

	gtk_window_set_title (GTK_WINDOW (facebookWin), fbookWinTitle);

	gtk_container_add (GTK_CONTAINER (facebookWin_scrollw), facebookWin_webview);
	gtk_container_add (GTK_CONTAINER (facebookWin), facebookWin_scrollw);

	webkit_web_view_load_uri (WEBKIT_WEB_VIEW (facebookWin_webview), my_profile);
	
	g_signal_connect (facebookWin, "destroy", G_CALLBACK (gtk_main_quit), NULL);

	gtk_window_set_default_size (GTK_WINDOW (facebookWin),800,600);

	gtk_widget_show_all (facebookWin);

	gtk_main ();

	return 0;

} 
