#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

struct Process {
    string id;
    int arrivalTime;
    int burstTime;
    int remainingTime;
    int completionTime;
    int waitingTime;
    int turnaroundTime;
};

string intToString(int num) {
    stringstream ss;
    ss << num;
    return ss.str();
}

int main() {
    int i, n, time, remain, temps = 0, timeQuantum;
    int wt = 0, tat = 0;

    cout << "Enter the total number of processes: ";
    cin >> n;

    remain = n;
    vector<Process> processes(n);

    cout << "Enter the Arrival time, Burst time for All the processes" << endl;
    for (i = 0; i < n; i++) {
        cout << "Arrival time for process " << i + 1 << endl;
        cin >> processes[i].arrivalTime;
        cout << "Burst time for process " << i + 1 << endl;
        cin >> processes[i].burstTime;
        processes[i].remainingTime = processes[i].burstTime;
        processes[i].id = "P";
        processes[i].id += intToString(i + 1);
    }

    cout << "Enter the value of time QUANTUM: ";
    cin >> timeQuantum;

    cout << "\n\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\tExecution Periods\n\n";
    vector<string> ganttChart;
    for (time = 0, i = 0; remain != 0;) {
        if (processes[i].remainingTime <= timeQuantum && processes[i].remainingTime > 0) {
            time += processes[i].remainingTime;
            processes[i].remainingTime = 0;
            temps = 1;
            ganttChart.push_back(processes[i].id + " (" + intToString(processes[i].remainingTime) + ")");
        } else if (processes[i].remainingTime > 0) {
            processes[i].remainingTime -= timeQuantum;
            time += timeQuantum;
            ganttChart.push_back(processes[i].id + " (" + intToString(timeQuantum) + ")");
        }

        if (processes[i].remainingTime == 0 && temps == 1) {
            remain--;
            cout << processes[i].id << "\t\t" << processes[i].burstTime << "\t\t" << time - processes[i].arrivalTime - processes[i].burstTime << "\t\t" << time - processes[i].arrivalTime << "\t\t";
            int start = time - processes[i].burstTime;
            int end = time;
            cout << "[" << start << "," << end << "]" << endl;
            wt += time - processes[i].arrivalTime - processes[i].burstTime;
            tat += time - processes[i].arrivalTime;
            temps = 0;
        }

        if (i == n - 1) {
            i = 0;
        } else if (processes[i + 1].arrivalTime <= time) {
            i++;
        } else {
            i = 0;
        }
    }

    cout << "\nGantt Chart:\n";
    for (i = 0; i < ganttChart.size(); i++) {
        cout << ganttChart[i] << " ";
    }
    cout << endl;

    cout << "Average waiting time: " << wt * 1.0 / n << endl;
    cout << "Average turnaround time: " << tat * 1.0 / n << endl;

    return 0;
}
