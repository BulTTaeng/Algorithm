#include <iostream>
#include <queue>

using namespace std;

int N;

priority_queue<int , vector<int> , greater<int>>pq[5001];


int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N;
    int x , c;
    for(int i =0; i<N; i++){
        cin >>x >> c;

        pq[c].push(x);
    }

    int prev ,curr;
    prev = -1;
    int sum = 0;

    for(int i =1; i<=5000; i++){
        prev = -1;

        while(!pq[i].empty()){
            curr =pq[i].top();
            pq[i].pop();

            if(prev == -1){
                sum += pq[i].top() - curr;
            }
            else if(pq[i].empty()){
                sum += (curr - prev);
            }
            else{
                sum += min(curr- prev , pq[i].top() - curr );
            }

            prev = curr;  
        }

    }
    
    cout << sum;
    return 0;
}
