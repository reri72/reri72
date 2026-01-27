#[derive(Debug)]
pub struct Item {
    pub id : u32,
    pub name : String,
    pub birth : String,
    pub price : f32,
}

pub struct Color(pub u8, pub u8, pub u8);
pub struct Point(pub u8, pub u8, pub u8);

pub struct Guest;
pub struct Admin;