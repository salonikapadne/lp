#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

vector<int> adj[100];
bool visitedIter[100];
bool visitedRec[100];

void DFSRec(int node){
    visitedRec[node]=true;
    cout<<node<<" ";

    for(int i=0;i<adj[node].size();i++){
        int next = adj[node][i];
        if(!visitedRec[next]){
            DFSRec(next);
        }
    }
}
void DFSIter(int start){
    stack<int> s;
    s.push(start);

    while(!s.empty()){
        int node = s.top();
        s.pop();

        if(!visitedIter[node]){
            visitedIter[node]=true;
            cout<<node<<" ";

            for(int i=adj[node].size()-1;i>=0;i--){
                int next = adj[node][i];
                if(!visitedIter[next]){
                    s.push(next);
                }
            }
        }
    }
}

void BFS(int start,int V){
    bool visitedBFS[100]={false};
    queue<int> q;

    visitedBFS[start]=true;
    q.push(start);

    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout<<node<<" ";

        for(int i=0;i<adj[node].size();i++){
            int next = adj[node][i];
            if(!visitedBFS[next]){
                visitedBFS[next] = true;
                q.push(next);
            }
        }
    }
}

int main(){
    int V,E;
    cout<<"Enter V and E:";
    cin>>V>>E;
    cout<<"Enter edges:";
    for(int i=0;i<E;i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout<<"DFSIter:";
    for(int i=0;i<V;i++){
        if(!visitedIter[i]){
            DFSIter(i);
        }
    }
    cout<<"\nDFSRec:";
    for(int i=0;i<V;i++){
        if(!visitedRec[i]){
            DFSRec(i);
        }
    }
    cout<<"\nBFS:";
    BFS(0,V);
    return 0;
}