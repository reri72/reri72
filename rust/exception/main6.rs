use std::num::ParseIntError;

fn parse_num(s: &str) -> Result<i32, ParseIntError> {
    let n = s.parse::<i32>()?; // 실패하면 여기서 바로 return Err(e)
    Ok(n)
}

fn main() {
    match parse_num("7") {
        Ok(n) => println!("success: {}", n),
        Err(e) => println!("fail: {}", e),
    }
}