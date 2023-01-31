def lab1():
    a = []
    for i in range(10):
        a.append(input())
    print(a[0],end = '')
    for i in range(1,len(a)):
        print(',',a[i],end = '')

def lab1_2():
    a = []
    while len(a)!=10:
        a.append(input())
    print(a[0],end = '')
    i = 1
    while i<len(a):
        print(',',a[i],end = '')
        i+=1

def lab2():
    elem=[]
    n = int(input("Enter N: "))
    for i in range(n):
        elem.append(input())
    for i in range(n-1,-1,-1):
        print(elem[i],end = " ")

def lab3():
    num = []
    for i in range(7):
        num.append(int(input()))
        if num[i] <= 0:
            num.pop(i)
            break
    print('Sum( ',end='')
    for i in range(len(num)):
        print(num[i],end=' ')
    print(') =',sum(num))
    print(f'Avg = {sum(num)/len(num):n}')

def lab4():
    n = int(input('Number of list : '))
    A,B = [],[]
    print(f'Enter {n} number of A : ')
    for i in range(n):
        A.append(int(input()))
    print(f'Enter {n} number of B : ')
    for i in range(n):
        B.append(int(input()))
    print('List A+B = ',end='')
    for i in range(n):
        print(A[i]+B[i],end=' ')

def lab5():
    credit = [4,3,3,3,1]
    grade = ['B','B','C','B','A']
    sum_score = 0
    for i in range(5):
        if grade[i] == 'A':
            grade[i] = 4
        elif grade[i] == 'B':
            grade[i] = 3
        elif grade[i] == 'C':
            grade[i] = 2
        elif grade[i] == 'D':
            grade[i] = 1
        else:
            grade[i] = 0
        sum_score += credit[i]*grade[i]
    print('Tonkla GPA = {:.2f}'.format(sum_score/sum(credit)))


def lab6():
    data = []
    data = input('Please enter characters : ').split()
    revdata = ''.join(reversed(data))
    data = ''.join(data)

    print('Number of characters is',len(data))
    check = '' if data == revdata else 'not '
    print(f'{data} is {check}a palindome')

def lab6_2():
    data = []
    data = input('Please enter characters : ').split()
    print('Number of characters is',len(data))
    revdata = []
    for i in range(len(data)-1,-1,-1):
        revdata.append(data[i])
    strdata = ''.join(data)
    if data == revdata:
        print(f'{strdata} is a palindrome.')
    else:
        print(f'{strdata} is not a palindrome.')

def lab6_3():
    data = []
    data = input('Please enter characters : ').split()
    print('Number of characters is',len(data))
    revdata = []
    for i in range(len(data)-1,-1,-1):
        revdata.append(data[i])
    ans = ' not ' if data != revdata else ' '
    strdata = ''
    for i in range(len(data)):
        strdata += data[i]
    print(f'{strdata} is{ans}a palindrome.')
lab6_3()
