#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N;
long long num[1000002];

queue<long long> q;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N;
    memset(num , 0 , sizeof(num));

    for(int i =0; i<10; i++){
        q.push(i);
    }

    if(N ==0){
        cout << 0;
        return 0;
    }

    int index = 0;
    long long temp;
    int last_num = 0;
    long long next_num = 0;

    while(!q.empty()){
        temp = q.front();
        q.pop();
        last_num = temp%10;
        num[index] = temp;
        index++;

        for(int i =0;i <last_num; i++){
            next_num = temp*10 + i;
            q.push(next_num);
        }
    }

    if(num[N] != 0){
        cout << num[N];
    }
    else{
        cout << -1;
    }

}
