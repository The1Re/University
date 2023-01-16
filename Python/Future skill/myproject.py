import random
import string
import pyperclip as pc
from tkinter import *

FONT = ('ariel',10,'normal')

def window_main():

    def random_password():
        input1.config(state='normal')
        input1.delete(0,END)
        command_input()
        length = spin.get()
        dif = radio_value.get()

        if dif == 1:
            password = string.ascii_letters
        elif dif == 2:
            password = string.ascii_letters+string.digits
        elif dif == 3:
            password = string.ascii_letters+string.digits+string.punctuation
        else:
            input1.insert(0,'Error! Try again')
            input1.config(state='disabled')
            return

        ans = random.sample(password,length)
        input1.insert(0,''.join(ans))
        input1.config(state='disabled')

    def copy():
        cp = input_var.get()
        if cp == '':
            return
        check.config(text = f'Sussess! to copy : {cp}')
        pc.copy(cp)

    def command_input():
        check.config(text = '')

    root = Tk()
    root.geometry('600x150')
    root.title('Generate Password')

    #text Length
    Label(root,text = 'Lenth of the required password',font = FONT).place(x=20,y=15)    

    #Scale find length
    spin = IntVar()
    spin.set(8)
    Scale(root,variable=spin,from_=6,to=50,orient='horizontal',length=130).place(x=230,y=0)

    #radiobutton
    radio_value = IntVar()
    Radiobutton(root,text = 'low',variable=radio_value,value=1,font = FONT,command=command_input).place(x=380,y=15)       
    Radiobutton(root,text = 'medium',variable=radio_value,value=2,font = FONT,command=command_input).place(x=430,y=15)
    Radiobutton(root,text = 'high',variable=radio_value,value=3,font = FONT,command=command_input).place(x=510,y=15)

    #text genarate
    Label(root,text = 'Genarate password',font=FONT).place(x=20,y=50)          

    #show password genarate
    input_var = StringVar()
    input1 = Entry(textvariable=input_var,state='disabled',width=55)           
    input1.place(x=230,y=50)    

    #check success
    check = Label(root,text = '',font = ('ariel',8,'normal'))
    check.place(x=225,y=70)
    
    Button(root,text = 'Cancel',command = root.destroy,width=8).place(x=340,y=100)        #Cancel Button
    Button(root,text = 'Copy',command = copy,width=8).place(x=420,y=100)
    Button(root,text = 'Genarate',command = random_password,width=8).place(x=500,y=100)   #Genarate Button

    root.mainloop()

window_main()