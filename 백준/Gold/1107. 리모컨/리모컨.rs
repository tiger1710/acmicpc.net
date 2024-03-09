
use std:: io::Read;

fn main() {
    let mut buf = String::new();
    std::io::stdin()
        .read_to_string(&mut buf)
        .expect("Failed to read from stdin");

    let mut buf = buf
        .split_whitespace()
        .map(|str| str.parse().expect("Failed to parse number"));
    let n: u32 = buf.next().expect("Failed to read n");
    let broken: Vec<_> = buf.skip(1).collect();

    let mut ans = n.abs_diff(100);
    for i in 0..1000000u32 {
        let num = i.to_string();
        for (idx, c) in num.char_indices() {
            if broken.contains(&c.to_digit(10).expect("Failed to parse number")) {
                break;
            }

            if idx == num.len() - 1 {
                ans = ans.min(num.len() as u32 + i.abs_diff(n));
            }
        }
    }

    println!("{ans}");
}
