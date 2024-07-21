/* 
Topological sort in a DAG - Kahn's algo 
https://www.geeksforgeeks.org/topological-sorting-indegree-based-solution/
*/
vector<int> findOrder(int courses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(courses);
    vector<int> indegree(courses, 0);

    for(auto &prerequisite: prerequisites) {
        adj[prerequisite[1]].push_back(prerequisite[0]);
        indegree[prerequisite[0]]++;
    }

    queue<int> q;
    vector<int> order;

    for(int i = 0; i < courses; i++) {
        if (!indegree[i]) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int front = q.front(); q.pop();
        order.push_back(front);

        for(int &v : adj[front]) {
            indegree[v]--;

            if(!indegree[v]) {
                q.push(v);
            }
        }
    }

    if(order.size() != courses) {
        return {};
    }

    return order;
}
