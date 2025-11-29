# Nombre: Esteban David Muñoz Bautista
# Codigo: 8982338



from sys import stdin


def solution(plays_a, plays_b, probabilities):

    answer = []
    hope = None
    player_a_points = 0
    
    probabilities = [x * 0.01 for x in probabilities]

    #Esto calcula el resultado de un juego normal

    for i in range(len(plays_a)):

        if(plays_a[i] == plays_b[i]):
            player_a_points += 0
        elif(plays_a[i] == "R" and plays_b[i] == "P") or (plays_a[i] == "P" and plays_b[i] == "S") or (plays_a[i] == "S" and plays_b[i] == "R"):
            player_a_points -= 1
        else:
            player_a_points += 1
        
    
    answer.append(player_a_points) #La cantidad de puntos totales del juego completo

    #Ahora para calcular usando la estrategia de wsls

    results = [] #Esto guarda las esperanzas/probabilidades de éxito en cada ronda
    aux_rock = None  
    aux_scissor = None
    aux_paper = None
    future_probabilities = []
    aux_probability = probabilities
    next_probability = []

    for i in range(len(plays_b)): #Ciclo que recorre todas las rondas


        #Calcula la esperanza matematica (representa la "ganancia" promedio)
        #Usa la definición estandar de esperanza matematica
        #En este caso la "ganancia" de la definición de esperanza matematica es -1 o 1 o 0(porque gana punto o pierde un punto o no gana nada)
        if(plays_b[i] == "R"): # Si b saca roca tiene que sacar la esperanza de lo que le gana a la roca (papel) y restarle la esperanza con lo que pierde (Tijera) 
            hope = aux_probability[1] - aux_probability[2]
        elif(plays_b[i] == "P"): #Mismo procedimiento
            hope = -aux_probability[0] + aux_probability[2]
        else: #Mismo procedimiento
            hope = aux_probability[0] - aux_probability[1]
        
        results.append(hope) #Este valor se va a usar para obtener la esperanza final




        """
        Esta multiplicación se realiza porque: Por la regla de la probabilidad compuesta (esta dice: ¿Cuál es la probabilidad de que yo pueda escoger algo dado que escogi algo anteriormente?)
        la probabilidad de una secuencia de acciones, porque la probabilidad futura va a depender de los resultados en la jugada anterior. 
        """
        if(plays_b[i] == "R"): 
            next_probability = [number * aux_probability[0] for number in probabilities]
        elif(plays_b[i] == "P"):
            next_probability = [number * aux_probability[1] for number in probabilities]
                
        elif(plays_b[i] == "S"):
            next_probability = [number * aux_probability[2] for number in probabilities]

        """
        
        Para esta parte vamos a revisar los casos en que se gana o pierde (dependiendo de lo que el rival b elija)
        Si yo saqué la jugada que gana o la que pierde contra la del rival, esa probabilidad se pasa tal cual a la siguiente ronda (porque sigo teniendo la misma probabilidad que antes como si esa hubiera sido mi primera elección por lo tanto
        estas probabilidades de elección no se ven afectadas). 
        
        """
            
        if(plays_b[i] == "R"): #Aquí en este caso si yo gano, escogiendo papel, entonces la probabilidad que tenía anteriormente se la paso a si hubiera elegido tijeras (porque mi elección es la que le gana a mi jugada anterior)
            aux_paper = aux_probability[2]
            aux_scissor = aux_probability[1]
        elif(plays_b[i] == "P"): #Se aplica el mismo proceso, en caso de que se saque Tijera, entonces la probabilidad de que hubiera elegido el vencedor de la tijera es ahora hacia la roca (sucede lo mismo en caso de perder pero invirtiendolo)
            aux_rock = aux_probability[2]
            aux_scissor = aux_probability[0]
        elif(plays_b[i] == "S"): #mismo proceso que las dos anteriores, tanto para victoria como derrota
            aux_paper = aux_probability[0]
            aux_rock = aux_probability[1]
        
        #Aquí sumo las nuevas probabilidades obtenidas con las probabilidades anteriores para poder calcular las probabilidades de la n-esima ronda
        #Aquí las probabilidades futuras cargan con los resultados anteriores, por ese motivo hay una suma y se dejan los resultados del empate 
        if(plays_b[i] == "R"):
            future_probabilities = [next_probability[0], next_probability[1] + aux_paper, next_probability[2] + aux_scissor] 
            aux_probability = future_probabilities
        elif(plays_b[i] == "P"):
            future_probabilities = [next_probability[0]+ aux_rock, next_probability[1], next_probability[2] + aux_scissor]
            aux_probability = future_probabilities
        else:
            future_probabilities = [next_probability[0]+ aux_rock, next_probability[1] + aux_paper, next_probability[2]]
            aux_probability = future_probabilities

    answer.append(sum(results)) #Suma de todas las esperanzas
    if(answer[1] > answer[0]):
        answer.append("Y")
    else:
        answer.append("N")
    

    return answer

         
def main():

    total_cases = int(input())

    while total_cases > 0:

        plays_a = stdin.readline().strip()
        plays_b = stdin.readline().strip()
        probabilities = list(map(float, stdin.readline().split()))
        answer = solution(plays_a, plays_b, probabilities)
        print(f"{answer[0]} {answer[1]:.4f} {answer[2]}")

        total_cases -= 1
        


main()


