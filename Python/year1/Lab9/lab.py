def lab1():
    D1 = {0:'zero', 1:'one', 2:'two', 3:'three', 4:'four', 5:'five', 6:'six', 7:'seven', 8:'eight', 9:'nine'}
    D2 = {2:'twenty', 3:'thirty'}

    num = 0
    while num<20 or num>39 :
        num = int(input('Number 20-39 : '))

    x = num//10
    y = num%10

    print('Input Number in English is :',D2[x],end='-')
    print(D1[y])

def lab2():
    credit = [4,3,3,3,1]
    grade = ['B','B','C','B','A']
    gp = {'A':4, 'B':3, 'C':2, 'D':1, 'F':0}

    sum_score = 0
    sum_credit = 0

    for i in range(5):
        sum_score += credit[i]*gp[grade[i]]
        sum_credit += credit[i]
    print(f'Tonkla GPA = {sum_score/sum_credit:.2f}')

def lab3():
    credit = [4,3,3,3,1]
    gp = {'A':4, 'B':3, 'C':2, 'D':1, 'F':0,'B+':3.5 ,'C+':2.5, 'D+':1.5}
    grade = []

    for i in range(5):
        grade.append(input('Enter grade : '))
    
    sum_score = 0
    sum_credit = 0

    for i in range(5):
        sum_score += credit[i]*gp[grade[i]]
        sum_credit += credit[i]
    print(f'GPA = {sum_score/sum_credit:.2f}')

def lab4():
    data = {}
    sum = 0
    for i in range(3):
        name,score = input('Please Enter Name & Score : ').split()
        data[name] = int(score)
    
    for name,score in data.items():
        print('Score of',name,'is',score)
        sum += score
    
    print('AVG =',sum/3)

def lab5():
    Brand = {'Toyota':'red', 'Audi':'black', 'Honda':'blue', 'Porsche':'black'}

    i = 1
    for brand,color in Brand.items():
        print(f'Car # {i} Brand: {brand} Color: {color}')
        i+=1

    print()
    remove_brand = input('Enter Brand to remove from Dict : ')
    if remove_brand in Brand.keys():
        print()
        Brand.pop(remove_brand)
        i = 1
        for brand,color in Brand.items():
            print(f'Car # {i} Brand: {brand} Color: {color}')
            i+=1
    else:
        print(remove_brand,'does not exist')

def lab6():
    Brand = {'Toyota':'red', 'Audi':'black', 'Honda':'blue', 'Porsche':'black'}
    input_brand = input('Please Enter Brand : ')
    input_color = input('Please Enter color : ')
    
    Brand[input_brand] = input_color

    i = 1
    for brand,color in Brand.items():
        print(f'Car # {i} Brand: {brand} Color: {color}')
        i+=1

lab6()