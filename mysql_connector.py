import mysql.connector
from tkinter import *
conn=mysql.connector.connect(host="localhost",user="root",database="Connector")

c=conn.cursor()

def create():
    c.execute("Create table student (name varchar(30),rollno integer, marks integer);")
    conn.commit()

def insert():
    n=int(input("Enter number of students:"))
    for i in range(n):
        name=input("Enter name:")
        roll=int(input("Enter Rollno:"))
        marks=int(input("Enter Marks:"))
        c.execute(f"Insert into student (name,rollno,marks)  values(%s,%s,%s);",(name,roll,marks))
        conn.commit()

def display():
    c.execute("Select * from student;")
    for i in c:
        print(i)

if __name__ == '__main__':
    # create()
    insert()
    display()



