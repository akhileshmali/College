import java.io.*;
import java.util.Scanner;

public class FCFS {

    public static void main(String args[]) {
        int i, no_p, burst_time[], TT[], WT[]; // Declare variables for iteration, number of processes, burst time, turnaround time, and waiting time
        float avg_wait = 0, avg_TT = 0; // Declare variables for average waiting time and average turnaround time

        burst_time = new int[50]; // Initialize burst_time array
        TT = new int[50]; // Initialize TT array
        WT = new int[50]; // Initialize WT array
        WT[0] = 0; // Set the initial waiting time to 0

        Scanner s = new Scanner(System.in); // Create a Scanner object for user input

        System.out.println("Enter the number of process: "); // Prompt the user to enter the number of processes
        no_p = s.nextInt(); // Read the input as the number of processes

        System.out.println("\nEnter Burst Time for processes:"); // Prompt the user to enter the burst time for each process
        for (i = 0; i < no_p; i++) {
            System.out.print("\tP" + (i + 1) + ":  "); // Prompt for burst time of each process
            burst_time[i] = s.nextInt(); // Read the burst time for each process
        }

        // Calculate waiting time for each process
        for (i = 1; i < no_p; i++) {
            WT[i] = WT[i - 1] + burst_time[i - 1]; // Calculate waiting time
            avg_wait += WT[i]; // Update average waiting time
        }
        avg_wait /= no_p; // Calculate average waiting time

        // Calculate turnaround time for each process
        for (i = 0; i < no_p; i++) {
            TT[i] = WT[i] + burst_time[i]; // Calculate turnaround time
            avg_TT += TT[i]; // Update average turnaround time
        }
        avg_TT /= no_p; // Calculate average turnaround time

        // Display the results
        System.out.println("\n****************************************************************");
        System.out.println("\tProcesses:");
        System.out.println("****************************************************************");
        System.out.println("    Process\tBurst Time\tWaiting Time\tTurn Around Time");
        for (i = 0; i < no_p; i++) {
            System.out.println("\tP" + (i + 1) + "\t  " + burst_time[i] + "\t\t  " + WT[i] + "\t\t " + TT[i]);
        }
        System.out.println("\n----------------------------------------------------------------");
        System.out.println("\nAverage waiting time : " + avg_wait); // Display average waiting time
        System.out.println("\nAverage Turn Around time : " + avg_TT + "\n"); // Display average turnaround time
    }
}