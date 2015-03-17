#include <gtk/gtk.h>
#include "menu.h"
#include "menu/file/open.h"
#include "menu/help/about.h"
#include "shared.h"

static GtkItemFactoryEntry menu_items[] = {
    { "/_File", NULL, NULL, 0, "<Branch>" },
    { "/File/_New", "<control>N", hello, 0, "<StockItem>", GTK_STOCK_NEW },
    { "/File/_Open", "<control>O", menu_file_open, 0, "<StockItem>", GTK_STOCK_OPEN },
    { "/File/_Save", "<control>S", hello, 0, "<StockItem>", GTK_STOCK_SAVE },
    { "/File/Save _As", NULL, NULL, 0, "<Item>" },
    { "/File/sep1", NULL, NULL, 0, "<Separator>" },
    { "/File/_Quit", "<CTRL>Q", gtk_main_quit, 0, "<StockItem>", GTK_STOCK_QUIT },

    { "/_Help", NULL, NULL, 0, "<Branch>" },
    { "/_Help/About", NULL, menu_help_about, 0, "<StockItem>", GTK_STOCK_ABOUT },
};

static gint nmenu_items = sizeof (menu_items) / sizeof (menu_items[0]);

GtkWidget *get_menubar_menu(GtkWidget *window)
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
