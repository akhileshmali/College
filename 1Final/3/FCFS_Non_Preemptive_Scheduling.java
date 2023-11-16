import java.util.*;

// Class to represent a process
class calculn 
{
    String Process; // Process name
    int A_time, B_time; // Arrival time and Burst time
}

// Class for scheduling
class schd 
{
    Scanner sc = new Scanner(System.in);
    int n; // Number of processes
    calculn[] c; // Array to store processes
    int C_time[]; // Array to store Completion Time
    int T_time[]; // Array to store Turn-Around Time
    int W_time[]; // Array to store Waiting Time
    int totalWtime; // Total Waiting Time
    int totalTtime; // Total Turn-Around Time

    // Function to take input for processes
    void entry() 
    {
        System.out.println("Enter the no. of Processes : ");
        n = sc.nextInt();
        c = new calculn[n];
        C_time = new int[n];
        T_time = new int[n];
        W_time = new int[n];

        // Input for each process
        for (int i = 0; i < n; i++) {
            c[i] = new calculn();
            System.out.println("Enter the Process Name : ");
            c[i].Process = sc.next();
            System.out.println("Enter the Arrival Time of the Process " + c[i].Process + " : ");
            c[i].A_time = sc.nextInt();
            System.out.println("Enter the Burst Time of the Process " + c[i].Process + " : ");
            c[i].B_time = sc.nextInt();
            System.out.println(" ");
        }

        // Display the entered processes
        System.out.println("The Processes Entered  are : ");
        for (int i = 0; i < n; i++) {
            System.out.println("Process " + c[i].Process);
            System.out.println("->");
            System.out.println("Arrival time of Process " + c[i].Process + " is : " + c[i].A_time);
            System.out.println("Burst time of Process " + c[i].Process + " is : " + c[i].B_time);
            System.out.println(" ");
        }
    }

    // Function to sort the processes based on arrival time
    void sort() 
  {
    Arrays.sort(c, (o1, o2) -> {
      int comparison = Integer.compare(o1.A_time, o2.A_time);
      if (comparison == 0) {
        comparison = Integer.compare(o1.B_time, o2.B_time);
      }
      return comparison;
    });
  }

    // Function to calculate Completion Time, Turn-Around Time, and Waiting Time for each process
    void calculate() 
    {
        C_time[0] = c[0].B_time;
        T_time[0] = C_time[0] - c[0].A_time;
        W_time[0] = T_time[0] - c[0].B_time;
        totalWtime = W_time[0];
        totalTtime = T_time[0];

        for (int i = 1; i < n; i++) {
            C_time[i] = C_time[i - 1] + c[i].B_time;
            T_time[i] = C_time[i] - c[i].A_time;
            W_time[i] = T_time[i] - c[i].B_time;
            totalWtime += W_time[i];
            totalTtime += T_time[i];
        }
    }

    // Function to display the output table of Process ID, Arrival time, Burst time, CT, TAT, WT
    void show_table() 
    {
        System.out.println("Process ID\tArrival time\tBurst time\tCT\tTAT\tWT");
        for (int i = 0; i < n; i++) {
            System.out.println(c[i].Process + "\t\t" + c[i].A_time + "\t\t" + c[i].B_time + "\t\t" + C_time[i] + "\t\t" + T_time[i] + "\t\t" + W_time[i]);
        }
    }

    // Function to display the Gantt Chart
    void gantt_cht() 
    {
        for (int i = 0; i < n; i++) {
            System.out.print(c[i].Process + "\t\t\t");
        }
        System.out.println();
        for (int i = 0; i < C_time.length; i++) {
            if (i == 0) {
                System.out.print("0\t\t" + C_time[i]);
            } else {
                System.out.print("\t\t\t" + C_time[i]);
            }
        }
        System.out.println();
    }

    // Function to calculate and display the average waiting time
    void avg_wtime() 
    {
        double avgWait = (double) totalWtime / n;
        System.out.println("Average Waiting time : " + avgWait + " ms");
    }

    // Function to calculate and display the average Turnaround time
    void avg_Ttime() 
    {
        double avgTA = (double) totalTtime / n;
        System.out.println("Average Turnaround time : " + avgTA + " ms");
    }

    // Function to implement the FCFS scheduling algorithm
    void fcfs() 
    {
        //entry();
        sort();
        calculate();
        System.out.println("The Completion Time, Turn-Around Time, and Waiting Time for the Processes are : ");
        show_table();
        System.out.println("The Gantt Chart generated is as : ");
        gantt_cht();
        avg_wtime();
        avg_Ttime();
    }
}

// Main class
public class FCFS_Non_Preemptive_Scheduling 
{
    public static void main(String[] args) 
    {
        schd obj = new schd();
        int ch, ans = 1;
        while (ans == 1) {
            System.out.println("********************MENU********************");
            System.out.println("1.Take the Entry for Process Name,Arrival & Burst Time\n2.FCFS\n3.Exit");
            System.out.println("Enter your choice : ");
            ch = obj.sc.nextInt();
            switch (ch) {
                case 1:
                    obj.entry();
                    break;

                case 2:
                    obj.fcfs();
                    break;

                case 3:
                    System.out.println("Terminating successfully!!");
                    ans = 2;
                    break;

                default:
                    System.out.println("Wrong choice entered!!\nPlease Try again!");
                    break;
            }
        }
    }
}