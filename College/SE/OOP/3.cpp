//Write a function template for selection sort that inputs, sorts and outputs an integer array and a float array.
#include <iostream>
using namespace std;

template <class sel>
void selectionSort(sel array[], sel size) {
	sel temp;
	for (int step = 0; step < size - 1; step++) {
    int min_idx = step;
    for (int i = step + 1; i < size; i++) {

      // To sort in descending order, change > to < in this line.
      // Select the minimum element in each loop.
      if (array[i] < array[min_idx])
        min_idx = i;
    }

    // put min at the correct position
    temp = array[step];
    array[step] = array[min_idx];
    array[min_idx] = temp;
  }

}
template <class sel>
void swap(sel *a, sel *b) {
  sel temp = *a;
  *a = *b;
  *b = temp; 
}

// function to print an array
template <class sel>
void printArray(sel array[], int size) {
  for (int i = 0; i < size; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
}
// driver code
int main() 
{
	int size;
	int array[10];
	int x;
	do
	{
		cout<<"Enter choice: 1. Integer Array 2. Float Array 3. Exit"<<endl;
		cin>>x;
		switch(x)
		{
			case 1:
				int size;
				int array[10];
				cout<<"Enter Number of elements in Array:";
				cin>>size;
				cout<<"Enter elements of array:"<<endl;
				for(int i = 0;i<size;i++)
				{
					cin>>array[i];
				}
				cout<<"Array before selection sorting is "<<endl;
				printArray<int>(array, size);
				selectionSort<int>(array, size);
				cout << "Sorted array in Ascending Order:\n";
				printArray(array, size);
				break;
			case 2:
				int size1;
				float array1[10];
				cout<<"Enter Number of elements in Float Array:";
				cin>>size1;
				cout<<"Enter elements of array:"<<endl;
				for(int i = 0;i<size1;i++)
				{
					cin>>array1[i];
				}
				cout<<"Array before selection sorting is "<<endl;
				printArray<float>(array1, size1);
				selectionSort<float>(array1, size1);
				cout << "Sorted array in Ascending Order:\n";
				printArray(array1, size1);
				break;
			case 3:
				break;
			default:
				cout<<"Invalid Choice";
		}
			if(x==3)
			{
				cout<<"See you soon.Keep Coding"<<endl;
				break;
			}
		}while(x!=3);
return 0;
}
