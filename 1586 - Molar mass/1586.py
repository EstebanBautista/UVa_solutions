from sys import stdin

def main():
    cases = int(stdin.readline())
    quimica = {"C" : 12.01, "H" : 1.008, "O" : 16.00, "N" : 14.01 }

    for _ in range(cases):
        elementS = stdin.readline().strip()
        valor = 0.0
        
        

        for i in range(len(elementS)):
            num = 1
            if i+1 < len(elementS):
                if not elementS[i+1] in quimica:
                    if  i+2 < len(elementS) and not elementS[i+2] in quimica :
                        num = (int (elementS[i+1]) * 10) + int (elementS[i+2])
                    else:
                        num = int (elementS[i+1])

            if elementS[i] in quimica:
                elem = quimica[elementS[i]]
                valor += (elem * num)
            
        print(f"{valor:.3f}")



main()