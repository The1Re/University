import math
def distance(x1,y1,x2,y2):
    return math.sqrt((x1-x2)**2+(y1-y2)**2)

x1,y1 = input('(x1,y1) = ').split()
x2,y2 = input('(x2,y2) = ').split()
result = distance(int(x1),int(y1),int(x2),int(y2))
print(f'd = {result:.3f}')
