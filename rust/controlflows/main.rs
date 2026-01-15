
fn main() {
    check_num1();
    check_num2();
    check_match1();
    check_match2();
    loop_test1();
    loop_test2();
    loop_test3();
    loop_test4();
    loop_test5();
}

fn check_num1() {
    let number = 7;

    if number > 0 {
        println!("The number is positive.");
    } else if number < 0 {
        println!("The number is negative.");
    } else {
        println!("The number is zero.");
    }
}

fn check_num2() {
    let number = 10;

    if number != 0 {
        println!("The number is non-zero.");
    }

    let check = true;
    let number = if check { 10 } else { 0 };

    println!("The number is: {}", number);
}

fn check_match1() {
    let number = 13;
    match number {
        1 => println!("1"),
        2 | 3 | 5 | 7 | 11 => println!("소수"),
        10..=19 => println!("10대"),
        20..=29 => println!("20대"),
        30..=39 => println!("30대"),
        40..=49 => println!("40대"),
        50..=59 => println!("50대"),
        _ => println!("그 외"), // None 만 뜻하는게 아니라 나머지 싹 다.
    }
}

fn check_match2() {
    let names = ["철수", "영희"];
    let result = names.get(10); // 10번째 찾기

    if let Some(name) = result {
        println!("찾은 이름 : {name}");
    } else {
        println!("그런 이름 없음");
    }
}

fn loop_test1() {
    let mut count = 0;
    loop {
        println!("loop! ({})", count);
        count += 1;
        if count == 5 {
            break;
        }
    }

    println!("count : {}", count);
}

fn loop_test2() {
    let mut number = 3;

    while number != 0 {
        println!("{number}!");
        number -= 1;
    }

    println!("zero!");
}

fn loop_test3() {

    // 배열 순회
    let a = [10, 20, 30, 40, 50];
    for element in a {
        println!("값: {element}");
    }

    for item in a.iter() {
        println!("for loop ({})", item);
    }

    // 1부터 3까지 반복
    for number in 1..4 {
        println!("{number}");
    }

    // 3부터 1까지 반복
    for number in (1..4).rev() {
        println!("rev ({})", number);
    }
}

fn loop_test4() {
    'outer: loop {
        println!("Entered the outer loop");
        
        loop {
            println!("Entered the inner loop");

            break 'outer;
        }
    }
    println!("Exited the outer loop");
}

fn loop_test5() {
    'outer: for x in 1..=2 {
        println!("구구단 {} 단 시작!", x);
        for y in 1..11 {
            if y == 10 {
                continue 'outer;
            }
            println!("{} x {} = {}", x, y, x * y);
        }
    }
}
