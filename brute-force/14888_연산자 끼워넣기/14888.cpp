#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
int op[5];
//+ , - , * , /
vector<int> inp;

int mini = 1000000001;
int maxi = -1000000001;

void dfs(int sum , int loc , int plus , int minus , int mul , int div);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N;
    int temp;

    for(int i =0; i<N; i++){
        cin >> temp;
        inp.push_back(temp);
    }

    for(int i =0; i<4; i++){
        cin >> op[i];
    }

    dfs(inp[0],1,op[0] , op[1] , op[2] , op[3]);

    cout << maxi << "\n";
    cout << mini;

    return 0;
}

void dfs(int sum , int loc , int plus , int minus , int mul , int div){
    if(loc == N){
        mini = min(sum , mini);
        maxi = max(sum , maxi);
    }
    else{
        if(plus != 0){
            dfs(sum + inp[loc] , loc+1 , plus-1 , minus , mul , div);
        }
        if(minus != 0){
            dfs(sum - inp[loc] , loc+1 , plus , minus-1 , mul , div);
        }
        if(mul != 0){
            dfs(sum * inp[loc] , loc+1 , plus, minus , mul-1 , div);
        }
        if(div != 0){
            dfs(sum / inp[loc] , loc+1 , plus , minus , mul , div-1);
        }
    }
}
