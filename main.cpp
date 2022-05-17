#include "gtkmm.h"
#include <iostream>

void on_btn_click(Gtk::Label *lbl) {
    std::string temp = lbl->get_text();
    temp = "changed";
    lbl->set_label(temp);
}
int main(int argc, char **argv) {
    auto app = Gtk::Application::create(argc, argv);
    auto ui = Gtk::Builder::create_from_file("design.glade");

    Gtk::ApplicationWindow *window;
    ui->get_widget("window", window);

    Gtk::Box *main_box;
    ui->get_widget("main_box", main_box);

    Gtk::Label *lbl;
    ui->get_widget("lbl", lbl);

    Gtk::Entry *input;
    ui->get_widget("input", input);
    Gtk::Button *del_btn;
    ui->get_widget("del_btn", del_btn);
    Gtk::Button *left_btn;
    ui->get_widget("left_btn", left_btn);
    Gtk::Button *save_btn;
    ui->get_widget("save_btn", save_btn);
    Gtk::Button *right_btn;
    ui->get_widget("right_btn", right_btn);
    Gtk::Button *create_btn;
    ui->get_widget("create_btn", create_btn);

    create_btn->signal_clicked().connect(sigc::bind(sigc::ptr_fun(&on_btn_click), lbl));
    return app->run(*window);
}