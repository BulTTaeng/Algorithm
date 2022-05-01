import java.util.*

fun main() = with(System.`in`.bufferedReader()) {
    var N = readLine()!!.toInt()
    var inp =0
    var pq_revers = PriorityQueue<Int>(Collections.reverseOrder())

    for(i : Int in 0 until N){
        val x = readLine()!!.toInt()
        if(x == 0){
            if(pq_revers.isEmpty()){
                println(0)
            }
            else {
                inp = pq_revers.poll()
                println(inp)
            }
        }
        else{
            pq_revers.add(x)
        }
    }
}
