#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N;
priority_queue<long long , vector<long long> , greater<long long>> pq;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N;
    long long temp;

    for(int i =0; i<N; i++){
        cin >> temp;
        pq.push(temp);
    }

    for(int i =N; i<N*N; i++){
        cin >> temp;
        if(pq.top() < temp){
            pq.pop();
            pq.push(temp);
        }
    }

    cout << pq.top();
    return 0;
}  
