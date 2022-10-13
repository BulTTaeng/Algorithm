#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int xhave[28];
vector<char> v;
bool onlyZero = true;

string solution(string X, string Y) {
    string answer = "";
    
    memset(xhave , 0 ,sizeof(xhave));
    
    for(int i =0; i<X.length() ; i++){
        xhave[X[i] - '0']++;
    }
    
    for(int i =0; i<Y.length() ; i++){
        int currNum = Y[i] - '0'; 
        if(xhave[currNum] > 0){
            v.push_back(Y[i]);
            xhave[currNum]--;
            
            if(currNum != 0 ){
                onlyZero = false;
            }
        }
    }
    
    sort(v.begin() , v.end() , greater());
    
    for(int i =0; i<v.size() ; i++){
        answer += v[i];
    }
    
    if(answer == ""){
        answer = "-1";
    }
    else if(onlyZero){
        answer = "0";
    }
    
    return answer;
}
