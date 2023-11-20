import complaint as comp
from tkinter import *

def run(flatno):
    def Submit():
        c=complaint.get()
        comp.insert(flatno,c)
        window.destroy()
    window=Tk()
    window.title("Lodge Complaints")

    Label(window,text='Enter the Complaint:').pack(padx=20,pady=20)
    complaint=Entry(window)
    complaint.pack()
    submit=Button(window,text='Submit',command=Submit).pack(padx=20,pady=20)

    window.mainloop()



if __name__ == '__main__':
    run()

