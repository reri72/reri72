fn main() {
    number_slice();
    string_slice();

    let arr = [1, 2, 3, 4, 5, 6];
    let vec = vec![10, 20, 30, 40, 50, 60];
    argument_slice(&arr);
    argument_slice(&vec);

    mutable_slice();
}

fn number_slice() {
    let numbers = [1,2,3,4,5];
    let slice = &numbers[0..4]; // 1 to 4

    let mut sum = 0;
    for item in slice
    {
        sum += item;
    }

    let sub_slice = &slice[0..2];   // 1 to 2

    println!("Sum of slice: {}", sum);
    println!("Sub-slice element: {:?}", sub_slice);
}

fn string_slice() {
    let message = String::from("Hello, World!");
    let world = &message[7..];
    let hello = &message[..5];

    println!("full message : '{}'", message);
    println!("slice1 : '{}' ", hello);
    println!("slice2 : '{}'", world);
}

fn argument_slice(data: &[i32]) {
    if data.len() >= 3 {
        println!("첫 세 요소 : {:?}", &data[0..3]);
    } else {
        println!("데이터 요소 길이가 3보다 작음. ({})", data.len());
    }
}

fn mutable_slice() {
    let mut arr = [1,2,3,4,5];
    let slice = &mut arr[0..3];
    
    for item in slice
    {
        (*item) *= 10;
    }

    println!("수정된 배열 : {:#?}", arr);
}