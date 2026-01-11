fn main() {
    let tuple: (i32, f64, char) = (32, 6.4, 'a');

    // 구조 분해 (Destructuring)
    let (x, y, z) = tuple;
    println!("{} {} {}", x, y, z);

    // 인덱스를 사용한 접근 (0이 첫 번째 색인)
    let first = tuple.0;
    let second = tuple.1;
    let third = tuple.2;
    println!("{} {} {}", first, second, third);


    let a = [10, 20, 30, 40, 50]; // 타입 추론
    let b: [i32; 5] = [10, 20, 30, 40, 50]; // [타입; 개수] 명시적 선언
    let c = [3; 5]; // (초기값; 개수) 3 으로 5개 초기화

    println!("Array a: {:?}, {} to {}", a, a[0], a[4]);
    println!("Array b: {:?}, {} to {}", b, b[0], b[4]);
    println!("Array c: {:?}, {} to {}", c, c[0], c[4]);
}