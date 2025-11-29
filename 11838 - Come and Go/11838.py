from sys import stdin

pilasS = []
pilasP = []
sccNodos = []
visitado = []
finalizacion = []
lista = []
tiempo = 0
num = 0

def gabow(ciudades):

    for i in range(ciudades):
        if visitado[i] == -1:
            gabowaux(i)

def gabowaux(nodo):
    global tiempo, num
    tiempo += 1
    visitado[nodo] = tiempo
    

    pilasS.append(nodo)
    pilasP.append(nodo)

    for apunta in range(len(lista[nodo])): # tambien  lo podria hacer asi  for newNodo in lista[nodo]:
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
    global lista, visitado, finalizacion, tiempo, num
    nodos, aristas = map(int, stdin.readline().split())
    
    while (nodos != 0 and aristas != 0):

        #inicializacion
        lista = [[] for _ in range(nodos)]
        finalizacion = [-1 for _ in range(nodos)]
        visitado = [-1 for _ in range (nodos)]

        #crear grafo
        for _ in range(aristas):
            nodoA, nodoB, tipo = map(int, stdin.readline().split())
            if tipo == 2:
                lista[nodoA - 1].append(nodoB - 1)
                lista[nodoB - 1].append(nodoA - 1)
            else:
                lista[nodoA - 1].append(nodoB - 1)

        gabow(nodos)

        if len(sccNodos) == 1:
            print("1")
        else:
            print("0")


        #limpieza
        pilasS.clear()
        pilasP.clear()
        sccNodos.clear()
        tiempo = 0
        num = 0

        #lectura
        nodos, aristas = map(int, stdin.readline().split())
main()