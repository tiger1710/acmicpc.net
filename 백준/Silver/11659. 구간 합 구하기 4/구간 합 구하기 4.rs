// 11659 구간 합 구하기 4

use std::fmt::Write;
use std::io::Read;

fn main() {
    let mut input = String::new();
    let mut output = String::new();
    std::io::stdin()
        .read_line(&mut input)
        .expect("read error");
    let mut input = input
        .split_whitespace()
        .map(|str| str.parse::<usize>().expect("parse error"));

    let _n = input.next().expect("n error");
    let m = input.next().expect("m error");

    let mut input = String::new();
    std::io::stdin()
        .read_line(&mut input)
        .expect("read error");

    let mut cumulative_sum: Vec<usize> = input.split_whitespace()
        .map(|str| str.parse::<usize>().expect("parse error"))
        .scan(0, |acc, i| {
            *acc += i;
            Some(*acc)
        })
        .collect();
    cumulative_sum.insert(0, 0);

    let mut input = String::new();
    std::io::stdin()
        .read_to_string(&mut input)
        .expect("read error");
    let mut input = input.split_whitespace().map(|str| str.parse::<usize>().expect("parse error"));
    for _ in 0..m {
        let from = input.next().expect("i error") - 1;
        let to = input.next().expect("j error");
        writeln!(output, "{}", cumulative_sum[to] - cumulative_sum[from]).expect("write error");
    }

    print!("{output}");
}
