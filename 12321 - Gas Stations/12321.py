# Nombre: Esteban David Muñoz Bautista
# Codigo: 8982338

from sys import stdin

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
    entrada = stdin.readline().strip()
    while entrada != "0 0":
        longitud, estaciones = map(int, entrada.split())
        intervalos = []

        for _ in range(estaciones):
            ubicacion, radio = map(int, stdin.readline().split())
            inicio = ubicacion - radio
            fin = ubicacion + radio
            intervalos.append([inicio, fin])

        ans = min_covering2(intervalos, longitud)
        
        if ans == -1:
            print(-1)
        else:
            print(estaciones - ans)

        entrada = stdin.readline().strip()

main()

