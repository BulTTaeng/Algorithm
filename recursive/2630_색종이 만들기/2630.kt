lateinit var inp : MutableList<List<Int>>
var white = 0
var blue = 0
var sum=0
var temp =0

fun main() = with(System.`in`.bufferedReader()) {
    //var (N,M) = readLine()!!.split(" ").map{it.toInt()
    var N = readLine()!!.toInt()
    //val inp = List(N,{List(N,{0})})
    var i =0
    inp = mutableListOf()

    for(i : Int in 0 until N){
        val x = readLine()!!.split(" ").map{it.toInt()}
        inp.add(x)
    }

    solve(N,0,0,N,N)

    println(white)
    println(blue)
}

fun solve(size : Int , x1 : Int, y1 : Int , x2 : Int , y2 : Int) {



        val ok = checkcolor(x1,y1,x2,y2)

        if(ok == -1){
            solve(size/2 , x1,y1,x1 +size/2,y1 + size/2)
            solve(size/2 , x1 , y1 + size/2 , x2 - size/2 , y2)
            solve(size/2 , x1 + size/2 , y1 , x2 , y2 - size/2)
            solve(size/2 , x1+size/2 , y1+size/2 , x2 , y2)
        }
        else if(ok == 0){
            //println("white "  + x1.toString() + y1.toString() + x2.toString() + y2.toString() )
            white++
        }
        else{
            //println("blue "  + x1.toString() + y1.toString() + x2.toString() + y2.toString() )
            blue++
        }


}

fun checkcolor(x1 : Int, y1 : Int , x2 : Int , y2 : Int) : Int{
    sum=0
    temp =0
    for(i : Int in x1 until x2){
        for(j : Int in y1 until y2){
            sum += inp[i][j]
            temp++
            if(sum !=0 && sum != temp){
                return -1
            }
        }
    }

    if(sum == 0){
        return 0 // white
    }
    else{
        return 1 // blue
    }
}
