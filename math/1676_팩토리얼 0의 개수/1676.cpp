#include <iostream>
#include <string>

using namespace std;

int N;
int ans = 0;

pair<int, int> find_zero(int num);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N;
    int lastnum =1;
    int temp = 1;
    pair<int,int> p;

    for(int i =1; i <=N; i++){
        temp = lastnum * i;

        //cout << lastnum <<  " " << temp << endl;

        p = find_zero(temp);
        ans += p.first;
        temp = p.second;

        lastnum = 0;
        lastnum += temp %10;
        temp = temp/10;

        lastnum += temp %10 *10;
        temp = temp/10;

        lastnum += temp %10 * 100;
        temp = temp/10;
    }

    cout << ans;
    return 0;
}

pair<int, int> find_zero(int num){
    int re = 0;

    while(true){
        if(num % 10 != 0){
            pair<int, int> p = make_pair(re , num);
            return p;
        }
        num = num /10;
        re++;
    }
}
