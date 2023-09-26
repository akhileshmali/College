#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void goBackN(int tf, int N) {
    int i = 1;
    int tt = 0;
    srand(time(NULL));
    while (i <= tf) {
        int z = 0;
        for (int k = i; k < i + N && k <= tf; k++) {
            cout << "Sending Frame " << k << "..." << endl;
            tt++;
        }
        for (int k = i; k < i + N && k <= tf; k++) {
            int f = rand() % 2;
            if (!f) {
                cout << "Acknowledgment for Frame " << k << "..." << endl;
                z++;
            }
            else {
                cout << "Timeout!! Frame Number : " << k << " Not Received" << endl;
                cout << "Retransmitting Window..." << endl;
                break;
            }
        }
        cout << "\n";
        i = i + z;
    }
    cout << "Total number of frames which were sent and resent are : " << tt << endl;
}



int main() {
    int tf, N;
    cout << "Enter the total number of frames: ";
    cin >> tf;
    cout << "Enter the window size: ";
    cin >> N;
    cout << "Go-Back-N Mode Simulation:\n";
    goBackN(tf, N);
    return 0;
}
