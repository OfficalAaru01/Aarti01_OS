//FCFS with arrival time
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Process {
    string name;
    int burstTime;
    int arrivalTime;
    int waitingTime;
    int turnAroundTime;
};

int main() {
    int numProcess;
    cout << "Enter the number of Processes: ";
    cin >> numProcess;
    
    vector<Process> Processes(numProcess);
    
   
    for(int i = 0; i < numProcess; i++) {
        cout << "Enter burst time for process " << (i + 1) << ": ";
        cin >> Processes[i].burstTime;
        cout << "Enter arrival time for process " << (i + 1) << ": ";
        cin >> Processes[i].arrivalTime;
        Processes[i].name = "p" + to_string(i + 1);
        Processes[i].waitingTime = 0;
        Processes[i].turnAroundTime = 0;
    }
    
    
    sort(Processes.begin(), Processes.end(), [](const Process& a, const Process& b) {
        return a.arrivalTime < b.arrivalTime;
    });
    
    
    for(int i = 1; i < numProcess; i++) {
        int prevCompletionTime = Processes[i - 1].arrivalTime + Processes[i - 1].burstTime;
        Processes[i].waitingTime = max(0, prevCompletionTime - Processes[i].arrivalTime);
        Processes[i].turnAroundTime = Processes[i].waitingTime + Processes[i].burstTime;
    }
    
    
    double avgWaitingTime = 0, avgTurnAroundTime = 0;
    for(const Process& process: Processes) {
        avgWaitingTime += process.waitingTime;
        avgTurnAroundTime += process.turnAroundTime;
    }
    avgWaitingTime /= numProcess;
    avgTurnAroundTime /= numProcess;
    
    cout << "Average Turnaround Time: " << avgTurnAroundTime << endl;
    cout << "Average Waiting Time: " << avgWaitingTime << endl;
    
    return 0;
}



//FCFS without arrival time
#include <iostream>
#include<string.h>
#include<vector>

using namespace std;

struct Process{
    string name;
    int burstTime;
    int waitingTime;
    int turnAroundTime;
};

int main()
{
    int numProcess;
    cout<<"Enter the number of Process :"<<endl;
    cin>>numProcess;
    vector<Process> Processes(numProcess);
    for(int i =0; i<numProcess; i++){
        cout<<"Enter burst time for process"<<(i+1)<<":";
        cin>>Processes[i].burstTime;
        Processes[i].name = "p"+ to_string(i+1);
        Processes[i].waitingTime = 0;
        
        Processes[i].turnAroundTime = 0;
        }
        
        for(int i =1; i<numProcess; i++){
         Processes[i].waitingTime = Processes[i-1].waitingTime+Processes[i-1].burstTime;
         Processes[i].turnAroundTime = Processes[i].waitingTime+ Processes[i].burstTime;
         
        }
        
        double avgWaitingTime = 0, avgTurnArounfTime=0;
        for(const Process& process: Processes){
            avgWaitingTime += process.waitingTime;
            avgTurnArounfTime += process.turnAroundTime;
        }
        avgWaitingTime/= numProcess;
        avgTurnArounfTime /= numProcess;
        
        cout<<avgTurnArounfTime;
        cout<<avgWaitingTime;

        return 0;
}



// LJF with arrival time 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
    int id;
    int burst_time;
    int arrival_time;
};

bool compareJobs(const Job& a, const Job& b) {
    if (a.arrival_time != b.arrival_time)
        return a.arrival_time < b.arrival_time;
    return a.burst_time > b.burst_time;
}

class LIFScheduler {
private:
    vector<Job> joblist;

public:
    LIFScheduler(vector<Job>& jobs) {
        joblist = jobs;
    }

    void schedule() {
        sort(joblist.begin(), joblist.end(), compareJobs);
        int current_time = 0;
        cout << "jobschedule (LJF with arrival time):\n";
        cout << "Job ID \t Burst Time \t Arrival Time \t Completion Time\n";

        for (Job& job : joblist) {
            int completion_time = max(current_time, job.arrival_time) + job.burst_time;
            cout << job.id << "\t" << job.burst_time << "\t\t" << job.arrival_time << "\t\t" << completion_time << endl;
            current_time = completion_time;
        }
    }
};

int main() {
    vector<Job> jobs = {
        {1, 10, 0},
        {2, 5, 2},
        {3, 8, 3}
    };

    LIFScheduler scheduler(jobs);

    scheduler.schedule();

    return 0;
}



//LJF without  arrival time 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
    int id;
    int burst_time;
};

bool compareJobs(Job& a, Job& b) {
    return a.burst_time > b.burst_time;
}

class LIFScheduler {
private:
    vector<Job> joblist;

public:
    LIFScheduler(vector<Job>& jobs) {
        joblist = jobs;
    }

    void schedule() {
        sort(joblist.begin(), joblist.end(), compareJobs);
        int current_time = 0;
        cout << "jobschedule (lif):" << endl;
        cout << "Job ID \t burst time \t completion Time\n";

        for (Job& job : joblist) {
            int completion_time = current_time + job.burst_time;
            cout << job.id << "\t" << job.burst_time << "\t\t" << completion_time << endl;
             current_time = completion_time;
        }
    }
};

int main() {
    vector<Job> jobs = {
        {1, 10},
        {2, 5},
        {3, 8}
    };

    LIFScheduler scheduler(jobs);

    scheduler.schedule();

    return 0;
}
