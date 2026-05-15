#include <iostream>
using namespace std;

int N;
bool col[50];
bool diag1[100];
bool diag2[100];
bool board[50][50];
bool canPlaceMore(int row) {
    int remaining = N - row;

    int freeCols = 0;
    for (int c = 0; c < N; c++) {
        if (!col[c]) freeCols++;
    }

    return freeCols >= remaining;
}
void solve(int row){
    if (!canPlaceMore(row)) return;
    if(row==N){
        cout<<"Solution:\n";
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cout<<board[i][j]<<" ";
            }
            cout<<"\n";
        }
        return;
    }
    

    for(int c=0;c<N;c++){
        if(!col[c] && !diag1[row-c+N] && !diag2[row+c]){
            board[row][c] = 1;
            col[c] = diag1[row-c+N] = diag2[row+c] = true;
            solve(row+1);

            board[row][c] = 0;
            col[c] = diag1[row-c+N] = diag2[row+c] = false;
        }
    }
}

int main(){
    cout<<"Enter the number of queens: ";
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            board[i][j] = 0;
        }
    }
    solve(0);
    return 0;
}