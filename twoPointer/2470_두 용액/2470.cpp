#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int N;
vector<int> v;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N;
    int t;

    for(int i =0; i<N; i++){
        cin >> t;
        v.push_back(t);
    }

    sort(v.begin() , v.end() );

    int start =0 ;
    int end = v.size()-1;
    int x , y;
    long long sum = 2000000001;
    long long diff = 0;
    
    while(start < end && end >=0){
        diff = v[end] + v[start];

        if(diff == 0){
            x= start;
            y= end;
            break;
        }
        else{
            if(diff < 0){
                if(abs(sum) > abs(diff)){
                    x = start;
                    y = end;  
                    sum = diff;
                }
                start++;
            }
            else{
                if(abs(sum) > abs(diff)){
                    x = start;
                    y = end;  
                    sum = diff;
                }
                end--;
            }
        }
    }

    cout << v[x] << " " << v[y];
    return 0;
}
