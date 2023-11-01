import signup
import choices
from tkinter import *

def run():
    def check():
        global id
        fn=flatno.get()
        p=password.get()
        ans=signup.findbypassword(fn,p)
        print(ans)
        if(len(ans)==0):
            alert=Tk()
            alert.title('Alert')
            Label(alert,text='Alet').pack()
        else:
            choices.run(fn)
    login=Tk()
    login.title("Login")

    frame1=LabelFrame(login).pack()

    Label(login,text='Enter the Flat Number').pack(padx=20,pady=20)
    flatno=Entry(login)
    flatno.pack()
    Label(login,text='Enter the Password').pack(padx=20,pady=20)
    password=Entry(login)
    password.pack()
    sumbit=Button(login,text='Sumbit',command=check).pack()

    login.mainloop()


if __name__ == '__main__':
    run()