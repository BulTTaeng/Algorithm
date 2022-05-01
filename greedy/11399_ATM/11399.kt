import kotlin.collections.ArrayList

fun main() = with(System.`in`.bufferedReader()) {
  
    var N = readLine()!!.toInt()
    var x = readLine()!!.split(" ").map{it.toInt()}

    x = x.sorted()
    var n = N
    var ans = 0
    for(i : Int  in 0 until N){
        ans += x[i] * n
        n--
    }
    println(ans)
}
