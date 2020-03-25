#include <iostream>
#include <algorithm>
using namespace std;

int n, m, ans = 1, mmax;
char mmap[105][105];
int dir[4][2] = {0, 1, 1,0,0,-1,-1,0};

void func(int x, int y){
    for(int i = 0; i < 4; i++){
        int tx = x + dir[i][0];
        int ty = y + dir[i][1];
        if(mmap[tx][ty] == '1'){
            ans++;
            mmap[tx][ty] = '0';
            func(tx, ty);
        }
    }
}


int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> mmap[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(mmap[i][j] == '1'){
                mmap[i][j] = '0';
                func(i, j);
                mmax = max(mmax, ans);
                ans = 1;
            }
        }
    }
    cout << mmax << endl;
    return 0;
}