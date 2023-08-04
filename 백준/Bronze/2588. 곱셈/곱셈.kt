package boj

fun main(){
    val a = readLine().orEmpty().toInt()
    val b = readLine().orEmpty().toString()
    println(a * b[2].toString().toInt())
    println(a * b[1].toString().toInt())
    println(a * b[0].toString().toInt())
    println(a * b.toInt())
}