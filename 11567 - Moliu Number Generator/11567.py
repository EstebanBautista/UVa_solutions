# Nombre: Esteban David Muñoz Bautista
# Codigo: 8982338

from sys import stdin

def main():
    entrada = stdin.readline()

    while entrada != "":
        numero = int(entrada)
        cont = 0
        
        if numero == 0:
            print(0)
        else:
            while numero > 1:
                if numero % 2 == 0:
                    cont += 1
                    numero = numero >> 1
                else:
                    if numero == 3 or (numero % 4) == 1:
                        numero -= 1
                        cont += 1
                    else:
                        numero += 1
                        cont += 1
            cont += 1
            print(cont)

        entrada = stdin.readline()


main()