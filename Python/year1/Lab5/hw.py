n = int(input('Enter amount of money : '))
if n//50!=0 :print('Coupon A -->',n//50)
n%=50
if n//20!=0 :print('Coupon B -->',n//20)
n%=20
if n//10!=0 :print('Coupon C -->',n//10)
n%=10
if n//5!=0 :print('Coupon D -->',n//5)
n%=5
if n!=0 :print('Coupon E -->',n)

