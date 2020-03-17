#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

enum algo_list {
  FCFS,
  SJF,
  SRTF,
  P,
  RR
};

algo_list hashit(string const& algo);

void solveFCFS(int n, int arrival[], int burst[], int prio[]);
void solveSJF(int n, int arrival[], int burst[], int prio[]);
void solveSRTF(int n, int arrival[], int burst[], int prio[]);
void solveP(int n, int arrival[], int burst[], int prio[]);
void solveRR(int n, int arrival[], int burst[], int prio[], int q);

int main() {
  string line;
  string input;
  ifstream myfile("CE155_Project1_Cruz_Ordona_testfile.txt");

  if(myfile.is_open()) {
    int num_test_cases;
    myfile >> num_test_cases;

    for(int test_case = 1; test_case <= num_test_cases; test_case++) {
      cout << test_case << '\n';
      
      int num_processes;
      string algo;
      int q;
      int arrival_times[num_processes];
      int burst_times[num_processes];
      int priority_list[num_processes];

      myfile >> num_processes;
      myfile >> algo;
      // cout << num_processes << " " << algo;

      if(algo == "RR") {
        myfile >> q;
        // cout << " " << q;
      }

      for(int p = 0; p < num_processes; p++) {
        myfile >> arrival_times[p];
        myfile >> burst_times[p];
        myfile >> priority_list[p];
        // cout << '\n' << arrival_times[p] << " " << burst_times[p] << " " << priority_list[p];
      }

      switch(hashit(algo)) {
        case FCFS:
          solveFCFS(num_processes, arrival_times, burst_times, priority_list);
          break;
        case SJF:
          solveSJF(num_processes, arrival_times, burst_times, priority_list);
          break;
        case SRTF:
          solveSRTF(num_processes, arrival_times, burst_times, priority_list);
          break;
        case P:
          solveP(num_processes, arrival_times, burst_times, priority_list);
          break;
        case RR:
          solveRR(num_processes, arrival_times, burst_times, priority_list, q);
          break;
      }
    }
    
    myfile.close();
  }

  else cout << "Unable to open file"; 

  return 0;
}


void solveFCFS(int n, int arrival[], int burst[], int prio[]) {
  int sorted_arrival[n];
  for(int i = 0; i < n; i++) {
    sorted_arrival[i] = arrival[i];
  };

  sort(sorted_arrival, sorted_arrival+n);

  for (int i = 0; i < n; i++) {
    int index = distance(arrival, find(arrival, arrival + n, sorted_arrival[i]));
    cout << arrival[index] << " " << index + 1 << " " << burst[index] << "X" << '\n';
  };
};


void solveSJF(int n, int arrival[], int burst[], int prio[]) {
  for (int i = 0; i < n; i++) {
    cout << arrival[i] << " " << burst[i] << " " << prio[i] << '\n';
  };
};


void solveSRTF(int n, int arrival[], int burst[], int prio[]) {
  for (int i = 0; i < n; i++) {
    cout << arrival[i] << " " << burst[i] << " " << prio[i] << '\n';
  };
};


void solveP(int n, int arrival[], int burst[], int prio[]) {
  for (int i = 0; i < n; i++) {
    cout << arrival[i] << " " << burst[i] << " " << prio[i] << '\n';
  };
};


void solveRR(int n, int arrival[], int burst[], int prio[], int q) {
  for (int i = 0; i < n; i++) {
    cout << arrival[i] << " " << burst[i] << " " << prio[i] << '\n';
  };
};


algo_list hashit(string const& algo) {
  if (algo == "FCFS") return FCFS;
  if (algo == "SJF") return SJF;
  if (algo == "SRTF") return SRTF;
  if (algo == "P") return P;
  if (algo == "RR") return RR;
};