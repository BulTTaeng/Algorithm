#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

int N;
pair<double , double> inp[101];

struct st{
    double x;
    double y;
    double dis;
}typedef st;

struct cmp{
    bool operator()(const st &s1 , const st &s2){
        return s1.dis > s2.dis;
    }
};

priority_queue<st , vector<st> , cmp> pq; 

int parent[101];

int _find(int x);
void _union(int x, int y);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N;

    double x , y , dis;

    for(int i =0; i<N; i++){
        cin >> inp[i].first >> inp[i].second;
    }
    st temp;

    for(int i =0; i<N; i++){
        for(int j =i+1; j <N; j++){
            x = (inp[i].first - inp[j].first) * (inp[i].first - inp[j].first);
            y  = (inp[i].second - inp[j].second) * (inp[i].second - inp[j].second);
            dis = sqrt(x+y);

            temp.x = i;
            temp.y = j;
            temp.dis = dis;
            pq.push(temp);
        }
    }

    for(int i =0; i<N; i++){
        parent[i] = i;
    }

    double ans  = 0;

    while(!pq.empty()){
        x = pq.top().x;
        y = pq.top().y;
        dis = pq.top().dis;
        pq.pop();

        if(_find(x) != _find(y)){
            ans += dis;
            _union(x, y);
        }
    }

    cout << fixed;
    cout.precision(2);
    cout << ans;

    return 0;
}

int _find(int x){
    if( parent[x] == x) return x;
    else{
        return parent[x] = _find(parent[x]);
    }
}

void _union(int x , int y){
    x = _find(x);
    y = _find(y);

    parent[y] = x; 
}
