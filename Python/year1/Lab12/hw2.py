# def addtime(ds,hs,ms,da,ha,ma):
#     m = ms+ma
#     h = hs+ha
#     d = ds+da
#     if m >= 60:
#         m = m%60
#         h += 1
#     if h >= 23:
#         h = h%24
#         d += 1
#     return d,h,m

def addtime(start,add):
    minute = start[2]+add[2]
    hour = start[1]+add[1]
    day = start[0]+add[0]
    if minute >= 60:
        minute = minute%60
        hour += 1
    if hour >= 24 :
        hour = hour%24
        day += 1
    return day,hour,minute
    
start = input("Enter starting time (d,h,m) : ").split()
add = input("Enter adding time (d,h,m) : ").split()
for i in range(3):
    start[i] = int(start[i])
    add[i] = int(add[i])

d,h,m = addtime(start,add)
print("A new time :",d,h,m)
