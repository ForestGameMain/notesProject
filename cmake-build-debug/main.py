import sys


def add_note(text_note, id_note):
    pass


def delete_note():
    pass


def return_note_by_number():
    pass


def save_note_by_number(text_note, id_note):
    pass


def get_next_id():
    pass


def main(args):
    args = args[1:]

    e = args[0]
    id_note = get_next_id()
    args = args[1:]

    if e == "add":
        print("ok")
        new_note = str()
        for i in args:
            new_note += str(i) + " "
        add_note(new_note, id_note=1)
    elif e == "del":
        pass
    elif e == "get":
        geted_note = return_note_by_number()
    elif e == "save":
        new_note = str()
        for i in args:
            new_note += str(i) + " "
        save_note_by_number(new_note, id_note)
    else:
        print("command error")

    print(args)


if __name__ == '__main__':
    main(sys.argv)
