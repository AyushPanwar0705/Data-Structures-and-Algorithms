#include <iostream>
#include <queue>

using namespace std;

struct Process {
    int id;
    int arrivalTime;
    int burstTime;
};

void FCFS(queue<Process>& processes) {
    int currentTime = 0;
   
    while (!processes.empty()) {
        Process currentProcess = processes.front();
        processes.pop();
       
        // Process the current process
        cout << "Processing Process " << currentProcess.id << " (AT: " << currentProcess.arrivalTime << ", BT: " << currentProcess.burstTime << ")" << endl;
        currentTime += currentProcess.burstTime;
       
        // Calculate waiting time for the current process
        int waitingTime = currentTime - currentProcess.arrivalTime - currentProcess.burstTime;
        if (waitingTime < 0) {
            waitingTime = 0;
        }
       
        cout << "  Waiting Time: " << waitingTime << endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    queue<Process> processes;

    for (int i = 1; i <= n; ++i) {
        Process p;
        p.id = i;
        cout << "Enter Arrival Time for Process " << i << ": ";
        cin >> p.arrivalTime;
        cout << "Enter Burst Time for Process " << i << ": ";
        cin >> p.burstTime;
        processes.push(p);
    }

    cout << "\nFCFS Scheduling Order:\n";
    FCFS(processes);

    return 0;
}
