"""Write a Python program to store marks scored in subject “Fundamental of Data 
Structure” by N students in the class. Write functions to compute following:
a) The average score of class 
b) Highest score and lowest score of class 
c) Count of students who were absent for the test
d) Display mark with highest frequency"""

n=int(input("Enter total number of students in the class : "))
marks=[]
present=[]
absent=[]
print("Enter marks of students present and enter -1 for absent students")
def store():
	for i in range(0,n):
		print("Enter marks of roll no ",i+1)
		ele1=int(input())
		if ele1==-1:
			absent.append(ele1)
		else:
			present.append(ele1)
def display():
	print("Total number of students in the class : ",n)
	print("Marks of present students is : ",present)		
	print("Total no of absent students is : ",len(absent))	
store()
s=0
def ag():
	s=0
	for i in present:
		s=s+i
	avg=s/len(present)
	print("Average score of present students is : ",avg)
def highest():
	high=present[0]
	for i in present:
		if i>high:
			high=i
	print("Highest score of the class is : ",high)

def lowest():
	low=present[0]
	for i in present:
		if i<low:
			low=i
	print("Lowest score of the class is : ",low)

def mcount():
		n = []                  
		for x in present:
			count = 0
			for i in range(len(present)):
				if x == present[i]:
					count+=1
			n.append(count)
			a = max(n)      
		for i in range(len(n)):
			if n[i] == a:
				print("Marks with highest frequency are : ",present[i])
				return(present[i],a)  
		print(a)
		return a                 

while 1:
	a=int(input("Enter choice :\n1.Average score of present students\n2.Highest score of the class\n3.Lowest score of the class\n4.Total no of absent students\n5.Marks with highest frequency\n6. All\n7. Exit\n"))
	if a==1:
		ag()	
	elif a==2:
		highest()
	elif a==3:
		lowest()
	elif a==4:
		display()
	elif a==5:
		mcount()
	elif a==6:
		display()
		ag()	
		highest()
		lowest()
		mcount()
	else :
		print("Invalid Input")


	



	


