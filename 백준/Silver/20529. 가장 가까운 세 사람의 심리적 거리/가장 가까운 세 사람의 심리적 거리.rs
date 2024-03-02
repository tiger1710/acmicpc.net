
fn diff(a: &str, b: &str) -> usize {
    a.chars()
        .zip(b.chars())
        .fold(0, |acc, (cha, chb)| if cha != chb { acc + 1 } else { acc })
}

fn main() {
    let mut buf = String::new();
    std::io::stdin()
        .read_line(&mut buf)
        .expect("Failed to read from stdin");

    let t = buf.trim().parse::<usize>().expect("Failed to parse t");

    for _ in 0..t {
        let mut buf = String::new();
        std::io::stdin()
            .read_line(&mut buf)
            .expect("Failed to read from stdin");
        let _ = buf.trim().parse::<usize>().expect("Failed to parse n");
        buf = String::new();
        std::io::stdin()
            .read_line(&mut buf)
            .expect("Failed to read from stdin");
        let n = buf.split_whitespace().count();
        if 32 < n {
            println!("0");
            continue;
        }

        let mbties: Vec<_> = buf.split_whitespace().collect();

        let mut min_diff = usize::MAX;
        for (i, a) in mbties.iter().enumerate() {
            for (k, b) in mbties.iter().enumerate().skip(i + 1) {
                for c in mbties.iter().skip(k + 1) {
                    let d = diff(a, b) + diff(b, c) + diff(c, a);
                    min_diff = min_diff.min(d);
                }
            }
        }

        println!("{min_diff}");
    }
}
