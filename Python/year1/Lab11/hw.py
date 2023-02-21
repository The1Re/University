def hw1():
    n = int(input('N : '))
    for i in range(n):
        print('*'*(2*i+1))

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
        j=i
        while j<=n:
            print(j,end=' ')
            j+=i
        print()
hw2_2()