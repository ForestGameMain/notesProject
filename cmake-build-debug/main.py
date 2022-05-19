import sys
import sqlite3
import datetime

def add_note(text_note, id_note):
    pass


def delete_note():
    pass


def return_note_by_number():
    pass


def save_note(text_note, id_note):
    time = str(datetime.datetime.now())
    conn = sqlite3.connect('notes.db')
    cur = conn.cursor()
    cur.execute("DELETE FROM notes WHERE id == ? ", (id_note,))
    conn.commit()
    cur.execute("INSERT INTO notes VALUES(?, ?, ?);", (id_note, text_note, time))
    conn.commit()
    print("saved")


def get_next_id():
    conn = sqlite3.connect('notes.db')
    cur = conn.cursor()
    cur.execute("DELETE FROM notes WHERE id == ? ", )
    conn.commit()
    cur.execute("SELECT id FROM notes ORDER BY id")
    print(cur.fetchmany())
    return 1


def main(args):
    args = args[1:]

    e = args[0]
    # id_note = get_next_id()
    args = args[1:]

    if e == "add":
        pass
    elif e == "del":
        pass
    elif e == "get":
        geted_note = return_note_by_number()
    elif e == "save":
        print("saving...")
        new_note = str()
        id_note = args[0]
        args = args[1:]
        for i in args:
            new_note += str(i) + " "
        save_note(new_note, id_note)
    else:
        print("command error")


if __name__ == '__main__':
    main(sys.argv)
