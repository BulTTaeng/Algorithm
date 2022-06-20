#include <iostream>
#include <queue>

using namespace std;

struct compare{
    bool operator()(pair<long long  , int> p1 , pair<long long, int> p2){
        if(p1.first == p2.first){
            return p1.second > p2.second;
        }

        return p1.first > p2.first;
    }
};

int N , M;
long long num[100002];
priority_queue<pair<long long , int> , vector<pair<long long , int>> , compare> pq;

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> N;

    for(int  i= 1; i<=N; i++){
        cin >> num[i];
        pq.push({num[i] , i});
    }

    cin >> M;
    int temp, idx;
    long long val;
    pair<long long , int > p;

    for(int i =0; i<M; i++){
        cin >> temp;

        if(temp == 1){
            cin >> idx >> val;
            num[idx] = val;
            pq.push({val , idx});
        }
        else{
            while(true){
                p = pq.top();

                if(p.first == num[p.second]){
                    cout << p.second << "\n";
                    break;
                }
                else{
                    pq.pop();
                }
            }
        }
    }

    return 0;
}
