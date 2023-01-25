while True:
    a,b = input().split()
    a = int(a)
    b = int(b)
    if b==0:
        break
    elif (a>0 and b>0) or (a<0 and b<0):
        print(a*b)
    