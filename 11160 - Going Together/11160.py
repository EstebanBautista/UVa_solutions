#Esteban David Muñoz Bautista
#Codigo: 8982338
#La complejidad des O(n^6) siendo n las filas pero tambien las columnas
#pero esta elevado a la 6, dado quehay tres personajes (A, B, C), cada uno
#de los cuales puede estar en cualquier celda, lo que hace que sea n^2 por cada personaje


from collections import deque
from sys import stdin

dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]

def bfs(posInicialA, posInicialB, posInicialC, n, muros, destinos):
    cola = deque()  
    cola.append((posInicialA, posInicialB, posInicialC))  
    visitados = {}  
    visitados[(posInicialA, posInicialB, posInicialC)] = 0  
    ans = 0 

    while cola:
        estadoActual = cola.popleft()
        posicionA = estadoActual[0]
        posicionB = estadoActual[1]
        posicionC = estadoActual[2]
        tiempo = visitados[estadoActual]

        if (posicionA in destinos and posicionB in destinos and posicionC in destinos and posicionA != posicionB and posicionA != posicionC and posicionB != posicionC):
            ans = tiempo
            cola.clear()
        
        else:
            for i in range(4):
                #mover A
                nuevaPosA = (posicionA[0] + dx[i], posicionA[1] + dy[i])
                #muros
                if nuevaPosA in muros or not (0 <= nuevaPosA[0] < n and 0 <= nuevaPosA[1] < n):
                    nuevaPosA = posicionA
                
                #mover B
                nuevaPosB = (posicionB[0] + dx[i], posicionB[1] + dy[i])
                if nuevaPosB in muros or not (0 <= nuevaPosB[0] < n and 0 <= nuevaPosB[1] < n):
                    nuevaPosB = posicionB
                
                #mover C
                nuevaPosC = (posicionC[0] + dx[i], posicionC[1] + dy[i])
                if nuevaPosC in muros or not (0 <= nuevaPosC[0] < n and 0 <= nuevaPosC[1] < n):
                    nuevaPosC = posicionC

                #colisiones
                if nuevaPosA == nuevaPosB:
                    if nuevaPosB == nuevaPosC:
                        nuevaPosC = posicionC
                    nuevaPosA = posicionA
                    nuevaPosB = posicionB
                
                if nuevaPosA == nuevaPosC:
                    nuevaPosA = posicionA
                    nuevaPosC = posicionC
                
                if nuevaPosB == nuevaPosC:
                    nuevaPosB = posicionB
                    nuevaPosC = posicionC
                    if nuevaPosB == nuevaPosA:
                        nuevaPosA = posicionA

                nuevoEstado = (nuevaPosA, nuevaPosB, nuevaPosC)
                tiempoActualizado = tiempo + 1
                if nuevoEstado not in visitados or visitados[nuevoEstado] > tiempoActualizado:
                    visitados[nuevoEstado] = tiempoActualizado
                    cola.append(nuevoEstado)

    return ans

def main():
    casos = int(stdin.readline())
    
    for caso in range(casos):
        n = int(stdin.readline())
        muros = set()
        destinos = set()

        for x in range(n):
            linea = stdin.readline()
            for y, coordenada in enumerate(linea):

                if coordenada == 'X':
                    destinos.add((x, y))
                elif coordenada == 'A':
                    posInicialA = (x, y)
                elif coordenada == 'B':
                    posInicialB = (x, y)
                elif coordenada == 'C':
                    posInicialC = (x, y)
                elif coordenada == '#':
                    muros.add((x, y))

        resultado = bfs(posInicialA, posInicialB, posInicialC, n, muros, destinos)

        print(f"Case {caso+1}: ", end="")
        if resultado == 0:
            print("trapped")
        else:
            print(resultado)

main()
