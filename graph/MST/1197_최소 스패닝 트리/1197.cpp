#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

vector<int> v;

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

priority_queue<st , vector<st> , compare>pq;
int N , M;

int root[10001];
bool visit[10001];

int _find(int x);
void _union(int x , int y );

int main(){
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  cin >> N >> M;

  int x , y , w;
  st temp;
  
  for(int i =0; i<M; i++){
    cin >> x >> y >> w;
    temp.x = x;
    temp.y = y;
    temp.w = w;
    pq.push(temp);
  }

  for(int i =1 ; i<=N ; i++){
    root[i] = i;
  }

  memset(visit ,false ,sizeof(visit));
  
  int num = 0;
  long long ans = 0;

  
  for(int k= 0; k<M; k++){
    x = pq.top().x;
    y = pq.top().y;
    w = pq.top().w;
    pq.pop();
      
      if(_find(x) != _find(y)){
        ans += w;
        _union(x,y);
      }
      
  }
  
  cout << ans;
  return 0;
}

int _find(int x){
    if(root[x] == x) return x;
    else{
        return root[x] = _find(root[x]);
    }
}

void _union(int x , int y ){
    x = _find(x);
    y = _find(y);

    root[y] = x;
}
