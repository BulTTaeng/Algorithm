#include <iostream>
#include <cstring>

using namespace std;

string str;
bool visit[51];

int recur(int idx);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> str;
    memset(visit ,false ,sizeof(visit));
    cout << recur(0);
    return 0;
}

int recur(int idx){
    int re = 0;

    for(int i =idx ; i<str.length(); i++){
        if(str[i] == '(' && !visit[i]){
            visit[i] = true;
            re--;
            re += (str[i-1]-'0') * recur(idx+1);
        }
        else if(str[i] == ')' && !visit[i]){
            visit[i] = true;
            return re;
        }
        else if(!visit[i]){
            re++;
            visit[i] = true;
        }
    }

    return re;
}
