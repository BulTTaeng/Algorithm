#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N , K;
int c = 0;
string ans = "";

void dfs(int num , string str);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N >> K;

    for(int i = 1 ; i<=3; i++){
        dfs(i , to_string(i));
    }

    
    if(ans.empty()){
        cout << -1;
    }
    else{
        cout << ans;
    }
    return 0;
}

void dfs(int num , string str){

    if(!ans.empty()){
        //cout << str << " ";
        return;
    }

    if(num > N) return;
    
    if(num == N){
        c++;

        if(c == K){
            ans = str;
            return;
        }
    }

    for(int i =1; i<=3; i++){
        dfs(num + i , str+"+" + to_string(i));
    }
}
