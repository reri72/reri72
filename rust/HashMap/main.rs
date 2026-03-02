use std::collections::HashMap;

fn main() {
    let mut scores = create_hashmap();
    access_hashmap_val(&scores);
    update_hashmap_val(&mut scores);
    iterate_hashmap(&scores);
}

fn create_hashmap() -> HashMap<String, i32> {
    let mut scores = HashMap::new();

    scores.insert(String::from("Red"), 10);
    scores.insert(String::from("Blue"), 20);

    println!("{:?}", scores);

    scores
}

fn access_hashmap_val(scores: &HashMap<String, i32>) {
    let name = String::from("Blue");
    let _score = scores.get(&name).copied().unwrap_or(0);

    if let Some(score) = scores.get(&name) {
        println!("The score of {} is {}", name, score);
    } else {
        println!("{} does not have a score.", name);
    }
}

fn update_hashmap_val(scores: &mut HashMap<String, i32>) {
    scores.insert(String::from("Red"), 1);
    scores.entry(String::from("Yellow")).or_insert(5);

    let text = "hello world hello rust";
    let mut map = HashMap::new();
    
    for word in text.split_whitespace() {
        let count = map.entry(word).or_insert(0);
        *count += 1;
    }

    println!("{:?}", map);
}

fn iterate_hashmap(scores: &HashMap<String, i32>) {
    for (key, val) in scores {
        println!("{}: {}", key, val);
    }
}