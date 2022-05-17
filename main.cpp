#include "gtkmm.h"
#include <iostream>


int main(int argc, char **argv) {
    auto app = Gtk::Application::create(argc, argv);
    auto ui = Gtk::Builder::create_from_file("design.glade");

    Gtk::ApplicationWindow *window;
    ui->get_widget("window", window);

    Gtk::Box *main_box;
    ui->get_widget("main_box", main_box);

    Gtk::Label lbl("1");
    main_box->add(lbl);
    lbl.show();

    Gtk::Entry input;
    main_box->add(input);
    input.show();

    Gtk::Box button_box;
    Gtk::Button del_btn("Удалить");
    Gtk::Button left_btn("<-");
    Gtk::Button save_btn("Сохранить");
    Gtk::Button right_btn("->");
    Gtk::Button create_btn("Создать");

    button_box.add(del_btn);
    button_box.add(left_btn);
    button_box.add(save_btn);
    button_box.add(right_btn);
    button_box.add(create_btn);
    main_box->add(button_box);

    del_btn.show();
    left_btn.show();
    save_btn.show();
    right_btn.show();
    create_btn.show();
    button_box.show();

    return app->run(*window);
}