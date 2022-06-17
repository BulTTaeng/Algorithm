#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int T , M;
int inp[10000];
vector<int> ans;

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> T;
    int temp;
    int t1 , t2;

    while(T--){
        cin >> M;
        
        priority_queue<int> maxheap;
        priority_queue<int , vector<int> , greater<>> minheap;
        ans.clear();

        for(int i =1; i<=M; i++){
            cin >> temp;

            if(maxheap.size() > minheap.size()){
                minheap.push(temp);
            }
            else{
                maxheap.push(temp);

                if(!maxheap.empty() && !minheap.empty() && maxheap.top() > minheap.top()){
                    t1 = maxheap.top();
                    t2 = minheap.top();

                    maxheap.pop();
                    minheap.pop();

                    maxheap.push(t2);
                    minheap.push(t1);
                }
            }

            if(i%2 == 1){
                ans.push_back(maxheap.top());
            }
        }

        cout << ans.size() << "\n";

        for(int i =0; i<ans.size() ; i++){
            cout << ans[i] << " ";
            if((i+1) %10 == 0){
                cout << "\n";
            }
        }
        cout << "\n";
    }
}
