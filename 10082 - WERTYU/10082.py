# Esteban David Muñoz Bautista

from sys import stdin

mapping = {
    'W': 'Q', 'E': 'W', 'R': 'E', 'T': 'R', 'Y': 'T', 'U': 'Y', 'I': 'U', 'O': 'I', 'P': 'O', 
    'S': 'A', 'D': 'S', 'F': 'D', 'G': 'F', 'H': 'G', 'J': 'H', 'K': 'J', 'L': 'K', ';': 'L', 
    'X': 'Z', 'C': 'X', 'V': 'C', 'B': 'V', 'N': 'B', 'M': 'N', ',': 'M', '.': ',', '/': '.',
    '2': '1', '3': '2', '4': '3', '5': '4', '6': '5', '7': '6', '8': '7', '9': '8', '0': '9',
    '[': 'P', ']': '[', '\\': ']', '\'': ';', '=': '-', '-': '0', '1': '`'
}

def main():
    word = list(stdin.readline())
    while word :  
        for i in word:
            if i in mapping:
                print(mapping[i], end="")
            else:
                print(i, end="")
        word = list(stdin.readline())
        
main()
