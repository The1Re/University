def Fact(n):
    result = 1
    for i in range(n,0,-1):
        result *= i
    return result

while True:
    print('======= Menu =======')
    print('p or P : Permutation')
    print('c or C : Combination')
    print('q or Q : Exit program')
    select = input('Select choice : ')
    if select in ['q','Q']:
        break
    n = int(input('  Enter n : '))
    r = int(input('  Enter r : '))
    if select in ['p','P']:
        result = Fact(n)/Fact(n-r)
        print(f'  P({n},{r}) = {result:n}')
    else:
        result = Fact(n)/Fact(n-r)/Fact(r)
        print(f'  C({n},{r}) = {result:n}')