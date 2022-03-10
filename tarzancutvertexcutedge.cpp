class Solution {
public:
    void get_cut_edges(vector<vector<int>> &adj,int n,vector<bool> &visit, vector<vector<int>>& cut_edges,vector<int> &low,vector<int> &parent,int v,int &time,vector<int> &disc){
        visit[v] = true;
        time++;
        disc[v] = low[v] = time;
        for(auto x: adj[v]){
            if(visit[x] && parent[v]!=x){
                low[v] = min(low[v],disc[x]);//back-edge
            }
            if(!visit[x]){
                parent[x] = v;
                get_cut_edges(adj,n,visit,cut_edges,low,parent,x,time,disc);
                low[v] = min(low[v],low[x]);//tree-edge
                if(disc[v]<low[x]){
                    cut_edges.push_back({v,x});//v-x is cut edge
                }
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto x:connections){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        
        vector<vector<int>> cut_edges;
        vector<bool> visit(n,false);
        vector<int> low(n,0),parent(n,-1),disc(n,0);
        int time = 0;
        
        for(int i=0;i<n;i++)if(!visit[i])get_cut_edges(adj,n,visit,cut_edges,low,parent,i,time,disc);
        
        return cut_edges;
    }
};
