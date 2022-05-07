import java.util.*
import java.io.BufferedWriter
import java.io.OutputStreamWriter
import kotlin.collections.ArrayList

val br = System.`in`.bufferedReader()
val bw = BufferedWriter(OutputStreamWriter(System.out))
val s = Stack<Pair<Char , Int>>()

fun main() =with(bw){
    val inp = br.readLine()!!
    var ans = ""

    for( i : Int in 0 until inp.length){

        if(inp[i] == '+' || inp[i] == '-'){
            while(!s.empty() && s.peek().second >= 0){
                ans += s.peek().first
                s.pop()
            }
            s.push(Pair(inp[i] , 0))
        }
        else if(inp[i] == '*' || inp[i] == '/'){
            while(!s.empty() && s.peek().second == 1){
                ans += s.peek().first
                s.pop()
            }
            s.push(Pair(inp[i] , 1))
        }
        else if(inp[i] == '('){
            s.push(Pair(inp[i],-1))
        }
        else if(inp[i] == ')'){

            while(!s.empty()){
                if(s.peek().first == '('){
                    s.pop()
                    break
                }
                ans+=s.peek().first
                s.pop()
            }
        }
        else{
            ans += inp[i]
        }
    }

    while(!s.empty()){
        ans += s.peek().first
        s.pop()
    }
    write("$ans")
    close()
}import java.util.*
import java.io.BufferedWriter
import java.io.OutputStreamWriter
import kotlin.collections.ArrayList

val br = System.`in`.bufferedReader()
val bw = BufferedWriter(OutputStreamWriter(System.out))
val s = Stack<Pair<Char , Int>>()

fun main() =with(bw){
    val inp = br.readLine()!!
    var ans = ""

    for( i : Int in 0 until inp.length){

        if(inp[i] == '+' || inp[i] == '-'){
            while(!s.empty() && s.peek().second >= 0){
                ans += s.peek().first
                s.pop()
            }
            s.push(Pair(inp[i] , 0))
        }
        else if(inp[i] == '*' || inp[i] == '/'){
            while(!s.empty() && s.peek().second == 1){
                ans += s.peek().first
                s.pop()
            }
            s.push(Pair(inp[i] , 1))
        }
        else if(inp[i] == '('){
            s.push(Pair(inp[i],-1))
        }
        else if(inp[i] == ')'){

            while(!s.empty()){
                if(s.peek().first == '('){
                    s.pop()
                    break
                }
                ans+=s.peek().first
                s.pop()
            }
        }
        else{
            ans += inp[i]
        }
    }

    while(!s.empty()){
        ans += s.peek().first
        s.pop()
    }
    write("$ans")
    close()
}
