#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

bool visitS[100001];
bool visitT[100001];
bool visitRS[100001];
bool visitRT[100001];

vector<int> edge[100001];
vector<int> reverseEdge[100001];
vector<int> route;
int ans = -2; // 출발지와 도착지를 빼고 계산해야 함.

int N, M, s,e, S, T;

void dfs(int curr, bool visit[100001]){

	if(visit[curr]){
		return;
	}

	visit[curr] = true;

	for(int i = 0 ;i <edge[curr].size(); i++){
		int next = edge[curr][i];

		if(!visit[next]){
			dfs(next, visit);
		}
	}
}

void dfsR(int curr, bool visit[100001]){

	if(visit[curr]){
		return;
	}

	visit[curr] = true;

	for(int i = 0 ;i <reverseEdge[curr].size(); i++){
		int next = reverseEdge[curr][i];

		if(!visit[next]){
			dfsR(next, visit);
		}
	}
}


int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);

	cin >> N >> M;

	for(int i=0; i<M; i++){
		cin >> s >> e;
		edge[s].push_back(e);
		reverseEdge[e].push_back(s);
	}

	cin >> S >> T;

	memset(visitS, false , sizeof(visitS));
	memset(visitT, false , sizeof(visitT));
	memset(visitRS, false , sizeof(visitRS));
	memset(visitRT, false , sizeof(visitRT));

	visitS[T] = true; //목적지를 한번 visit하고 다시 visit 하지 않기 위해 
	visitT[S] = true; //목적지를 한번 visit하고 다시 visit 하지 않기 위해

	dfs(S, visitS);
	dfs(T , visitT);
	
	dfsR(S, visitRS);
	dfsR(T, visitRT);

	for(int i =1; i<=N; i++){
		if(visitS[i] && visitT[i] && visitRS[i] && visitRT[i]){
			ans++;
		}
	}

	cout << ans;
	return 0;
}
