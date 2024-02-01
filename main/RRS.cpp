//Round Robin Scheduling Method
//Compile using "g++ RRS.cpp -o RSS"

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
    sort(processes.begin(), processes.end(), comparePriority);

    vector<int> gantt;
    vector<int> waitingTime(n, 0);
    vector<int> turnaroundTime(n, 0);

    int currentTime = 0;
    queue<int> readyQueue;
    for (int i = 0; i < n; i++) {
        if (processes[i].arrivalTime <= currentTime)
            readyQueue.push(i);

        while (!readyQueue.empty() && processes[readyQueue.front()].arrivalTime <= currentTime) {
            int index = readyQueue.front();
            readyQueue.pop();

            while (processes[index].burstTime > 0) {
                int executionTime = min(processes[index].burstTime, 2); // 2 is the time quantum
                gantt.push_back(processes[index].id);
                currentTime += executionTime;
                processes[index].burstTime -= executionTime;

                if (processes[index].burstTime > 0) {
                    readyQueue.push(index);
                    break;
                }
            }
        }
    }

    cout << "Scheduling Method: Round Robin" << "\n";
    cout << "Process Waiting Times:" << "\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << processes[i].id + 1 << ": " << waitingTime[i] << "\n";
    }

    double totalWaitingTime = 0;
    for (int i = 0; i < n; i++) {
        totalWaitingTime += waitingTime[i];
    }

    cout << "Average Waiting Time: " << totalWaitingTime / (double)n << "\n";

    return 0;
}