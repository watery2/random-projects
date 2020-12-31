import sqlite3

connection = sqlite3.connect("aquarium.db")

cursor = connection.cursor()

end = 0


def create():
    new = input("do you want to make a phone number list [y/n]: ")

    if new == "y" or new == "Y":
        name = input("enter him/her name: ")
        number = int(input("enter him/her number: "))
        try:
            cursor.execute("CREATE TABLE num (name TEXT, number INTEGER)")
        except sqlite3.OperationalError:
            print("ok")
        cursor.execute("INSERT INTO num VALUES (?, ?)", (name, number),)
        rows = cursor.execute("SELECT 'name:',name, 'number:',number FROM num ").fetchall()
        print(rows)
        connection.commit()

    elif new == "n" or new == "N":
        print("ok")


create()


def see():

    get = input("do you want to see someones number [y/n]: ")

    if get == "y" or get == "Y":
        print("this is what we got")
        show()
        try:
            name = input("enter him/her name: ")
            rows = cursor.execute("SELECT 'name:',name, 'number:', number FROM num WHERE name = ? ", (name,),
                                  ).fetchall()
            print(rows)
        except sqlite3.OperationalError:
            print("we cant find that")
            new = input("would you like to create it? [y/n]: ")
            if new == "y" or new == "Y":
                create()

            elif new == "n" or new == "N":
                print("ok")

    elif get == "n" or get == "N":
        print("ok")
        create()
    else:
        print("ok")

    modify_y = input("would you like to modify anything? [y/n]: ")

    if modify_y == "y" or modify_y == "Y":
        modify()

    else:
        print("ok")

    delete_t = input("would you like to delete anything? [y/n]: ")

    if delete_t == "y" or delete_t == "Y":
        delete()

    else:
        print("ok")

    ending = input("would you like to end this? [y/n]: ")

    if ending == "y" or ending == "Y":
        global end
        end = end + 1

    else:
        print("ok")


def modify():
    name = input("enter him/her name: ")
    new_number = int(input("enter a new number: "))
    cursor.execute("UPDATE num SET number = ? WHERE name = ?", (new_number, name))
    rows = cursor.execute("SELECT 'name:',name, 'number:',number FROM num ").fetchall()
    print(rows)
    connection.commit()


def delete():
    name = input("enter him/her name: ")
    cursor.execute("DELETE FROM num Where name = ?", (name,))
    rows = cursor.execute("SELECT 'name:',name, 'number:',number FROM num ").fetchall()
    print(rows)
    connection.commit()


def show():
    rows = cursor.execute("SELECT 'name:',name, 'number:',number FROM num ").fetchall()
    print(rows)


while end == 0:
    see()

connection.close()
