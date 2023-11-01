import signup as s
from tkinter import *
import random as rd
import string


def run():
    def insertinto():
        password=''.join(rd.choice(string.ascii_letters) for i in range(5))
        fn=flatno.get()
        n=name.get()
        p=phone.get()
        flist=s.findbyflatno(fn)
        print("list:",flist)
        if fn in flist:
            alert=Tk()
            alert.title('Alert')
            Label(alert,text="Already exists",font=(30,30)).pack(padx=100,pady=100)
            alert.mainloop()
        else:
            s.insert(int(fn),n,int(p),password)
            Password=Tk()
            Password.title("Password")
            Label(Password,text="Your Password is: ",font=(25,25)).pack(padx=100,pady=10)
            Label(Password,text=password,font=(30,30)).pack(padx=100,pady=100)
            Password.mainloop()
        signup.destroy()


    signup=Tk()
    signup.title("Signup")

    Label(signup,text='Enter the Flat Number').pack(padx=20,pady=20)
    flatno=Entry(signup)
    flatno.pack()
    Label(signup,text='Enter the Name').pack(padx=20,pady=20)
    name=Entry(signup)
    name.pack()
    Label(signup,text='Enter the Phone Number').pack(padx=20,pady=20)
    phone=Entry(signup)
    phone.pack()

    sumbit=Button(signup,text='Sumbit',command=insertinto).pack()

    signup.mainloop()


if __name__ == '__main__':
    run()
