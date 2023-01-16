def lab2():
    x = float(input('Enter x : '))
    if x<0:
        y=6
    elif x>=0 and x<15:
        y=6*x+10
    elif x>=15 and x<35:
        y=3*x**2-5
    else:
        y=x**3+5
    print(f'x = {x:n} make y = {y:n}')

def lab3():
    m,n = map(int,input('Enter m and n : ').split())
    if n<= 0:
        print('Error : n is negative or zero')
    else:
        if m%n:
            print(f'{m} is not multiple of {n}')
        else:
            print(f'{m} is multiple of {n}')

def lab4():
    x,y = map(int,input('Enter coordinates (x,y) : ').split())
    if x>0 and y>0:ans = 'Q1'
    elif x<0 and y>0:ans = 'Q2'
    elif x<0 and y<0:ans = 'Q3'
    elif x>0 and y<0:ans = 'Q4'
    elif x==0 and y!=0:ans = 'y-intercept'
    elif x!=0 and y==0:ans = 'x-intercept'
    else:ans = 'origin'
    print(f'coordinates({x},{y}) = {ans}')

def lab5():
    name = input('Name of the resident : ')
    status = input('Status (S,M) : ')
    salary = int(input('Salary (euros) : '))
    area = int(input('residence area (mxm) : '))
    rent = int(input('residence rent (euros) : '))
    if area < 30:
        if salary<900 :net=0.5*rent
        elif salary>1500 :net=0.2*rent
        else :net=0.4*rent
    else:
        if salary<900 :net=0.4*rent
        elif salary>1500 :net=0.3*rent
        else :net=0.4*rent
    if status == 'M':net*=1.2
    print(f'The net residence rent of {name} is {rent-net:n} euros')

lab4()