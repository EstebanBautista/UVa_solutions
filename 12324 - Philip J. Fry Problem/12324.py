# Nombre: Esteban David Muñoz Bautista
# Codigo: 8982338

from sys import stdin

def solveSolvini(n, trips):
    #dp[i][k] = min tiempo tras hacer i viajes con k esferas disponibles
    dp = [[None] * (n+1) for _ in range(n+1)]
    dp[0][0] = 0  #al inicio 0 viajes - 0 esferas  - tiempo 0

    for i in range(n):
        t, b = trips[i]
        for k in range(n+1):
            if dp[i][k] is not None:

                #no usar pelotica
                newK = min(n, k + b)
                newTiempo = dp[i][k] + t
                if dp[i+1][newK] is None or newTiempo < dp[i+1][newK]:
                    dp[i+1][newK] = newTiempo

                #usar esfera si es que hay
                if k > 0:
                    newK = min(n, k - 1 + b)
                    newTiempo = dp[i][k] + (t >> 1)
                    if dp[i+1][newK] is None or newTiempo < dp[i+1][newK]:
                        dp[i+1][newK] = newTiempo

    #minimo tiempo entre todos los estados finales alcanzables
    mejor = None
    for tim in dp[n]:
        if tim is not None:
            if mejor is None or tim < mejor:
                mejor = tim
    return mejor



def main():
    n = int(stdin.readline())
    while n != 0:
        trips = []
        for _ in range(n):
            t, b = map(int, stdin.readline().split())
            trips.append((t, b))

        print(solveSolvini(n, trips))
        n = int(stdin.readline())

main()
