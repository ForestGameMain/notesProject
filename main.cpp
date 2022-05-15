//
// Created by Ilya on 15.05.2022.
//
#include "gtkmm.h"
#include <iostream>


int main(int argc, char **argv) {
    auto app = Gtk::Application::create(argc, argv);
    auto ui = Gtk::Builder::create_from_file("design.glade");

    Gtk::ApplicationWindow *window;
    ui->get_widget("window", window);

    Gtk::Box *NoteBook;
    ui->get_widget("NoteBook", NoteBook);

    return app->run(*window);
}