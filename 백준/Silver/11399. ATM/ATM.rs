// 11399 ATM

use std::io::Read;

fn main() {
    let mut input = String::new();
    std::io::stdin()
        .read_to_string(&mut input)
        .expect("read error");

    let mut t: Vec<usize> = input
        .split_whitespace()
        .skip(1)
        .map(|str| str.parse().expect("parse error"))
        .collect();

    t.sort();

    let total_time: usize = t
        .iter()
        .fold((0, 0), |(acc, curr), time| {
            let ct = curr + time;
            (acc + ct, ct)
        })
        .0;

    println!("{total_time}");
}
