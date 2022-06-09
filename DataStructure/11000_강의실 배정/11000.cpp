#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N;

struct compare_increasing{
    bool operator()(pair<long long , long long > &p1 , pair<long long , long long > &p2){
        if(p1.first == p2.first){
            return p1.second > p2.second;
        }
        return p1.first > p2.first;
    }
};

priority_queue<pair <long long , long long> , vector<pair<long long , long long>> , compare_increasing>pq;
priority_queue<long long , vector<long long>, greater<>> endtime;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N;
    long long s, t;
    for(int i =0; i<N; i++){
        cin >> s >> t;
        pq.push({s,t});
    }

    while(!pq.empty()){
        s = pq.top().first;
        t = pq.top().second;
        pq.pop();

        if(endtime.empty()){
            endtime.push(t);
        }
        else{
            if(endtime.top() <= s){
                endtime.pop();
                endtime.push(t);
            }
            else{
                endtime.push(t);
            }
        }
    }

    cout << endtime.size();
    return 0;

}
