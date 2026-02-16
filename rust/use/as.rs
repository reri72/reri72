use std::fmt::Result;
use std::io::Result as IoResult;

fn func1() -> Result {
    Ok(())
}

fn func2() -> IoResult<()> {
    Ok(())
}

fn main() {
    match func1() {
        Ok(_) => println!("func1 succeeded"),
        Err(e) => println!("func1 failed: {:?}", e),
    }

    match func2() {
        Ok(_) => println!("func2 succeeded"),
        Err(e) => println!("func2 failed: {:?}", e),
    }
}
