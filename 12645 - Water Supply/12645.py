# Esteban David Muñoz Bautista
# Codigo: 8982338

import sys
from sys import stdin

sys.setrecursionlimit(10**6)

pilasS = []
pilasP = []
sccNodos = []
visitado = []
finalizacion = []
lista = []
t = 0
num = 0

def gabow(pueblos):

    for i in range(pueblos):
        if visitado[i] == -1:
            gabowaux(i)

def gabowaux(nodo):
    global t, num
    t += 1
    visitado[nodo] = t
    

    pilasS.append(nodo)
    pilasP.append(nodo)

    for apunta in range( len(lista[nodo])): # tambien  lo podria hacer asi  for newNodo in lista[nodo]:
        newNodo = lista[nodo][apunta]
 
        if visitado[newNodo] == -1:
            gabowaux(newNodo)
        elif finalizacion[newNodo] == -1:
            while visitado[pilasP[-1]] > visitado[newNodo]:
                pilasP.pop()

    if pilasP[-1] == nodo:
        num += 1
        sccNodos.append([])
        while pilasS[-1] != nodo:
            componente = pilasS.pop()
            finalizacion[componente] = num - 1
            sccNodos[num - 1].append(componente)

        componente = pilasS.pop()
        finalizacion[componente] = num - 1
        sccNodos[num - 1].append(componente)
        pilasP.pop()


def main():
    global lista, finalizacion, visitado, num
    entrada = stdin.readline().strip()

    while ( entrada!= ""):

        pueblos, tuberias = map(int, entrada.split())
        pueblos += 1
        
        #Limpieza
        pilasS.clear()
        pilasP.clear()
        sccNodos.clear()
        t = 0
        num = 0

        lista = [[] for _ in range (pueblos)]
        finalizacion = [-1 for _ in range(pueblos)]
        visitado = [-1 for _ in range(pueblos)]
        

        #Crear grafo 
        for _ in range(tuberias):
            ciudadA, ciudadB = list(map(int, stdin.readline().split()))
            lista[ciudadA].append(ciudadB)
        
        gabow(pueblos)

        senialados = [0 for _ in range(len(sccNodos))]
        
        #Creamos la insidencia del grafo scc 
        for nodo in range(pueblos):
            for apunta in lista[nodo]:
                if finalizacion[nodo] != finalizacion[apunta]:
                    senialados[finalizacion[apunta]] += 1

        #Determinar el origen de donde viene el agua y sumar la cantidad de tuberias que hacen falta con base 
        #en la insidencia 0, sin contar el origen
        origen = finalizacion[0]
        canridadTuberias = 0
        
        for i in range(len(sccNodos)) :
            if senialados[i] == 0 and i != origen:
                canridadTuberias += 1

        print(canridadTuberias)



        entrada = stdin.readline().strip()
main()