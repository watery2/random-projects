from turtle import *
from random import *
import math

screen = getscreen()
screen.setup(width=800, height=800)
screen.title("Trash Collector")
screen.bgpic("background.png")
screen.addshape('player1.GIF')
screen.addshape('player2.GIF')
screen.addshape('player3.GIF')
screen.addshape('player4.GIF')
screen.addshape('player5.GIF')
screen.addshape('trash1.GIF')
screen.addshape('trash2.GIF')
direction = "forward"

random_num = 0

trashes = ["trash1.GIF", "trash2.GIF"]

hideturtle()

cash_a = 0
cash = Turtle()
cash.hideturtle()
cash.speed(0)
cash.penup()
cash.goto(180, 250)
cash.color("black")
cash.write(f"Money {cash_a}€", font=('Arial', 20, 'bold'))

words = Turtle()
words.hideturtle()
words.speed(0)
words.penup()
words.goto(-380, 250)
words.color("black")
words.write("", font=('Arial', 20, 'bold'))

player = Turtle()
player.speed(0)
player.penup()
player.shape('player1.GIF')
player.goto(-180, -170)


def right():
    global direction
    direction = "right"
    x = player.xcor()
    x += 10
    player.setx(x)


def left():
    global direction
    direction = "left"
    x = player.xcor()
    x -= 10
    player.setx(x)


def let_go():
    global direction
    direction = "forward"


def animate():
    if direction == "left":
        if player.shape() == "player4.GIF":
            player.shape("player5.GIF")
        elif player.shape() == "player5.GIF":
            player.shape("player4.GIF")
        else:
            player.shape("player4.GIF")

    if direction == "right":
        if player.shape() == "player2.GIF":
            player.shape("player3.GIF")
        elif player.shape() == "player3.GIF":
            player.shape("player2.GIF")
        else:
            player.shape("player2.GIF")

    if direction == "forward":
        player.shape('player1.GIF')

    screen.ontimer(animate, 500)


screen.listen()
screen.onkeypress(right, "d")
screen.onkeypress(left, "a")
screen.onkeyrelease(let_go, "d")
screen.onkeyrelease(let_go, "a")


def Collision(t1, t2):
    distance = math.sqrt(math.pow(t1.xcor()-t2.xcor(), 2)+math.pow(t1.ycor()-t2.ycor(), 2))
    if distance < 20:
        return True
    else:
        return False


Trash = []
for k in range(12):
    trash = Turtle()
    Trash.append(trash)
    x = -350 + k*65
    y = randint(100, 200)
    trash.speed(0)
    trash.penup()
    trash.goto(x, y)
    trash.shape(choice(trashes))
    trash.zingsnis = randint(8, 15)

animate()
while True:
    for trashh in Trash:
        y = trashh.ycor()
        y -= trashh.zingsnis
        trashh.sety(y)

        if Collision(player, trashh):
            trashh.sety(200)
            trashh.shape(choice(trashes))
            cash_a += 10
            cash.clear()
            cash.write(f"Money {cash_a}€", font=('Arial', 20, 'bold'))

        if trashh.ycor() < - 180:
            trashh.sety(200)

    if player.xcor() > 350:
        player.setx(-350)
    if player.xcor() < -350:
        player.setx(350)

    if cash_a == 10 and random_num == 0:
        words.write("You can buy some chicken nuggets", font=('Arial', 20, 'bold'))
        random_num += 1
    elif cash_a == 100 and random_num == 1:
        words.clear()
        words.write("Its time to buy some Video games", font=('Arial', 20, 'bold'))
        random_num += 1
    elif cash_a == 500 and random_num == 2:
        words.clear()
        words.write("Ps5 here i come", font=('Arial', 20, 'bold'))
        random_num += 1
    elif cash_a == 5000 and random_num == 3:
        words.clear()
        words.write("Time for a gaming pc", font=('Arial', 20, 'bold'))
        random_num += 1
    elif cash_a == 10000000 and random_num == 4:
        words.clear()
        words.write("Whats the point of working now?", font=('Arial', 20, 'bold'))
        random_num += 1
    elif cash_a == 100000000 and random_num == 5:
        words.clear()
        words.write("Go get some fresh air", font=('Arial', 20, 'bold'))
        random_num += 1

    screen.update()
