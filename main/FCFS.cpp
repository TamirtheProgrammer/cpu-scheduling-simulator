//First Come, First Served Algorithm
// Compile using "g++ FCFS.cpp -o FCFS"


#include <bits/stdc++.h>
using namespace std;

struct Process {
    int id;
    int arrivalTime;
    int burstTime;
    int priority;
    Process(int id, int arrivalTime, int burstTime, int priority) : id(id), arrivalTime(arrivalTime), burstTime(burstTime), priority(priority) {}
};

bool compareArrivalTime(const Process &p1, const Process &p2) {
    return p1.arrivalTime < p2.arrivalTime;
}

bool comparePriority(const Process &p1, const Process &p2) {
    return p1.priority < p2.priority;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<Process> processes;
    for (int i = 0; i < n; i++) {
        int id, arrivalTime, burstTime, priority;
        cin >> id >> arrivalTime >> burstTime >> priority;
        processes.push_back(Process(id, arrivalTime, burstTime, priority));
    }

    sort(processes.begin(), processes.end(), compareArrivalTime);

    vector<int> gantt;
    vector<int> waitingTime(n, 0);
    vector<int> turnaroundTime(n, 0);

    int currentTime = 0;
    for (int i = 0; i < n; i++) {
        if (processes[i].arrivalTime > currentTime)
            currentTime = processes[i].arrivalTime;

        gantt.push_back(processes[i].id);
        waitingTime[i] = currentTime - processes[i].arrivalTime;
        currentTime += processes[i].burstTime;
        turnaroundTime[i] = currentTime - processes[i].arrivalTime;
    }

    cout << "Scheduling Method: First Come First Served" << "\n";
    cout << "Process Waiting Times:" << "\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << processes[i].id + 1 << ": " << waitingTime[i] << "\n";
    }

    int totalWaitingTime = 0;
    for (int i = 0; i < n; i++) {
        totalWaitingTime += waitingTime[i];
    }

    cout << "Average Waiting Time: " << totalWaitingTime / (double)n << "\n";

    return 0;
}
