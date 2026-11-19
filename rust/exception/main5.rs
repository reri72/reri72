use std::num::ParseIntError;

fn parse_num(s: &str) -> Result<i32, ParseIntError> {
    match s.parse::<i32>() {
        Ok(n) => Ok(n),
        Err(e) => return Err(e), // 실패하면 에러를 main으로 넘김
    }
}

fn main() {
    // fail: invalid digit found in string
    match parse_num("2") {
        Ok(n) => println!("success: {}", n),
        Err(e) => println!("fail: {}", e),
    }
}