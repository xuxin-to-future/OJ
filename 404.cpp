#include <iostream>
using namespace std;

int sx, sy, n, m, ans = 1;
char mmap[3005][3005];
char mark[3005][3005];
int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};

void func(int x, int y){
    for(int i = 0 ; i < 4; i++){
        int tx = x + dir[i][0];
        int ty = y + dir[i][1];
        if(tx == 0 || ty == 0 || tx >n || ty > m) continue;
        if(mmap[tx][ty] != mmap[x][y] && mark[tx][ty] == 0){
            mark[tx][ty] = 1;
            ans++;
            func(tx, ty);
        }
    }
}

int main(){
    cin >>n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> mmap[i][j];
        }
    }
    cin >> sx >> sy;
    mark[sx][sy] = 1;
    func(sx, sy);
    cout << ans << endl;
    return 0;
}