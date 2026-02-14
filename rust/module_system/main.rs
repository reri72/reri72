mod garden;
mod front_of_house;

mod back_of_house {
    pub struct Breakfase {
        pub toast: String,
        seasonal_fruit: String,
    }

    impl Breakfase {
        pub fn summer(toast: &str) -> Breakfase {
            Breakfase {
                toast: String::from(toast),
                seasonal_fruit: String::from("peaches"),
            }
        }
    }
}

fn main() {
    let mut meal = back_of_house::Breakfase::summer("Rye");
    meal.toast = String::from("Wheat");
    println!("{} toast", meal.toast);

    garden::plant_flower();
    front_of_house::hosting::add_to_waitlist();
}
