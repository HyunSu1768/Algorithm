package boj

fun main(){
    val (a, b) = readLine().orEmpty().split(" ").map { it -> it.toInt() }
    println(a + b)
    println(a - b)
    println(a * b)
    println(a / b)
    println(a % b)

}