#include <iostream>

using namespace std;

int N;
int numO[1001];
int numA1[1001];
int numA2[1001];
int numA1L[1001];
int numA2L[1001];
int numL[1001];

#define MOD 1000000

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);

  cin >> N;

  numO[0] = numA1[0]= numA2[0] = numA2L[0] = numA1L[0] = numL[0] = 0;
  
  numA2[1] = numA1L[1] = numA2L[1] = 0;
  numO[1] = numA1[1] = numL[1] = 1;

  int o, a1, a2, a2l , a1l, l;
  int no , na1 , na2 , na1l , na2l, nl;
  
  for(int i =2; i<=N; i++){
    o = numO[i-1];
    a1 = numA1[i-1];
    a2 = numA2[i-1];
    l = numL[i-1];
    a1l = numA1L[i-1];
    a2l = numA2L[i-1];

    no = o+a1 + a2;
    na1 = o;
    na2 = a1;
    nl = o + a1 + a2 +l + a1l + a2l;
    na1l = l;
    na2l = a1l;
    
    numO[i] = no % MOD;
    numA1[i] = na1 % MOD;
    numA2[i] = na2 % MOD;
    numL[i] = nl % MOD;
    numA1L[i] = na1l % MOD;
    numA2L[i] = na2l % MOD;
  }

  cout << (numO[N] + numA1[N] + numA2[N] + numL[N] + numA1L[N] + numA2L[N]) % MOD;
  return 0;
  
}
