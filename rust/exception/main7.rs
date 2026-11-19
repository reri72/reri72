use std::num::ParseIntError;

fn parse_num(s: &str) -> Result<i32, ParseIntError> {
    let n = s.parse::<i32>()?;
    Ok(n)
}

// main에서도 ? 가능
fn main() -> Result<(), ParseIntError> {
    let ans = parse_num("10")?;
    println!("result: {}", ans);
    Ok(())
}