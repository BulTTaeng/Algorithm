#include<iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int N, M , a,b,c;
vector<pair<int, int>> v[10001];

bool visit[10001][10001];
int mini = 1000000002;
long long ans =0;

#define INF 1000000002


bool dij(int lim){
	priority_queue<pair<int,int> , vector<pair<int,int>> , greater<>> pq;
	memset(visit , false, sizeof(visit));

	pq.push({0, 1});

	int cost,curr,ncost,next;

	while(!pq.empty()){
		cost = pq.top().first;
		curr = pq.top().second;
		pq.pop();

		for(int i =0; i<v[curr].size(); i++){
			ncost = v[curr][i].first;
			next = v[curr][i].second;

			if(ncost <= lim){
				if(next == N) return true;
				if(!visit[next][curr] && !visit[curr][next]){
					pq.push({ncost, next});
					visit[next][curr] = true;
					visit[curr][next] = true;
				}
			}

		}
	}

	return false;
}

void binary(){
	int start = 1;
	int end = 1000000001;
	int mid;

	while(start<=end){
		mid = (start+end)/2;

		if(dij(mid)){
			mini = min(mini , mid);
			end = mid-1;
		}
		else{
			start = mid+1;
		}
	}
}

bool isPrime(int target){
	int lim = sqrt(target);

	for(int i=2; i<=lim+1; i++){
		if(target % i == 0) return false;
	}

	return true;
}

int main(int argc, char** argv)
{
	cin >> N >> M;

	for(int i =0; i<M; i++){
		cin >>a >> b >> c;
		v[b].push_back({c,a});
		v[a].push_back({c,b});
	}

	binary();

	mini++;

	for(long long i =mini;; i++){
		if(isPrime(i)){
			ans = i;
			break;
		}
	}

	cout << ans;

	return 0;
}
