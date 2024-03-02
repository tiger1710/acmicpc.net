use std::io::Read;

fn main() {
    let mut buf = String::new();
    std::io::stdin()
        .read_to_string(&mut buf)
        .expect("Failed to read from stdin");

    let mut buf = buf.split_whitespace();
    let n = buf.next().expect("Failed to read n").parse::<usize>().expect("Failed to parse n");
    let s = buf.skip(1).next().expect("Failed to read S");

    let mut count = 0;
    let mut i = 0;
    let mut length = 0;
    while i < s.len() - 2 {
        if &s[i..i + 3] == "IOI" {
            length += 1;
            if length == n {
                count += 1;
                length -= 1;
            }
            i += 2;
        } else {
            length = 0;
            i += 1;
        }
    }

    println!("{count}");
}
