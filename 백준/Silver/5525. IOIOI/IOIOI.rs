use std::io::Read;

fn main() {
    let mut buf = String::new();
    std::io::stdin()
        .read_to_string(&mut buf)
        .expect("Failed to read from stdin");

    let mut buf = buf.split_whitespace();
    let n = buf.next().expect("Failed to read n").parse::<usize>().expect("Failed to parse n");
    let s = buf.skip(1).next().expect("Failed to read S");
    let p = "IO".repeat(n) + "I";

    let mut count = 0;
    let end = s.len() - p.len() + 1;
    for i in 0..end {
        if s[i..i + p.len()].contains(&p) {
            count += 1;
        }
    }
    println!("{count}");
}