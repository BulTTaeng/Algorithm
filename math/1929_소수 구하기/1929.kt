import java.lang.Math.sqrt

val br = System.`in`.bufferedReader()

fun main() =with(System.out.bufferedWriter()){

    var n = br.readLine().split(" ").map{it.toInt()}
    var ans = BooleanArray(n[1]+1)
    for(i : Int in 0 until n[1]+1){
        ans[i] = true
    }
    ans[1] = false

    var j =1

    for(i : Int in 2..sqrt(n[1]+1+0.1).toInt()){
        j=i
        if(ans[j]){
            j+=i
           while(j <= n[1]){
               ans[j] = false
               j+=i
           }
        }
    }

    for(i : Int in n[0] until n[1]+1){
        if(ans[i]){
            write("${i}\n")
        }
    }

    close()
}
