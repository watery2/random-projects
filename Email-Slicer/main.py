
email = input("enter your email address:")

name = ""

domain = ""

go = False

for i in email:
    if i == "@":
        i = ""
        break
    name = name + i

for n in email:
    if n == "@":
        go = True
        continue
    if go:
        domain = domain + n

print(f"your email is {email} and your name is {name} and domain is {domain}")

