#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

int N , L ,P;
int ans =0;

struct compare_increasing{
    bool operator()(pair<int , int > &p1 , pair<int , int > &p2){
        if(p1.first == p2.first){
            return p1.second > p2.second;
        }
        return p1.first > p2.first;
    }
};

priority_queue<pair<int , int> , vector<pair<int , int>>  ,  compare_increasing> station;
priority_queue<int> fuel;

bool solve();

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N;
    int dis , f;
    for(int i =0; i<N; i++){
        cin >> dis >> f;
        station.push({dis , f});
    }

    cin >> L >> P;

    if(solve()){
        cout << ans;
    }
    else{
        cout << -1;
    }

    return 0;
}

bool solve(){

    int currloc = P;
    bool re = false;

    while(1){

        //cout << currloc <<"\n";

        if(currloc >= L){
            re = true;
            return re;
        }

        while(!station.empty() && station.top().first <= currloc ){ // fill up the fuels
            fuel.push(station.top().second);
            station.pop();
        }

        if(fuel.empty()){ // if we don't have any fuel left
            return false;
        }

        currloc += fuel.top();
        fuel.pop();
        ans++;
    }

    return re;
}
