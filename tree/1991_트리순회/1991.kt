import java.io.BufferedWriter
import java.io.OutputStreamWriter

val br = System.`in`.bufferedReader()
val bw = BufferedWriter(OutputStreamWriter(System.out))
val tree = mutableListOf<Node>()

fun main() =with(bw){
    val N = br.readLine()!!.toInt()

    for(i : Int in 0 until N){
        val node =Node('A'+i, null, null)
        tree.add(node)
    }

    for(i : Int in 0 until N){
        val inp =br.readLine()!!.split(" ").map{it.single()}

        if(inp[1] != '.'){
            tree[inp[0]-'A'].l = tree[inp[1]-'A']
        }
        if(inp[2] != '.'){
            tree[inp[0]-'A'].r = tree[inp[2]-'A']
        }

    }

    pre(tree[0])
    write("\n")
    inOrder(tree[0])
    write("\n")
    post(tree[0])
    close()
}

fun pre(start : Node){
    bw.write("${start.value}")
    if(start.l != null){
        pre(start.l!!)
    }
    if(start.r != null){
        pre(start.r!!)
    }
}

fun post(start : Node){
    if(start.l != null){
        post(start.l!!)
    }
    if(start.r != null){
        post(start.r!!)
    }
    bw.write("${start.value}")
}

fun inOrder(start : Node){
    if(start.l != null){
        inOrder(start.l!!)
    }
    bw.write("${start.value}")
    if(start.r != null){
        inOrder(start.r!!)
    }
}

data class Node(
    var value: Char,
    var l: Node? = null,
    var r: Node? = null
)
