#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N;
vector<int> v;
bool visit[2000001];

void dfs(int num , int index);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int temp;

    memset(visit ,false ,sizeof(visit));

    cin >> N;

    for(int i =0; i<N; i++){
        cin >> temp;
        v.push_back(temp);
    }

    dfs(0,0);

    for(int i =0; i<2000001; i++){
        if(!visit[i]){
            cout << i;
            break;
        }
    }

    return 0;
}

void dfs(int num , int index){

    visit[num] = true;

    if(index == N){
        return;
    }

    dfs(num+v[index] , index+1);
    dfs(num , index+1);

}
