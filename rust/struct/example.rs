use crate::models::{Item, Color, Point, Guest, Admin};
use crate::unithandle::{create_item_instance, check_permission_guest, check_permission_admin};

pub fn classic_struct() {
    let mut item1 = create_item_instance(String::from("Hello"));
    item1.name = String::from("Sun");

    let item2 = Item {
        id : item1.id,
        name : item1.name,
        birth : String::from("Earth"),
        price : item1.price,
    };

    let item3 = Item {
        birth : String::from("Mars"),
        ..item2
    };

    // println!("Item1 : {:?}", item1);
    // println!("Item2 : {:?}", item2);
    println!("Item3 : {:?}", item3);

    let item4 = item3;
    println!("Item4 : {:?}", item4);
}

pub fn tuple_struct() {
    let black = Color(0, 0, 0);
    let point = Point(0, 0, 0);

    println!("Black color : ({}, {}, {})", black.0, black.1, black.2);
    println!("Origin point : ({}, {}, {})", point.0, point.1, point.2);

    // black = point;
}

pub fn unit_struct() {
    let user1 = Guest;
    let user2 = Admin;

    check_permission_guest(user1);
    check_permission_admin(user2);

    // check_permission_admin(user1);
}