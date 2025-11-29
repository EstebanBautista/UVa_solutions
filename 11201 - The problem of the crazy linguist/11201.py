# Nombre: Esteban David Muñoz Bautista
# Código: 8982338

from sys import stdin

probabilidades = [12.53, 1.42, 4.68, 5.86, 13.68,
                  0.69, 1.01, 0.70, 6.25, 0.44,
                  0.00, 4.97, 3.15, 6.71, 8.68,
                  2.51, 0.88, 6.87, 7.98, 4.63,
                  3.93, 0.90, 0.02, 0.22, 0.90, 0.52]


abecedario = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
             'j', 'k', 'l', 'm','n', 'o', 'p', 'q', 'r', 
             's', 't', 'u', 'v', 'w', 'x', 'y', 'z']


posicionLetra = {ch: i for i, ch in enumerate(abecedario)}

vocales = ['a', 'e', 'i', 'o', 'u']
consonantes = [c for c in abecedario if c not in vocales]

idVocales = [posicionLetra[c] for c in vocales]
idConsonantes = [posicionLetra[c] for c in consonantes]


def SBC(palabra):
    i = 0
    suma = 0.0

    while i < len(palabra):
        suma += (i + 1) * probabilidades[posicionLetra[palabra[i]]]
        i += 1

    ans = suma
    
    return ans


def solveSolvini(posicion, longitud, contador, memoria):

    total = 0.0
    cantidad = 0.0

    if posicion == longitud:
        ans = (0.0, 1.0)

    else:
        clave = (posicion, tuple(contador))
        
        if clave in memoria:
            ans = memoria[clave]
        
        else:

            if (posicion + 1) % 2 == 0:
                grupo = idVocales
            else:
                grupo = idConsonantes

            i = 0
            while i < len(grupo):
                letra = grupo[i]
                
                if contador[letra] < 2:

                    contador[letra] += 1
                    sumaParcial, cantidadParcial = solveSolvini(posicion + 1, longitud, contador, memoria)
                    valorLetra = (posicion + 1) * probabilidades[letra]
                    total += valorLetra * cantidadParcial + sumaParcial
                    cantidad += cantidadParcial
                    contador[letra] -= 1

                i += 1

            memoria[clave] = (total, cantidad)
            ans = (total, cantidad)
    return ans


def solve(letra, longitud):
    contador = [0] * 26
    contador[posicionLetra[letra]] = 1
    memoria = {}

    if longitud == 1:
        suma = probabilidades[posicionLetra[letra]]
        ans = (suma, 1)
    else:
        sumarestante, cantidadRestante = solveSolvini(1, longitud, contador, memoria)
        total = probabilidades[posicionLetra[letra]] * cantidadRestante + sumarestante
        ans = (total, cantidadRestante)

    return ans


def main():
    linea = stdin.readline()
    casos = int(linea)
    c = 0

    while c < casos:
        palabra = stdin.readline().strip().lower()

        if palabra != "":
            sbc = SBC(palabra)
            n = len(palabra)
            total, cantidad = solve(palabra[0], n)
            promedio = total / cantidad

            if sbc >= promedio:
                print("above or equal")
            else:
                print("below")
            c += 1
main()