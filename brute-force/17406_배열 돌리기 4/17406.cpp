#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N, M , K;
int A[52][52];
int CA[52][52];
int r,c,s;
int ans = 987654321;

struct st{
  int r;
  int c;
  int s;
}typedef st;

vector<st> command;

void copyA(){
  for(int i =1; i<=N ; i++){
    for(int j =1; j<=M; j++){
      CA[i][j] = A[i][j];
    }
  }
}

void print(){
  for(int i =1; i<=N ; i++){
    for(int j =1; j<=M; j++){
      cout << CA[i][j] << " ";
    }
    cout <<"\n";
  }
}

void _move(st com){

  int save , save2;
  int sr = com.r-com.s; //start row
  int er = com.r+com.s; //end row
  int sc = com.c-com.s; // start col
  int ec = com.c+com.s; // end col
  
  for (int iter = 0; iter <com.s ; iter++){
    
    save = CA[sr+iter][ec-iter];
    
    for(int j = ec-iter ; j>sc+iter; j--){
      CA[sr+iter][j] = CA[sr+iter][j-1];
    }
    ////////////////////
    save2 = CA[er-iter][ec-iter];

    for(int j =er-iter; j>sr+iter; j--){
      CA[j][ec-iter] = CA[j-1][ec-iter];
    }

    CA[sr+iter+1][ec-iter] = save;
    //////////////////////////////////////
    save = CA[er-iter][sc+iter];

    for(int j = sc+iter; j<ec-iter; j++){
      CA[er-iter][j] = CA[er-iter][j+1];
    }

    CA[er-iter][ec-iter-1] =save2;

    ////////////////////////////////

    for(int j = sr+iter ; j<er-iter; j++){
      CA[j][sc+iter] = CA[j+1][sc+iter];
    }

    CA[er-iter-1][sc+iter] = save;
  }
}

void findMin(){
  int sum = 0;
  
  for(int i =1; i<=N ; i++){
    sum = 0;
    for(int j =1; j<=M; j++){
      sum += CA[i][j];
    }
    ans = min(ans , sum);
  }
}

void move(string str){
  int idx = 0;
  
  for(int i =0; i<str.length(); i++){
    idx = str[i] - '0';
    _move(command[idx]);
  }

  findMin();
}



int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> N  >> M >> K;
  for(int i =1;i<=N ; i++){
    for(int j =1; j<=M; j++){
      cin >> A[i][j];
    }
  }

  st temp;

  for(int i =0; i<K; i++){
    cin >> r >> c >> s;
    temp.r = r;
    temp.s = s;
    temp.c = c;
    command.push_back(temp);
  }

  string str = "";

  for(int i =0; i<K; i++){
    str += to_string(i);
  }
  
  do{
    copyA();
    move(str);
  }while(next_permutation(str.begin() , str.end()));
  
  cout << ans;
  return 0;
  
}
