#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int N, M;
vector<int> box;
vector<int> crane;
int num[1000001];
int ans = 0;

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);

  cin >> N;

  int temp;
  for(int i =0; i<N; i++){
    cin >> temp;
    crane.push_back(temp);
  }

  cin >>M;

  for(int i =0; i<M; i++){
    cin >> temp;
    box.push_back(temp);
  }

  sort(box.begin() , box.end());
  sort(crane.begin(), crane.end());
  int index = 0;

  memset(num , 0 ,sizeof(num));

  if(box[M-1] > crane[N-1]){
    cout << -1;
    return 0;
  }

  for(int i =0; i<M; i++){
    if(crane[index] >= box[i] ){
      num[index]++;
    }
    else{
      index++;
      i--;
    }
  }

  int moved_box = 0;

  while (true) {
		for (int i = N - 1; i >= 0; i--) {
			for (int j = i; j >= 0; j--) {
				if (num[j]) {
					num[j]--;
					moved_box++;
					break;
				}
			}
			if (moved_box == M) break;
		}

		ans++;
		if (moved_box == M) break;
	}

  cout << ans;
  return 0;
   
}
