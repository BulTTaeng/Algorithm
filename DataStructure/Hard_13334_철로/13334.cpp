#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

struct compare{
    bool operator()(pair<int , int> &x , pair<int , int> &y){
        if(x.second == y.second){
            return x.first > y.first;
        }
        return x.second > y.second;
    }
};


priority_queue<pair<int , int> , vector <pair<int , int >> , compare > pq;
priority_queue<pair<int , int> , vector <pair<int , int >> , compare > inrange;

int N;
int d;

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> N;
    int x, y;

    for(int i =0; i<N ; i++){
        cin >> x >> y;
        if(x < y){
        pq.push({x,y});
        }
        else{
            pq.push({y,x});
        }
    }

    cin >> d;
    pair<int , int> p;
    int end;

    int ans = 0;
    int t = 0;
    
    
    
    while(!pq.empty()){
        
        end = pq.top().second;    

        while(!pq.empty()){
            if(pq.top().second - pq.top().first > d){
                pq.pop();
            }
            else if(pq.top().second <= end){
                inrange.push({pq.top().second , pq.top().first});
                pq.pop();
            }
            else{
                break;
            }
        }

        while(!inrange.empty()){
            if(inrange.top().second < end-d){
                inrange.pop();
            }
            else{
                break;
            }
        }

        
        t = inrange.size();
        ans = max(ans , t);

    }

    cout << ans;
    return 0;
}
