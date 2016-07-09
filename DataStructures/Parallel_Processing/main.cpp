//
//  main.cpp
//  Parallel_Processing
//
//  Created by Nitesh Thali on 7/8/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.
/*
 Ref: https://www.coursera.org/learn/data-structures/home/week/3
 You have a program which is parallelized and uses n independent threads to process the given list of m jobs. Threads take jobs in the order they are given in the input. If there is a free thread, it immediately takes the next job from the list. If a thread has started processing a job, it doesn't interrupt or stop until it nishes processing the job. If several threads try to take jobs from the list simultaneously, the thread with smaller index takes the job. For each job you know exactly how long will it take any thread to process this job, and this time is the same for all the threads. You need to determine for each job which thread will process it and when will it start processing.
 
 Input Format. The rst line of the input contains integers n and m. The second line contains m integers ti | the times in seconds it takes any thread to process i-th job. The times are given in the same order
 
 Output Format. Output exactly m lines. i-th line (0-based index is used) should contain two space-
 separated integers | the 0-based index of the thread which will process the i-th job and the time in
 seconds when it will start processing that job.
 
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>


using std::vector;
using std::cin;
using std::cout;

using namespace std;

class JobQueue {
private:
    int num_workers_;
    vector<int> jobs_;
    
    vector<int> assigned_workers_;
    vector<long long> start_times_;
    
    void WriteResponse() const {
        for (int i = 0; i < jobs_.size(); ++i) {
            cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
        }
    }
    
    void ReadData() {
        int m;
        cin >> num_workers_ >> m;
        jobs_.resize(m);
        for(int i = 0; i < m; ++i)
            cin >> jobs_[i];
    }
   
    void AssignJobs() {
        // TODO: replace this code with a faster algorithm.
        assigned_workers_.resize(jobs_.size());
        start_times_.resize(jobs_.size());
        priority_queue < pair<int, int>, vector <pair<int, int> >, JobQueue > pq;
        
        /* Brute force implementation, O(mn), nice idea, instead of subtracting time think interms of adding time and then finding the worker with the least time as nextWorker*/
        /*
        vector<long long> next_free_time(num_workers_, 0);
        
        for (int i = 0; i < jobs_.size(); ++i) {
            int duration = jobs_[i];
            int next_worker = 0;
            for (int j = 0; j < num_workers_; ++j) {
                if (next_free_time[j] < next_free_time[next_worker])
                    next_worker = j;
            }
            assigned_workers_[i] = next_worker;
            start_times_[i] = next_free_time[next_worker];
            next_free_time[next_worker] += duration;
        }
        */
        /* We can improve this running time by using min-heap and replacing the inner code which takes linear time to logrithmic time. So time complexity of this algorithm will be m*log(n)*/
        
        for(int i=0; i<num_workers_; i++)
        {
            assigned_workers_[i] = i;
            start_times_[i] = 0 ;
            pq.push(make_pair(i, jobs_[i]));
        }
        
        for(int i=num_workers_; i<(int)jobs_.size(); i++)
        {
            pair<int, int> current = pq.top();
            assigned_workers_[i] = current.first;
            start_times_[i] = current.second;
            pq.pop();
            pq.push(make_pair(current.first, current.second + jobs_[i]));
        }
        
        
    }
    
public:
    void Solve() {
        ReadData();
        AssignJobs();
        WriteResponse();
    }
    bool operator()(const pair<int,int> &n1, const pair<int,int> &n2) {
        if (n1.second > n2.second)
            return true;
        else if (n1.second == n2.second)
            return n1.first > n2.first;
        return false;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    JobQueue job_queue;
    job_queue.Solve();
    return 0;
    
}
/*
 Sample Input Output
 Input:
 2 5
 1 2 3 4 5
 Output:
 
 0 0
 1 0
 0 1
 1 2
 0 4
 explanation: 
 1. The two threads try to simultaneously take jobs from the list, so thread with index 0 actually
 takes the rst job and starts working on it at the moment 0.
 2. The thread with index 1 takes the second job and starts working on it also at the moment 0.
 3. After 1 second, thread 0 is done with the rst job and takes the third job from the list, and starts
 processing it immediately at time 1.
 4. One second later, thread 1 is done with the second job and takes the fourth job from the list, and
 starts processing it immediately at time 2.
 5. Finally, after 2 more seconds, thread 0 is done with the third job and takes the fth job from the
 list, and starts processing it immediately at time 4.
 */
