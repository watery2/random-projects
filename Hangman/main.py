import random

thing = ["boxing", "football", "police", "fireman", "meat"]

guess_list = []

z = 0

e = 0

s = 0


turns = 10

guess = random.choice(thing)

for i in guess:
    guess_list.append("_")

print(guess_list)

while turns > 0:
    enter = input("enter a letter: ")
    while len(enter) > 1:
        print("you can only enter one letter")
        enter = input("enter a letter: ")

    for n in guess:
        if n == enter:
            guess_list[z] = n
            z = z + 1
            s = s + 1

    for n in guess:
        if n != enter:
            e += 1

    if e == len(guess):
        turns -= 1
        e = 0

    print(guess_list)

    print("turns you got left", turns)

    if s == len(guess):
        print("YOU WON!!!")
        turns = -1

    if turns == 0:
        print("YOU LOSE!!!")
