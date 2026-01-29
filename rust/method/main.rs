#[derive(Debug)]
struct Rectangle {
    width: u32,
    height: u32,
}

struct Counter {
    count : u32,
}

impl Rectangle {
    fn area(&self) -> u32 {
        self.width * self.height
    }

    fn width(&self) -> bool {
        self.width > 0
    }

    fn can_hold(&self, other: &Rectangle) -> bool {
        self.width > other.width && self.height > other.height
    }
}

impl Rectangle {
    fn square(size: u32) -> Self { // Self 대신 Rectangle 로 써도 됨
        Self {
            width: size,
            height: size,
        }
    }
}

impl Counter {
    fn default_value() -> u32 { 0 }

    fn increment(&mut self) {
        self.count += 1;
    }
}

fn main() {
    method_ex();
    assoc_ex();
    counter_ex();
}

fn method_ex() {
    let rect1 = Rectangle {
        width: 30,
        height: 50,
    };

    let rect2 = Rectangle {
        width: 10,
        height: 40,
    };
    
    println!("rect1 : {:?}", rect1.area());
    if rect1.width() {
        println!("rect1 width's val : {}, {}", 
                    rect1.width, rect1.width());
    }

    println!("rect1 can hold rect2 : {}", rect1.can_hold(&rect2));
}

fn assoc_ex()  {
    let rect3 = Rectangle::square(40);
    println!("square rect3 : {:?}", rect3);
}

fn counter_ex() {
    let mut counter = Counter{ count: Counter::default_value() };
    let mut i = 0;

    while i < 5 {
        counter.increment();
        i += 1;
    };

    println!("Counter's count : {}", counter.count);
}
