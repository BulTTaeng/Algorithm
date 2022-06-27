#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

vector<ll> stree;
ll inp[1000002];

int N , M ,K , a;
ll b , c;

void init();
ll makeSegTree(int Node ,int start ,int end);
ll query(int Node ,int start , int end , int left ,int right);
ll update(int Node ,int start ,int end , int target , ll val);

#define MOD 1000000007

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> N >> M >> K;

    for(int i =1 ; i<=N ; i++){
        cin >> inp[i];
    }

    init();

    for(int i =0 ; i<M+K ; i++){
        cin >> a >> b >> c;

        if(a == 1){
            update(1,1,N,b , c);
        }
        else{
            if(b>c){
                swap(b,c);
            }
            cout << query(1,1,N,b,c) << "\n";
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

ll makeSegTree(int Node ,int start ,int end){
    if(start == end) return stree[Node] = inp[start];

    int mid = (start+end)/2;

    return stree[Node] = ((makeSegTree(Node*2 , start , mid ) * makeSegTree(Node*2+1 , mid+1 , end) ) % MOD );
}

ll query(int Node ,int start , int end , int left ,int right){
    if(right < start || end < left) return 1;
    if(left <= start && end <= right) return stree[Node];

    int mid = (start+end)/2;

    return ( (query(Node*2 , start , mid ,left ,right) * query(Node*2 +1 , mid+1 , end , left ,right) ) % MOD);
}

ll update(int Node ,int start ,int end , int target ,ll val){
    if(target < start || target > end) return stree[Node];

    if(start == end){
        return stree[Node] = val;
    }
    else{
        int mid = (start+end)/2;

        ll l = update(Node*2 , start , mid , target , val);
        ll r = update(Node*2+1, mid+1 , end , target ,val);

        return stree[Node] = ((l*r) %MOD) ;
    }
}

