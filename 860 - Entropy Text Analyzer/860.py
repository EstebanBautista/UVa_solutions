# Esteban David Muñoz Bautista

import math


caracteres = {',', '.', ':', ';', '!', '?', '"', '(', ')', ' '}
palabras = {}

final_case = "****END_OF_TEXT****"
final_text = "****END_OF_INPUT****"


line = input()
totalPalabras = 0

while line != final_text:

    if line == final_case:
        entropia = 0

        for valor in palabras.values():
            pSubI = valor
            entropia += (pSubI * (math.log10(totalPalabras)-math.log10(pSubI)))
        if totalPalabras == 0:
            print(f"{totalPalabras} -nan -nan")
            

        else:
            entropia = entropia/totalPalabras
            entropiaMax = math.log10(totalPalabras)
            entropiaRelativa = (entropia / entropiaMax) * 100
            print(f"{totalPalabras} {entropia:.1f} {round(entropiaRelativa)}")
        
        totalPalabras = 0
        palabras.clear()

    else:
        i = 0
        formador_palabra = ""
        while i < len(line):
            if line[i] in caracteres:
                if formador_palabra:
                    minusPalabra = formador_palabra.lower()
                    if minusPalabra in palabras:
                        palabras[minusPalabra] += 1
                    else:
                        palabras[minusPalabra] = 1
                    
                    formador_palabra = ""
                    totalPalabras += 1
            else:
                formador_palabra += line[i]
            i += 1
        
        if formador_palabra:
            minusPalabra = formador_palabra.lower()
            if minusPalabra in palabras:
                palabras[minusPalabra] += 1
            else:
                palabras[minusPalabra] = 1

            totalPalabras += 1        

    line = input()