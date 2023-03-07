import os
    
def writetext(file,n):
    file.write('02204101 student list\n')
    file.write('\t\tStudent ID\t\tName\n')
    for i in range(1,n+1):
        file.write(str(i)+'\n')

choice = 'y'
while choice!='n':
    filename = input('Enter filename : ')
    n = int(input('Enter number of student : '))
    if os.path.exists(filename):
        file = open(filename,'w')
        writetext(file,n)
        file = open(filename,'r')
        print(file.read())
        file.close()
    else:
        print(filename,'doesn\'t exists')
        choice = input(f'Do you want to create {filename} (y/n) : ')
        if choice == 'y':
            file = open(filename,'x')
            writetext(file,n)
            file = open(filename,'r')
            print(file.read())
            file.close()
print('Exit')