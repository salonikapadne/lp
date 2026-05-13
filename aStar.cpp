#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
using namespace std;

struct Node{
    int x,y,g,h;
    vector<pair<int,int>> path;

    Node(int x,int y,int g,int h,vector<pair<int,int>> path):x(x),y(y),g(g),h(h),path(path){}

    int f()const{return g+h;}
};

struct Compare{
    bool operator()(const Node& a,const Node& b){
        return a.f()>b.f();
    }
};

int heuristic(int x,int y,int gx,int gy){
    return abs(x-gx)+abs(y-gy);
}

bool aStar(vector<vector<int>>& grid,pair<int,int> start, pair<int,int> goal){
    int n = grid.size(), m = grid[0].size();

    vector<vector<bool>> closed(n,vector<bool>(m,false));
    vector<vector<int>> cost(n,vector<int>(m,INT_MAX));

    priority_queue<Node,vector<Node>,Compare> open;

    vector<pair<int,int>> startPath = {start};
    open.push(Node(start.first,start.second,0,heuristic(start.first,start.second,goal.first,goal.second),startPath));

    cost[start.first][start.second] = 0;

    int dx[]={-1,1,0,0};
    int dy[]={0,0,-1,1};

    while(!open.empty()){
        Node cur = open.top();
        open.pop();

        int x = cur.x, y = cur.y;

        if(closed[x][y])continue;
        closed[x][y] = true;

        if(x==goal.first && y==goal.second){
            cout<<"Result:\n";
            for(auto& p:cur.path){
                cout<<"("<<p.first<<","<<p.second<<") ";
            }
            cout<<"\nPath :"<<cur.g<<"\n";
            return true;
        }
        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];

            if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]==0){
                int newCost = cur.g + 1;
                if(newCost<cost[nx][ny]){
                    cost[nx][ny] = newCost;
                    vector<pair<int,int>> newPath = cur.path;
                    newPath.push_back({nx,ny});
                    open.push(Node(nx,ny,newCost,heuristic(nx,ny,goal.first,goal.second),newPath));
                
                }
            }
        }
    }
    cout<<"No path found\n";
    return false;
}

int main(){
    int n,m;
    cout<<"Enter grid size (n m): ";
    cin>>n>>m;
    vector<vector<int>> grid(n,vector<int>(m));
    cout<<"Enter grid (0 for open, 1 for wall):\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    int sx,sy,gx,gy;
    cout<<"Enter start (x y): ";
    cin>>sx>>sy;
    cout<<"Enter goal (x y): ";
    cin>>gx>>gy;
    aStar(grid,{sx,sy},{gx,gy});
    return 0;
}