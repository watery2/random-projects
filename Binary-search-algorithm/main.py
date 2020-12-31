            #0 1  2  3  4   5    6   7  8    9   10 11  12  13  14  15  16  17  18 19   20  21  22  23  24
list_t_g = [1, 3, 6, 9, 12, 14, 18, 21, 24, 27, 30, 33, 36, 39, 42, 45, 48, 51, 54, 57, 60, 63, 66, 69, 72,
            75, 78, 81, 84, 87, 90, 93, 96, 99, 100]
           #25  26  27  28  29  30  31  32  33  34
num = int(input("enter a random number: "))


def do(list_t_t, num_m):
    high_h = len(list_t_t) - 1
    low_w = 0
    while low_w <= high_h:
        mid = (high_h + low_w) // 2
        print("high", high_h)
        print("low", low_w)
        print("mid", mid)
        value = list_t_t[mid]

        if value == num_m:
            return mid

        elif num_m < value:
            high_h = mid - 1

        else:
            low_w = mid + 1
    return 0


print(do(list_t_g, num))
