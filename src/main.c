#include <gtk/gtk.h>
#include "menu.h"
#include "shared.h"

static gboolean delete_event(
    GtkWidget *widget,
    GdkEvent *event,
    gpointer data)
{
    g_print("delete event occurred\n");

    // TRUE means main window is not destroyed with "delete-event"
    return TRUE;
}

static void destroy(
    GtkWidget *widget,
    gpointer data)
{
    gtk_main_quit();
}

int main(
    int argc,
    char *argv[])
{
    GtkWidget *window;
    GtkWidget *main_vbox;
    GtkWidget *menubar;
    GtkWidget *button;

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(window, "delete-event",
            G_CALLBACK(delete_event), NULL);
    g_signal_connect(window, "destroy",
            G_CALLBACK(destroy), NULL);

    main_vbox = gtk_vbox_new(FALSE, 1);
    gtk_container_set_border_width(GTK_CONTAINER(main_vbox), 1);
    gtk_container_add(GTK_CONTAINER(window), main_vbox);

    menubar = get_menubar_menu(window);

    button = gtk_button_new_with_label("Hello World");
    g_signal_connect(button, "clicked",
            G_CALLBACK(hello), NULL);
    g_signal_connect_swapped(button, "clicked",
            G_CALLBACK(gtk_widget_destroy), window);

    gtk_box_pack_start(GTK_BOX(main_vbox), menubar, FALSE, FALSE, 0);
    gtk_box_pack_end(GTK_BOX(main_vbox), button, TRUE, TRUE, 0);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}
