x = 1
y = 1
z = 0
for i in range(1,10):
    z = x+y
    x = y+1
    if x%3 != 0:
        y = 2*x
    print(f'{i} : \t{x}\t\t{y}\t\t{z}')