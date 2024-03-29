use std::{io, fmt::Write, collections::VecDeque};

fn main() {
    let mut input = String::new();
    let mut output: Vec<String> = Vec::new();
    io::stdin().read_line(&mut input).unwrap();
    let mut input = input.as_str().split_whitespace();

    let n: usize = input.next().unwrap().parse().unwrap();
    let k: usize = input.next().unwrap().parse().unwrap();

    let mut queue: VecDeque<usize> = (1..=n).collect();
    while !queue.is_empty() {
        let mut i;
        for _ in 1..k {
            i = queue.pop_front().unwrap();
            queue.push_back(i);
        }
        i = queue.pop_front().unwrap();
        output.push(i.to_string());
    }

    println!("<{}>", output.join(", "));
}
