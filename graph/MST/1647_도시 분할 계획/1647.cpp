#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

struct st{
    int x;
    int y;
    int w;
}typedef st;

struct compare {
	bool operator()(const st& s1, const st& s2) {
		return s1.w > s2.w;
	}
};

priority_queue<st , vector<st> , compare> pq;

int parent[100001];

int N  , M;

int _find(int x);
void _union(int  x, int y);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);


    cin >> N >> M;
    int x, y , w;

    st temp , newone;

    for(int i =0; i<M; i++){
        cin >> x >> y >> w;
        temp.x = x;
        temp.y = y;
        temp.w = w;
        pq.push(temp);
    }

    for(int i =1; i<=N ; i++){
        parent[i] = i;
    }
    
    int ans = 0;
    int lastw = 0;

    while(!pq.empty()){
        x = pq.top().x;
        y= pq.top().y;
        w = pq.top().w;
        pq.pop();

        if(_find(x) != _find(y)){
            ans += w;
            lastw = w;
            _union(x, y);
        }
        
    }

    cout << ans - lastw;
    return 0;

}

int _find(int x ){
    if(parent[x] == x) return x;
    else{
        return parent[x] = _find(parent[x]);
    }
}

void _union(int x , int y){
    x = _find(x);
    y = _find(y);

    parent[y] = x;
}
