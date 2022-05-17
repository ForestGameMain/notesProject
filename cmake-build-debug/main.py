import sys


def add_note(text_note, id_note):
    pass


def delete_note():
    pass


def return_note_by_number():
    pass


def save_note_by_number():
    pass


def main(args):
    args = args[1:]

    e = args[0]
    id_note = args[1]
    args = args[2:]

    if e == "add":
        new_note = str()
        for i in args:
            new_note += str(i) + " "
        add_note(new_note, id_note)
    elif e == "del":
        pass
    elif e == "get":
        pass
    elif e == "save":
        pass
    else:
        print("command error")

    print(args)


if __name__ == '__main__':
    main(sys.argv)
