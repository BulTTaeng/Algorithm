#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
vector<int> temp[51];

int N , M , T;

int root[51];

int _find(int x);
void _union(int x , int y );

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N >> M;

    cin >> T;
    int t;

    for(int i =0; i<T; i++){
        cin >> t;
        v.push_back(t);
    }

    for(int i =1; i<=N; i++){
        root[i] = i;
    }

    for(int i =0; i<v.size()-1; i++){
        _union(v[i] , v[i+1]);
    }
    

    int num;

    int ans = M;

    for(int i =0; i<M; i++){
        cin >> num;

        for(int j =0; j<num; j++){
            cin >> t;
            temp[i].push_back(t);
        }

        for(int j =0; j<temp[i].size()-1 ; j++){
            _union(temp[i][j] , temp[i][j+1]);
        }
    }

    for(int i = 0; i<M; i++){
        if(v.empty()){
            break;
        }
        
        for(int j =0; j<temp[i].size(); j++){
            
            if(_find(v[0]) == _find(temp[i][j]) ){
                //cout << i << " ";
                ans--;
                break;
            }
        }
        
    }

    
    cout << ans;
    

    return 0;
}

int _find(int x){
    if(root[x] == x) return x;
    else{
        return root[x] = _find(root[x]);
    }
}

void _union(int x , int y ){
    x = _find(x);
    y = _find(y);

    root[y] = x;
}
