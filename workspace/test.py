n = 1
while (n!=3):
    print ("(1) Compute A + B ")
    print("(2) Compute A - B ")
    print("Exit")
    n = int(input("Enter choice :"))
    if (n==2):
        x,y = map(int,input("Enter 2 numbers : ").split())
        z = x-y
        print(x,"-",y,"=",z)
    elif(n==1):
        x,y = map(int,input("Enter 2 numbers : ").split())
        z = x+y
        print(x,"+",y,"=",z)
    