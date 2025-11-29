# Nombre: Esteban David Muñoz Bautista
# Código: 898233

from sys import stdin

encontrado  = False

def solve(numeros, valor, cont):
    global encontrado 
    ans = False
    if(cont == 0):
        if(valor == 23):
            encontrado  = True
            ans = True
    else:
        sumita = sum(numeros)
        if not ((valor * sumita <23 and valor + sumita < 23) or (valor - sumita > 23 and valor * sumita >23)): 
            i = 0
            while(i < 5 and not encontrado ):
                if(numeros[i] != 0 and not encontrado ):
                    num = numeros[i]
                    numeros[i] = 0
                    j = 0
                    while(j < 3 and not encontrado ):
                        if(j == 0 and not encontrado ):
                            ans = solve(numeros, valor + num, cont - 1)
                        elif(j == 1 and not encontrado ):
                            ans = solve(numeros, valor - num, cont - 1)
                        elif(j == 2 and not encontrado ):
                            ans = solve(numeros, valor * num, cont - 1)
                        j += 1
                    numeros[i] = num
                i += 1
    return ans


def main():
    global encontrado 
    numeros = list(map(int, stdin.readline().split()))
    while(sum(numeros) > 0):
        encontrado  = False        
        i = 0
        while(i < 5 and not encontrado ):
            num = numeros[i]
            numeros[i] = 0
            solve(numeros, num, 4)
            numeros[i] = num
            i += 1
        
        if(encontrado ):
            print("Possible")
        else:
            print("Impossible")
        
        numeros = list(map(int, stdin.readline().split()))

main()