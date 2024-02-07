// 18870 좌표 압축

use std::fmt::Write;
use std::io::Read;

fn main() {
    let mut input = String::new();
    let mut output = String::new();
    std::io::stdin().read_to_string(&mut input).expect("read error");
    let mut p: Vec<(usize, isize)> = input.split_whitespace().skip(1).map(|str| str.parse().expect("parse error")).enumerate().collect();

    p.sort_by(|(_, a), (_, b)| a.cmp(b));

    let mut cnt = 0;
    let mut prev = p[0].1;

    for (_, x) in p.iter_mut() {
        if prev < *x {
            cnt += 1;
            prev = *x;
        }
        *x = cnt;
    }

    p.sort_by(|(a, _), (b, _)| a.cmp(b));

    for (_, v) in p {
        write!(output, "{v} ").expect("write error");
    }

    println!("{output}");
}
