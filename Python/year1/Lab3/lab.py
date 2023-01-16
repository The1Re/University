def lab1():
    a,b = 5,3.1
    x,y = 7.0,4
    p,q = True,False 
    print(a-x<-1*y and b==3)
    
def lab2():
    import math
    x,y = map(int,input('Enter x and y : ').split())
    print(f'The values of x and y are {x} and {y}')
    z = math.sqrt(x**y+y**x)
    print(f'The value of z is {z:0.5f}')

def lab3():
    PI = 22/7
    r,h = map(float,input('Enter r and h : ').split())
    volume = 1/3*PI*r**2*h
    area = 2*PI*r*(h+r)
    print(f'Volume of the cone is {volume:n}')
    print(f'The surface area of the cylinder is {area:n}')

def lab4():
    n = int(input('Enter Number : '))
    print(n,'is positive ->',n>0)
    print(n,'is odd ->',n%2==1)
    print(n,'divisible by 5 ->',n%5==0)

def lab4_2():
    x,y = map(int,input('Enter 2 Number : ').split())
    print(x,'&',y,'are equal ->',x==y)
    print(x,'&',y,'in range [-5,5] ->',x in range(-5,6) and y in range(-5,6))
    print(x,'is 3 times',y,'->',x==3*y)
    print(x,'<= 10 or',y,'even ->',x<=10 or y%2==0)

def lab5():
    n1,n2 = input('Enter two integer : ').split()
    if n1 == n2 :print(1)
    if n1 != n2 :print(2)
    if n1 < n2 :print(3)
    if n1 >n2 :print(4)
    if n1 <= n2 :print(5)
    if n1 >= n2 :print(6)

a = 5.3
b = 3.2
x = 6
y = 5
print(x/a+b)