fn main() {
    copy_test1();
    copy_test2();
}

fn copy_test1() {
    let s1 = String::from("hello");
    let s2 = s1.clone();    // 깊은 복사
    
    println!("s1 = {}, s2 = {}", s1, s2);

    let s3 = s2;
    println!("s3 = {}", s3);
    // println!("s2 = {}", s2); // 에러 발생"
}

#[derive(Copy, Clone, Debug)]
struct Point {
    _x: i32,
    _y: i32
}

fn copy_test2() {
    let a = 10;
    let b = a;
    println!("a = {}, b = {}", a, b);

    let bool1 = true;
    let bool2 = bool1;
    println!("bool1 = {}, bool2 = {}", bool1, bool2);

    // "123" 은 &str(문자열 슬라이스)타입이라 copy 가능
    // 프로그램 실행 파일 안에 박혀 있는 데이터를 가리키는 포인터이기 때문
    let tuple1 = (1, 2.0, "123");
    let tuple2 = tuple1;
    println!("tuple1 = {:?}, tuple2 = {:?}", tuple1, tuple2);

    let array_a = [1,2,3];
    let array_b = array_a;
    println!("array_a = {:?}, array_b = {:?}", array_a, array_b);

    let p1 = Point { _x: 10, _y: 20 };
    let p2 = p1;
    println!("p1: {:?}, p2: {:?}", p1, p2);
}