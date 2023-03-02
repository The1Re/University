def Square(x):
    return x*x

a,b,c,x = input("Enter a,b,c,x : ").split()
a,b,c,x = int(a),int(b),int(c),int(x)
result = a*Square(x)+b*x+c
print("The value of polynomial expression is :",result)