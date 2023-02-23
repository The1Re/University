def lab1():
    i=1
    while(i<=3):
        j=1
        while(j<=5):
            print(i,end='')
            j = j+1
        print()
        i = i+1

def lab1_2():
    for i in range(1,4):
        for j in range(5):
            print(i,end='')
        print()

def lab2():
    i=1
    while(i<=4):
        j=i
        while(j>=1):
            print(j,end='')
            j = j-1
        print()
        i = i+1

def lab3():
    n = int(input('N = '))
    for i in range(1,n+1):
        for j in range(n-i):
            print(end=' ')
        for j in range(i,0,-1):
            print(j,end='')
        print()

def lab4():
    n = int(input('N = '))
    for i in range(1,n+1):
        for j in range(n-i):
            print(end=' ')
        for j in range(2*i-1):
            print(end='*')
        print()

def lab5():
    while True:
        x,y = input('Please enter two numbers : ').split()
        x,y = int(x),int(y)
        if 0 in [x,y] or 1 in [x,y] :
            print('No need for calculation. Bye...')
            break
        elif x<0 or y<0:
            print('Invalid input!')
        else:
            checkcoprime = True
            for i in range(2,min(x,y)):
                if x%i==0 and y%i==0 :
                    checkcoprime = False
            if checkcoprime :
                print(f'{x} and {y} are coprime') 
            else: 
                print(f'{x} and {y} are not coprime')  

def lab6():
    box = [6,3,8,5,4]
    for i in range(len(box)):
        print('['+str(i+1)+']',end='')
        for j in range(box[i]):
            print(end='*')
        print()

def lab7():
    import math
    for c in range(1,101):
        for a in range(1,c):
            for b in range(1,c):
                if math.sqrt(a**2+b**2) == c:
                    print(f'a = {a},\tb = {b},\tc = {c}')
                    break

def lab7_2():
    from math import sqrt
    for c in range(1,101):
        for a in range(1,c):
            b = sqrt(c**2-a**2)
            if b == int(b):
                print(f'a = {a},\tb = {int(b)},\tc = {c}')
                print(f'a = {int(b)},\tb = {a},\tc = {c}')
                break
lab6()