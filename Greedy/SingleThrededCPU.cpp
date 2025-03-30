// The Single-Threaded CPU problem on LeetCode requires you to simulate the scheduling of tasks by a single-threaded CPU, following these rules:

// The CPU can process only one task at a time.

// If multiple tasks are available, the CPU picks the task with the shortest processing time.

// If two tasks have the same processing time, the CPU picks the task with the smallest index.

// The CPU becomes idle when there are no tasks to execute.

// Tasks are given as (enqueueTime, processingTime).

// Approach:
// Sort tasks by enqueueTime (so we can process them in order).

// Use a Min-Heap (priority queue) to always pick the shortest available task first.

// Process tasks sequentially, updating the current time.

class Solution {
    public:
        vector<int> getOrder(vector<vector<int>>& tasks) {
            int n = tasks.size();
            vector<int> result;
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
            vector<array<int, 3>> sortedTasks;
            for(int i=0;i<n;i++) {
                tasks[i].push_back(i);   ///adding index in third column
            }
            // Sort tasks by enqueue time
            sort(tasks.begin(), tasks.end());
    
            long long time = tasks[0][0];
            int i = 0; // Index for tasks
           
            while (i < n || !pq.empty()) {
                // Add all tasks that are available at the current time
                while (i < n && tasks[i][0] <= time) {
                    pq.push({tasks[i][1], tasks[i][2]}); // (processingTime, index)
                    i++;
                }
    
                // If no tasks are available, move time forward
                if (pq.empty()) {
                    time = tasks[i][0];
                    continue;
                }
    
                // Get the task with shortest processing time (or smallest index if tie)
                auto [procTime, idx] = pq.top();
                pq.pop();
                result.push_back(idx);
                time += procTime; // Process this task
            }
    
            return result;
        }
    };