#include <gtk/gtk.h>
#include "about.h"

static void show_about_dialog()
{
    gchar *authors[] = {
            "Lochlan McIntosh ❧ http://lochlanmcintosh.com/",
            NULL};

    gtk_show_about_dialog(NULL,
            "comments", "Just a little GTK+ 2 demo",
            "authors", authors,
            NULL);
}

void menu_help_about()
{
    show_about_dialog();
}
