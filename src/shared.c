#include <gtk/gtk.h>
#include "shared.h"

void hello(
    GtkWidget *widget,
    gpointer data)
{
    g_print("Hello World\n");
}
