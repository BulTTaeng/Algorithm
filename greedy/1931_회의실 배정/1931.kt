var ans = 0

fun main() = with(System.`in`.bufferedReader()) {
    val N = readLine()!!.toInt()


    val inp = Array(N,{IntArray(2,{0})})
    var i = 0

    while(i < N){
        val (x,y) = readLine()!!.split(" ").map{it.toInt()}
        inp[i][0] =x
        inp[i][1] = y
        i++
    }

    inp.sortWith(compareBy({it[1]} , {it[0]}))

    var endtime = -1

    for(it in inp){
        if(it[0] >= endtime){
            ans++
            endtime = it[1]
        }
    }

    println(ans)

}
