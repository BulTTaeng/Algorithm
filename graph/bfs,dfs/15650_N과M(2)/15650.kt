import java.io.BufferedWriter
import java.io.OutputStreamWriter
import kotlin.collections.ArrayList

val br = System.`in`.bufferedReader()
val bw = BufferedWriter(OutputStreamWriter(System.out))
val visit = Array<Boolean>(9){false}
var inp = List(2) {0}
fun main() =with(bw){
    inp = br.readLine()!!.split(" ").map{it.toInt()}

    dfs(1 , 0)

    close()
}

fun dfs(curr : Int , c : Int){
    if(c == inp[1]){
        for(i : Int in 1..inp[0]){
            if(visit[i]){
                bw.write(i.toString() + " ")
            }
        }
        bw.write("\n")
    }
    else if(curr > inp[0]){
        return
    }
    else {
        visit[curr] = true
        dfs(curr + 1, c + 1)
        visit[curr] = false
        dfs(curr + 1, c)
    }
}
