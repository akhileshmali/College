import sqlite3

conn=sqlite3.connect('Tenant.db')

cur=conn.cursor()

def create(c):
    if(c=='Y'):
        cur.execute("create table Tenant (flatno integer primary key,name string, phoneNumber integer, password string)")
    conn.commit()

def insert(flatno,name,phoneNumber,password):
    cur.execute("insert into Tenant values(?,?,?,?)",(flatno,name,phoneNumber,password))
    conn.commit()

def deletebyid(tenant_flatno):
    cur.execute("delete from Tenant where flatno==(?)",(tenant_flatno,))
    conn.commit()

def display():
    l=[]
    cur.execute("select flatno,name,phoneNumber from Tenant")
    for i in cur:
        l.append(i)
    return l

def displaypassword(pflatno):
    l=[]
    cur.execute("select password from (select * from Tenant where flatno==(?))",(pflatno,))
    for i in cur:
        l.append(i)
    return l

def findbypassword(tenant_flatno,password):
    l=[]
    cur.execute("select * from Tenant where flatno==(?) and password==(?)",(tenant_flatno,password))
    for i in cur:
        l.append(i)
    return l

def findbyflatno(tenant_flatno):
    l=[]
    cur.execute("select flatno from Tenant where flatno==(?)",(tenant_flatno,))
    l.append(cur)
    return l

def drop():
    cur.execute("drop table Tenant")

if __name__ == '__main__':
    drop()


