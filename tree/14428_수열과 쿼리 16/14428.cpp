#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

vector<pair<ll, int>> stree;
ll inp[1000002];

int N , M ,K , a;
ll b , c;

void init();
pair<ll,int> makeSegTree(int Node ,int start ,int end);
pair<ll, int> query(int Node ,int start ,int end , int left , int right);
pair<ll,int> update(int Node ,int start ,int end ,int target , ll val);

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
        else{
            if(b> c){
                swap(b,c);
            }
            cout << query(1,1,N,b,c).second << "\n";
        }
    }

    return 0;
}

void init(){
    int h = (int)ceil(log2(N));
    int size =  1 << (h+1);
    stree.resize(size);
    makeSegTree(1,1,N);
}

pair<ll, int> makeSegTree(int Node ,int start ,int end){
    if(start == end) {
        stree[Node].first =  inp[start];
        stree[Node].second = start;
        return stree[Node];
    }

    int mid = (start+end)/2;

    pair<ll, int> l = makeSegTree(Node*2 , start , mid);
    pair<ll, int> r = makeSegTree(Node*2+1 , mid+1 , end);

    if(l.first < r.first){
        stree[Node].first = l.first;
        stree[Node].second = l.second;
    }
    else if(l.first == r.first){
        stree[Node].first = l.first;
        stree[Node].second = min(l.second , r.second);
    }
    else{
        stree[Node].first = r.first;
        stree[Node].second = r.second;
    }

    return stree[Node];
}

pair<ll, int> query(int Node ,int start ,int end , int left , int right){
    if(start > right || end < left){
        pair<ll,int>  t;
        t.first = 1000000001;
        t.second = -1;
        return t;
    }
    if(left <= start && end <= right){
        return stree[Node];
    }

    int mid = (start+end)/2;

    pair<ll, int> l = query(Node*2 , start , mid , left , right);
    pair<ll, int> r = query(Node*2+1 , mid+1 , end , left ,right);

    pair<ll , int> re;

    if(l.first <= r.first){
        re.first = l.first;
        re.second = l.second;
    }
    else if(l.first == r.first){
        re.first = l.first;
        re.second = min(l.second , r.second);
    }
    else{
        re.first = r.first;
        re.second = r.second;
    }

    return re;
}

pair<ll , int> update(int Node ,int start ,int end ,int target , ll val){
    if(target > end || target < start) return stree[Node];

    if(start == end){
        inp[target] = val;
        stree[Node].first = val;
        return stree[Node];
    }
    else{
        int mid = (start+end)/2;

        pair<ll, int > l = update(Node*2, start ,mid , target ,val);
        pair<ll, int> r = update(Node*2+1 , mid+1 , end ,target ,val);
        
        if(l.first < r.first){
            stree[Node].first = l.first;
            stree[Node].second = l.second;
        }
        else if(l.first == r.first){
            stree[Node].first = l.first;
            stree[Node].second = min(l.second , r.second);
        }
        else{
            stree[Node].first = r.first;
            stree[Node].second = r.second;
        }

        return stree[Node];
    }
}
