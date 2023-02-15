def hw1():
    data = input('Input : ').split('_')
    print('First Name :',data[0])
    print('Middle Name :',data[1])
    print('Last Name :',data[2])

def hw2():
    msg = input('Enter string : ')
    print('string : ',end='')
    for i in range(len(msg)):
        if msg[i] == ' ':
            print('-',end='')
        else:
            print(msg[i],end='')

def hw3():
    a = input('Enter string A : ')
    b = input('Enter string B : ')
    pos = a.find(b)
    if pos != -1:
        print(b+' is contained in '+a+' at position',pos,'to',pos+len(b))
    else:
        print(b+' is not contained in '+a)

hw1()