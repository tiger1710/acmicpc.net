// 18110 solved.ac

use std::io::Read;

fn main() {
    let mut input = String::new();
    std::io::stdin()
        .read_to_string(&mut input)
        .expect("read error");
    let mut input = input
        .split_whitespace()
        .skip(1)
        .map(|str| str.parse().expect("parse error"))
        .collect::<Vec<usize>>();

    input.sort();

    let trim_count = (input.len() as f64 * 0.15).round() as usize;

    let result = input[trim_count..input.len() - trim_count]
        .iter()
        .sum::<usize>() as f64
        / (input.len() - trim_count * 2) as f64;

    println!("{result}", result = result.round() as usize);
}
