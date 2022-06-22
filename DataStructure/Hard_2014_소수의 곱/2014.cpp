#include <iostream>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int K , N;
priority_queue<long long , vector<long long> , greater<> > pq;
vector<int> v;
map<long long, int> m;

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >>  K >> N;
    long long temp;

    for(int i =0; i<K; i++){
        cin >> temp;
        pq.push(temp);
        v.push_back(temp);
        m[temp] = 1;
    }

    int count = 0;
    long long ans;
    long long n ;

    sort(v.begin() ,v.end());
    long long maxi = v.back();

    while(true){
        temp = pq.top();
        pq.pop();

        count++;

        if(count == N){
            ans = temp;
            break;
        }
        
        for(int i =0; i <v.size() ; i++){
            n = temp * v[i];
            if(maxi < n && pq.size() + count > N){
                break;
            }
            if(m[n] == 0){  
                pq.push(n);
                m[n] = 1;
                maxi = max(maxi , n);
            }
            
        }
    }

    cout << ans;
    return 0;
}
