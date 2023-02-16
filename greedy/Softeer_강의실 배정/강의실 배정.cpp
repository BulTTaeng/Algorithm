#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int N;

struct st{
	int s;
	int e;
}typedef st;

struct cmp{
	bool operator()(st &p1 , st &p2){
		if(p1.e == p2.e){
			return p1.s > p2.s;
		}

		return p1.e > p2.e;
	}
};

priority_queue<st , vector<st> , cmp > pq;

int ans = 0;

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N;
	int start , end;
	st temp;
	
	for(int i =0; i<N ; i++){
		cin >> start >> end;
		temp.s = start;
		temp.e = end;
		pq.push(temp);
	}

	int curr = 0;

	while(!pq.empty()){
		start = pq.top().s;
		end = pq.top().e;
		pq.pop();

		if(curr <= start){
			ans++;
			curr = end;
		}
	}

	cout << ans;

	return 0;
}
