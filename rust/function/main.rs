fn main() {
    let x = 5;
    let y = {
        let x = 3;
        x + 1
    };

    println!("x: {}, y: {}", x, y);
    small_function();

    // 사용할 때 컴파일러가 알아서 타입을 채워 줌
    print_val(10); // T는 i32
    print_val(3.14); // T는 f64
    print_val("안녕"); // T는 &str

    println!("{:?}", divide(10, 2));
    println!("divide(10, 2) 결과 : {}, 성공?{}, 실패?{}", 
                divide(10, 2).unwrap_or(-1), //unwrap() 쓰면 실패시 프로그램 종료
                divide(10, 2).is_ok(),
                divide(10, 2).is_err());

    println!("{:?}", divide(10, 0));
    println!("divide(10, 0) 결과 : {}, 성공?{}, 실패?{}",
                divide(10, 0).unwrap_or(-1),
                divide(10, 0).is_ok(),
                divide(10, 0).is_err());
}

#[inline]
fn small_function() {
    println!("inline function");
}

// <T: std::fmt::Display> 는 출력이 가능한 타입만 받겠다고 제한을 거는 것
fn print_val<T: std::fmt::Display>(value: T) {
    println!("{}", value);
}

// 숫자를 나누는 함수
fn divide(a: i32, b: i32) -> Result<i32, String> {
    if b == 0 {
        Err(String::from("0으로 나눌 수 없음!"))
    } else {
        Ok(a / b)
    }
}