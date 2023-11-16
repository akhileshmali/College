import signup
from tkinter import *
import signup

def run():
    window=Tk()
    window.title("View Tenants")
    cur=signup.display()
    for i,j in enumerate(cur):
        (flatno,name,Phone)=j
        label=Label(window,text=f"Flat no:{flatno} \n Name:{name} \n Phone Number:{Phone}")
        label.grid(row=i+1,column=1)
    window.mainloop()



if __name__ == '__main__':
    run()

