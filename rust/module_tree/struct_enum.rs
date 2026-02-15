mod back_of_house {
    pub struct Breakfast { // 공개 구조체
        pub toast: String, // 공개 필드
        seasonal_fruit: String, // 비공개 필드
    }

    impl Breakfast {
        pub fn summer(toast: &str) -> Breakfast {
            Breakfast {
                toast: String::from(toast),
                seasonal_fruit: String::from("peaches"),
            }
        }
    }
}

#[derive(Debug)]
pub enum Appetizer {
    Soup = 1,
    Salad = 2,
}

impl Appetizer {
    fn choice(&self) {
        println!("You chose an appetizer! ({:?})", self);
    }

    fn appetizer_list() {
        println!("Appetizer options: Soup, Salad");
    }
}

fn main() {
    let mut meal = back_of_house::Breakfast::summer("Rye");
    meal.toast = String::from("Wheat");
    println!("{} toast please", meal.toast);

    let my_choice = Appetizer::Soup;
    Appetizer::appetizer_list();
    my_choice.choice();
}