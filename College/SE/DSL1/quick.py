"""
Write a Python program to store first year percentage of 
students in array. Write function for sorting array of floating-point numbers in ascending order 
using quick sort and display top five scores
"""
array=[]
n=int(input("Enter the number of students "))
for i in range (n):
    ele=float(input("Enter the percentage marks "))
    array.append(ele)
def partition(array, low, high):
	pivot = array[high]
	i = low - 1
	for j in range(low, high):
		if array[j] <= pivot:
			i = i + 1
			(array[i], array[j]) = (array[j], array[i])
	(array[i + 1], array[high]) = (array[high], array[i + 1])
	return i + 1
def quick_sort(array, low, high):
	if low < high:
		pi = partition(array, low, high)
		quick_sort(array, low, pi - 1)
		quick_sort(array, pi + 1, high)
	return array
def switch():
    while True:
        ch=int(input("Enter choice \n1. Quick Sort \n2. Top 5 \n3. Exit \n"))
        if ch==1:
            print("The unsorted list is: ", array)  
            print("The l after sorting in Ascending Order by selection sort is:",quick_sort(array, 0, len(array) - 1) )
        elif ch==2:
            quick_sort(array, 0, len(array) - 1) 
            x=array[-5:]
            x.reverse()
            print(x)
        elif ch==3:
            break
        else:
            print("Invalid choice ")
switch()
