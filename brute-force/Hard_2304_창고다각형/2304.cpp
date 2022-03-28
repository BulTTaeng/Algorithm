#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

stack<pair<int , int>> s;
vector<pair<int , int>>v;
int N , sum =0;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N;
    int l , h , t = 0;
    int tloc = 0;
    for(int i =0; i<N; i++){
        cin >> l >> h;
        v.push_back(make_pair(l,h));
        t = max(t , h);
    }

    sort(v.begin() , v.end());

    int tempt = v[0].second;
    int temploc = v[0].first;
    for(int i =1; i<N; i++){

        if(v[i].second >= tempt){
            sum += (v[i].first-temploc ) * tempt;
            tempt = v[i].second;
            temploc = v[i].first;
        }
    }

    tempt = v[N-1].second;
    temploc = v[N-1].first;

    for(int i =N-2; i>=0; i--){

        if(v[i].second > tempt){
            sum += (temploc - v[i].first) * tempt;
            tempt = v[i].second;
            temploc = v[i].first;
        }
    }

    sum += t;
  
    cout << sum;
    return 0;
}
