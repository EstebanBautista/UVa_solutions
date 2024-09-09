from sys import stdin

#se utilizo el enfoque de dos punteros, debido a que nos piden encontrar la suma de dos numero en un arreglo
def dos_punteros(books, money):
    left = 0
    right = len(books)-1
    ans = (0, 0)

    while left < right:
        sum = books[left] + books[right]

        if sum == money:
            ans = (books[left], books[right])
            left += 1
            right -= 1
        elif sum < money:
            left += 1
        else:
            right -= 1
    return ans

def main():
    amount = stdin.readline().strip()
    while amount != "":
        cantidad = int(amount)
        books = stdin.readline().split()
        booksT = []

        for i in range(len(books)):
            booksT.append(int(books[i]))

        booksT.sort()
        money = int(stdin.readline())

        ans = dos_punteros(booksT, money)

        print(f"Peter should buy books whose prices are {ans[0]} and {ans[1]}.")
        print("")

        ignore = stdin.readline()
        amount = stdin.readline().strip()

main()