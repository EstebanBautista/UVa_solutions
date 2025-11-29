# Nombre: Esteban David Muñoz Bautista
# Código: 8982338

from sys import stdin

def check(indice, inicio, cadena):
    valido = True

    #para evitar duplicados en casos como aaaabccd
    if indice > inicio and cadena[indice] == cadena[indice - 1]:
        valido = False

    return valido


def solveSolvini(sols, indice, cadena, numero):
    inicio = indice
    if len(sols) == numero:
        print(''.join(sols))
    else:
        while indice < len(cadena):
            if check(indice, inicio, cadena):
                sols.append(cadena[indice])
                solveSolvini(sols, indice + 1, cadena, numero)
                sols.pop()
            indice += 1
    

def main():
    linea = stdin.readline()

    while linea != "":
        cadena, numero = linea.split()
        numero = int(numero)
        sols = []
        cadena = sorted(cadena)
        solveSolvini(sols, 0, cadena, numero)
        linea = stdin.readline()

main()