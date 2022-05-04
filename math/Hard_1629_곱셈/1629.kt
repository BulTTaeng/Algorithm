import java.io.BufferedWriter
import java.io.OutputStreamWriter

val br = System.`in`.bufferedReader()
val bw = BufferedWriter(OutputStreamWriter(System.out))

fun main() =with(bw){
    val (A,B,C) = br.readLine()!!.split(" ").map{it.toLong()}
    write("${solve(A,B,C)}")
    close()
}

fun solve(a : Long , b : Long , c:Long) : Long{
    if(b == 1L){
        return a%c
    }
    else if(b%2 == 1L){
        return (a*solve(a , b-1 , c)%c)
    }
    else{
        val temp : Long = solve(a,b/2,c)
        return (temp*temp)%c
    }
}
