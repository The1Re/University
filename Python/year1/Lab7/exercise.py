a = 100
b = 1
c = 5
while(a>c):
    b+=1
    if a%b!=0 :
        continue
    a/=b
    c+=5
    print('a =',a,'b =',b,'c =',c)