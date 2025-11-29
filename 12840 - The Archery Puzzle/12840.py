# Nombre: Esteban David Muñoz Bautista
# Código: 8982338

from sys import stdin

mejorLongitud = 0
mejorSecuencia = []


def solveSolvini(objetivo, puntajes, actual, suma):
    global mejorLongitud, mejorSecuencia

    if suma == objetivo:
        if mejorLongitud == 0 or len(actual) < mejorLongitud:
            mejorLongitud = len(actual)
            mejorSecuencia = list(actual)
        elif len(actual) == mejorLongitud:
            if actual > mejorSecuencia:
                mejorSecuencia = list(actual)
    else:
        if (suma < objetivo) and (mejorLongitud == 0 or len(actual) < mejorLongitud):
            i = 0
            while i < len(puntajes):
                actual.append(puntajes[i])
                solveSolvini(objetivo, puntajes, actual, suma + puntajes[i])
                actual.pop()
                i += 1


def main():
    global mejorLongitud, mejorSecuencia
    casos = int(stdin.readline())
    
    for c in range(1, casos+1):
        cantidad, objetivo = map(int, stdin.readline().split())
        puntajes = list(map(int, stdin.readline().split()))
        
        puntajes.sort(reverse=True)
        mejorLongitud = 0
        mejorSecuencia = []
        
        solveSolvini(objetivo, puntajes, [], 0)

        if mejorLongitud == 0:
            print(f"Case {c}: impossible")
        else:
            sec = " ".join(map(str, mejorSecuencia))
            print(f"Case {c}: [{mejorLongitud}] {sec}")
        


main()
