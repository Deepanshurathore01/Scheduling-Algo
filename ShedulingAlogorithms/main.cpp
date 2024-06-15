#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

// Process structure representing a job or process
struct Process {
    int id;          // Process ID
    int arrivalTime; // Arrival time of the process
    int burstTime;   // Burst time or execution time of the process
    int startTime;   // Start time of the process
    int finishTime;  // Finish time of the process
    int turnaroundTime; // Turnaround time of the process
    int waitingTime;    // Waiting time of the process
    int responseTime;   // Response time of the process

    // Constructor for initializing process
    Process(int id, int arrivalTime, int burstTime)
        : id(id), arrivalTime(arrivalTime), burstTime(burstTime), 
          startTime(0), finishTime(0), turnaroundTime(0), 
          waitingTime(0), responseTime(0) {}
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

// Scheduler class
class Scheduler {
private:
    vector<Process> processes; // Vector to store processes

public:
    // Function to add a process to the scheduler
    void addProcess(int id, int arrivalTime, int burstTime) {
        processes.emplace_back(id, arrivalTime, burstTime);
    }

    // Function to execute First-Come, First-Served (FCFS) scheduling
    void FCFS() {
        // Sort processes based on arrival time using ArrivalTimeComparator
        sort(processes.begin(), processes.end(), ArrivalTimeComparator());

        // Simulate FCFS scheduling
        int currentTime = 0;
        cout << "FCFS Scheduling:\n";
        cout << "Process\tArrival_Time\tBurst_Time\tStart_Time\tFinish_Time\tTurnaround_Time\tWaiting_Time\tResponse_Time\n";
        for (auto& process : processes) {
            process.startTime = currentTime;
            process.finishTime = process.startTime + process.burstTime;
            process.turnaroundTime = process.finishTime - process.arrivalTime;
            process.waitingTime = process.turnaroundTime - process.burstTime;
            process.responseTime = process.startTime - process.arrivalTime;

            cout << process.id <<"\t\t" <<process.arrivalTime << "\t"<<process.burstTime << "\t" << process.startTime << "\t\t" << process.finishTime << "\t\t" 
                 << process.turnaroundTime << "\t\t" << process.waitingTime << "\t\t" 
                 << process.responseTime << "\n";

            currentTime += process.burstTime;
        }
    }

        // Function to execute Shortest Job First (SJF) scheduling
    void SJF() {
        // Sort processes based on arrival time using ArrivalTimeComparator initially
        sort(processes.begin(), processes.end(), ArrivalTimeComparator());

        vector<Process> readyQueue;
        int currentTime = 0;
        cout << "SJF Scheduling:\n";
        cout << "Process\tArrival Time\tBurst_Time\tStart Time\tFinish Time\tTurnaround Time\tWaiting Time\tResponse Time\n";

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

                cout << process.id << "\t" << process.arrivalTime << "\t\t"<<process.burstTime<< "\t\t" << process.startTime << "\t\t"
                     << process.finishTime << "\t\t" << process.turnaroundTime << "\t\t" << process.waitingTime
                     << "\t\t" << process.responseTime << "\n";

                readyQueue.erase(readyQueue.begin());
            } else {
                currentTime++;
            }
        }
    }
       
};

// Example usage
int main() {
    Scheduler scheduler;

    // Add processes to the scheduler
    scheduler.addProcess(0, 0, 5);
    scheduler.addProcess(1, 2, 3);
    scheduler.addProcess(2, 1, 6);
    scheduler.addProcess(3, 4, 2);

    // Execute FCFS scheduling algorithm
        scheduler.FCFS();
        scheduler.SJF();
        



    return 0;
}
