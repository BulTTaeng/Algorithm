#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

vector<pair<int , int> > v[21];

int N,K;

int ans = 4000009;

int currx , curry;

int cal(int minx , int miny , int maxx , int maxy){

	int width = abs(maxx - minx);
	int height = abs(maxy - miny);

	return width * height;
}

void dfs(int minx , int miny ,int maxx , int maxy, int currK, int idx){

	if(currK == K+1){
		ans = min( ans , cal(minx , miny , maxx , maxy));
		return;
	}

	if(minx != 1001 && cal(minx, miny, maxx, maxy) >= ans) {
		return;
	}

	int x1= minx;
	int y1 = miny;

	int x2 = maxx;
	int y2 = maxy;

	currx = v[currK][idx].first;
	curry = v[currK][idx].second;

	minx = min(minx , currx);
	miny = min(miny , curry);

	maxx = max(maxx , currx);
	maxy = max(maxy , curry);

	if(idx +1 == v[currK].size()){
		dfs(minx , miny, maxx , maxy , currK+1 , 0);
	}
	else{
		dfs(minx , miny, maxx , maxy , currK+1 , 0);
		minx = x1;
		miny = y1;
		maxx = x2;
		maxy = y2;
		dfs(minx, miny, maxx , maxy , currK, idx+1);
	}


}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N >> K;
	int x,y,k;

	for(int i =0; i<N; i++){
		cin >> x >> y >>k;
		v[k].push_back({x,y});
	}

	dfs(1001, 1001 , -1001 , -1001 , 1, 0);

	cout << ans;

	return 0;
}
