n = int(input('Enter n : '))
for i in range(n):
    num = int(input(f'Enter number{i+1}: ',end='\t'))
    if num%3==0 :
        print('Divisble by 3')