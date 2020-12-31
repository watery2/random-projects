import random

do_it = input("do you want to roll the dice [y/n]: ")

if do_it == "y":
    roll = random.randint(1, 6)
    print(roll)

while do_it != "n":

    do_it = input("do you want to roll the dice [y/n]: ")
    if do_it == "y":
        roll = random.randint(1, 6)
        print(roll)

