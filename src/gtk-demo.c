#include <gtk/gtk.h>

static void hello(
    GtkWidget *widget,
    gpointer data)
{
    g_print("Hello World\n");
}

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

static GtkItemFactoryEntry menu_items[] = {
    { "/_File", NULL, NULL, 0, "<Branch>" },
    { "/File/_New", "<control>N", hello, 0, "<StockItem>", GTK_STOCK_NEW },
    { "/File/_Open", "<control>O", hello, 0, "<StockItem>", GTK_STOCK_OPEN },
    { "/File/_Save", "<control>S", hello, 0, "<StockItem>", GTK_STOCK_SAVE },
    { "/File/Save _As", NULL, NULL, 0, "<Item>" },
    { "/File/sep1", NULL, NULL, 0, "<Separator>" },
    { "/File/_Quit", "<CTRL>Q", gtk_main_quit, 0, "<StockItem>", GTK_STOCK_QUIT },

    { "/_Help", NULL, NULL, 0, "<Branch>" },
    { "/_Help/About", NULL, NULL, 0, "<Item>" },
};

static gint nmenu_items = sizeof (menu_items) / sizeof (menu_items[0]);

static GtkWidget *get_menubar_menu(GtkWidget *window)
{
    GtkAccelGroup *accel_group;
    GtkItemFactory *item_factory;

    accel_group = gtk_accel_group_new();
    item_factory = gtk_item_factory_new(GTK_TYPE_MENU_BAR, "<main>",
            accel_group);

    gtk_item_factory_create_items(item_factory, nmenu_items, menu_items, NULL);
    gtk_window_add_accel_group(GTK_WINDOW(window), accel_group);

    return gtk_item_factory_get_widget(item_factory, "<main>");
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
