//priority queue solve
//1.812ms

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

typedef long long ll;

int N , L;
ll inp[5000002];

struct compare{
    bool operator()(const pair<ll,int> x , const pair<ll,int> y){
        return x.first > y.first;
    }
};

priority_queue<pair<ll , int>, vector<pair<ll,int>> , compare> pq;


int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> N >> L;

    for(int i =1 ; i<= N ; i++){
        cin >> inp[i];
    }
    
    int s;

    for(int i =1 ; i<=N; i++){
        s = i-L+1;
        s = max(1, s);
        pq.push({inp[i] , i});

        while(!pq.empty() && pq.top().second <s){
            pq.pop();
        }

        cout << pq.top().first << " ";
    }

    return 0;
}
