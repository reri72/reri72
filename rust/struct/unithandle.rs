use crate::models::{Item, Guest, Admin};

pub fn create_item_instance(name : String) -> Item {
    Item {
        id: 1,
        name,
        birth: String::from("Unknown"),
        price:9.99,
    }
}

pub fn check_permission_guest(_: Guest) {
    println!("비허용");
}

pub fn check_permission_admin(_: Admin) {
    println!("허용");
}