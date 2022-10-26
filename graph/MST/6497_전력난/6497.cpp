#include <iostream>
#include <queue>

using namespace std;

struct st{
    int x;
    int y;
    int w;
}typedef st;

struct cmp{
    bool operator()(const st &s1 , const st &s2){
        return s1.w > s2.w;
    }
};

priority_queue<st , vector<st> , cmp>pq;

int N , M;
int parent[200001];

int _find(int x);
void _union(int x , int y);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int x, y , w ;
    long long ans , sum;
    st temp;

    while(true){
        cin >> N >> M;
        ans = 0;
        sum = 0;
        if(N == 0 && M == 0){
            break;
        }

        for(int i = 0 ; i<M; i++){
            cin >> x >> y >> w;
            temp.x = x;
            temp.y = y;
            temp.w = w;
            pq.push(temp);
            sum += w;
        }

        for(int i =0 ; i<N ; i++){
            parent[i] = i;
        }

        while(!pq.empty()){
            x = pq.top().x;
            y = pq.top().y;
            w = pq.top().w;
            pq.pop();

            if(_find(x) != _find(y)){
                ans += w;
            }
            _union(x, y);
        }

        cout << sum-ans << "\n";

    }

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
