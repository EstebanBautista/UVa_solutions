# Nombre: Esteban David Muñoz Bautista
# Código: 8982338

from sys import stdin

adj = []
visitados = []
walks = []

def walk(v, n, N, camino, dis):
    global adj, walks, visitados

    if dis == n:
        walks.append(list(camino))
    else:
        for i in range(N):

            if adj[v][i] == 1 and visitados[i] == 0:
                visitados[i] = 1            
                camino.append(i + 1)

                walk(i, n, N, camino, dis + 1)  

                camino.pop()                
                visitados[i] = 0            

def main():
    global adj, visitados, walks
    linea = "-9999"
    
    while linea == "-9999":
        v, n = map(int, stdin.readline().split())
        adj.clear()
        visitados.clear()
        walks.clear()

        for _ in range(v):
            adj.append(list(map(int, stdin.readline().split())))
            visitados.append(0)
        
        visitados[0] = 1  
        walk(0, n, v, [1], 0)

        if len(walks) > 0:
            for caminito in walks:
                print('(' + ','.join(map(str, caminito)) + ')')
        else:
            print(f'no walk of length {n}')
        
        linea = stdin.readline().strip()
        if linea == "-9999":
            print()
            
    return 0


main()
