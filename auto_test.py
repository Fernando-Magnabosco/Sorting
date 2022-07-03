from curses.ascii import isalpha
import sys
import subprocess

num = int(sys.argv[1])
file = sys.argv[2]
times = []
sum = 0

for i in range(num):
    args = ("obj/"+file+".o")
    popen = subprocess.Popen(args, stdout=subprocess.PIPE)
    popen.wait()
    output = popen.stdout.read()

    data = []

    for char in str(output):
        if not isalpha(char) and char != "'":
            data.append(char)
        if char == 'm':
            break
    data = "".join(data)

    times.append(int(data))

    sum += int(data)

mean = sum/num
variancy = 0.0

for xi in times:
    variancy += (xi - mean) ** 2

variancy = variancy/num


print(f"Mean: {mean}ms\nSD: {variancy ** (1/2)}ms")
