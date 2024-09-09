from sys import stdin

#La complejidad es contasnte ya que sabemos que siempre son 3 empleados, es decir la lista employees siempre sera 3
def main():
    cases = int(stdin.readline())

    for i in range(cases):

        employees = list(map(int, stdin.readline().split()))
        employees.sort()
        print(f"Case {i+1}: {employees[1]}")

main()