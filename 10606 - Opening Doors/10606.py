# Nombre: Esteban David Muñoz Bautista
# Codigo: 8982338

from sys import stdin


def busquedaBuscona(numerin):
    left = 1
    right = numerin
    ans = 0  

    while left <= right:
        mid = ((left + right) // 2)
        cuadradoPerfecto = mid * mid #El cuadrado perfecto es basicamente el numero a la dos 

        if cuadradoPerfecto <= numerin:
            ans = cuadradoPerfecto
            left = mid + 1 #Para buscar un locker con un numero mas grande abierto
        else:
            right = mid - 1 #Como se pasa no pertenece al rango limite impuesto por numerin

    return ans


def main():
    entrada = int(stdin.readline())
    while entrada != 0:
        ans = busquedaBuscona(entrada)
        print(ans)
        
        entrada = int(stdin.readline())

main()