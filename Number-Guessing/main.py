import random

range_to = int(input("enter a range:"))

ans = random.randint(1, range_to)

i = int(input("enter your guess:"))

t = 0

while i != ans:
    if i > range_to:
        t = t + 1
        print("out of range, tries:", t)
    elif i > ans:
        t = t + 1
        print("its larger, tries:", t)
    elif i < ans:
        t = t + 1
        print("its less, tries:", t)

    i = int(input("enter again:"))

print("correct its:", ans, "tries:", t)