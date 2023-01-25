def hw2():
    i = 1
    min = int(input(f'Enter number{i}: '))
    while True:
        i += 1
        n = int(input(f'Enter number{i}: '))
        if n<=0 :
            break
        elif n<min :
            min = n
    print('Minimum number is',min)

def hw3():
    money = float(input('Enter principle : '))
    rate = float(input('Enter interest rate : '))
    year = int(input('Enter number of year : '))
    print('Year\t\tAmount of deposit')
    for i in range(1,year+1):
        print(f'{i}\t\t{money*(1+rate)**i:0.1f}')

hw3()