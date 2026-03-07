use std::io::Read;

fn main() {
    let mut input = String::new();
    std::io::stdin()
        .read_line(&mut input)
        .expect("Failed to read line");

    let mut input = input
        .split_whitespace()
        .map(|s| s.parse().expect("Failed to parse integer"));

    let _: usize = input.next().expect("Failed to read n");
    let m = input.next().expect("Failed to read m");

    let mut input = String::new();
    std::io::stdin()
        .read_to_string(&mut input)
        .expect("Failed to read input");

    let t = input
        .split_whitespace()
        .map(|s| s.parse::<usize>().expect("Failed to parse integer"))
        .collect::<Vec<_>>();

    let mut l = 1usize;
    let mut h = usize::MAX;

    while l < h {
        let i = l + ((h - l) >> 1);

        let mut count: u128 = 0;
        for x in &t {
            count += (i / x) as u128;
        }

        if m as u128 <= count {
            h = i;
        } else {
            l = i + 1;
        }
    }

    println!("{h}");
}
