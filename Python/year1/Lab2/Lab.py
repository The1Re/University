def lab2_3():
    base,height = [int(float(x)) for x in input("Enter base & height : ").split()]
    print("Area = {:n}".format(0.5*base*height))

def lab2_3_1():
    base,high = input("Enter base & high : ").split()
    area = 1/2*int(float(base))*int(float(high))
    print("Area = {:n}".format(area))

def lab2_3_2():
    base,height = [int(float(x)) for x in input("Enter base & height : ").split()]
    area = 0.5*base*height
    if area%1 == 0:
        print("Area =",int(area))
    else:
        print("Area =",area)

def lab5():
    name = input("Enter first name : ")
    score = [int(x) for x in input("Enter 5-scores : ").split()]
    print("Student",name+"'s average score : {:n}".format(sum(score)/len(score)))

