#include <iostream>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

int N;
vector<int> inp;
vector<int> ans;
int check[1000001];
int iter = 1;
vector<int> v;

void binary(int num , int loc);

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

    ans.push_back(inp[0]);
    memset(check , -1, sizeof(check));
    check[0] = 0;

    for(int i=1; i<N; i++){
        if(ans.back() < inp[i]){
            ans.push_back(inp[i]);
            check[i] = iter;
            iter++;
        }
        else{
            binary(inp[i] , i);
        }
    }

    cout << ans.size() << "\n";
    iter = ans.size()-1;


    for(int i=inp.size()-1; i>=0; i--){
        if(check[i] == iter){
            v.push_back(inp[i]);
            iter--;
        }
    }

    for(int i =v.size()-1; i>=0 ; i--){
        cout << v[i] << " "; 
    }

    return 0;
}

void binary(int num , int loc){
    int start = 0;
    int end = ans.size()-1;
    int mid;
    int target = 987654321;

    while(start<=end){
        mid = (start+end)/2;

        if(num <= ans[mid]){
            target = min(target , mid);
            end = mid-1;         
        }
        else{
            start = mid+1;
        }
    }

    ans[target] = num;
    check[loc] = target;
}
