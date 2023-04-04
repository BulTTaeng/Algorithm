#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int N;
vector<int> v[58];
int c[58][58]; //capacity
int f[58][58]; //flow
int p[58]; //parent

int ans = 0;

#define INF 987654321

void solve(){
  int start = 0;
  int end = 'Z'-'A';


  while (true) {
		memset(p, -1, sizeof(p));
		queue<int> q;
		q.push(start);
 
		while (!q.empty()) { //capacity가 빈 경로 찾기
			int cur = q.front();
			q.pop();
 
			if (cur == end) {
				break;
			}
 
			for (int i = 0; i < v[cur].size(); i++) {
				int next = v[cur][i];
 
				if (p[next] == -1 && c[cur][next] - f[cur][next] > 0) {
					q.push(next);
					p[next] = cur;
				}
			}
		}
 
		if (p[end] == -1) { //더 이상 유량을 더 보낼 수 있는 경로가 없음!
			break;
		}
 
		int minFlow = INF;
		for (int i = end; i != start; i = p[i]) { //보낼 수 있는 최대 유량 찾기!
			minFlow = min(minFlow, c[p[i]][i] - f[p[i]][i]);
		}

    //minFlow만큼 유량을 보내주고 
    // 음수 간선과 양수 간선에 minflow 차감
		for (int i = end; i != start; i = p[i]) {
			f[p[i]][i] += minFlow;
			f[i][p[i]] -= minFlow;
		}
 
		ans += minFlow;
	}
  
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> N;

  memset(c , 0 , sizeof(c));
  memset(f , 0 , sizeof(f));
  
  char a , b;
  int ff;
  int aa, bb;
  
  for(int i =0; i<N; i++){
    cin >> a >> b >> ff;
    aa = a -'A';
    bb = b -'A';
    c[aa][bb] += ff;
    c[bb][aa] += ff;
    v[aa].push_back(bb);
    v[bb].push_back(aa);
  }

  solve();

  cout << ans;
  return 0;
}
