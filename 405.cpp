#include <iostream>
#include <queue>
using namespace std;

struct node{
    int x, y;
};

int n, m, k, ans;
char mmap[3005][3005];
int mark[3005][3005];
int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
queue<node> q;

void func(int x, int y){
    for(int i = 0 ;i < 4; i++){
        int tx = x + dir[i][0];
        int ty = y + dir[i][1];
        if(tx == 0 || ty == 0 || tx >n || ty > m) continue;
        if(mark[tx][ty] == 0 && mmap[x][y] != mmap[tx][ty])
        {
            ans++;
            mark[tx][ty] = 1;
            q.push({tx, ty});
            func(tx, ty);
        }
    }
}

int main(){
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> mmap[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(mark[i][j] == 0){
                ans = 1;
                mark[i][j] = 1;
                q.push({i, j});
                func(i, j);
                while(!q.empty()){
                    node tmp = q.front();
                    q.pop();
                    mark[tmp.x][tmp.y] = ans;
                }
                ans = 0;
            }
        }
    }
    for(int i = 0; i < k; i++){
        int t1, t2;
        cin >> t1 >> t2;
        cout <<mark[t1][t2] << endl;
    }
    return 0;
}