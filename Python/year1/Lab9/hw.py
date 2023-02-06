name_score = {}
n = int(input('Please Enter Number of student : '))
for i in range(n):
    name,score = input('Please Enter Name & Score : ').split()
    name_score[name] = int(score)

max = 0
for name,score in name_score.items():
    if score > max :
        max = score
        key = name

print('Top 1 of this class is : ',key,'with score =',max)
name_score.pop(key)

for name,score in name_score.items():
    print(f'Name: {name} score= {score}')
