use std::fs::File;
use std::io::ErrorKind;

fn main() {
    let open_file = match File::open("text.txt") {
        Ok(file) => file,
        Err(error) => match error.kind() {
            ErrorKind::NotFound => match File::create("text.txt") {
                Ok(fc) => fc,
                Err(e) => panic!("file create failed: {:?}", e),
            },
            other_error => panic!("file open failed: {:?}", other_error),
        },
    };
}