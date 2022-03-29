#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N;
vector<pair<int , int>> v;

bool visit[12];

int mini = 987654321;

void dfs(int sour , int bit , int num);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N;

    int x, y;

    for(int i =0; i<N; i++){
        cin >> x >> y;
        v.push_back({x,y});
    }

    dfs(1 , 0 ,0);
    
    cout << mini;
    return 0;
}

void dfs(int sour , int bit , int num){
    

    if(num != 0 && bit !=0 && sour != 0){
        mini = min(mini , abs(sour - bit));
    }

    if(num == N){
        return;
    }

    
    
        dfs(sour * v[num].first , bit+v[num].second , num+1);
        dfs(sour , bit, num+1);
    
    

}
