fn main() {
    back_of_house::fix_incorrect_order();
}

fn deliver_orders() {
    println!("Delivering orders...");
}

mod back_of_house {
    pub fn fix_incorrect_order() {
        cook_order();
        super::deliver_orders();
    }

    fn cook_order() {
        println!("Cooking order...");
    }
}
