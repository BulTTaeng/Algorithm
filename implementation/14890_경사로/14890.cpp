#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int N , L;
int ans =0;
int map[102][102];
bool visit[102][102];

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> N >> L;

  for(int i =0; i<N; i++){
    for(int j =0; j<N; j++){
      cin >> map[i][j];
    }
  }

  int prev = 0;
  int curr;
  int count = 0;
  
  bool possible =true;
  bool tp = true;

  memset(visit , false ,sizeof(visit));
  
  //가로
  for(int i = 0 ;i<N; i++){
    prev = map[i][0];
    possible = true;
    count = 1;
    
    for(int j = 1 ;j<N; j++){
      curr = map[i][j];
      
      if(prev == curr){
         count++; 
      }
      else if(abs(prev - curr) >= 2 ){
        possible = false;
        break;
      }
      else{

        if(prev > curr){
          tp = true;
          
          for(int k =0; k<L; k++){

            if(visit[i][j+k]){
              tp = false;
              break;
            }
            
            if(map[i][j+k] != curr){
              tp = false;
              break;
            }
          } // end of k

          if(tp){
            for(int k =0; k<L; k++){
              visit[i][j+k] = true;
            }
            count = 0;
          }
          else{
            possible = false;
            break;
          }
          
        }
        
        else if(prev < curr){

          if(count >= L){
            tp = true;
            
            for(int k = 1; k<=L; k++){
              if(visit[i][j-k]){
                tp = false;
                break;
              }
            }// end of k
  
            if(tp){
              for(int k =1; k<=L; k++){
                visit[i][j-k] = true;
              }
              count =1;
            }
            else{
              possible = false;
              break;
            }
            
          } // end of count >= L
          else{
            possible = false;
            break;
          }
        }
        else{
          possible = false;
          break;
        }
        
      }// end of else

      prev = curr;
    }
    
    if(possible){
      //cout << "row !!" << i << "\n";
      ans++;
    }
    
  }


  memset(visit , false ,sizeof(visit));
  
  //세로
  for(int i = 0 ;i<N; i++){
    prev = map[0][i];
    possible = true;
    count = 1;
    
    for(int j = 1 ;j<N; j++){
      curr = map[j][i];

      if(prev == curr){
         count++; 
      }
      else if(abs(prev - curr) >= 2 ){
        possible = false;
        break;
      }
      else{

        if(prev > curr){
          tp = true;
          
          for(int k =0; k<L; k++){

            if(visit[j+k][i]){
              tp = false;
              break;
            }
            
            if(map[j+k][i] != curr){
              tp = false;
              break;
            }
          } // end of k

          if(tp){
            for(int k =0; k<L; k++){
              visit[j+k][i] = true;
            }
            count = 0;
          }
          else{
            possible = false;
            break;
          }
          
        }
        
        else if(prev < curr){

          if(count >= L){
            tp = true;
            
            for(int k = 1; k<=L; k++){
              if(visit[j-k][i]){
                tp = false;
                break;
              }
            }// end of k
  
            if(tp){
              for(int k =1; k<=L; k++){
                visit[j-k][i] = true;
              }
              count =1;
            }
            else{
              possible = false;
              break;
            }
            
          } // end of count >= L
          else{
            possible = false;
            break;
          }
        }
        else{
          possible = false;
          break;
        }
      }// end of else

      prev = curr;
    }

    if(possible){
      //cout << "col !!" << i << "\n";
      ans++;
    }
    
  }


  cout << ans;
  return 0;
  
}
