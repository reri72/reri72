package main

// 모든 Go 프로그램은 패키지로 구성 됨

import (
	"fmt"
	"math"
)

/*
var 문은 변수 목록을 선언 함
패키지 수준이나 함수 수준에 둘 수 있음
*/
var c, python, java bool
var one, two int = 1, 2

func add(x int, y int) int {
	return x + y
}

func mult(x, y int) int {
	return x * y
}

func swap(x, y string) (string, string) {
	return y, x
}

/*
인수 없는 반환
반환값의 의미를 설명하는 데 사용
*/
func split(sum int) (x, y int) {
	x = sum * 4 / 9
	y = sum - x
	return
}

func main() {
	fmt.Println("hello") // hello

	/*
		패키지를 import 하면 그 패키지의 공개된 이름만 사용 가능
		 > 이름이 대문자로 시작하면 공개 이름
	*/
	fmt.Println(math.Pi)    // 3.141592653589793
	fmt.Println(add(1, 2))  // 3
	fmt.Println(mult(2, 3)) // 6

	// := 짧은 대입문으로 암시적 타입을 사용하는 var 선언을 대신할 수 있음
	a, b := swap("hello", "world")
	println(a, b) // world hello

	fmt.Println(split((17))) // 7 10

	var i int
	fmt.Println(i, c, python, java) // 0 false false false

	fmt.Println(one, two) // 1 2
}
