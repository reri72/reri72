fn main() {
    test1();
    test2();
    test3();
    test4();
}

fn test1() {
    let mut v1: Vec<i32> = Vec::new();
    let v2 = vec![1,2,3];
    let v3: Vec<i32> =Vec::with_capacity(10);

    v1.push(10);

    println!("v1: {:?}, v2: {:?}, v3: {:?}", v1, v2, v3);
}

fn test2() {
    let mut v = Vec::new();

    // 위에 i32라고 명시하지 않았지만
    // push 메서드에서 i32 타입이 추론되어
    // v는 Vec<i32> 타입이 된다.
    v.push(1);
    v.push(2);
    v.push(3);
    println!("v: {:?}", v);
}

fn test3() {
    let v1 = vec![1,2,3,4,5];
    let mut v2 = vec![1,2,3,4,5];

    // indexing
    let third: &i32 = &v1[2];
    println!("third is {}", third);

    // get method
    let third: Option<&i32> = v1.get(2);
    match third {
        Some(third) => println!("third is {third}"),
        None => println!("x"),
    }

    for i in &mut v2 {
        *i *= 10;
    }

    println!("v2: {:?}", v2);
}

#[derive(Debug)]
enum Person {
    Height(i32),
    Weight(f64),
    Name(String),
}

fn test4() {
    let row = vec![
        Person::Height(160),
        Person::Name(String::from("Reri")),
        Person::Weight(48.7),
    ];

    for cell in &row {
        // enum을 꺼낼 때에는 반드시 match를 사용해야 한다.
        match cell {
            Person::Height(i) => println!("Height: {i}"),
            Person::Weight(f) => println!("Weight: {f}"),
            Person::Name(s) => println!("Name: {s}"),
        }
    }
}