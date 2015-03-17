#include <gtk/gtk.h>
#include "open.h"

static void show_file_open_dialog()
{
    GtkWidget *dialog;

    dialog = gtk_file_chooser_dialog_new("Open File",
            NULL,
            GTK_FILE_CHOOSER_ACTION_OPEN,
            GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
            GTK_STOCK_OPEN, GTK_RESPONSE_ACCEPT,
            NULL);

    if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT) {
        char *filename;
        filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));
        // TODO open_file(filename);
        g_print(filename);
        g_free(filename);
    }
    gtk_widget_destroy(dialog);
}

void menu_file_open()
{
    show_file_open_dialog();
}
