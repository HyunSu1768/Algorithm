package boj

fun main(){
    readLine()!!.split(" ").sumOf { it.toLong() }.also {
        println(it)
    }
}