#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int N , M;
ll inp[100001];
int a, b;

vector<ll> stree;

void initSegTree();
ll makeSegTree(int Node , int start , int end);
ll query(int Node , int start , int end , int left , int right);

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> N >> M;

    for(int i =1; i<=N; i++){
        cin >> inp[i];
    }

    initSegTree();

    for(int i =0; i<M; i++){
        cin >> a >> b;

        if(a>b){
            swap(a,b);
        }
        cout << query(1,1,N,a,b) << "\n";
    }

    return 0;
}

void initSegTree(){
    int h =(int)ceil(log2(N));
    int size = 1 << (h+1);
    stree.resize(size);
    makeSegTree(1,1,N);
}

ll makeSegTree(int Node ,int start ,int end){
    if(start == end) return stree[Node] = inp[start];

    int mid = (start+end)/2;

    ll left = makeSegTree(Node*2 , start, mid);
    ll right = makeSegTree(Node*2+1 , mid+1 , end);
    
    return stree[Node] = min(left , right);
}

ll query(int Node , int start ,int end , int left , int right){
    if(right < start || left > end) return 1000000001;
    if(left <= start && end <= right) return stree[Node];

    int mid = (start+end)/2;

    ll l = query(Node*2 , start , mid , left ,right);
    ll r = query(Node*2 +1 , mid+1 ,  end , left ,right);

    return min(l,r);
}
