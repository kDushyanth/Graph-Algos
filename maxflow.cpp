class node{
  public:
    int data;
    int w;
    node *next;
    node(int data,int w):data(data),w(w){
        next = NULL;
    }
};
//find max flow in the undirected graph from node 0 to node N-1;
class Solution
{
public:
    void dfs(node *adj[],int src,int dest,vector<bool> &v,int &bcap,bool &found){
        //dest reached => path found
        if(src==dest){
            found = true;
            return;
        }
        v[src] = true;
        for(node *x = adj[src];x!=NULL;x=x->next){
            if(v[x->data]==false && found==false && x->w){
                //bottle neck capacity
                bcap  = min(x->w,bcap);
                dfs(adj,x->data,dest,v,bcap,found);
                //if path found
                if(found){
                    // decrease by bcap
                        x->w -=bcap;
                        for(node *y = adj[x->data];y!=NULL;y = y->next){
                            if(y->data==src){
                                //increase by bcap on reverse edge
                                y->w+=bcap;
                                break;
                            }
                        }
                        return;
                }
            }
        }
    }
    void printer(node *adj[],int v){
        for(int i=0;i<v;i++){
            cout<<i<<"->";
            for(node *x = adj[i];x!=NULL;x=x->next){
                cout<<x->data<<".."<<x->w<<"-";
            }cout<<endl;
        }
    }
    int solve(int N,int M,vector<vector<int>> Edges)
    {
        // code here
        node *adj[N]={0};
        for(int i=0;i<M;i++){
           int u = Edges[i][0]-1,v = Edges[i][1]-1, w = Edges[i][2];
           node *nn;
           //edge: u->v (w) => v->u (w)
           nn = new node(v,w);
           nn->next = adj[u];
           adj[u] = nn;
           nn = new node(u,w);
           nn->next = adj[v];
           adj[v] = nn;
        }
        
        int bcap=0;
        int flow=0;
        bool found = true;
        int counter=0;
        //continue until path is found
        while(found){
            //initial bcap is infinity
            bcap = INT_MAX; found = false;
            vector<bool> v(N,false);
            v[0] = true;
            //find the path
            dfs(adj,0,N-1,v,bcap,found);
            //if path found, increase the flow by bcap
            if(found)flow+=bcap;
        }
        return flow;
    }
};