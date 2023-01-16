import math
def hw1():
    x,y,z = [float(x) for x in input("Enter x,y and z : ").split()]
    print("The average value is",(x+y+z)/3)

def hw1_1():
    lst = [float(x) for x in input("Enter x,y and z : ").split()]
    print("The average value is {:.2n}".format(sum(lst)/len(lst)))
    print(lst)

def hw2():
    PI = 3.14159
    x = int(input("Enter x : "))
    print("Cos(",x,") = {:.6f}".format(math.cos(x*PI/180)))

def hw3():
    x,y = input("Enter x and y :").split()
    print("{}-{}^{} = {}".format(x,y,x,int(x)-int(y)**int(x)))

def hw4():
    PI = 3.1416
    area = int(input("Enter area : "))
    print("r = {:.6n}".format(math.sqrt(area/PI)))

def test():
    x = 14
    print("{:b}".format(x))

hw1_1()