use std::io::stdin;

fn go(a: u128, b: u128, c: u128) -> u128 {
    if b == 0 {
        return 1;
    }

    let half = go(a, b / 2, c) % c;
    let half_square = (half * half) % c;

    if b % 2 == 0 {
        half_square
    } else {
        a * half_square % c
    }
}

// 10 11 12
fn main() {
    let mut buf = String::new();
    stdin().read_line(&mut buf).expect("Failed to read line");
    let mut buf = buf.split_whitespace().map(|str| str.parse().expect("parse error"));
    let a: u128 = buf.next().expect("Failed to get a");
    let b = buf.next().expect("Failed to get b");
    let c = buf.next().expect("Failed to get c");
    let ans = go(a, b, c);
    println!("{ans}");
}
