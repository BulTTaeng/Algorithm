#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> inp;
vector<int> ans;

void binary(int num);

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

    for(int i =1; i<N; i++){
        if(ans.back() < inp[i]){
            ans.push_back(inp[i]);
        }
        else{
            binary(inp[i]);
        }
    }

    cout << ans.size();
    return 0;
}

void binary(int num){
    int start = 0;
    int end = ans.size()-1;
    int mid;
    int target = 987654321;

    while(start<=end){
        mid = (start + end)/2;

        if(ans[mid] >= num){
            end = mid-1;
            target = min(target , mid);
        }
        else{
            start = mid+1;
        }
    }

    ans[target] = num;
}
