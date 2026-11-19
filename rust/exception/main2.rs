use std::fs::File;

fn main() {
    let openfile = match File::open("text.txt") {
        Ok(file) => file,
        Err(error) => panic!("file open failed: {:?}", error),
    };
    /*
        thread 'main' (8865) panicked at main2.rs:6:23:
        file open failed: Os { code: 2, kind: NotFound, message: "No such file or directory" }
        note: run with `RUST_BACKTRACE=1` environment variable to display a backtrace
    */
}