# Nombre: Esteban David Muñoz Bautista
# Codigo: 8982338

from sys import stdin
import math

def min_covering2(intervalos, final):
    intervalos.sort()
    ans = 0
    indice = 0
    numIntervalos = len(intervalos)
    posCubierta = 0.0
    posible = True

    while posCubierta < final and posible:
        #aqui defino si no hay mas intervalos o el siguiente deja un hueco es decir empieza despues de mi ultima posicion cubierta
        if indice >= numIntervalos or intervalos[indice][0] > posCubierta:
            posible = False
        else:
            best = indice 
            indice = indice + 1

            #revisamos todos los intervalos que inicien antes o hasta mi ultima posicion cubierta
            while indice < numIntervalos and intervalos[indice][0] <= posCubierta:

                #se elige el que mas se extienda a la derecha
                if intervalos[indice][1] > intervalos[best][1]:
                    best = indice
                indice += 1
            
            posCubierta = intervalos[best][1]
            ans += 1

    if posCubierta < final:
        ans = -1
    
    return ans


def main():
    entrada = stdin.readline()
    while entrada != "":
        aspersores, long, wide = map(int, entrada.split())
        intervalos = []
        #mid es lo mismo que "Y" en la formula
        mid = wide * 0.5

        for _ in range(aspersores):
            pos, radio = map(int, stdin.readline().split())
            if radio > mid:
                x = math.sqrt((radio * radio) - (mid * mid))
                intervalos.append([pos - x, pos + x])

        ans = min_covering2(intervalos, long)
        print(ans)

        entrada = stdin.readline()

main()

