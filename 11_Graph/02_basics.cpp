// creating and printing graph using adjacency list
#include<bits/stdc++.h>
using namespace std;

class graph{
    public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool direction){
        // direction == 0 -> undirected graph
        // direction == 1 -> directed graph

        // creating an edge from u to v
        adj[u].push_back(v);
        if(direction == 0){
            adj[v].push_back(u);
        }
    }

    void printAdjList(){
        for(auto i: adj){
            cout<< i.first<<"-> ";
            for(auto j:i.second){
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }
};

// counting and printing using vector<vector<int>>
vector<vector<int>> printAdjacency(int n, int m, vector<vector<int>> &edges){
    vector<int> ans[n]; // array of n vector 
    // ans array will store all adjacency nodes corresponding on index
    for(int i=0;i<m;i++){
        int u = edges[i][0];
        int v = edges[i][1];

        ans[u].push_back(v);
        ans[v].push_back(u);
    }

    vector<vector<int>> adj(n);
    for(int i=0;i<n;i++){
        adj[i].push_back(i);

        // entering neightbours
        for(int j=0;j<ans[i].size();j++){
            adj[i].push_back(ans[i][j]);
        }
    }
}

int main(){
    int n;
    cout<<"Enter the number of nodes :"<<endl;
    cin>>n;
    int m;
    cout<<"Enter the number of edges : "<<endl;
    cin>>m;

    graph g;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        // creating an undirected graph
        g.addEdge(u,v,0);
    }
    // printing graph
    g.printAdjList();
}