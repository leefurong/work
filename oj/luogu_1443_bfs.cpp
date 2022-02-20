#include<queue>
#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;
struct coord{
    int x, y;
    coord(int _x, int _y){
        x=_x;
        y=_y;
    }
};

int m, n, x, y;

int steps[401][401];

void print(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cout << left<<setw(5)<<steps[i][j];
        }
        cout <<endl;
    }
}
void bfs(int x1, int y1){
    memset(steps, -1, sizeof(steps));
    queue<coord> q;
    q.push(coord(x1, y1));
    steps[x1][y1] = 0;

    while(!q.empty()){
        coord pos = q.front();q.pop();

        for (int dx=-2; dx<=2; dx++){
            for (int dy=-2; dy<=2; dy++){
                if(dx!=0 && dy!=0 && abs(dx)!=abs(dy)){
                    int next_x = pos.x+dx;
                    int next_y = pos.y+dy;
                    if (steps[next_x][next_y]==-1 && next_x>=1 && next_y>=1 && next_x<=n && next_y<=m){
                        q.push(coord(next_x, next_y));
                        steps[next_x][next_y] = steps[pos.x][pos.y]+1;
                    }
                }
            }
        }
    }
}

int main(){
    cin >> n>> m>>x>>y;
    bfs(x, y);
    print();
}