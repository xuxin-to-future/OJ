#include <iostream>
using namespace std;

int func(int s, int num, int cnt){
    if(cnt == 0){
        if(num == 0) return 1;
        return 0;
    }
    int ans = 0;
    for(int i = s; i <= num; i++){
        ans += func(i, num - i, cnt - 1);
    }
    return ans;
}

int main(){
    int n, m;
    cin >> n >> m;
    cout << func(1, n, m) << endl;

    return 0;
}