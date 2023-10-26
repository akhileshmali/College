#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

// Process structure
struct Process {
    int pid; // Process ID
    int burst_time; // Burst time
    int arrival_time; // Arrival time
    int priority; // Priority
    int remaining_time; // Remaining time
    int waiting_time; // Waiting time
    int turnaround_time; // Turnaround time
    int completion_time; // Completion time
};

// Function to implement FCFS scheduling algorithm
void fcfs(vector<Process>& processes) {
    int n = processes.size();
    int current_time = 0;
    for (int i = 0; i < n; i++) {
        if (current_time < processes[i].arrival_time) {
            current_time = processes[i].arrival_time;
        }
        processes[i].waiting_time = current_time - processes[i].arrival_time;
        processes[i].completion_time = current_time + processes[i].burst_time;
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        current_time = processes[i].completion_time;
    }
}

// Function to implement SJF Preemptive scheduling algorithm
void sjf_preemptive(vector<Process>& processes) {
    int n = processes.size();
    int current_time = 0;
    int completed = 0;
    while (completed < n) {
        int min_burst_time = INT_MAX;
        int min_index = -1;
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= current_time && processes[i].remaining_time < min_burst_time && processes[i].remaining_time > 0) {
                min_burst_time = processes[i].remaining_time;
                min_index = i;
            }
        }
        if (min_index == -1) {
            current_time++;
        } else {
            processes[min_index].remaining_time--;
            current_time++;
            if (processes[min_index].remaining_time == 0) {
                completed++;
                processes[min_index].completion_time = current_time;
                processes[min_index].turnaround_time = processes[min_index].completion_time - processes[min_index].arrival_time;
                processes[min_index].waiting_time = processes[min_index].turnaround_time - processes[min_index].burst_time;
            }
        }
    }
}

// Function to implement Priority Non-Preemptive scheduling algorithm
void priority_non_preemptive(vector<Process>& processes) {
    int n = processes.size();
    int current_time = 0;
    int completed = 0;
    while (completed < n) {
        int max_priority = INT_MIN;
        int max_index = -1;
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= current_time && processes[i].priority > max_priority && processes[i].remaining_time > 0) {
                max_priority = processes[i].priority;
                max_index = i;
            }
        }
        if (max_index == -1) {
            current_time++;
        } else {
            processes[max_index].remaining_time--;
            current_time++;
            if (processes[max_index].remaining_time == 0) {
                completed++;
                processes[max_index].completion_time = current_time;
                processes[max_index].turnaround_time = processes[max_index].completion_time - processes[max_index].arrival_time;
                processes[max_index].waiting_time = processes[max_index].turnaround_time - processes[max_index].burst_time;
            }
        }
    }
}

// Function to implement Round Robin Preemptive scheduling algorithm
void round_robin_preemptive(vector<Process>& processes, int time_quantum) {
    int n = processes.size();
    int current_time = 0;
    int completed = 0;
    queue<int> ready_queue;
    for (int i = 0; i < n; i++) {
        ready_queue.push(i);
    }
    while (completed < n) {
        int current_process = ready_queue.front();
        ready_queue.pop();
        if (processes[current_process].remaining_time > time_quantum) {
            current_time += time_quantum;
            processes[current_process].remaining_time -= time_quantum;
        } else {
            current_time += processes[current_process].remaining_time;
            processes[current_process].remaining_time = 0;
            completed++;
            processes[current_process].completion_time = current_time;
            processes[current_process].turnaround_time = processes[current_process].completion_time - processes[current_process].arrival_time;
            processes[current_process].waiting_time = processes[current_process].turnaround_time - processes[current_process].burst_time;
        }
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= current_time && processes[i].remaining_time > 0 && i != current_process) {
                ready_queue.push(i);
            }
        }
        if (processes[current_process].remaining_time > 0) {
            ready_queue.push(current_process);
        }
        if (ready_queue.empty()) {
            current_time++;
        }
    }
}

// Function to print the results of the scheduling algorithm
void print_results(vector<Process>& processes) {
    int n = processes.size();
    double total_waiting_time = 0;
    double total_turnaround_time = 0;
    cout << "Process\tBurst Time\tArrival Time\tPriority\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++) {
        cout << processes[i].pid << "\t\t" << processes[i].burst_time << "\t\t" << processes[i].arrival_time << "\t\t" << processes[i].priority << "\t\t" << processes[i].waiting_time << "\t\t" << processes[i].turnaround_time << endl;
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }
    cout << "Average waiting time: " << total_waiting_time / n << endl;
    cout << "Average turnaround time: " << total_turnaround_time / n << endl;
}

// Main functionint main() {
    int n, time_quantum;
    cout << "Enter the number of processes: ";
    cin >> n;
    vector<Process> processes(n);
    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        cout << "Enter the burst time for process " << i + 1 << ": ";
        cin >> processes[i].burst_time;
        cout << "Enter the arrival time for process " << i + 1 << ": ";
        cin >> processes[i].arrival_time;
        cout << "Enter the priority for process " << i + 1 << ": ";
        cin >> processes[i].priority;
        processes[i].remaining_time = processes[i].burst_time;
    }
    cout << "Enter the time quantum for Round Robin Preemptive: ";
    cin >> time_quantum;
    int choice;
    cout << "Choose a scheduling algorithm:\n";
    cout << "1. First Come First Served (FCFS)\n";
    cout << "2. Shortest Job First (SJF) Preemptive\n";
    cout << "3. Priority Non-Preemptive\n";
    cout << "4. Round Robin Preemptive\n";
    cin >> choice;
    switch (choice) {
        case 1:
            fcfs(processes);
            break;
        case 2:
            sjf_preemptive(processes);
            break;
        case 3:
            priority_non_preemptive(processes);
            break;
        case 4:
            round_robin_preemptive(processes, time_quantum);
            break;
        default:
            cout << "Invalid choice\n";
            return 0;
    }
    print_results(processes);
    return 0;
}
