# Nombre: Esteban David Muñoz Bautista
# Codigo: 8982338

from sys import stdin

def solveSolvini(dividendo, divisor):
    #limite inferior
    leftA = 0
    leftB = 1
    #limite superior
    rightA = 1
    rightB = 0

    flag = False

    while flag == False:
        midA = leftA + rightA
        midB = leftB + rightB

        if dividendo == midA and divisor == midB:
            flag = True

        #si mi objetivo es mayor a mi mid ajusto mi limite inferior por que no me interesa ver los resultados de la izquierda
        elif dividendo * midB > divisor * midA:
            leftA = midA
            leftB = midB
            print("R", end="")
        #si mi objetivo es mayor a mi mid ajusto mi limite superior por que no me interesa ver los resultados de la derecha
        else:
            rightA = midA
            rightB = midB
            print("L", end="")
            

def main():
    casos = stdin.readline()
    while casos != "":
        numeros = casos.split()
        
        solveSolvini(int(numeros[0]), int(numeros[1]))
        
              
        casos = stdin.readline()
        if casos != "":
            print()
    
    return 0

main()