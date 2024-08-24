use std::io::{stdin, Read};

fn get_output(i: usize) -> String {
    if i % 3 == 0 && i % 5 == 0 {
        "FizzBuzz".to_owned()
    } else if i % 3 == 0 {
        "Fizz".to_owned()
    } else if i % 5 == 0 {
        "Buzz".to_owned()
    } else {
        i.to_string()
    }
}

fn main() {
    let mut buf = String::new();
    stdin()
        .read_to_string(&mut buf)
        .expect("Failed to read line");
    let buf: Vec<_> = buf.split_whitespace().collect();

    for (i, str) in buf.iter().enumerate() {
        if let Ok(num) = str.parse::<usize>() {
            println!("{ans}", ans = get_output(num + (3 - i)));
            break;
        }
    }
}
