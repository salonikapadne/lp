#include <iostream>
#include <vector>
#include <algorithm>
#include<climits>
using namespace std;

void SelectionSort(){
    int n;
    cout<<"Enter n:\n";
    cin>>n;
    int arr[100];
    cout<<"Enter array:\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    cout<<"Array Before Sorting: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    
    for(int i=0;i<n-1;i++){
        int min =i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min = j;
            }
        }
        swap(arr[i],arr[min]);
    }
    cout<<"\nArray After Sorting: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

struct Job{
    int id,deadline,profit;
};
bool Compare(Job& a, Job& b){
    return a.profit>b.profit;
}
void jobScheduling(){
    int n;
    cout<<"Enter no of jobs:\n";
    cin>>n;
    Job jobs[100];
    cout<<"Enter jobs(id deadline profit):\n";
    for(int i=0;i<n;i++){
        cin>>jobs[i].id>>jobs[i].deadline>>jobs[i].profit;
    }
    sort(jobs,jobs+n,Compare);
    
    int slots[100]={0};
    int totalprofit =0;
    
    for(int i=0;i<n;i++){
        for(int j=jobs[i].deadline;j>0;j--){
            if(slots[j] == 0){
                slots[j]= jobs[i].id;
                totalprofit+=jobs[i].profit;
                cout<<jobs[i].id<<" ";
                break;
            }
        }
    }
    cout<<"\nTotal profit: "<<totalprofit<<endl;
}

int minDist(int dist[],bool visited[],int V){
    int minVal = INT_MAX, index=-1;
    
    for(int i=0;i<V;i++){
        if(!visited[i] && dist[i]<minVal){
            minVal = dist[i];
            index =i;
        }
    }
    return index;
}

void dijkstra(){
    int V;
    cout<<"Enter no of vertices:\n";
    cin>>V;
    int graph[50][50];
    cout<<"Enter adj matrix:\n";
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cin>>graph[i][j];
        }
    }
    int src;
    cout << "Enter source vertex: ";
    cin >> src;
    int dist[100];
    bool visited[100]={false};
    
    for(int i=0;i<V;i++){
        dist[i]=INT_MAX;
    }
    
    dist[src]=0;
    
    for(int i=0;i<V-1;i++){
        int u = minDist(dist,visited,V);
        if (u==-1)break;
        visited[u]=true;
        
        for(int v=0;v<V;v++){
            if(!visited[v] && dist[u]!=INT_MAX && graph[u][v]!=0 && dist[u] + graph[u][v] < dist[v]){
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    
    cout<<"Vertice Distance:\n";
    for(int i=0;i<V;i++){
        cout<<i<<"\t"<<dist[i]<<"\n";
    }
}
int main(){
    dijkstra();
    jobScheduling();
    SelectionSort();
    return 0;
}