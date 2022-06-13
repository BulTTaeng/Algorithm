#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;
int ans = 0;

struct compare_decreasing{
    bool operator()(pair<int , int > &p1 , pair<int , int > &p2){
        if(p1.first == p2.first){
            return p1.second < p2.second;
        }
        return p1.first < p2.first;
    }
};

priority_queue<pair<int , int> , vector<pair<int , int>>  ,  compare_decreasing> pq;
priority_queue<int> pay;


int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N;

    int p ,d;

    for(int i =0; i<N; i++){
        cin >> p >> d;
        pq.push({d,p});
    }

    int day = 10001;

    while(--day){

        while(!pq.empty() && pq.top().first == day){
            pay.push(pq.top().second);
            pq.pop();
        }
        
        if(!pay.empty()){
            ans += pay.top();
            pay.pop();
        }
    }

    cout << ans;
    return 0;
}
