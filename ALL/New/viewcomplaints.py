import complaint
from tkinter import *

def run():
    window=Tk()
    window.title("View Complaints")
    cur=complaint.display()
    for i,j in enumerate(cur):
        (flatno,compl)=j
        label=Label(window,text=f"flat number:{flatno} \n Complaint :{compl}")
        label.grid(row=i+1,column=1)
        print(i,j)
    window.mainloop()



if __name__ == '__main__':
    run()

