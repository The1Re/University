def lab1():
    while True:
        n = int(input('Enter n : '))
        if n<0 :
            break
        print(n%10)
    print('End of program')

def lab2():
    print('Calculation of x*x/(2*x-1)+10')
    print('------------------------------')
    i=0
    while i<=4.5:
        if i == 0.5 :
            ans = 'Can\'t divide by 0'
        else:
            ans = f'{i*i/(2*i-1)+10:0.2f}'
            ans = f'{float(ans):n}'
        print(f'x = {i}\t\tf({i}) = {ans}')
        i+=0.5
    print('------------------------------')
            
def lab3():
    n = int(input('Enter N : '))
    for i in range(1,n+1):
        if n%i==0 :
            print(i,end = ' ')

def lab4():
    n = int(input('Enter number : '))
    i = 2
    while(n!=1):
        if n%i == 0:
            print(i,end = '')
            n/=i
            if n!= 1:
                print(end = ' * ')
        else:
            i+=1

def lab4_2():
    n = int(input('Enter number : '))
    i = 2
    ans = []
    while(n!=1):
        if n%i == 0:
            ans.append(str(i))
            n/=i
        else:
            i+=1
    print(' * '.join(ans))

def lab4():
    i = 0
    ans = 0
    while True:
        n = int(input('Enter binary number : '))
        if n != 0 and n != 1 : break
        ans = (ans+n)*2
        i+=1
    print('The result is',ans//2)

def lab5():
    while True:
        type_customer = input('Type of customer (s for student,o for other,q for quit) : ')
        if type_customer == 'q' : break
        elif type_customer != 's' and type_customer != 'o': continue

        tk_type = int(input('Ticket type (1 for single trip, 2 for one-day trips,3 for one-month trips) : '))
        if tk_type <1 or tk_type>3: continue

        value = int(input('How many tickets? '))

        if type_customer == 's':
            if tk_type == 1 :
                value *= 10
            elif tk_type == 2 :
                value *= 25
            else:
                value *= 500
        else :
            if tk_type == 1 :
                value *= 10
            elif tk_type == 2 :
                value *= 30
            else:
                value *= 600
        print('Fare(baths) :',value)
        print()
    print('Thank you for using our service.')

lab5()