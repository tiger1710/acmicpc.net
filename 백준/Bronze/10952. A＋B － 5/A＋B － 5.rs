// 10952 A+B - 5

use std::io::{self, Read};
use std::fmt::Write;

fn main() {
    let mut input = String::new();
    let mut output = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut input: Vec<i32> = input
        .split_whitespace()
        .map(|str| str.parse().expect("can't parse"))
        .collect();
    input.pop();
    input.pop();

    input.chunks(2).for_each(|chunk| {
        let a = chunk[0];
        let b = chunk[1];
        let sum = a + b;
        writeln!(output, "{sum}").expect("can't write to output");
    });

    println!("{output}");
}
