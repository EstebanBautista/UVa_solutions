# Nombre: Esteban David Muñoz Bautista
# Codigo: 8982338

from sys import stdin
import math

eps = 1e-9

def funcion (x, y, z):
    altura1 = math.sqrt((x**2)-(z**2))
    altura2 = math.sqrt((y**2)-(z**2))
    c = (altura1*altura2) / (altura1+altura2)
    return c

def bisection(limitA, limitB, valor, otro):
    left = limitA
    right = limitB

    while abs (right - left) > eps:
        mid = (left+right)/2
        if valor <= funcion(limitB, otro, mid):
            left = mid
        else:
            right = mid
    ans = left
    return ans


def main():
    into = stdin.readline()
    string = into.split()
    while into != "":
        x = float(string[0])
        y = float(string[1])
        c = float(string[2])
        if x >= y:
            ans = bisection(0, y, c, x)
        else:
            ans = bisection(0, x, c, y)

        print(f'{ans:.3f}')
        into = stdin.readline()
        string = into.split()
    

main()