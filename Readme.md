# CPU Scheduling Simulator

A comprehensive simulation of various CPU scheduling algorithms implemented in C++. This project helps developers and students understand the behavior and differences between scheduling strategies like FCFS, SJF, Priority Scheduling, and Round Robin.

---

## Features ✨

- **First-Come, First-Served (FCFS):** Processes are executed in the order they arrive.
- **Shortest Job First (SJF):** Executes processes with the shortest burst time first.
- **Priority Scheduling:** Executes processes based on their priority levels.
- **Round Robin (RR):** Time-sliced scheduling for fair execution.

### Key Metrics Calculated:
- **Start Time**
- **Finish Time**
- **Turnaround Time**
- **Waiting Time**
- **Response Time**

---

## How to Run 🛠️

### Prerequisites:
- **C++ Compiler:** Ensure you have `g++` or any other standard C++ compiler installed.

### Steps:
1. Clone the repository:
   ```bash
   git clone https://github.com/Deepanshurathore01/Scheduling-Algo.git

2. Navigate to the project directory:

  cd ShedulingAlogorithms
  
3. Compile the program:

   g++ scheduling_simulator.cpp -o scheduling_simulator
   
4. Run the executable:

bash
Copy code
./scheduling_simulator






Usage 📚
Input Process Details:

Enter the number of processes.
For each process, provide:
Process ID
Arrival Time
Burst Time
Priority (optional for certain algorithms).
Choose a Scheduling Algorithm:

Enter the choice:
1 for FCFS
2 for SJF
3 for Priority Scheduling
4 for Round Robin
View the Output:

The program displays:
Scheduling Gantt chart
Per-process metrics
Average Turnaround Time
Average Waiting Time

   
Example Input/Output 🖥️
Input:

Enter the number of processes: 3
Enter process ID, arrival time, burst time, and priority for process 1: 1 0 5 2
Enter process ID, arrival time, burst time, and priority for process 2: 2 2 3 1
Enter process ID, arrival time, burst time, and priority for process 3: 3 4 1 3

Enter algorithm choice (1-4), 0 to Exit:
1. FCFS
2. SJF
3. Priority
4. Round Robin
0. Exit
Enter your choice: 2
Output:

SJF Scheduling:
Process  Arrival_Time  Burst_Time  Start_Time  Finish_Time  Turnaround_Time  Waiting_Time  Response_Time
1        0            5           0           5            5                0             0
2        2            3           5           8            6                3             3
3        4            1           8           9            5                4             4

SJF Scheduling Results:
Gantt Chart:
| P1 | P2 | P3 |
0 5 8 9

Average Turnaround Time: 5.33
Average Waiting Time: 2.33


Algorithms Overview 🚀
First-Come, First-Served (FCFS)
Order of Execution: Based on arrival time.
Non-Preemptive.

Shortest Job First (SJF)
Order of Execution: Shortest burst time first.
Non-Preemptive.

Priority Scheduling
Order of Execution: Highest priority first.
Preemptive or Non-Preemptive (depends on implementation).

Round Robin (RR)
Order of Execution: Time-sliced execution in a cyclic order.
Preemptive.


Contributions 🤝
Contributions are welcome!
Feel free to fork the repository, make improvements, and create pull requests.

License 📄
This project is licensed under the MIT License.


Here's a README.md file tailored for your scheduling algorithms project:

markdown
Copy code
# CPU Scheduling Simulator

A comprehensive simulation of various CPU scheduling algorithms implemented in C++. This project helps developers and students understand the behavior and differences between scheduling strategies like FCFS, SJF, Priority Scheduling, and Round Robin.

---

## Features ✨

- **First-Come, First-Served (FCFS):** Processes are executed in the order they arrive.
- **Shortest Job First (SJF):** Executes processes with the shortest burst time first.
- **Priority Scheduling:** Executes processes based on their priority levels.
- **Round Robin (RR):** Time-sliced scheduling for fair execution.

### Key Metrics Calculated:
- **Start Time**
- **Finish Time**
- **Turnaround Time**
- **Waiting Time**
- **Response Time**

---

## How to Run 🛠️

### Prerequisites:
- **C++ Compiler:** Ensure you have `g++` or any other standard C++ compiler installed.

### Steps:
1. Clone the repository:
   ```bash
   git clone https://github.com/your-repo/cpu-scheduling-simulator.git
Navigate to the project directory:
bash
Copy code
cd cpu-scheduling-simulator
Compile the program:
bash
Copy code
g++ scheduling_simulator.cpp -o scheduling_simulator
Run the executable:
bash
Copy code
./scheduling_simulator
Usage 📚
Input Process Details:

Enter the number of processes.
For each process, provide:
Process ID
Arrival Time
Burst Time
Priority (optional for certain algorithms).
Choose a Scheduling Algorithm:

Enter the choice:
1 for FCFS
2 for SJF
3 for Priority Scheduling
4 for Round Robin
View the Output:

The program displays:
Scheduling Gantt chart
Per-process metrics
Average Turnaround Time
Average Waiting Time
Example Input/Output 🖥️
Input:
mathematica
Copy code
Enter the number of processes: 3
Enter process ID, arrival time, burst time, and priority for process 1: 1 0 5 2
Enter process ID, arrival time, burst time, and priority for process 2: 2 2 3 1
Enter process ID, arrival time, burst time, and priority for process 3: 3 4 1 3

Enter algorithm choice (1-4), 0 to Exit:
1. FCFS
2. SJF
3. Priority
4. Round Robin
0. Exit
Enter your choice: 2
Output:
yaml
Copy code
SJF Scheduling:
Process  Arrival_Time  Burst_Time  Start_Time  Finish_Time  Turnaround_Time  Waiting_Time  Response_Time
1        0            5           0           5            5                0             0
2        2            3           5           8            6                3             3
3        4            1           8           9            5                4             4

SJF Scheduling Results:
Gantt Chart:
| P1 | P2 | P3 |
0 5 8 9

Average Turnaround Time: 5.33
Average Waiting Time: 2.33
Algorithms Overview 🚀
First-Come, First-Served (FCFS)
Order of Execution: Based on arrival time.
Non-Preemptive.
Shortest Job First (SJF)
Order of Execution: Shortest burst time first.
Non-Preemptive.
Priority Scheduling
Order of Execution: Highest priority first.
Preemptive or Non-Preemptive (depends on implementation).
Round Robin (RR)
Order of Execution: Time-sliced execution in a cyclic order.
Preemptive.
Contributions 🤝
Contributions are welcome!
Feel free to fork the repository, make improvements, and create pull requests.

License 📄
This project is licensed under the MIT License.

Author ✍️
Developed by Deepanshu Rathore.
For any queries, feel free to reach out via rathoredeepanshu84@gmail.com.