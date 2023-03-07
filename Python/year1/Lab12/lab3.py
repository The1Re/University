import os
filename = input('Enter a filename : ')
if os.path.exists(filename):
    file = open(filename,'r')

    line,word,char = 0,0,0
    for textline in file:
        line += 1
        word += len(textline.split())
        char += len(textline)

    print('Lines :',line)
    print('Words :',word)
    print('character(with spaces):',char-(line-1))
    file.close()
else:
    print('Cannot open file to read!')