fn main() {
    create_string();

    merge_string1();
    merge_string2();

    iter_push();
    iter_format();
    iter_chars();
    iter_bytes();
}

fn create_string() {
    // heap에 공간을 할당할 준비가 된 상태
    let s = String::new();
    println!("s is [{s}]");

    // String::from -> 문자열 리터럴(&str)을 소유권이 있는 heap mem으로 복사
    let s = String::from("Hello");
    println!("s is [{s}]");

    // to_string() -> Display 트레이트가 구현된 타입을 String으로 변환
    let s = "Hello".to_string();
    println!("s is [{s}]");
}

fn merge_string1() {
    let s1 = String::from("Hello ");
    let s2 = String::from("World");

    // s1 + &s2의 내부 동작: fn add(self, s: &str) -> String
    let s = s1 + &s2; // s1은 소유권 이동되어 사용 불가
    println!("s is [{s}]");
}

fn merge_string2() {
    let s1 = String::from("Hello");
    let s2 = String::from("World");

    // 소유권 이동 없음
    // 여러 문자열 결합 시 가장 많이 사용 됨
    let s = format!("{} {}", s1, s2);
    println!("s is [{s}]");
}

fn iter_push() {
    let mut s = String::new();
    for _ in 0 .. 3 {
        // push_str -> 기존 힙 메모리 공간에 문자열을 추가 (성능상 효율적)
        s.push_str("hi");
    }
    println!("s is [{s}]");
}

fn iter_format() {
    let mut s = String::new();
    for _ in 0..3 {
        // 기존 s에 있던 데이터는 매번 버려짐
        s = format!("{}hi", s);
    }
    println!("s is [{s}]");
}

fn iter_chars() {
    let s = String::from("가나다라");
    for c in s.chars() {
        print!("{c}");
    }
    println!();
}

fn iter_bytes() {
    let s = String::from("가");
    for b in s.bytes() {
        print!("{b} ");
    }
    println!();
}
