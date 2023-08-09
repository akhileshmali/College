"""Write a Python program to store roll numbers of student array who attended training program in sorted order. 
Write function for searching whether particular student attended training program or not, using Binary search 
and Fibonacci search"""
def get():
	l=[]
	n=int(input("Enter no of students in class SE who attended training program: "))
	for i in range(n):
		k=int(input("Enter roll no "))
		l.append(k)
	return l

def disp(l):
	for i in l:
		print(i,end=" ")

def fibonacci_search(l, target):
    size = len(l)
    start = -1
    f0 = 0
    f1 = 1
    f2 = 1
    while(f2 < size):
        f0 = f1
        f1 = f2
        f2 = f1 + f0
    while(f2 > 1):
        index = min(start + f0, size - 1)
        if l[index] < target:
            f2 = f1
            f1 = f0
            f0 = f2 - f1
            start = index
        elif l[index] > target:
            f2 = f0
            f1 = f1 - f0
            f0 = f2 - f1
        else:
            return index
    if (f1) and (l[size - 1] == target):
        print("Roll number",target,"was present")
	
    else:
      print("Roll number ",target,"was absent")

def binary_search(l,target):
    start=0
    end=len(l)-1
    while(start<=end):
        mid=int((start+end)/2)
        if(l[mid]==target):
            print("Roll number ",target,"was present")
            break
        elif(target>l[mid]):
            start=mid+1
        elif(target<l[mid]):
            end=mid-1
    else:
        print("Roll number ",target,"was absent")

print("Enter roll number of students present : ")
l=get()
print("List of roll number of students present : ")
disp(l)
while 1:
	ch=int(input("\nEnter choice \n1. Fibonacci Search \n2. Binary Search \n3. Exit\n"))
	if ch==1:
		target=int(input("Enter roll no to search whether particular student attended training program or not "))
		fibonacci_search(l, target)
	if ch==2:
		target=int(input("Enter roll no to search whether particular student attended training program or not "))
		binary_search(l, target)
	if ch==3:
		break

	
