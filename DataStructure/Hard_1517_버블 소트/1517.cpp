#include <iostream>
#include <vector>

using namespace std;

int N;
long long ans = 0;
vector<int> v;

void mergeSort(int start ,int end);
void merge(int start ,int mid , int end , int left , int right);

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> N;
    
    int tt;

    for(int i =0;i<N; i++){
        cin >> tt;
        v.push_back(tt);
    }

    mergeSort(0,N-1);

    cout << ans;
    return 0;

}

void mergeSort(int start ,int end){
    int mid = (start+end)/2;
    int left = start;
    int right = mid+1;

    if(start== end) return;

    mergeSort(start, mid);
    mergeSort(mid+1 , end);

    merge(start , mid , end , left , right); 
}

void merge(int start ,int mid , int end , int left , int right){
    vector<int> temp;

    while(left <= mid && right <= end){
        if(v[left] <= v[right]){
            temp.push_back(v[left]);
            left++;
        }
        else{
            temp.push_back(v[right]);
            right++;
            ans += (mid+1 - left);
        }
    }

    while (left <= mid) {
		temp.push_back(v[left]);
        left++;
	}
	while (right <= end) {
		temp.push_back(v[right]);
        right++;
	}

	for (int i = start, j = 0; i <= end; i++, j++) {
		v[i] = temp[j];
	}
}
