fn main() {
    let s1 = String::from("hello");

    let (s2, len) = calc_length1(s1);
    println!("The length of '{}' is {}.", s2, len);

    let len = calc_length2(&s2);
    println!("The length of '{}' is {}.", s2, len);

    //------------------------------------------------
    let s = String::from("hello");
    change_string1(&s);

    let mut s = String::from("hello");
    change_string2(&mut s);
    println!("change string: {}", s);
}

fn calc_length1(s: String) -> (String, usize) {
    let length = s.len();
    (s, length)
}

fn calc_length2(s: &String) -> usize {
    s.len()
}

fn change_string1(_s: &String) {
    // s.push_str(", world!");
}

fn change_string2(s: &mut String) {
    s.push_str(", world!");
}

fn check_mutable_ref() {
    let mut s = String::from("hello");
    let test1 = &mut s;
    //let test2 = &mut s;

    println!("{}", test1);
}

fn check_non_mutable_ref() {
    let mut _s = String::from("hello");
    let _r1 = &_s;
    let _r2 = &_s;

    //let r3 = &mut s; 
}

fn check_dangle_ref() {
    // let _first = return_dangle();
    let _second = return_normal();
}

/*
fn return_dangle() -> &String {
    let s = String::from("text");
    &s
}
*/

fn return_normal() -> String {
    let s = String::from("text");
    s
}