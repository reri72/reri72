
fn main() {
    basic_if();
    expression_if();
    pattern_if();
}

fn basic_if() {
    let num = 7;

    if num < 5 {
        println!("5보다 작음");
    } else if num == 7 {
        println!("num : 7");
    } else {
        println!("그 외 숫자");
    }
}

fn expression_if() {
    let condition = true;
    let num = if condition { 5 } else { 6 };

    println!("num : {}", num);
}

fn pattern_if() {
    let some_val: Option<i32> = Some(10);

    match some_val {
        Some(i) => println!("val : {i}"),
        None => (),
    }

    if let Some(i) = some_val {
        println!("val : {i}");
    }
}