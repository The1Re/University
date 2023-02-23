def hw1():
    n = int(input('N : '))
    for i in range(n):
        for j in range(2*i+1):
            print(end='*')
        print()

def hw2():
    n = int(input('Please enter n : '))
    for i in range(2,6):
        j = 1
        while j*i<=n:
            print(i*j,end=' ')
            j+=1
        print()

def hw2_2():
    n = int(input('Please enter n : '))
    for i in range(2,6):
        for j in range(i,n+1,i):
            print(j,end=' ')
        print()

hw2_2()