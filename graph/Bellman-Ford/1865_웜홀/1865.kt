import java.util.*
import java.io.BufferedWriter
import java.io.OutputStreamWriter

val br = System.`in`.bufferedReader()
val bw = BufferedWriter(OutputStreamWriter(System.out))

fun main() =with(bw){
    var TC = br.readLine()!!.toInt()
    while(TC>0){

        val (n,m,w) = br.readLine()!!.split(" ").map{it.toInt()}
        val dist = Array<Int>(502) { 987654321}
        val adj = Array(502) { ArrayList<Pair<Int, Int>>() }
        println(dist[1])
        for(i:Int in 0 until m){
            val (s,e,t) =br.readLine()!!.split(" ").map{it.toInt()}
            adj[s].add(Pair(e,t))
            adj[e].add(Pair(s,t))
        }
        for(i:Int in 0 until w){
            val (s,e,t) =br.readLine()!!.split(" ").map{it.toInt()}
            adj[s].add(Pair(e,-t))
        }

        val is_minus = bellmanFord(n , dist , adj)
        if(is_minus){
            write("YES\n")
        }
        else{
            write("NO\n")
        }
        TC--
    }
    close()
}

fun bellmanFord(N: Int, dist: Array<Int>, adj: Array<ArrayList<Pair<Int, Int>>>) : Boolean{
    dist[1] = 0
    var re : Boolean = false
    for(i :Int in 1..N){
        for(j:Int in 1..N){
            for(it in adj[j]){
                if(dist[it.first] > dist[j] + it.second){
                    dist[it.first] = dist[j] + it.second
                    if(i == N) re = true
                }
            }
        }
    }

    return re
}
