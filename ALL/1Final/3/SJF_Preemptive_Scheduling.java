import java.util.*;

class Entry1 {
    String Process; // Name of the process
    int A_time; // Arrival time of the process
    int B_time; // Burst time of the process
    int C_time; // Completion time of the process
    int T_time; // Turnaround time of the process
    int W_time; // Waiting time of the process
}

public class SJF_Preemptive_Scheduling {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n;
        System.out.println("Enter the number of processes: ");
        n = sc.nextInt();
        Entry1[] processes = new Entry1[n]; // Array to store process details

        // Input process details
        for (int i = 0; i < n; i++) {
            processes[i] = new Entry1();
            System.out.println("Enter the Process Name: ");
            processes[i].Process = sc.next();
            System.out.println("Enter the Arrival Time of Process " + processes[i].Process + ": ");
            processes[i].A_time = sc.nextInt();
            System.out.println("Enter the Burst Time of Process " + processes[i].Process + ": ");
            processes[i].B_time = sc.nextInt();
        }

        int totalTurnaroundTime = 0;
        int totalWaitingTime = 0;

        int[] remainingTime = new int[n];
        for (int i = 0; i < n; i++) {
            remainingTime[i] = processes[i].B_time; // Initialize remaining time with burst time
        }

        int currentTime = 0;
        int completed = 0;

        System.out.println("Gantt Chart:");
        StringBuilder ganttChart = new StringBuilder();

        // Execute processes based on SJF Preemptive Scheduling Algorithm
        while (completed != n) {
            int shortest = -1;
            int shortestBurst = 999;

            // Find the process with the shortest remaining burst time
            for (int i = 0; i < n; i++) {
                if (processes[i].A_time <= currentTime && remainingTime[i] < shortestBurst && remainingTime[i] > 0) {
                    shortest = i;
                    shortestBurst = remainingTime[i];
                }
            }

            // Execute the process with the shortest remaining burst time
            if (shortest == -1) {
                currentTime++;
                ganttChart.append("-  ");
            } else {
                remainingTime[shortest]--;
                currentTime++;
                ganttChart.append(processes[shortest].Process).append("  ");
                if (remainingTime[shortest] == 0) {
                    completed++;
                    processes[shortest].C_time = currentTime;
                    processes[shortest].T_time = processes[shortest].C_time - processes[shortest].A_time;
                    processes[shortest].W_time = processes[shortest].T_time - processes[shortest].B_time;
                }
            }
        }

        // Calculate total turnaround time and waiting time
        for (int i = 0; i < n; i++) {
            totalTurnaroundTime += processes[i].T_time;
            totalWaitingTime += processes[i].W_time;
        }

        // Print Gantt chart and process details
        System.out.println(ganttChart);
        System.out.println(" ");
        System.out.println("PID\t\tArrival Time\tBurst Time\tCompletion Time\t\tTurnaround Time\t\tWaiting Time");

        for (int i = 0; i < n; i++) {
            System.out.println(processes[i].Process + "\t\t\t" + processes[i].A_time + "\t\t\t\t" + processes[i].B_time + "\t\t\t\t" + processes[i].C_time + "\t\t\t\t" + processes[i].T_time + "\t\t\t\t" + processes[i].W_time);
        }

        // Calculate and print average turnaround time and waiting time
        double avgTurnaroundTime = (double) totalTurnaroundTime / n;
        double avgWaitingTime = (double) totalWaitingTime / n;

        System.out.println("\nAverage Turnaround Time: " + avgTurnaroundTime + " ms");
        System.out.println("Average Waiting Time: " + avgWaitingTime + " ms");
    }
}

/*
OUTPUT:-
Enter the number of processes:
5
Enter the Process Name:
P1
Enter the Arrival Time of Process P1:
2
Enter the Burst Time of Process P1:
6
Enter the Process Name:
P2
Enter the Arrival Time of Process P2:
5
Enter the Burst Time of Process P2:
2
Enter the Process Name:
P3
Enter the Arrival Time of Process P3:
1
Enter the Burst Time of Process P3:
8
Enter the Process Name:
P4
Enter the Arrival Time of Process P4:
0
Enter the Burst Time of Process P4:
3
Enter the Process Name:
P5
Enter the Arrival Time of Process P5:
4
Enter the Burst Time of Process P5:
4
*/
