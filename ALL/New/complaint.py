from dis import dis
import sqlite3

conn=sqlite3.connect('Tenant.db')

cur=conn.cursor()

def create(c):
    if(c=='Y'):
        cur.execute("create table Complaint (flatno integer ,complaint string,foreign key (flatno) references Tenant(flatno))")

def insert(id,complaint):
    cur.execute("insert into Complaint values(?,?)",(id,complaint))
    conn.commit()

def deletebyid(tenant_id):
    cur.execute("delete from Complaint where flatno=(?)",tenant_id)

def display():
    l=[]
    cur.execute("select * from Complaint")
    for i in cur:
        l.append(i)
    return l

def drop():
    cur.execute("drop table Complaint")

if __name__ == '__main__':
    drop()




