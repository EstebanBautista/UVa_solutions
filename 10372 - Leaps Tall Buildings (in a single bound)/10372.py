# Nombre: Esteban David Muñoz Bautista
# Codigo: 8982338

from sys import stdin
import math

eps = 1e-8
aceleracion = 9.8

def funcion(casos, alturaOri, distanciaOri, teta, velocidad):
    
    noChoca = True

    velocidad_En_X = velocidad * math.cos(teta)
    velocidad_En_Y = velocidad * math.sin(teta)
    
    distanciaNew = 0

    for i in range(casos):
        
        # Altura actual
        tiempo = distanciaNew/ velocidad_En_X
        alturaNew = (velocidad_En_Y*tiempo) - (0.5*aceleracion*(tiempo)**2)

        if alturaNew < (alturaOri[i]-eps):
            noChoca = False

        # La altura que le sigue a la actual
        tiempo = (distanciaNew + distanciaOri[i]) / velocidad_En_X
        alturaNew = (velocidad_En_Y*tiempo) - (0.5*aceleracion*(tiempo)**2)

        if alturaNew < (alturaOri[i]-eps):
            noChoca = False

        distanciaNew += distanciaOri[i]

    return noChoca


def bisection(limitA, limitB, distancia, altura, max): 
    left = limitA
    right = limitB

    while abs (right - left) > eps:

        mid = (left+right)/2
        velocidad = math.sqrt((max*aceleracion) / math.sin(2*mid))

        if funcion(len(distancia), altura, distancia, mid, velocidad) == False:
            left = mid
        else:
            right = mid

    mid = mid * 180 / math.pi
    ans = (mid, velocidad)
    return ans




def main():
    into = stdin.readline()
    while into != "":

        repe = int(into)
        lista_Distancias = []
        lista_Alturas = []
        distancia_Max = 0

        while repe > 0:
            into2 = stdin.readline().split()
            altura = float(into2[0])
            distancia = float(into2[1])
            distancia_Max += distancia 
            lista_Distancias.append(distancia)
            lista_Alturas.append(altura)
            repe -= 1
        
        par = bisection( 0, (math.pi / 2), lista_Distancias, lista_Alturas, distancia_Max)
        print(f'{par[0]:.2f} {par[1]:.2f}')
        
        into = stdin.readline()
    

main()    