def lab5():
    n = 0
    while n<=0 :
        n = int(input('Enter n : '))
    print(f'Even numbe 0-{n} is ',end = '')
    for i in range(2,n+1,2):
        print(i,end = ' ')

def lab6():
    a = int(input('Enter a : '))
    i = 2
    while a%i :
        i+=1
    print('Value of b is',i)

def lab7():
    while True:
        print('(1) Compute A+B')
        print('(2) Compute A-B')
        print('(3) Exit')
        choice = int(input('Enter choice : '))
        if choice == 3:break 
        x,y = map(int,input('Enter 2 numbers : ').split())
        if choice == 1:
            print(f'{x}+{y} = {x+y}')
        else:
            print(f'{x}-{y} = {x-y}')
    print('Thank you for using our program')

lab7()