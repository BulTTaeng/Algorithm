fun main() = with(System.`in`.bufferedReader()) {
    var (N,M) = readLine()!!.split(" ").map{it.toInt()}


    var inpmap = HashMap<String, String>()

    var i =1
    while(i <= N){
        val str = readLine()!!
        inpmap.put(str.toString() , i.toString())
        inpmap.put(i.toString() , str)
        i++
    }


    i=1

    while(i<=M){
        val value = readLine()!!
        println(inpmap[value])
        i++
    }

}
