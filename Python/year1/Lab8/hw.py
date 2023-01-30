binary = list(map(int,input('Enter 8 binary number (0,1) : ').split()))
dec = 0
for i in range(8):
    dec += binary[i]*2**(7-i)
print('The decimal number is',dec)