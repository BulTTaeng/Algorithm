#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int a , N , Q;
ll p ,q;

vector<ll> stree;
ll inp[1000001];

void init();
ll makeSegTree(int Node ,int start ,int end);
ll query(int Node ,int start , int end , int left ,int right);
void update(int Node ,int start ,int end , int target , ll diff);

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> N >> Q;

    init();

    for(int i =0; i<Q; i++){
        cin >> a >> p >> q;

        if(a == 1){
            update(1,1,N,p,q);
        }
        else{
            if(p > q){
                swap(p,q);
            }

            cout << query(1,1,N,p,q) << "\n";
        }
    }

    return 0;

}

void init(){
    int h = (int)ceil(log2(N));
    int size =  1 << (h+1);
    stree.resize(size , 0);
    makeSegTree(1,1,N);
}

ll makeSegTree(int Node ,int start ,int end){
    if(start == end) return stree[Node] = inp[start];


    int mid = (start+end)/2;

    return stree[Node] = (makeSegTree(Node*2 , start , mid ) + makeSegTree(Node*2+1 , mid+1 , end) );
}

ll query(int Node ,int start , int end , int left ,int right){
    if(right < start || left > end ) return 0;
    if(left <= start && end <= right) return stree[Node];

    int mid = (start+end)/2;

    return query(Node*2 , start , mid ,left ,right) + query(Node*2 +1 , mid+1 , end , left ,right);
}

void update(int Node ,int start ,int end , int target , ll diff){
    if(target < start || target > end) return;

    stree[Node] += diff;

    if(start == end){
        inp[target] += diff;
    }
    else{
        int mid = (start+end)/2;
        update(Node*2 , start , mid , target ,diff);
        update(Node*2+1 , mid+1 , end ,target ,diff);
    }
}
