import Signupgui
import logingui
from tkinter import *

def signup():
    Signupgui.run()

def login():
    logingui.run()

window=Tk()
window.title('Welcome to appilcation')

frame=LabelFrame(window).pack()

description="Welcome to the Application.\n You can sign up and add your complaints to it."

label=Label(frame,text='Application',font=(30,30)).pack(padx=100,pady=100)
Label(frame,text=description,font=(15,15)).pack()

button1=Button(window,text='SignUp',font=(20,20),command=signup).pack(side=LEFT,padx=100,pady=100)
button2=Button(window,text='Login',font=(20,20),command=login).pack(side=LEFT,padx=100,pady=100)

window.mainloop()