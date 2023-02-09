#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

int N , M , K;
vector<int> v;

int ans = 987654321;

int cal(){
	int count = 0;
	int sum = 0;
	int bucket = 0;
	int idx = 0;

	while(true){

		if(bucket + v[idx] <= M){
			bucket += v[idx];
		}
		else{
			count++;
			sum += bucket;
			bucket = v[idx];
		}

		if(count == K) return sum;

		idx++;
		idx = idx % N;
	}

	return 987654321;
}

void solve(){
	sort(v.begin() , v.end());

	do{
		ans = min(ans , cal());
	}while(next_permutation(v.begin() , v.end()));

	
}


int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N >> M >> K;
	
	int temp;

	for(int i = 0; i<N ; i++){
		cin >> temp;
		v.push_back(temp);
	}

	solve();
	cout << ans;


	return 0;
}
