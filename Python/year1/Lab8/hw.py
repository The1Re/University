def hw1():
    x = [1,2,3,4,5,6]
    for i in range(int(len(x)/2)):
        t = x[i]
        x[i] = x[len(x)-i-1]
        x[len(x)-i-1] = t
    print(x)

def hw2():
    binary = list(map(int,input('Enter 8 binary number (0,1) : ').split()))
    dec = 0
    for i in range(8):
        dec += binary[i]*2**(7-i)
    print('The decimal number is',dec)

def hw2_2():
    binary = []
    binary = input('Input 8 binary numbers (0 or 1) : ').split()
    for i in range(len(binary)):
        binary[i] = int(binary[i])
    dec = 0
    for i in range(len(binary)):
        dec += binary[i]*2**(len(binary)-i-1)
    print('The decimal number is',dec)

hw2_2()