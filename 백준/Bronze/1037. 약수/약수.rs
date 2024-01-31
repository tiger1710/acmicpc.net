// 9663 N-Queen
use std::io::{self, Read};
// use std::fmt::Write;

fn main() {
    let mut input = String::new();
    // let mut output = String::new();
    io::stdin().read_to_string(&mut input).unwrap();

    let mut max: usize = 0;
    let mut min: usize = usize::MAX;
    input.trim().split_whitespace().skip(1).for_each(|u| {
        let parsed = u.parse().unwrap();
        max = if max < parsed { parsed } else { max };
        min = if parsed < min { parsed } else { min };
    });
    let ans = min * max;

    println!("{ans}");
}
