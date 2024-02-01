//Shortest Job First (Preemptive)
//Compile using "g++ SJF_Pre.cpp -o SJF_Pre"

#include <bits/stdc++.h>
using namespace std;

class Process {
public:
    int id, arrivalTime, burstTime;

    Process(int id, int arrivalTime, int burstTime) : id(id), arrivalTime(arrivalTime), burstTime(burstTime) {}
};

bool compareArrivalTime(const Process &p1, const Process &p2) {
    if (p1.arrivalTime == p2.arrivalTime)
        return p1.burstTime < p2.burstTime;
    return p1.arrivalTime < p2.arrivalTime;
}

void printProcesses(vector<Process> &processes) {
    cout << "Processes: " << "\n";
    for (Process &process : processes) {
        cout << "P" << process.id + 1 << " " << process.arrivalTime << " " << process.burstTime << "\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<Process> processes;
    for (int i = 0; i < n; i++) {
        int id, arrivalTime, burstTime;
        cin >> id >> arrivalTime >> burstTime;
        processes.push_back(Process(id, arrivalTime, burstTime));
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

    cout << "Scheduling Method: Shortest Job First Scheduling (Preemptive)" << "\n";
    printProcesses(processes);
    cout << "\nProcess Waiting Times:" << "\n";
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