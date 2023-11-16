#include<iostream>
#include<algorithm>
using namespace std;

void first(int block_size[], int b, int process_size[], int p,int result[],int resultprocess[])
{

	// Allocate the processes to the blocks using the First Fit algorithm (iterate over the processes array)
	for (int k = 0; k < p; k++) {
	  // Iterate over the blocks
	  for (int i = 0; i < b; i++) {
	    // If the process size is less than or equal to the block size and the block is not already allocated, then allocate the process to the block
	    if (process_size[k] <= block_size[i] && result[i] == 0) {
	      result[i] = process_size[k];
	      resultprocess[i] = k + 1;
	      break;
	    }
	  }
	}
	
	// Display the allocated blocks for the processes
	cout << "Allocated blocks for the processes: ";
	for (int i = 0; i < b; i++) {
	  cout << result[i] << " ";
	}
	cout << endl;
	
}

void printTable(int block_size[], int b, int result[],int resultprocess[]) {
  // Display a table of block number, size of block, allocated process number, and memory wastage
	
  cout << "Block Number | Size of Block | Allocated Process Number | Memory Wastage" << endl;
  cout << "-----------|----------------|-----------------------|----------------" << endl;
  for (int i = 0; i < b; i++) {
    int memoryWastage = block_size[i] - result[i];
    cout << i + 1 << " | " << block_size[i] << " | " << result[i] << " | " << memoryWastage << endl;
  }
}

void best(int block_size[], int b, int process_size[], int p)  
{  
  bool allocated[b] = {false};
  // Iterate over the processes
  for (int i = 0; i < p; i++) 
  {
	    // Find the minimum block size that can be assigned to the current process
	  int min_block_size = INT_MAX;
	  int min_block_index = -1;
	  for (int j = 0; j < b; j++) 
	  {
	    if (block_size[j] >= process_size[i] && !allocated[j]) 
		{
	  	    if (block_size[j] < min_block_size) 
			{
	          min_block_size = block_size[j];
	          min_block_index = j;
	        }
	    }
	  }
	
	    // If a small enough block is found, allocate the process to the block
	    if (min_block_index != -1) {
	      allocated[min_block_index] = true;
	      cout << "Process " << i + 1 << " is allocated to memory block " << min_block_index + 1 << endl;
	    } else {
	      cout << "Process " << i + 1 << " cannot be allocated" << endl;
	    }
	}


}  
  
void worst(int block_size[], int b, int process_size[], int p) {
  // Initialize all memory blocks as free
    bool allocated[b] = {false};

  // Iterate over the processes
  for (int i = 0; i < p; i++) {
    // Find the maximum block size that can be assigned to the current process
    int max_block_size = 0;
    int max_block_index = -1;
    for (int j = 0; j < b; j++) {
      if (block_size[j] >= process_size[i] && !allocated[j]) {
        if (block_size[j] > max_block_size) {
          max_block_size = block_size[j];
          max_block_index = j;
        }
      }
    }

    // If a large enough block is found, allocate the process to the block
    if (max_block_index != -1) {
      allocated[max_block_index] = true;
      cout << "Process " << i + 1 << " is allocated to memory block " << max_block_index + 1 << endl;
      
    } else {
      cout << "Process " << i + 1 << " cannot be allocated" << endl;
    }
  }

}

void next(int block_size[], int b, int process_size[], int p)
{
	bool allocated[b] = {false};
	// Start by picking each process and check if it can be assigned to the current block
    int current_block_index = 0;
    for (int i = 0; i < p; i++) 
    {
    	// If the current block size is smaller than the process size, keep checking the further blocks
	    while (current_block_index < b && block_size[current_block_index] < process_size[i]) 
		{
	      current_block_index++;
	    }
		// If a block is found that is large enough to fit the process, allocate the required memory and check for next process but from the block where we left not from starting
	    if (current_block_index < b && block_size[current_block_index] >= process_size[i]) 
		{
	      allocated[current_block_index] = true;
	      cout << "Process " << i + 1 << " is allocated to memory block " << current_block_index + 1 << endl;
	      current_block_index++;
	    } else 
		{
	      cout << "Process " << i + 1 << " cannot be allocated" << endl;
	    }
   }  
}

int main()
{
	
	// Declare variables
	int b; // Number of blocks
	int p; // Number of processes
	cout << "Enter number of blocks: ";
	cin >> b;
	
	cout << "Enter number of processes: ";
	cin >> p;
	
	int block_size[b]; // Array to store the sizes of the blocks
	int process_size[p]; // Array to store the sizes of the processes
	
	int result[b]; // Array to store the allocated blocks for the processes
	int resultprocess[b]; // Array to store the allocated process number for the blocks
	
	// Get the number of blocks and processes from the user
	
	// Get the sizes of the blocks from the user
	for (int i = 0; i < b; i++) {
	  cout << "Enter size of block " << i + 1 << ": ";
	  cin >> block_size[i];
	}
	
	// Get the sizes of the processes from the user
	for (int j = 0; j < p; j++) {
	  cout << "Enter size of process " << j + 1 << ": ";
	  cin >> process_size[j];
	}
	
	
	//first(block_size, b, process_size, p, result,resultprocess);
	//printTable(block_size, b, result,resultprocess);
	//best(block_size, b, process_size, p);
	//worst(block_size, b, process_size, p);
	//next(block_size, b, process_size, p);

	// Declare a variable to store the user's choice
	int choice;
	
	// Prompt the user to choose a function
	cout << "Enter the number of the function you want to call:" << endl;
	cout << "1. First fit" << endl;
	cout << "2. Best fit" << endl;
	cout << "3. Worst fit" << endl;
	cout << "4. Next fit" << endl;
	cin >> choice;
	
	// Switch on the user's choice and call the appropriate function
	switch (choice) {
	case 1:
	  first(block_size, b, process_size, p, result, resultprocess);
	  break;
	case 2:
	  best(block_size, b, process_size, p);
	  break;
	case 3:
	  worst(block_size, b, process_size, p);
	  break;
	case 4:
	  next(block_size, b, process_size, p);
	  break;
	default:
	  cout << "Invalid choice" << endl;
	}
	return 0;
}
