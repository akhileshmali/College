"""
Write a Python program to store first year percentage 
of students in l. Write function for sorting l of floating point numbers in ascending 
order using
a)Selection Sort
b)Bubble sort and display top five scores.
""" 
l=[]
n=int(input("Enter the number of students "))
for i in range (n):
    ele=float(input("Enter the percentage marks "))
    l.append(ele)
def selection_sort(l,n):  
    for i in range(n-1):  
        minIndex = i  
        for j in range(i+1, n):  
            if l[j]<l[minIndex]:  
                minIndex = j  
        l[i], l[minIndex] = l[minIndex], l[i]  
    return l 
def bubble_sort(l,n): 
    for i in range(0,len(l)-1):  
        for j in range(len(l)-1):  
            if(l[j]>l[j+1]):
                l[j],l[j+1]=l[j+1],l[j] 
    return l  
def switch():
    while True:
        ch=int(input("Enter choice \n1. Selection Sort \n2. Bubble Sort \n3. Top 5 \n4. Exit \n"))
        if ch==1:
            print("The unsorted list is: ", l)  
            print("The l after sorting in Ascending Order by selection sort is:", selection_sort(l,n))
        elif ch==2:
            print("The unsorted list is: ", l)  
            print("The l after sorting in Ascending Order by bubble sort is:", bubble_sort(l,n))  
        elif ch==3:
            selection_sort(l, n)
            x=l[-5:]
            x.reverse()
            print(x)
        elif ch==4:
            break
        else:
            print("Invalid choice ")
switch()
