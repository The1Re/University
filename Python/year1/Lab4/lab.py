def lab2():
    n = float(input('Enter number : '))
    if n>0:print('Postive')
    elif n<0:print('Negative')
    else:print('Zero')

def lab3():
    time = float(input('Time in minutes : '))
    minutes = int(time)
    second = round(time%1*100)
    if second < 60:
        print(f'{time:n} minutes = {minutes*60+second} seconds')
    else:
        print('Invalid input!')

def lab4():
    print('Please enter 3 different numbers : ')
    string = ' number is '
    n1 = int(input('1st'+string))
    n2 = int(input('2nd'+string))
    n3 = int(input('3rd'+string))
    if n1>n2 and n1>n3:
        rank = '1st'
    elif n2>n1 and n2>n3:
        rank = '2nd'
    else:
        rank = '3rd'
    print(rank+string+'the maximum number')

def lab5():
    a,b,c = map(int,input('Number of product A,B,C : ').split())
    total = a*3000+b*750+c*1500
    print(f'Total amount = {total} baht')
    discount = 0
    if total >= 10000:
        discount = total*0.12
        print(f'12% discount = {discount} baht')
    print(f'Total payment = {total-discount} baht')

lab5()