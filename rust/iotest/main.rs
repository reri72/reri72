use std::io;
use std::io::Write;

fn echo_name() -> io::Result<()> {
    let mut name = String::new();

    print!("이름 입력 : ");
    io::stdout().flush()?;
    io::stdin().read_line(&mut name)?;
    println!("[{}:{}] 안녕 {} 아 ~", file!(), line!(), name.trim());

    Ok(())
}

fn get_name_return() -> io::Result<String> {
    let mut name = String::new();

    print!("이름 입력 : ");
    io::stdout().flush()?;
    io::stdin().read_line(&mut name)?;

    Ok(name.trim().to_string())
}

fn main() {
    echo_name().expect("입력 중 에러 발생");

    let name = get_name_return().expect("이름 가져오기 실패");
    println!("[{}:{}] 가져온 이름 : {}", file!(), line!(), name);
}