try:
    n = ''.join(input().split('-'))
except:
    n = input()

last = int(n[-1])
x = 0
for i in range(1,13):
    x += (14-i)*int(n[i-1])
x = x%11
lastn = 1-x if x<= 1 else 11-x
if last == lastn:
    print('Maybe right')
else:
    print('Wrong NO.')