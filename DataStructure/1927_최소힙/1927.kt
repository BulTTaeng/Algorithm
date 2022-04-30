import java.util.*

fun main() = with(System.`in`.bufferedReader()) {
    var N = readLine()!!.toInt()
    var inp =0
    val pq = PriorityQueue<Int>()

    for(i : Int in 0 until N){
        val x = readLine()!!.toInt()
        if(x == 0){
            if(pq.isEmpty()){
                println(0)
            }
            else {
                inp = pq.poll()
                println(inp)

            }
        }
        else{
            pq.add(x)
        }
    }
}
