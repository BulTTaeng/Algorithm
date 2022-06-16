#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

int N;
vector<int> inp;
priority_queue<int , vector<int> , greater<> > inc;
priority_queue<int> decen;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N;

    int temp;
    for(int i =0; i<N; i++){
        cin >> temp;
        inp.push_back(temp); 
    }

    int x, y;

    for(int i =0; i<N; i++){
        if(decen.size() > inc.size()){
            inc.push(inp[i]);
        }
        else{
            decen.push(inp[i]);
        }

        if(!decen.empty() && !inc.empty() ){
            if(decen.top() > inc.top()){
                x = decen.top();
                y = inc.top();
                decen.pop();
                inc.pop();

                decen.push(y);
                inc.push(x);   
            }
        }
        
        cout << decen.top() << "\n";
    }
    
}
