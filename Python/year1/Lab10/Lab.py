def lab2():
    while True:
        s1,s2 = input().split()
        if s1=='0' or s2=='0':
            break
        if s1 == s2:print(1)
        if s1 != s2:print(2)
        if s1 <s2 :print(3)
        if s1 <= s2:print(4)
        if s1 > s2:print(5)
        if s1 >= s2:print(6)

def lab3():
    i = 1
    ans = ''
    while True:
        msg = input(f'word {i} : ')
        if msg == 'end':
            break
        ans += msg
    print(ans)

def lab4():
    msg = input('Enter sentence : ')
    print('String shown back : ',end='')
    if len(msg) > 20:
        print(msg[:20]+'...')
    else:
        print(msg)

def lab5():
    msg = input('Enter sentence : ')
    msg = msg.replace('happy','happy :)')
    msg = msg.replace('sad','sad :(')
    print(msg)

def lab6():
    msg = input('Enter sentence : ')
    print('Character count =',len(msg))
    print('Word count =',len(msg.split()))
