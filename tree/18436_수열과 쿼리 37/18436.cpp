#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

vector<pair<int,int>> stree;
ll inp[1000002];

int N , M ,K , a;
ll b , c;

void init();
pair<int,int> makeSegTree(int Node ,int start ,int end);
pair<int,int> query(int Node ,int start ,int end , int left , int right);
pair<int,int> update(int Node ,int start ,int end ,int target , ll val);

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> N;

    for(int i =1 ; i<=N ; i++){
        cin >> inp[i];
    }

    init();

    cin >> M;

    for(int i =0; i<M; i++){
        cin >> a >> b >> c;

        if(a == 1){
            update(1,1,N,b,c);
        }
        else if(a == 2){
            if(b> c){
                swap(b,c);
            }
            cout << query(1,1,N,b,c).second << "\n";
        }
        else{
            if(b> c){
                swap(b,c);
            }
            cout << query(1,1,N,b,c).first << "\n";
        }
    }

    return 0;
}

void init(){
    int h = (int)ceil(log2(N));
    int size = 1 << (h+1);
    stree.resize(size);
    makeSegTree(1,1,N);
}

pair<int ,int> makeSegTree(int Node ,int start ,int end){
    if(start == end ){
        if(inp[start]%2 == 0){
            stree[Node].first = 0;
            stree[Node].second = 1;
        }
        else{
            stree[Node].first = 1;
            stree[Node].second = 0;
        }
         return stree[Node];
    }


    int mid = (start+end)/2;

    pair<int, int> l = makeSegTree(Node*2, start , mid);
    pair<int, int> r = makeSegTree(Node*2+1 , mid+1 ,end);
    
    stree[Node].first = l.first + r.first;
    stree[Node].second = l.second + r.second;

    return stree[Node];
}


pair<int ,int> query(int Node ,int start ,int end , int left , int right){
    if(right < start || end < left){
        pair<int ,int> t;
        t.first = 0;
        t.second = 0;
        return t;
    }
    if(left <= start && end <=right) return stree[Node];

    int mid = (start+end)/2;

    pair<int, int> l =query(Node*2, start ,mid , left ,right);
    pair<int ,int> r = query(Node*2+1 , mid+1 , end ,left , right);

    pair<int,int> t;

    t.first = l.first+r.first;
    t.second = l.second + r.second;

    return t;
}


pair<int , int> update(int Node ,int start ,int end ,int target , ll val){

    if(target < start || target > end ) return stree[Node];

    if(start == end){
        if(val %2 == 0){
            stree[Node].first = 0;
            stree[Node].second = 1;
        }
        else{
            stree[Node].first = 1;
            stree[Node].second = 0;
        }
        return stree[Node]; 
    }
    else{
        int mid = (start+end)/2;

        pair<int, int> l = update(Node*2, start , mid , target , val);
        pair<int,int> r = update(Node*2+1, mid+1 , end,  target ,val);

        stree[Node].first = l.first + r.first;
        stree[Node].second = l.second + r.second;
        return stree[Node];
    }

}
