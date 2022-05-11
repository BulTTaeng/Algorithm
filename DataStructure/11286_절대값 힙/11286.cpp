#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;

priority_queue<pair<int , int> , vector<pair<int , int>>, greater<> > pq;


int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N;
    int temp;

    while(N--){
        cin >> temp;

        if(temp == 0){
            if(pq.empty()){
                cout << 0 << "\n";
            }
            else{
                cout << pq.top().first * pq.top().second << "\n";
                pq.pop();
            }
        }
        else{
            if(temp < 0){
                pq.push({-temp , -1});
            }
            else{
                pq.push({temp , 1});   
            }
        }
    }

    return 0;
}
