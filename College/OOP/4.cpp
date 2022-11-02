//Write a function template for selection sort that inputs, sorts and outputs an integer array and a float array.
#include <iostream>
using namespace std;


// function to print an array
template <class sel>
void printArray(sel array[], int size) {
  for (int i = 0; i < size; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
}

template <class sel>
void acceptArray(int size) {
	int array[10];
	cout<<"Enter elements of array:"<<endl;
	for(int i = 0;i<size;i++)
	{
		cin>>array[i];
	}
	cout<<"Array before selection sorting is "<<endl;
}

// driver code
int main() 
{
	int x;
	int size;
	int array[10];
	do
	{
		cout<<"Enter choice: 1. Integer Array 2. Float Array 3. Exit"<<endl;
		cin>>x;
		switch(x)
		{
			case 1:
				cout<<"Enter Number of elements in Array:";
				cin>>size;
				acceptArray<int>(size);
				printArray<int>(array, size);
				break;
			case 2:
				break;
			default:
				cout<<"Invalid Choice";
		}
			if(x==2)
			{
				cout<<"See you soon.Keep Coding"<<endl;
				break;
			}
		}while(x!=2);
	
	
return 0;
}
