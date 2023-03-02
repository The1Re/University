def Promotion(promotion,minutes):
    if promotion == 'Happy1':
        pay,time = 199,200
        if minutes-time > 0:
            pay += 3*(minutes-time)
    else:
        pay,time = 299,400
        if minutes-time > 0:
            pay += 5*(minutes-time)
    return pay

select = input('Your promotion : ')
minutes = int(input('Total mintues : '))
pay = Promotion(select,minutes)
print('You have to pay',pay,'baht')