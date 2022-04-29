fun main() = with(System.`in`.bufferedReader()) {
    var (N,M) = readLine()!!.split(" ").map{it.toInt()}


    var inpmap = HashMap<String, String>()
    var answer = ArrayList<String>()

    var i =1
    var str = ""
    while(i <= N){
        str = readLine()!!
        inpmap.put(str , str)
        i++
    }


    i=1

    while(i<=M){
        str = readLine()!!
        if(inpmap[str] != null){
            answer.add(str)
        }
        i++
    }
    
    answer.sort()

    println(answer.size)
    for(it in answer){
        println(it)
    }


}
