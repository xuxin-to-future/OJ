#include <iostream>
using namespace std;

int num[10] = {0, 1, 3, 9, 27, 81, 243, 729};
char ans[750][750];

void func(int x, int y, int n){
    if(n == 1) {
        ans[x][y] = 'x';
        return;
    }
    func(x, y, n - 1);
    func(x, y + num[n] / 3 * 2, n - 1);
    func(x + num[n] / 3 * 2, y, n - 1);
    func(x + num[n] / 3 * 2, y + num[n] / 3 * 2, n - 1);
    func(x + num[n] / 3, y + num[n] / 3, n - 1);
}

int main(){
    func(1, 1, 7);
    int n;
    while(cin >> n){
        if(n == -1) break;
        for(int i = 1; i <= num[n]; i++){
            for(int j = 1; j <= num[n]; j++){
                if(ans[i][j] == 'x'){
                    cout << 'x';
                }else{
                    cout << " ";
                }
            }
            cout << endl;
        }
        cout << "-" << endl;
    }
    return 0;
}