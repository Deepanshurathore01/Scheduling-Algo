#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <unordered_set>

using namespace std;

// Process structure representing a job or process
struct Process {
    int id;              // Process ID
    int arrivalTime;     // Arrival time of the process
    int burstTime;       // Burst time or execution time of the process
    int remainingTime;   // Remaining time of the process (used for Round Robin)
    int startTime;       // Start time of the process
    int finishTime;      // Finish time of the process
    int turnaroundTime;  // Turnaround time of the process
    int waitingTime;     // Waiting time of the process
    int responseTime;    // Response time of the process
    int priority;        // Priority of the process 

    // Constructor for initializing process
    Process(int id, int arrivalTime, int burstTime, int priority = 0)
        : id(id), arrivalTime(arrivalTime), burstTime(burstTime), remainingTime(burstTime),
          startTime(-1), finishTime(0), turnaroundTime(0), 
          waitingTime(0), responseTime(0), priority(priority) {}
};

// Comparator for sorting processes based on arrival time
struct ArrivalTimeComparator {
    bool operator()(const Process& p1, const Process& p2) const {
        return p1.arrivalTime < p2.arrivalTime;
    }
};

// Comparator for sorting processes based on burst time
struct BurstTimeComparator {
    bool operator()(const Process& p1, const Process& p2) const {
        return p1.burstTime < p2.burstTime;
    }
};

// Comparator for sorting processes based on priority
struct PriorityComparator {
    bool operator()(const Process& p1, const Process& p2) const {
        return p1.priority < p2.priority;
    }
};


// Scheduler class
class Scheduler {
private:
    vector<Process> processes; // Vector to store processes
    vector<Process> result;    // Vector to store the result of scheduling

public:
    // Function to add a process to the scheduler
    void addProcess(int id, int arrivalTime, int burstTime, int priority = 0) {
        processes.emplace_back(id, arrivalTime, burstTime, priority);
    }

    // Function to take process input from the user
    void inputFromUser() {
        int n;
        cout << "Enter the number of processes: ";
        cin >> n;
        for (int i = 0; i < n; ++i) {
            int id, arrivalTime, burstTime, priority;
            cout << "Enter process ID, arrival time, burst time, and priority for process " << i + 1 << ": ";
            cin >> id >> arrivalTime >> burstTime >> priority;
            addProcess(id, arrivalTime, burstTime, priority);
        }
    }

    // Function to execute First-Come, First-Served (FCFS) scheduling
    void FCFS() {
        result.clear(); // Clear result vector before scheduling

        // Sort processes based on arrival time using ArrivalTimeComparator
        sort(processes.begin(), processes.end(), ArrivalTimeComparator());

        // Simulate FCFS scheduling
        int currentTime = 0;
        cout << "FCFS Scheduling:\n";
        cout << "Process\tArrival_Time\tBurst_Time\tStart_Time\tFinish_Time\tTurnaround_Time\tWaiting_Time\tResponse_Time\n";
        for (auto& process : processes) {
            process.startTime = max(currentTime, process.arrivalTime);
            process.finishTime = process.startTime + process.burstTime;
            process.turnaroundTime = process.finishTime - process.arrivalTime;
            process.waitingTime = process.startTime - process.arrivalTime;
            process.responseTime = process.startTime - process.arrivalTime;

            cout << process.id << "\t\t" << process.arrivalTime << "\t\t" << process.burstTime << "\t\t" 
                 << process.startTime << "\t\t" << process.finishTime << "\t\t" 
                 << process.turnaroundTime << "\t\t" << process.waitingTime << "\t\t" 
                 << process.responseTime << "\n";

            currentTime = process.finishTime;
            result.push_back(process);
        }
        displayResults("FCFS");
    }

    // Function to execute Shortest Job First (SJF) scheduling
    void SJF() {
        result.clear(); // Clear result vector before scheduling

        // Sort processes based on arrival time using ArrivalTimeComparator initially
        sort(processes.begin(), processes.end(), ArrivalTimeComparator());

        vector<Process> readyQueue;
        int currentTime = 0;
        cout << "SJF Scheduling:\n";
        cout << "Process\tArrival_Time\tBurst_Time\tStart_Time\tFinish_Time\tTurnaround_Time\tWaiting_Time\tResponse_Time\n";

        while (!processes.empty() || !readyQueue.empty()) {
            // Move processes that have arrived by current time to ready queue
            while (!processes.empty() && processes.front().arrivalTime <= currentTime) {
                readyQueue.push_back(processes.front());
                processes.erase(processes.begin());
            }

            // Sort ready queue based on burst time
            sort(readyQueue.begin(), readyQueue.end(), BurstTimeComparator());

            if (!readyQueue.empty()) {
                Process& process = readyQueue.front();
                process.startTime = max(currentTime, process.arrivalTime);
                process.finishTime = process.startTime + process.burstTime;
                process.turnaroundTime = process.finishTime - process.arrivalTime;
                process.waitingTime = process.startTime - process.arrivalTime;
                process.responseTime = process.startTime - process.arrivalTime;
                currentTime = process.finishTime;

                cout << process.id << "\t\t" << process.arrivalTime << "\t\t" << process.burstTime << "\t\t" 
                     << process.startTime << "\t\t" << process.finishTime << "\t\t" 
                     << process.turnaroundTime << "\t\t" << process.waitingTime << "\t\t" 
                     << process.responseTime << "\n";

                readyQueue.erase(readyQueue.begin());
                result.push_back(process);
            } else {
                currentTime++;
            }
        }
        displayResults("SJF");
    }

