#include <iostream>
#include <queue>

using namespace std;

int N ;
queue<int> q;

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> N;

    for(int i = 1; i<=N; i++){
        q.push(i);
    }

    int temp;

    while(!q.empty()){
        temp  = q.front();
        q.pop();
        if(q.empty()){
            break;
        }
        else{
            temp = q.front();
            q.pop();
            q.push(temp);
        }
    }
    cout << temp;
    return 0;
}
