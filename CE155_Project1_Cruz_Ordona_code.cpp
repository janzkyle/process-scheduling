#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

enum algo_list {
  FCFS,
  SJF,
  SRTF,
  P,
  RR
};

algo_list hashit(string const& algo);

void solveFCFS(int n, vector<int> arrival, vector<int> burst);
void solveSJF(int n, vector<int> arrival, vector<int> burst, vector<int> prio);
void solveSRTF(int n, vector<int> arrival, vector<int> burst, vector<int> prio);
void solveP(int n, vector<int> arrival, vector<int> burst, vector<int> prio);
void solveRR(int n, vector<int> arrival, vector<int> burst, vector<int> prio, int q);

int main() {
  string line;
  int temp;
  ifstream myfile("CE155_Project1_Cruz_Ordona_testfile.txt");

  if(myfile.is_open()) {
    int num_test_cases;
    myfile >> num_test_cases;

    for(int test_case = 1; test_case <= num_test_cases; test_case++) {
      // cout << test_case << endl;
      
      int num_processes;
      string algo;
      int q;
      vector<int> arrival_times;
      vector<int> burst_times;
      vector<int> priority_list;

      myfile >> num_processes;
      myfile >> algo;
      // cout << num_processes << " " << algo << endl;

      if(algo == "RR") {
        myfile >> q;
        // cout << " " << q << endl;
      }

      for(int p = 0; p < num_processes; p++) {
        myfile >> temp;
        arrival_times.push_back(temp);
        myfile >> temp;
        burst_times.push_back(temp);
        myfile >> temp;
        priority_list.push_back(temp);
        // cout << arrival_times[p] << " " << burst_times[p] << " " << priority_list[p] << endl;
      }

      switch(hashit(algo)) {
        case FCFS:
          solveFCFS(num_processes, arrival_times, burst_times);
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


void solveFCFS(int n, vector<int> arrival, vector<int> burst) {
  vector<int> sorted_arrival(arrival);
  sort(sorted_arrival.begin(), sorted_arrival.end());
  int time_elapsed = sorted_arrival.at(0);
  for (int i = 0; i < n; i++) {
    vector<int>::iterator it = find(arrival.begin(), arrival.end(), sorted_arrival.at(i));
    int index = distance(arrival.begin(), it);
    time_elapsed = max(arrival.at(index), time_elapsed);

    cout << time_elapsed << " " << index + 1 << " " << burst.at(index) << "X" << endl;

    time_elapsed += burst.at(index);
    arrival.at(index) = -1;
  };
};


void solveSJF(int n, vector<int> arrival, vector<int> burst, vector<int> prio) {
  for (int i = 0; i < n; i++) {
    cout << arrival.at(i) << " " << burst.at(i) << " " << prio.at(i) << '\n';
  };
};


void solveSRTF(int n, vector<int> arrival, vector<int> burst, vector<int> prio) {
  for (int i = 0; i < n; i++) {
    cout << arrival.at(i) << " " << burst.at(i) << " " << prio.at(i) << '\n';
  };
};


void solveP(int n, vector<int> arrival, vector<int> burst, vector<int> prio) {
  for (int i = 0; i < n; i++) {
    cout << arrival.at(i) << " " << burst.at(i) << " " << prio.at(i) << '\n';
  };
};


void solveRR(int n, vector<int> arrival, vector<int> burst, vector<int> prio, int q) {
  for (int i = 0; i < n; i++) {
    cout << arrival.at(i) << " " << burst.at(i) << " " << prio.at(i) << '\n';
  };
};


algo_list hashit(string const& algo) {
  if (algo == "FCFS") return FCFS;
  if (algo == "SJF") return SJF;
  if (algo == "SRTF") return SRTF;
  if (algo == "P") return P;
  if (algo == "RR") return RR;
};