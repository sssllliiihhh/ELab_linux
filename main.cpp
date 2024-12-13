#include <iostream>
//#include <vector>
#include <gtk-3.0/gtk/gtk.h>

//std::vector<GtkWidget> view_list;
GtkWidget *oldWindow = nullptr;

void create_window(const char string[8]);

void on_button_clicked(GtkWidget *button, gpointer user_data) {
    create_window("NotELab");
}

void create_window(const gchar *title){
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), title);
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);

    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(window), box);

    GtkWidget *button = gtk_button_new_with_label(title);

    // Устанавливаем размер кнопки
    gtk_widget_set_size_request(button, 200, 100); // Ширина 200, высота 100

    // Устанавливаем цвет фона кнопки с помощью CSS
    GtkCssProvider *css_provider = gtk_css_provider_new();
    gtk_css_provider_load_from_data(css_provider,
                                    "button { background-color: #f54242; color: black; }", -1, NULL);

    gtk_style_context_add_provider_for_screen(gdk_screen_get_default(),
                                              GTK_STYLE_PROVIDER(css_provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

    g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), NULL);

    gtk_box_pack_start(GTK_BOX(box), button, FALSE, FALSE, 0);

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(window);

    oldWindow = window;

    gtk_window_maximize(reinterpret_cast<GtkWindow *>(window));
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    create_window("ELab");

    gtk_main();
    return 0;
}
