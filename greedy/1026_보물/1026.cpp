#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> A;
vector<int> B;

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> N;
    int t;

    for(int i =0; i<N; i++){
        cin >> t;
        A.push_back(t);
    }

    for(int i =0; i<N; i++){
        cin >> t;
        B.push_back(t);
    }

    sort(A.begin() , A.end());
    sort(B.begin() , B.end() , greater<>());
    
    int ans = 0;

    for(int i =0; i<N; i++){
        ans += A[i]*B[i];
    }

    cout << ans;
    return 0;
}
