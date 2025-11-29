# Nombre: Esteban David Muñoz Bautista
# Codigo: 8982338

from sys import stdin

p, rango = [0 for _ in range(200)], [0 for _ in range(200)]

def makeSet(v):
    p[v], rango[v] = v, 0

def findSet(v):
    ans = None
    if v == p[v]:
        ans = v
    else:
        p[v] = findSet(p[v])
        ans = p[v]
    return ans

def unionSet(u, v):
    u, v = findSet(u), findSet(v)
    if u != v:
        if rango[u] < rango[v]:
            u, v = v, u
        p[v] = u
        if rango[u] == rango[v]:
            rango[u] += 1

def kruskal(n, aristas, prohibida):
    # DSU local limpio
    p = list(range(n+1))
    r = [0]*(n+1)

    def find(x):
        if x != p[x]:
            p[x] = find(p[x])
        return p[x]

    def union(a,b):
        ra, rb = find(a), find(b)
        if ra != rb:
            if r[ra] < r[rb]:
                ra, rb = rb, ra
            p[rb] = ra
            if r[ra] == r[rb]:
                r[ra] += 1
            return True
        return False

    aristas.sort(key=lambda x: x[2])

    mst = []
    costo = 0

    for idx, (u,v,c) in enumerate(aristas):
        if idx == prohibida:
            continue
        if union(u,v):
            mst.append(idx)
            costo += c
            if len(mst) == n-1:
                break

    if len(mst) == n-1:
        return mst, costo
    else:
        return [], float("inf")


def main():
    casos = int(stdin.readline())
    caso = 1
    while caso <= casos:
        linea = stdin.readline()
        n, m = map(int, linea.split())
        aristas= []
        for _ in range(m):
            u, v, c = map(int, stdin.readline().split())
            aristas.append((u, v, c))
        
        mst, costo = kruskal(n, aristas, -1)

        if costo == float("inf"):
            print(f"Case #{caso} : No way")
        else:
            segundo = float("inf")

            for edgeIndex in mst:
                _, costo2 = kruskal(n, aristas, edgeIndex)
                segundo = min(segundo, costo2)

            if segundo == float("inf"):
                print(f"Case #{caso} : No second way")
            else:
                print(f"Case #{caso} : {segundo}")

        caso += 1  




main()