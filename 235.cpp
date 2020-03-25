#include <iostream>
using namespace std;

int n, num[15], cnt;

int func(int s){
    for(int i = s; i <= n; i++){
        num[cnt++] = i;
        for(int j = 0; j < cnt; j++){
            if(j) cout << " ";
            cout << num[j];
        }
        cout << endl;
        func(i + 1);
        cnt--;
    }
}

int main(){
    cin >> n;
    cout << func(1);
    return 0;
}