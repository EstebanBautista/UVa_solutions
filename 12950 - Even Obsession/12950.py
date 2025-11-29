# Nombre: Esteban David Muñoz Bautista
# Codigo: 8982338


# Nombre: Esteban David Muñoz Bautista
# Codigo: 8982338

from sys import stdin
from heapq import heappush, heappop


def dijkstra(G, s, t):
    dist = [[float("inf") for _ in range(len(G))] for _ in range(2)]
    dist[0][s] = 0

    pqueue, found = list(), False
    heappush(pqueue, (0, s, 0))

    while len(pqueue) != 0 and not found:
        du, u, par = heappop(pqueue)

        if u == t and par == 0:
            found = True

        else:
            if du == dist[par][u]:
                for v, w in G[u]:
                    newPar = 1 - par 
                    nuevoCost = du + w
                    
                    if nuevoCost < dist[newPar][v]:
                        dist[newPar][v] = nuevoCost
                        heappush(pqueue, (nuevoCost, v, newPar))


    return dist[0][t]  


def main():
    entrada = stdin.readline()

    while entrada != "":
        ciudad, caminos = map(int, entrada.split())
        lista = [[] for _ in range(ciudad)]

        for _ in range(caminos):
            c1, c2, g = map(int, stdin.readline().split())
            lista[c1 - 1].append((c2 - 1, g))
            lista[c2 - 1].append((c1 - 1, g))

        ans = dijkstra(lista, 0, ciudad - 1)

        if ans == float("inf"):
            print(-1)
        else:
            print(ans)

        entrada = stdin.readline()


main()
