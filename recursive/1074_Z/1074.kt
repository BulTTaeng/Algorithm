package com.example.appprac

import kotlin.math.pow
import kotlin.math.sqrt

var n = 0
var ans = 0
var count = 0

fun main() = with(System.`in`.bufferedReader()) {
    val (N, r, c) = readLine().split(" ").map { it.toInt() }
    n = 2.0.pow(N).toInt()

    recur(n,0,0,r,c)

    println(ans)
}

fun recur(n : Int, row :Int , col : Int,  r: Int , c : Int) {

    if(row == r && c == col){
        ans = count
        return
    }

    if(row + n > r && col + n > c && row <= r && col <=c){
        recur(n/2 , row, col ,r , c)
        recur(n/2 ,row , col+n/2 , r, c)
        recur(n/2 ,row+n/2 , col , r, c)
        recur(n/2 ,row+n/2 , col+n/2 , r, c)
    }
    else{
        count += n*n
    }
}
