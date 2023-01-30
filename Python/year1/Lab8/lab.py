def lab2():
    elem=[]
    n = int(input("Enter N: "))
    for i in range(n):
        elem.append(input())
    for i in range(n-1,-1,-1):
        print(elem[i],end = " ")

def lab3():
    num = []
    i = 0
    while i<=7:
        num.append(int(input()))
        if num[i] <= 0 :
            break
        i+=1
    sum1 = sum(num)
    print('Sum ( {}) ='.format(num[j] for j in range(i+1)),sum1)
    print('Avg =',sum1/i)
    
def lab6():
    data = []
    data = input('Please enter characters : ').split()
    revdata = ''.join(reversed(data))
    data = ''.join(data)

    print('Number of characters is',len(data))
    check = '' if data == revdata else 'not '
    print(f'{data} is {check}a palindome')

lab3()