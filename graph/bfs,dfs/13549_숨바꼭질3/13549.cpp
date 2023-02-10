#include <iostream>
#include <deque>
#include <cstring>

bool visit[100001];

using namespace std;

int N , K;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    deque<pair<int , int>> dq;
    cin >> N >> K;

    dq.push_front(make_pair(N, 0));
    int n , d;
    int nx;

    memset(visit ,false ,sizeof(visit));

    while(!dq.empty()){
        n = dq.front().first;
        d = dq.front().second;
        dq.pop_front();

        visit[n] = true;

        if(n == K){
            cout << d;
            break;
        }

        nx  = n*2;

        if(nx >=0 && nx<= 100000){
            if(!visit[nx]){
                dq.push_front(make_pair(nx, d));
            }
        }

        nx = n +1;

        if(nx >=0 && nx<= 100000){
            if(!visit[nx]){
                dq.push_back(make_pair(nx, d+1));
            }
        }

        nx = n -1;

        if(nx >=0 && nx<= 100000){
            if(!visit[nx]){
                dq.push_back(make_pair(nx, d+1));
            }
        }
    }

    return 0;
}
