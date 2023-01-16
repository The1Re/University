from tkinter import *

titles = 'Area Calculator'
fonts = ('arial',10,'bold')

def window_main():
    root = Tk()
    root.geometry('300x180')
    root.title(titles)

    def area_calculator():
        width = input1.get()
        height = input2.get()
        return width*height
    
    def backtomain():
        cal.destroy()
        window_main()

    def window_sum_area():
        root.destroy()
        global cal
        cal = Tk()
        cal.geometry('300x90')
        cal.title(titles)

        Label(cal,text='Area of rectangle is :',font = fonts).place(x=20,y=10)
        Label(cal,text=str(area_calculator()),font = fonts).place(x=20,y=30)

        Button(cal,text = 'Retry',font = fonts,width = 10,command=backtomain).place(x=110,y=50)

    Label(root,text='Enter width',font = fonts).place(x=20,y=10)
    input1 = IntVar()
    Entry(root, textvariable=input1,font = fonts,width=35).place(x=23,y=34)

    Label(root,text='Enter height',font = fonts).place(x=20,y=60)
    input2 = IntVar()
    Entry(root, textvariable=input2,font = fonts,width=35).place(x=23,y=84)

    Button(root,text = 'OK',font = fonts,width=8,command = window_sum_area).place(x=200,y=120)
    Button(root,text = 'Cancel',font = fonts,width=8,command = root.destroy).place(x=110,y=120)

    root.mainloop()

window_main()