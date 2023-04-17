#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int parent[1002];
vector<int> v;

int _find(int x);
void _union(int x , int y);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n, m ;

    cin >> n >> m;
    int t1 , t2;
    
    for(int i =1; i<=n; i++){
        parent[i] = i;
    }

    for(int i =0;i <m ; i++){
        cin >> t1 >> t2;
        
        _union(t1 , t2);
        
    }

    for(int i=1; i<=n; i++){
        v.push_back(_find(i));
    }
    
    sort(v.begin() , v.end());
    v.erase(unique(v.begin() , v.end()), v.end());

    cout << v.size();
    return 0;
}

int _find(int x){
    if(parent[x] == x) return x;
    else{
        return parent[x] = _find(parent[x]);
    }
}

void _union(int x , int y){
    
    x= _find(x);
    y = _find(y);

    parent[y] = x;
}
