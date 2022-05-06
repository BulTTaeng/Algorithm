import java.io.BufferedWriter
import java.io.OutputStreamWriter
import kotlin.collections.ArrayList

val br = System.`in`.bufferedReader()
val bw = BufferedWriter(OutputStreamWriter(System.out))
val visit = Array<Boolean>(9){false}
val num = Array<Int>(9){987654321}
var inp = List(2) {0}
var ans = ArrayList<Int>()

fun main() =with(bw){
    inp = br.readLine()!!.split(" ").map{it.toInt()}
    val temp = br.readLine()!!.split(" ").map{it.toInt()}
    for(i : Int in 0 until inp[0]){
        num[i] = temp[i]
    }

    num.sort()
    dfs2(0)
    close()
}

fun dfs2( c : Int){

    if(c == inp[1]){
        for(it in ans){
            bw.write("$it ")
        }
        bw.write("\n")
    }
    else{
        for(i : Int in 0 until inp[0]){
            if(!visit[i]){
                visit[i] = true
                ans.add(num[i])
                dfs2(c+1)
                ans.removeAt(ans.size-1)
                visit[i] = false
            }
        }
    }
}
