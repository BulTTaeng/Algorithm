#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N , temp;
vector<int> v;

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> N;
    
    for(int i =0; i<N; i++){
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin() , v.end());

    if(N %2 == 0){
        cout << v[N/2-1];
    }
    else{
        cout << v[N/2];
    }
    
    return 0;
}
