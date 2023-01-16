#include<iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

long long N;
long long B;
vector<long long > inp;
long long temp;
long long ans = 0;

void binaray();
bool solve(long long num);


int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N >> B;

	for(int i =0; i<N ; i++){
		cin >> temp;
		inp.push_back(temp);
	}

	sort(inp.begin() , inp.end());

	binaray();
	cout << ans;

	return 0;
}

void binaray(){
	long long start = inp[0];
	long long end = inp[N-1] + (long long)sqrt(B);
	long long mid;

	while(start<=end){
		mid = (start+ end)/2;

		if(solve(mid)){
			ans = max(ans , mid);
			start = mid+1;
		}
		else{
			end = mid-1;
		}
	}

	return;
}

bool solve(long long num){
	long long b = B;
	long long t;

	for(int i =0; i<N;i++){

		if(inp[i] >= num) break;
		t = (num - inp[i]);
		t = t * t;

		if(b >= t){
			b -= t;
		}
		else{
			b = -999;
			break;
		}
	}
	if(b == -999) return false;
	else return true;
}