    // Function to execute Priority scheduling
    void PriorityScheduling() {
        result.clear(); // Clear result vector before scheduling

        // Sort processes based on arrival time initially
        sort(processes.begin(), processes.end(), ArrivalTimeComparator());

        vector<Process> readyQueue;
        int currentTime = 0;
        cout << "Priority Scheduling:\n";
        cout << "Process\tArrival_Time\tPriority\tBurst_Time\tStart_Time\tFinish_Time\tTurnaround_Time\tWaiting_Time\tResponse_Time\n";

        while (!processes.empty() || !readyQueue.empty()) {
            // Move processes that have arrived by current time to ready queue
            while (!processes.empty() && processes.front().arrivalTime <= currentTime) {
                readyQueue.push_back(processes.front());
                processes.erase(processes.begin());
            }

            // Sort ready queue based on priority
            sort(readyQueue.begin(), readyQueue.end(), PriorityComparator());

            if (!readyQueue.empty()) {
                Process& process = readyQueue.front();
                process.startTime = max(currentTime, process.arrivalTime);
                process.finishTime = process.startTime + process.burstTime;
                process.turnaroundTime = process.finishTime - process.arrivalTime;
                process.waitingTime = process.startTime - process.arrivalTime;
                process.responseTime = process.startTime - process.arrivalTime;
                currentTime = process.finishTime;

                cout << process.id << "\t\t" << process.arrivalTime << "\t\t" << process.priority << "\t\t" 
                     << process.burstTime << "\t\t" << process.startTime << "\t\t" << process.finishTime << "\t\t" 
                     << process.turnaroundTime << "\t\t" << process.waitingTime << "\t\t" 
                     << process.responseTime << "\n";

                readyQueue.erase(readyQueue.begin());
                result.push_back(process);
            } else {
                currentTime++;
            }
        }
        displayResults("Priority");
    }

    // Function to execute Round Robin scheduling
    void RoundRobin(int timeQuantum) {
        result.clear(); // Clear result vector before scheduling

        queue<Process*> readyQueue;
        unordered_set<int> inQueue;
        int currentTime = 0;
        cout << "Round Robin Scheduling (Time Quantum = " << timeQuantum << "):\n";
        cout << "Process\tArrival_Time\tBurst_Time\tStart_Time\tFinish_Time\tTurnaround_Time\tWaiting_Time\tResponse_Time\n";

        for (auto& process : processes) {
            if (process.arrivalTime <= currentTime) {
                readyQueue.push(&process);
                inQueue.insert(process.id);
            }
        }

        while (!readyQueue.empty()) {
            Process* process = readyQueue.front();
            readyQueue.pop();
            inQueue.erase(process->id);

            if (process->startTime == -1) {
                process->startTime = currentTime;
                process->responseTime = process->startTime - process->arrivalTime;
            }

            if (process->remainingTime <= timeQuantum) {
                currentTime += process->remainingTime;
                process->finishTime = currentTime;
                process->turnaroundTime = process->finishTime - process->arrivalTime;
                process->waitingTime = process->turnaroundTime - process->burstTime;
                process->remainingTime = 0;

                cout << process->id << "\t\t" << process->arrivalTime << "\t\t" << process->burstTime << "\t\t" 
                     << process->startTime << "\t\t" << process->finishTime << "\t\t" << process->turnaroundTime << "\t\t" 
                     << process->waitingTime << "\t\t" << process->responseTime << "\n";

                result.push_back(*process);
            } else {
                currentTime += timeQuantum;
                process->remainingTime -= timeQuantum;

                // Push processes that have arrived during the time quantum
                for (auto& p : processes) {
                    if (p.arrivalTime <= currentTime && p.remainingTime > 0 && inQueue.find(p
                    .id) == inQueue.end()) {
                        readyQueue.push(&p);
                        inQueue.insert(p.id);
                    }
                }
                
                readyQueue.push(process);
                inQueue.insert(process->id);
            }
        }
        displayResults("Round Robin");
    }

    // Function to display results
    // Function to display results
void displayResults(const string& algorithm) {
    cout << "\n" << algorithm << " Scheduling Results:\n";

    if (result.empty()) {
        cout << "No processes scheduled.\n";
        return;
    }

    cout << "Gantt Chart:\n";
    for (const auto& process : result) {
        cout << "| P" << process.id << " ";
    }
    cout << "|\n";

    int currentTime = 0;
    for (const auto& process : result) {
        if (process.startTime > currentTime) {
            cout << currentTime << " idle ";
            currentTime = process.startTime;
        }
        cout << currentTime << " ";
        currentTime = process.finishTime;
    }
    cout << currentTime << "\n";

    double totalTurnaroundTime = 0;
    double totalWaitingTime = 0;
    for (const auto& process : result) {
        totalTurnaroundTime += process.turnaroundTime;
        totalWaitingTime += process.waitingTime;
    }
    
    if (result.size() > 0) {
        cout << "Average Turnaround Time: " << totalTurnaroundTime / result.size() << "\n";
        cout << "Average Waiting Time: " << totalWaitingTime / result.size() << "\n";
    } else {
        cout << "No processes to calculate averages.\n";
    }
}

};

// Example usage
int main() {
    Scheduler scheduler;
    int choice;

    scheduler.inputFromUser();
    do {
        cout << "\nEnter algorithm choice (1-4), 0 to Exit: ";
        cout << "\n1. FCFS\n2. SJF\n3. Priority\n4. Round Robin\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                scheduler.FCFS();
                break;
            case 2:
                scheduler.SJF();
                break;
            case 3:
                scheduler.PriorityScheduling();
                break;
            case 4:
                scheduler.RoundRobin(2); // Example: Round Robin with quantum 2
                break;
            case 0:
                cout << "Exiting...";
                break;
            default:
                cout << "Invalid choice. Please enter a number between 0 and 4." << endl;
                break;
        }
    } while (choice != 0);

    return 0;
}
