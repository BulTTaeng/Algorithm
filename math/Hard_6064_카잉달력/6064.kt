var ans = 0
var temp = 0

fun main() = with(System.`in`.bufferedReader()) {
    val T = readLine()!!.toInt()
    var t = T

    var limit = 0

    while(t >0){
        var (M,N,x,y) = readLine()!!.split(" ").map{it.toInt()}
        ans = x
        limit = lcm(M,N)

        while(true){
            if(ans > limit ){
                break
            }

            if(ans%N == 0){
                temp = N;
            }
            else{
                temp = ans%N
            }
            if(temp == y){
                break
            }

            ans += M

        }
        if(ans > limit){
            println(-1)
        }
        else{
            println(ans)
        }

        t--
    }

}

fun gcd(a : Int , b : Int) : Int{
    var newa =a
    var newb = b
    var  r = 0
    while(newb != 0) {
        r = newa % newb
        newa = newb
        newb = r
    }
    return newa
}

fun lcm(a : Int , b : Int) : Int{
    return a*b/gcd(a,b)
}
