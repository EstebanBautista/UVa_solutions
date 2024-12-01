#Esteban David Muñoz Bautista
#Codigo: 8982338

from collections import deque
from sys import stdin

INF = float("inf")
dx = [0, -1, 0, 1]
dy = [-1, 0, 1, 0]


def bfs(posInicial, destino, filas, columnas, muros):
    cola = deque()
    cola.append(posInicial)
    flag = False
    visitados = {}

    while cola and flag == False:
        estadoAct = cola.popleft()
        fila = estadoAct[0]
        columna = estadoAct[1]
        direccion = estadoAct[2]
        color = estadoAct[3]
        tiempo = estadoAct[4]
        newEstado = (fila, columna, direccion, color)

        if newEstado not in visitados:
            visitados[newEstado] = True
            
            #acabaste?
            if fila == destino[0] and columna == destino[1] and color == destino[3]:
                if tiempo < destino[4]:
                    destino[4] = tiempo
                    flag = True
            else:
                #izquierda
                cola.append((fila, columna, (direccion - 1) % 4, color, tiempo + 1))
                
                #derecha
                cola.append((fila, columna, (direccion + 1) % 4, color, tiempo + 1))

                #subir
                nuevaFila = fila + dy[direccion]
                nuevaColumna = columna + dx[direccion]
                if 0 <= nuevaFila < filas and 0 <= nuevaColumna < columnas and (nuevaFila, nuevaColumna) not in muros:
                    cola.append((nuevaFila, nuevaColumna, direccion, (color + 1) % 5, tiempo + 1))

def main():
    filas, columnas = list(map(int, stdin.readline().split()))
    caso = 0

    while filas != 0 and columnas != 0:
        muros = set()
        caso += 1

        for x in range(filas):
            linea = stdin.readline()
            y = 0
            for coordenada in linea:
                if coordenada == 'S':
                    posInicial = (x, y, 0, 0, 0)
                elif coordenada == 'T':
                    destino = [x, y, 0, 0, INF]
                elif coordenada == '#':
                    muros.add((x, y))
                y += 1
        bfs(posInicial, destino, filas, columnas, muros)

        print(f"Case #{caso}")
        if destino[4] < INF:
            print(f"minimum time = {destino[4]} sec")
        else:
            print("destination not reachable")

        filas, columnas = list(map(int, stdin.readline().split()))
        if filas != 0 and columnas != 0:
            print("")

main()