//min jump to rech end
#include <bits/stdc++.h> 
using namespace std;   
//  Method returns minimum step to reach end of array 
int Solution(int arr[], int N) { 
    bool visit[N]; 
    int distance[N]; 
    vector<int> digit[10]; 
    memset(visit, false, sizeof(visit)); 
  
    //  storing indices of each number in digit vector 
    for (int i = 1; i < N; i++) 
        digit[arr[i]].push_back(i); 
  
    //  for starting index distance will be zero 
    distance[0] = 0; 
    visit[0] = true; 
  
    // Creating a queue and inserting index 0. 
    queue<int> q; 
    q.push(0); 
  
    //  loop untill queue in not empty 
    while(!q.empty()) 
    { 
        // Get an item from queue, q. 
        int idx = q.front();        q.pop(); 
  
        //  If we reached to last index break from loop 
        if (idx == N-1) 
            break; 
  
        // Find value of dequeued index 
        int d = arr[idx]; 
  
        // looping for all indices with value as d. 
        for (int i = 0; i<digit[d].size(); i++) 
        { 
            int nextidx = digit[d][i]; 
            if (!visit[nextidx]) 
            { 
                visit[nextidx] = true; 
                q.push(nextidx); 
  
                //  update the distance of this nextidx 
                distance[nextidx] = distance[idx] + 1; 
            } 
        } 
  
        // clear all indices for digit d, because all 
        // of them are processed 
        digit[d].clear(); 
  
        //  checking condition for previous index 
        if (idx-1 >= 0 && !visit[idx - 1]) 
        { 
            visit[idx - 1] = true; 
            q.push(idx - 1); 
            distance[idx - 1] = distance[idx] + 1; 
        } 
  
        //  checking condition for next index 
        if (idx + 1 < N && !visit[idx + 1]) 
        { 
            visit[idx + 1] = true; 
            q.push(idx + 1); 
            distance[idx + 1] = distance[idx] + 1; 
        } 
    } 
  
    //  N-1th position has the final result 
    return distance[N - 1]; 
} 
  
//  driver code to test above methods 
int main() 
{ 
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 5, 
                 4, 3, 6, 0, 1, 2, 3, 4, 5, 7}; 
    int N = sizeof(arr) / sizeof(int); 
    cout << Solution(arr, N); 
    return 0; 
} 
