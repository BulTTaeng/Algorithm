var ans = 0

fun main() = with(System.`in`.bufferedReader()) {
    val n = readLine()!!.toInt()
    val m = readLine()!!.toInt()
    val str = readLine()

    var state = 0

    solve(str, n)

    println(ans)

}

fun solve(str : String , n : Int) {
    var state = 0

    var i = 0
    while(i<str.length-2){
        if(str[i] == 'I' && str[i+1] == 'O' && str[i+2] == 'I' ){
            state++
            if(state >= n){
                ans++
            }
            i += 2
        }
        else{
            state = 0
            i++
        }

    }
}
