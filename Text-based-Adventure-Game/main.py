
move = input("enter move:")

if move == "move":
    print("there are 3 rooms 2 of the leed to your death")
    room = int(input("enter a room:"))
    if room == 1:
        print("you fell into a pool of sharks")
    elif room == 2:
        print("good job you chose the right one")
    elif room == 3:
        print("this room is full of ghouls witch ate you")
    else:
        print("there is no room called", room)

else:
    print("404")
