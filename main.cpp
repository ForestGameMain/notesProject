#include "gtkmm.h"
#include <iostream>


int main(int argc, char **argv) {
    auto app = Gtk::Application::create(argc, argv);
    auto ui = Gtk::Builder::create_from_file("design.glade");

    Gtk::ApplicationWindow *window;
    ui->get_widget("window", window);

    Gtk::Box *main_box;
    ui->get_widget("main_box", main_box);
    Gtk::Entry *input = ;
    ui->get_widget("input", input);
    main_box.add(input);

    return app->run(*window);
}