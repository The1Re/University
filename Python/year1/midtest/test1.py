n = int(input('Enter n : '))
while n<=0:
    n = int(input('Enter n : '))

print('Odd number 0-'+str(n)+' is ',end='')

for i in range(1,n+1,2):
    print(i,end=' ')