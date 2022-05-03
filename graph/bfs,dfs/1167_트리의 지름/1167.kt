import java.io.BufferedWriter
import java.io.OutputStreamWriter

val br = System.`in`.bufferedReader()
val bw = BufferedWriter(OutputStreamWriter(System.out))
var visit = BooleanArray(100001){false}
var inp = MutableList(1000001, {mutableListOf<Pair<Int, Int>>()})
var ans = 0
var endpoint = -1
var startpoint = 0

fun main() =with(br){
    val n = br.readLine()!!.toInt()
    var iter = 0

    for(i : Int in 1..n){
        val x = br.readLine().split(" ").map{it.toInt()}
        iter = 1
        startpoint = x[0]
        while(true){
            if(x[iter] == -1){
                break
            }
            else {
                inp[x[0]].add(Pair(x[iter] , x[iter+1]))
            }
            iter +=2
        }
    }

    dfs(startpoint , 0)

    for (i :Int in 0..100000){
        visit[i] = false
    }

    dfs(endpoint , 0)
    bw.write("${ans}")
    //var arr = br.readLine().split(' ').map{it.toInt()}
    close()
}

fun dfs(loc : Int , cost : Int){
    visit[loc] = true
    if(ans < cost){
        ans = cost
        endpoint = loc
    }

    for(i : Int in 0 until inp[loc].size){
        if(!visit[inp[loc][i].first]){
            dfs(inp[loc][i].first , cost + inp[loc][i].second)
        }
    }
}
