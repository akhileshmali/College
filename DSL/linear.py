"""Write a Python program to store roll numbers of student array who attended training program in sorted order. 
Write function for searching whether particular student attended training program or not, using Linear search 
and sentinel search"""
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

def linear_search(l, key):
    for i in range(len(l)):
        if(l[i] == key):
            print("Roll number",key,"was present")
            break
    else:
            print("Roll number",key,"was absent")
        

def sentinel(l, key):
    size = len(l)
    l.append(key)
    i = 0
    while(l[i] != key):
        i += 1
    if(i == size):
        print("Roll number",key,"was absent")
    else:
        print("Roll number",key,"was present")

print("Enter roll number of students present : ")
l=get()
print("List of roll number of students present : ")
disp(l)
while 1:
	ch=int(input("\nEnter choice \n1. Linear Search \n2. Sentinel Search \n3. Exit\n"))
	if ch==1:
		key=int(input("Enter roll no to search whether particular student attended training program or not "))
		linear_search(l, key)
	if ch==2:
		key=int(input("Enter roll no to search whether particular student attended training program or not "))
		sentinel(l, key)
	if ch==3:
		break

	
