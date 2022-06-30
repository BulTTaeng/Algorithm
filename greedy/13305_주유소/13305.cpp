#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N;
vector<int> road;
vector<int> price;

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> N;
    int temp;

    for(int i =0; i<N-1; i++){
        cin >> temp;
        road.push_back(temp);
    }

    for(int i =0; i<N; i++){
        cin >> temp;
        price.push_back(temp);
    }

    long long min_price = 1000000001;

    int loc =0;
    long long ans = 0;
    long long templen = 0;

    for(int i =0; i<N-1; i++){
        if(min_price > price[i]){
            ans += templen * min_price;
            min_price = price[i];
            templen=0;
        }
        
        templen+=road[i];
        
    }
    
    ans += templen * min_price;

    cout << ans;

    return 0;
}
