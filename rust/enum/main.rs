enum Light {
    On,
    Off,
}

impl Light {
    fn new() -> Self {
        Light::Off
    }

    fn status(&self) {
        match self {
            Light::On => println!("ON"),
            Light::Off => println!("OFF"),
        }
    }

    fn toggle(&mut self) {
        match self {
            Light::On => *self = Light::Off,
            Light::Off => *self = Light::On,
        }
    }
}

enum Direction {
    Up,
    Down,
    Left,
    Right,
}

enum Message {
    Quit,
    Move {x: i32, y: i32},
    Write(String),
    ChangeColor(i32, i32, i32),
}

fn main() {
    let msg = Message::ChangeColor(255,255,255);
    process(msg);

    let mut lamp = Light::new();
    lamp.status();
    lamp.toggle();
    lamp.status();    
}

fn process(msg: Message) {
    match msg {
        Message::Quit => println!("quit"),
        Message::Move{x,y} => println!("x :{}, y :{}", x, y),
        Message::Write(text) => println!("msg : {}", text),
        Message::ChangeColor(r,g,b) => println!("r:{}, g:{}, b:{}", r, b, g),
    }
}
