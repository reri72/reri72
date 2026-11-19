use std::fs::File;

fn main() {
    // 실패 시 기본 panic!
    let f1 = File::open("text.txt").unwrap();

    // 실패 시 지정한 메시지와 함께 panic!
    let f2 = File::open("text.txt")
        .expect("text.txt is not exist.");
}