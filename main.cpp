#include "gtkmm.h"
#include <iostream>
#include <fstream>

void on_del_btn_click(Gtk::Label *lbl, Gtk::Entry *input) {
    Glib::ustring temp = "python main.py del ";
    temp += lbl->get_text();
    system(temp.c_str());
    std::cout << "PYTHON CODE EXIT WITHOUT ERRORS\n";
    input->set_text("this note was deleted, press <- or ->");
}

void on_left_btn_click(Gtk::Label *lbl, Gtk::Entry *input) {
    Glib::ustring temp = "python main.py getl ";
    temp += lbl->get_text();
    temp += " ";
    system(temp.c_str());
    std::cout << "PYTHON CODE EXIT WITHOUT ERRORS\n";
    std::fstream fs;
    fs.open("ids.txt");
    std::string text;
    std::getline(fs, text);
    fs.close();
    std::ofstream file("ids.txt");
    file << "";
    std::string for_label = "", note = "";
    int flag = 1;
    for (int i = 0; i < text.size(); ++i) {
        if (flag) {
            for_label += text[i];
        } else {
            note += text[i];
        }
        if (text[i] == ' ') {
            flag = 0;
        }
    }
    lbl->set_text(for_label);
    input->set_text(note);
}

void on_save_btn_click(Gtk::Label *lbl,
                       Gtk::Entry *input) { // сохранение в БД под тем же idшником, старое сохранение стерается
    Glib::ustring temp = "python main.py save ";
    temp += lbl->get_text();
    temp += " ";
    temp += input->get_text();
    system(temp.c_str());
    std::cout << "PYTHON CODE EXIT WITHOUT ERRORS\n";
}

void on_right_btn_click(Gtk::Label *lbl, Gtk::Entry *input) {
    Glib::ustring temp = "python main.py getr ";
    temp += lbl->get_text();
    temp += " ";
    system(temp.c_str());
    std::cout << "PYTHON CODE EXIT WITHOUT ERRORS\n";
    std::fstream fs;
    fs.open("ids.txt");
    std::string text;
    std::getline(fs, text);
    fs.close();
    std::ofstream file("ids.txt");
    file << "";
    std::string for_label = "", note = "";
    int flag = 1;
    for (int i = 0; i < text.size(); ++i) {
        if (flag) {
            for_label += text[i];
        } else {
            note += text[i];
        }
        if (text[i] == ' ') {
            flag = 0;
        }
    }
    lbl->set_text(for_label);
    input->set_text(note);
}

void on_create_btn_click(Gtk::Label *lbl,
                         Gtk::Entry *input) { // лучше не вдумываться что за бред тут написан, но он работает
    const char *temp = "python main.py add ";
    system(temp);
    std::fstream fs;
    fs.open("ids.txt");
    std::string ids;
    std::getline(fs, ids);
    fs.close();
    std::ofstream file("ids.txt");
    file << "";
    std::set<int> format_ids;
    std::string t = "";
    for (int i = 0; i < ids.size(); ++i) {
        t += ids[i];
        if (ids[i] == ' ') {
            format_ids.insert(std::stoi(t));
            t = "";
        }
    }
    int id = 1;
    while (format_ids.count(id)) {
        id++;
    }

    lbl->set_text(std::to_string(id));
    input->set_text("new note");
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

    del_btn->signal_clicked().connect(sigc::bind(sigc::ptr_fun(&on_del_btn_click), lbl, input));
    left_btn->signal_clicked().connect(sigc::bind(sigc::ptr_fun(&on_left_btn_click), lbl, input));
    save_btn->signal_clicked().connect(sigc::bind(sigc::ptr_fun(&on_save_btn_click), lbl, input));
    right_btn->signal_clicked().connect(sigc::bind(sigc::ptr_fun(&on_right_btn_click), lbl, input));
    create_btn->signal_clicked().connect(sigc::bind(sigc::ptr_fun(&on_create_btn_click), lbl, input));

    return app->run(*window);
}