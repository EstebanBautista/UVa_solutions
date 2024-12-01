from sys import stdin

def main():
    _ = stdin.readline().strip()
    string = stdin.readline().strip()
    
    while string != "___________":
        ask = []
        
        for i in range(1, len(string) - 1 ) :
            if string[i] == 'o':
                ask.append('1')
            elif string[i] == ' ':
                ask.append('0')

        binario = "".join(ask)
        letra = chr(int(binario, 2))
        print(letra, end="") 
        string = stdin.readline().strip()

main()

