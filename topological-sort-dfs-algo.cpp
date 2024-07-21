void dfs(vector<vector<int>> &adj, int src, vector<int> &visit, bool &hasCycle, vector<int> &order) {
    visit[src] = 1; // visiting is in progress

    for(int &v : adj[src]) { // src -> v
        if (!visit[v]) {
            dfs(adj, v, visit, hasCycle, order);
        } else if (visit[v] == 1) {
            hasCycle = true;
        }
    }

    visit[src] = 2; // visiting is done
    order.push_back(src);
}

/* Topological sort in a DAG - DFS algo */
vector<int> findOrder(int courses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(courses);

    for(auto &prerequisite: prerequisites) {
        adj[prerequisite[1]].push_back(prerequisite[0]);
    }

    vector<int> visit(courses, 0);
    vector<int> order;
    bool hasCycle = false;

    for(int i = 0; i < courses; i++) {
        if (!visit[i]) {
            dfs(adj, i, visit, hasCycle, order);

            if (hasCycle) {
                return {};
            }
        }
    }

    reverse(order.begin(), order.end());

    return order;
}
