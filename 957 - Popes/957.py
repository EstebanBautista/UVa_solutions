from sys import stdin

def upper_bound(popes, valor):
    left = 0
    right = len(popes) 
    while left < right:
        mid = (left + right) // 2 # se usa // para hacer una division entera y mid no sea un flotante
        if popes[mid] <= valor:
            left = mid + 1
        else:
            right = mid
    return left - 1  # Se le resta 1 para hallar la posicion del ultimo valor dentro del intervalo, valor = 4, [0,1,2,2,4,4,10,11], nos devuelve 5 en vez de 6

def main():
    period = stdin.readline().strip()
    while period != "":
        periodo = int(period)
        years = int(stdin.readline())
        popes = []
        ans = 0
        first_value = 0
        second_value = 0

        for _ in range(int(years)):
            onePope = int(stdin.readline().strip())
            popes.append(onePope)

        for j in range(len(popes)):
            intervalo = popes[j] + (periodo - 1)
            max = upper_bound(popes, intervalo)
            if (max - j + 1) > ans:
                ans = max - j + 1
                first_value = popes[j]
                second_value = popes[max]

        print(f"{ans} {first_value} {second_value}")
        ignore = stdin.readline()
        period = stdin.readline().strip()

main()