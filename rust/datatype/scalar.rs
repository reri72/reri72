fn main() {
    let int8: i8 = 8;
    let int16: i16 = 16;
    let int32: i32 = 65;
    let int64: i64 = 64;
    let int128: i128 = 128;

    let uint8: u8 = 8;
    let uint16: u16 = 16;
    let uint32: u32 = 32;
    let uint64: u64 = 64;
    let uint128: u128 = 128;

    let i:isize = 32;
    let u:usize = 64;

    println!("Signed Integers: {}, {}, {}, {}, {}", int8, int16, int32, int64, int128);
    println!("Unsigned Integers: {}, {}, {}, {}, {}", uint8, uint16, uint32, uint64, uint128);
    println!("isize: {}, usize: {}", i, u);

    let x = 2.0;
    let y: f32 = 3.0;

    println!("x: {}, y: {}", x, y);


    let t = true;
    let f: bool = false;

    println!("t: {}, f: {}", t, f);


    let a = 'a';
    let b : char = 'b';
    let c = '히';
    let d : char = '😎';

    println!("Characters: {}, {}, {}, {}", a, b, c, d);
}