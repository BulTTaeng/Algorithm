import kotlin.collections.HashMap

val br = System.`in`.bufferedReader()

fun main() =with(System.out.bufferedWriter()){


    var ans = HashMap<Int , Int>()

    val n = br.readLine().toInt()
    var arr = br.readLine().split(' ').map{it.toInt()}
    var ar = arr.distinct().sorted()


    for(i in 0 until ar.size){
        ans[ar[i]] = i
    }

    for(i in 0 until n){
        write("${ans[arr[i]]} ")
    }
    close()
}
