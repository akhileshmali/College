from tkinter import *
import viewtenants as vt
import viewcomplaints as vc
import lodgecomplaints as lc
def run(flatno):
    def viewrecord():
        vt.run()

    def viewcomplaint():
        vc.run()

    def lodgecomplaint():
        lc.run(flatno)

    choices=Tk()
    Label(choices,text="Choose your option",font=(30,30),padx=20,pady=20).pack(padx=50,pady=50)
    viewtenants=Button(choices,text='View Tenants',font=(15,15),command=viewrecord,padx=20,pady=20).pack(side=LEFT,padx=100,pady=100)
    viewcomplaints=Button(choices,text='View Complaints',font=(15,15),command=viewcomplaint,padx=20,pady=20).pack(side=LEFT,padx=100,pady=100)
    logdecomplaints=Button(choices,text='Lodge Complaints',font=(15,15),command=lodgecomplaint,padx=20,pady=20).pack(side=LEFT,padx=100,pady=100)

    choices.mainloop()


if __name__ == '__main__':
    run()