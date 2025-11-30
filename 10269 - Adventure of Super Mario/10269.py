"""

Complejidad del algoritmo: La complejidad del algoritmo es O(N + M * log K) donde N es el numero de
nodos, M el total de aristas y K seria la cantidad de combinaciones y posibilidades que puede tomar
el estado (posicion, usos restantes, tiempo restante, y si tiene puestas las boticas) :D.  

"""

import sys
from heapq import heappush,heappop


def dijkstra(grafito, noditoInicial, noditoFinal, usosIniciales, tiempoPorUso, aldeas):
    distancias = {}
    colitaPrioridad = list()
    found = False

    tiempoRestantePorUso = tiempoPorUso

    heappush(colitaPrioridad, (0,  (noditoInicial, usosIniciales, tiempoRestantePorUso, None)))

    distancias[(noditoInicial, usosIniciales, tiempoRestantePorUso, None)] = 0
    
    while len(colitaPrioridad) != 0 and not found:
        tiempo, estado = heappop(colitaPrioridad)
        nodito, usosRestantes, tiempoRestantePorUso, botasActive = estado[0], estado[1], estado[2], estado[3]

        if nodito == noditoFinal:
            found = True

        if botasActive == None and found == False:
            
            if usosRestantes > 0:
                nuevoEstadoConBotas = (nodito, usosRestantes, tiempoRestantePorUso, True)
                if nuevoEstadoConBotas not in distancias:
                    distancias[nuevoEstadoConBotas] = tiempo
                heappush(colitaPrioridad, (tiempo, nuevoEstadoConBotas))

            nuevoEstadoSinBotas = (nodito, usosRestantes, tiempoRestantePorUso, False)
            if nuevoEstadoSinBotas not in distancias:
                distancias[nuevoEstadoSinBotas] = tiempo
            heappush(colitaPrioridad, (tiempo, nuevoEstadoSinBotas))


        else:
            if found == False:
                
                if botasActive == True :
                    for vNodito, tiempoVcNodito in grafito[nodito]:
                        
                        # revisar si la arista pesa mas que el tiempo restante
                        if tiempoVcNodito <= tiempoRestantePorUso:
                            #si es castillo
                            if vNodito > aldeas:
                                
                                nuevoEstado = (vNodito, usosRestantes - 1, tiempoPorUso, None)
                                
                                if nuevoEstado not in distancias:
                                    distancias[nuevoEstado] = float("inf")

                                if tiempo < distancias[nuevoEstado]: 
                                    distancias[nuevoEstado] = tiempo
                                    heappush(colitaPrioridad, (tiempo, nuevoEstado))

                            else:
                                if tiempoVcNodito == tiempoRestantePorUso:
                                    nuevoEstado = (vNodito, usosRestantes - 1, tiempoPorUso, None)
                                
                                elif tiempoVcNodito < tiempoRestantePorUso:
                                    nuevoEstado = (vNodito, usosRestantes, tiempoRestantePorUso - tiempoVcNodito, True)

                                    # CASO SURREALISTIC AUTISTIC CREAMPIE ANASHE
                                    nuevoEstado2 = (vNodito, usosRestantes-1, tiempoPorUso, None)
                                    if nuevoEstado2 not in distancias:
                                        distancias[nuevoEstado2] = float("inf")
                                    
                                    if tiempo < distancias[nuevoEstado2]: 
                                        distancias[nuevoEstado2] = tiempo
                                        heappush(colitaPrioridad, (tiempo, nuevoEstado2))

                                
                                if nuevoEstado not in distancias:
                                    distancias[nuevoEstado] = float("inf")

                                if tiempo < distancias[nuevoEstado]: 
                                    distancias[nuevoEstado] = tiempo
                                    heappush(colitaPrioridad, (tiempo, nuevoEstado))

                        # tiene las botas puestas y la arista pesaMas y toca caminarse eso
                        else:
                            SumaNuevoTiempo = tiempo + tiempoVcNodito

                            nuevoEstado = (vNodito, usosRestantes - 1, tiempoPorUso, None)
                            if nuevoEstado not in distancias:
                                distancias[nuevoEstado] = float("inf")

                            if SumaNuevoTiempo < distancias[nuevoEstado]: 
                                distancias[nuevoEstado] = SumaNuevoTiempo
                                heappush(colitaPrioridad, (SumaNuevoTiempo, nuevoEstado))


                else:
                    for vNodito, tiempoVcNodito in grafito[nodito]:
                        SumaNuevoTiempo = tiempo + tiempoVcNodito

                        nuevoEstado = (vNodito, usosRestantes, tiempoRestantePorUso, None)
                        if nuevoEstado not in distancias:
                            distancias[nuevoEstado] = float("inf")

                        if SumaNuevoTiempo < distancias[nuevoEstado]: 
                            distancias[nuevoEstado] = SumaNuevoTiempo
                            heappush(colitaPrioridad, (SumaNuevoTiempo, nuevoEstado))

    return tiempo


def main():
    contador = 1
    casos = int(input())
    while casos > 0:
        entrada = sys.stdin.readline().strip().split()
        aldeas, castillos, caminos, distanciaMaxALaVez, totalUsoBotas = map(int, entrada)

        grafito = {x: [] for x in range(aldeas+castillos+1)}

        i = 0
        while i < caminos:

            entradaNodos = sys.stdin.readline().strip().split()
            A, B, peso = map(int, entradaNodos)

            grafito[A].append((B, peso))
            grafito[B].append((A, peso))

            i += 1

        result = dijkstra(grafito, aldeas + castillos, 1, totalUsoBotas, distanciaMaxALaVez, aldeas)
 
        print(result)

        casos -= 1

main()