// use std::cmp::Ordering;
// use std::io;

// 중괄호를 사용하여 사용
use std::{cmp::Ordering, io};

// 자기 자신(io)과 하위 아이템 (Write)를 사용
use std::io::{self, Write};

fn main() {
    let order = Ordering::Less;
    let result: io::Result<()> = Ok(());

    let mut buffer = Vec::new();
    buffer.write_all(b"Hello, world!").unwrap();
}