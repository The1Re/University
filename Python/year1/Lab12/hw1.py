def printRectangle(w,l):
    for i in range(w):
        print("*"*l)

def printTriangle(h):
    for i in range(h):
        print("*"*(i+1))

def printIsoTriangle(h):
    for i in range(h):
        print(" "*(h-i-1)+"*"*(2*i+1))

while True:
    print("0 : Exit")
    print("1 : Draw a rectangle")
    print("2 : Draw a right triangle")
    print("3 : Draw an isosceles triangle")
    option = input("Please select your option : ")
    if option == "0":
        break
    elif option == "1":
        width = int(input("Enter width : "))
        length = int(input("Enter length : "))
        printRectangle(width,length)
    else :
        height = int(input("Enter height : "))
        if option == "2":
            printTriangle(height)
        else :
            printIsoTriangle(height)
    