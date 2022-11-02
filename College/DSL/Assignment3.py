"""Write a Python program to compute following computation on matrix:
a) Addition of two matrices
b) Subtraction of two matrices
c) Multiplication of two matrices
d) Transpose of a matrix"""
r1=int(input("Enter number of rows of your matrix 1"))
c1=int(input("Enter number of columns of your matrix 1"))
r2=int(input("Enter number of rows of your matrix 2"))
c2=int(input("Enter number of columns of your matrix 2"))
def inp(r,c):
    n=[]
    for i in range(0,r):
        m=[]
        for j in range(0,c):
            ele1=int(input(f"Enter element of ({i},{j})"))
            m.append(ele1)
        n.append(m)
    return n
def show(q,r,c):
    for i in range(r):
        for j in range(c):
            print(q[i][j],end=" ")
        print()
a=inp(r1,c1)
b=inp(r2,c2)
show(a,r1,c1)
show(b,r2,c2)
p=[]
def add(x,y):
    p=[]
    for i in range(len(a)):
        ar=[]
        for j in range(len(a[0])):
             ar.append(a[i][j]+b[i][j])
        p.append(ar)
    return p         
add(a,b)
show(p,r1,c1)
            
