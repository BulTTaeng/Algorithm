import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;
import java.lang.Math;

class Main {
  
  public static void main(String[] args) {

    long dp[][];

    int MOD = 1000000009;

    dp = new long[4][100002];
    Scanner sc = new Scanner(System.in);
    int T, temp, maxi = 0;

    T = sc.nextInt();

    List<Integer> input = new ArrayList<Integer>();

    for(int i =0; i<T; i++){
      temp = sc.nextInt();
      input.add(temp);
      maxi = Math.max(temp, maxi);
    }

    dp[1][1] = 1;
    dp[2][1] = 0;
    dp[3][1] = 0;

    dp[1][2] = 0;
    dp[2][2] = 1;
    dp[3][2] = 0;

    dp[1][3] = 1;
    dp[2][3] = 1;
    dp[3][3] = 1;

    for(int i =4; i<= maxi; i++){
      dp[1][i] = (dp[2][i-1] + dp[3][i-1]) % MOD;
      dp[2][i] = (dp[1][i-2] + dp[3][i-2]) % MOD;
      dp[3][i] = (dp[1][i-3] + dp[2][i-3]) % MOD;
    }

    long ans = 0;

    for(int i =0; i<T; i++){
      ans = ( dp[1][input.get(i)] + dp[2][input.get(i)] + dp[3][input.get(i)] ) % MOD;
      System.out.println(ans);
    }


  }

}
