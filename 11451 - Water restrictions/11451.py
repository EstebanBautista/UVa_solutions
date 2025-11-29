# Nombre: Esteban David Muñoz Bautista
# Código: 8982338

from sys import stdin


def solveSolvini(i, aguaUsada, riego, S, C, posiciones, maxFlujos, L):

    if aguaUsada > C:
        ans = -1

    elif i == S:
        regadas = 0
        j = 0
        while j < L:
            if riego[j]:
                regadas += 1
            j += 1
        ans = regadas

    else:
        mejor = 0
        f = 0
        while f <= maxFlujos[i]:
            if aguaUsada + f <= C:
                copia = list(riego)

                if f > 0:
                    izq = max(1, posiciones[i] - f)
                    der = min(L, posiciones[i] + f)
                    j = izq
                    while j <= der:
                        copia[j - 1] = True
                        j += 1

                valor = solveSolvini(i + 1, aguaUsada + f, copia, S, C, posiciones, maxFlujos, L)
                if valor > mejor:
                    mejor = valor
            f += 1

        ans = mejor

    return ans


def main():
    casos = int(stdin.readline())
    c = 0

    while c < casos:
        L = int(stdin.readline())
        S = int(stdin.readline())
        posiciones = list(map(int, stdin.readline().split()))
        C = int(stdin.readline())
        maxFlujos = list(map(int, stdin.readline().split()))

        riego = [False] * L

        ans = solveSolvini(0, 0, riego, S, C, posiciones, maxFlujos, L)
        print(ans)

        c += 1


main()
