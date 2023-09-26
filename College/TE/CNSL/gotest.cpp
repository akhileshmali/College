#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

// Function to simulate Go-Back-N mode
void goBackN(int tf, int N) {
    int i = 1; // Initialize the frame number
    int tt = 0; // Initialize the total number of frames sent and resent
    srand(time(NULL)); // Seed the random number generator with the current time
    while (i <= tf) { // Loop until all frames have been sent
        int z = 0; // Initialize the number of frames acknowledged
        for (int k = i; k < i + N && k <= tf; k++) {
            cout << "Sending Frame " << k << "..." << endl; // Send the frame
            tt++; // Increment the total number of frames sent and resent
        }
        for (int k = i; k < i + N && k <= tf; k++) {
            int f = rand() % 2; // Generate a random number (0 or 1) to simulate the acknowledgment
            if (!f) {
                cout << "Acknowledgment for Frame " << k << "..." << endl; // Frame is acknowledged
                z++; // Increment the number of frames acknowledged
            }
            else {
                cout << "Timeout!! Frame Number : " << k << " Not Received" << endl; // Frame is not acknowledged
                cout << "Retransmitting Window..." << endl; // Retransmit the window
                break; // Break out of the inner loop
            }
        }
        cout << "\n"; // Print a new line for better readability
        i = i + z; // Update the frame number based on the number of frames acknowledged
    }
    cout << "Total number of frames which were sent and resent are : " << tt << endl; // Print the total number of frames sent and resent
}

//Selective Repeat Mode
int receiver(int tmp1) // define receiver function that takes an integer parameter tmp1
{
    int i;
    for(i = 0;i < 5;i++) // loop 5 times
        rand(); // generate a random number
        i = rand() % tmp1; // calculate i as the remainder of the random number divided by tmp1
        return i; // return i
}

int negack(int tmp1) // define negack function that takes an integer parameter tmp1
{
    int i;
    for(i = 0;i < 5;i++) // loop 5 times
        rand(); // generate a random number
        i = rand() % tmp1; // calculate i as the remainder of the random number divided by tmp1
        return i; // return i
}

void selectiveRepeat(int windowsize, int noofPacket) // define selectiveRepeat function that takes two integer parameters: windowsize and noofPacket
{
    int tmp1, tmp2, tmp3 = 0, tmp4 = 0, tmp5 = 0, i, morePacket = noofPacket; // declare and initialize variables
    
    for(int i = 0;i < 10;i++) // loop 10 times
        rand(); // generate a random number
    cout<<"Number of frames is: "<<noofPacket; // output the number of frames
    
    while(morePacket >= 0) // loop while morePacket is greater than or equal to 0
    {
        tmp1 = simulate(windowsize); // call simulate function and assign the result to tmp1
        windowsize -= tmp1; // subtract tmp1 from windowsize
        tmp4 += tmp1; // add tmp1 to tmp4
        
        if(tmp4 > noofPacket) // if tmp4 is greater than noofPacket
            tmp4 = noofPacket; // set tmp4 to noofPacket
            
        for(i = noofPacket - morePacket; i <= tmp4; i++) // loop from noofPacket - morePacket to tmp4
            cout<<"\nSending Frame "<<i; // output the sending frame
        
        tmp2 = receiver(tmp1); // call receiver function with tmp1 as parameter and assign the result to tmp2
        tmp3 += tmp2; // add tmp2 to tmp3
        
        if(tmp3 > noofPacket) // if tmp3 is greater than noofPacket
           tmp3 = noofPacket; // set tmp3 to noofPacket
           
        tmp2 = negack(tmp1); // call negack function with tmp1 as parameter and assign the result to tmp2
        tmp5 += tmp2; // add tmp2 to tmp5
        
        if(tmp5 != 0) // if tmp5 is not equal to 0
        {
           cout<<"\nNo acknowledgement for the frame "<<tmp5; // output no acknowledgement message
           cout<<"\nRetransmitting frame "<<tmp5; // output retransmitting frame message
        }
        morePacket -= tmp1; // subtract tmp1 from morePacket
        
        if(windowsize <= 0) // if windowsize is less than or equal to 0
           windowsize = 4; // set windowsize to 4
    }
}


int main() {
    int tf, N;
    cout << "Enter the Total number of frames : ";
    cin >> tf;
    cout << "Enter the Window Size : ";
    cin >> N;

    int choice;
    while (true) {
        cout << "Choose an option:\n";
        cout << "1. Go-Back-N Mode\n";
        cout << "2. Selective Repeat Mode\n";
        cout << "3. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Go-Back-N Mode:\n";
                goBackN(tf, N);
                break;
            case 2:
                cout << "Selective Repeat Mode:\n";
                selectiveRepeat(tf, N);
                break;
            case 3:
                exit(0);
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    }

    return 0;
}
