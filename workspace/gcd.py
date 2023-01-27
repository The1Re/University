from tkinter import *

def gcd(a,b):
    return gcd(b%a,a) if a!=0 else b

def Calculate_gcd(a,b):
    anstextgcd.configure(text=f'GCD = {gcd(a,b):n}')

def Calculate_lcm(a,b):
    lcm = lambda a,b : (a*b)/gcd(a,b)
    anstextlcm.configure(text=f'LCM = {lcm(a,b):n}')

def Calculate():
    a,b = inp1.get(),inp2.get()
    a,b = int(a),int(b)
    Calculate_gcd(a,b)
    Calculate_lcm(a,b)

def reset():
    inp1.delete(0,END)
    inp2.delete(0,END)
    anstextgcd.configure(text='')
    anstextlcm.configure(text='')

root = Tk()
root.title('GCD Calculate')
root.geometry('300x150')

img = PhotoImage(file="C:\\Users\\User\\Downloads\\check.png")
root.iconphoto(False,img)

label1 = Label(root,text='Input number :',font=('Ariel',15,'bold'))
label1.place(x=20,y=10)

anstextgcd = Label(root,text='',font=('Ariel',10,'bold'))
anstextgcd.place(x=180,y=50)

anstextlcm = Label(root,text='',font=('Ariel',10,'bold'))
anstextlcm.place(x=180,y=80)

a = StringVar()
inp1 = Entry(root,textvariable=a)
inp1.place(x=35,y=50)

b = StringVar()
inp2 = Entry(root,textvariable=b)
inp2.place(x=35,y=80)

btn = Button(root,text='Calculate',command=Calculate)
btn.place(x=200,y=110)

reset = Button(root,text='Reset',command=reset)
reset.place(x=150,y=110)

root.mainloop()
