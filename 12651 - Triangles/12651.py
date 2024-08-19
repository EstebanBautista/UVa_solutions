# Nombre: Esteban David Muñoz Bautista
# Codigo: 8982338
# La complejidad del problema es O(n) esto debido a que no hay bucles anidados
# tambien se puede observar que n es la cantidad de puntos en el circulo

from sys import stdin

def main():
    point = stdin.readline() 
    while point != "":

        large = set()
        repe = 0
        val = 0
        nums = stdin.readline().split()

        #Creacion del conjunto
        for i in nums:
            if i != " ":
                val += int(i)
                large.add(val)

        operation = val/3
        hay = False
        
        # Bucle para verificacion de los tres lados del triangulo
        for l in large: 
            if (l + operation) in large:    
                if (l + operation * 2) in large:
                    hay = True
            if hay:
                repe += 1
                hay = False
        
        print(repe)
        point = stdin.readline() 

main()