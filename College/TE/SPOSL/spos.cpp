#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

struct Process {
    int pid;
    int arrivalTime;
    int burstTime;
    int remainingTime;
};

bool compareArrivalTime(Process p1, Process p2) {
    return p1.arrivalTime < p2.arrivalTime;
}

bool compareBurstTime(Process p1, Process p2) {
    return p1.remainingTime < p2.remainingTime;
}

int main() {
    int p, i, j, sum = 0, index;
    float awt = 0, atat = 0;

    cout << "\nEnter The Total Number of Processes: ";
    cin >> p;

    Process *proc = new Process[p];
    int *wt = new int[p];
    int *gc = new int[1000];
    int *tat = new int[p];

    cout << "\nEnter Arrival Time and Burst Time of Processes:\n";

    for (i = 0; i < p; i++) {
        proc[i].pid = i + 1;
        cin >> proc[i].arrivalTime >> proc[i].burstTime;
        proc[i].remainingTime = proc[i].burstTime;
    }

    sort(proc, proc + p, compareArrivalTime);

    cout << "\n========================================================\n";
    cout << "\t\tShortest Job First (Preemptive) Gantt Chart";
    cout << "\n========================================================\n";

    int currentTime = 0;
    int completedProcesses = 0;

    while (completedProcesses < p) {
        index = -1;
        int minRemainingTime = 1000;

        for (i = 0; i < p; i++) {
            if (proc[i].arrivalTime <= currentTime && proc[i].remainingTime < minRemainingTime && proc[i].remainingTime > 0) {
                minRemainingTime = proc[i].remainingTime;
                index = i;
            }
        }

        if (index == -1) {
            gc[currentTime] = 0;
            currentTime++;
            continue;
        }

        gc[currentTime] = proc[index].pid;
        proc[index].remainingTime--;
        currentTime++;

        if (proc[index].remainingTime == 0) {
            completedProcesses++;
            tat[index] = currentTime - proc[index].arrivalTime;
            wt[index] = tat[index] - proc[index].burstTime;
        }
    }

    cout << "\n--------------------------------------------------------\n";

    cout << setw(4) << "Time | ";

    for (j = 0; j < currentTime; j++) {
        if (gc[j] == 0) {
            cout << "  |  ";
        } else {
            cout << "P" << gc[j] << " | ";
        }
    }

    cout << endl;

    for (i = 0; i < p; i++) {
        awt += wt[i];
        atat += tat[i];
    }

    awt /= p;
    atat /= p;

    cout << "\n--------------------------------------------------------";
    cout << "\nProcess\t\tArrival Time\tBurst Time\tWaiting Time\tTurn Around Time";
    cout << "\n--------------------------------------------------------\n";

    for (i = 0; i < p; i++) {
        cout << "P[" << proc[i].pid << "]\t\t" << proc[i].arrivalTime << "\t\t" << proc[i].burstTime << "\t\t" << wt[i] << "\t\t" << tat[i] << endl;
    }

    cout << "\n\nAverage Waiting Time: " << awt;
    cout << "\nAverage Turn Around Time: " << atat << endl;

    return 0;
}
