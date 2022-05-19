import sys
import sqlite3
import datetime


def delete_note(id_note):
    conn = sqlite3.connect('notes.db')
    cur = conn.cursor()
    cur.execute("DELETE FROM notes WHERE id == ? ", (id_note,))
    conn.commit()
    print("delete sucessful")


def return_note_by_id(id_note):
    conn = sqlite3.connect('notes.db')
    cur = conn.cursor()
    cur.execute("SELECT text FROM notes WHERE id == ? ", (id_note,))
    result = cur.fetchall()
    print("search sucessful")
    return result


def save_note(text_note, id_note):
    time = str(datetime.datetime.now())
    conn = sqlite3.connect('notes.db')
    cur = conn.cursor()
    cur.execute("DELETE FROM notes WHERE id == ? ", (id_note,))
    conn.commit()
    cur.execute("INSERT INTO notes VALUES(?, ?, ?);", (id_note, text_note, time))
    conn.commit()
    print("saved")


def get_next_id_for_cpp():
    conn = sqlite3.connect('notes.db')
    cur = conn.cursor()
    cur.execute("SELECT id FROM notes")
    ids = cur.fetchall()
    format_ids = list()
    for unformat_id in ids:
        for id in unformat_id:
            format_ids.append(id)
    with open("ids.txt", 'w') as f:
        for id in format_ids:
            f.write(str(id) + " ")


def get_id_for_py():
    conn = sqlite3.connect('notes.db')
    cur = conn.cursor()
    cur.execute("SELECT id FROM notes")
    ids = cur.fetchall()
    return ids


def main(args):
    args = args[1:]

    e = args[0]
    args = args[1:]

    if e == "add":
        get_next_id_for_cpp()
    elif e == "del":
        delete_note(args[0])
    elif e == "getr":
        geted_note = ""
        right_id = -1
        ids = get_id_for_py()
        print(ids)
        flag = 1
        for unf_id in ids:
            if flag:
                for id in unf_id:
                    if id > int(args[0]):
                        geted_note = return_note_by_id(id)
                        right_id = id
                        print(*geted_note)
                        flag = 0
        print(right_id)
    elif e == "getl":
        geted_note = ""
        left_id = -1
        ids = get_id_for_py()
        ids = ids[::-1]
        print(ids)
        flag = 1
        for unf_id in ids:
            if flag:
                for id in unf_id:
                    if id < int(args[0]):
                        geted_note = return_note_by_id(id)
                        left_id = id
                        print(*geted_note)
                        flag = 0
        print(left_id)
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
