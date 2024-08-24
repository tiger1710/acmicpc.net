use std::io::{stdin, Read};

fn main() {
    let mut buf = String::new();
    stdin()
        .read_to_string(&mut buf)
        .expect("Failed to read line");
    let mut it = buf.split_whitespace();
    let a = it.next().expect("Input error");
    let b = it.next().expect("Input error");
    let c = it.next().expect("Input error");

    let str_calc = (a.to_owned() + b)
        .parse::<isize>()
        .expect("Failed to parse")
        - c.parse::<isize>().expect("Failed to parse");

    let num_calc = a.parse::<isize>().expect("Failed to parse")
        + b.parse::<isize>().expect("Failed to parse")
        - c.parse::<isize>().expect("Failed to parse");

    println!("{num_calc}\n{str_calc}");
}
