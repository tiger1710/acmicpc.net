
fn calculate_subsum(interval: &str) -> isize {
    interval.split('+').map(|str| str.parse::<isize>().expect("Failed to parse")).sum()
}

fn main() {
    let mut buf = String::new();
    std::io::stdin()
        .read_line(&mut buf)
        .expect("Failed to read from stdin");

    let mut buf = buf.trim().split('-');

    let mut sum = calculate_subsum(buf.next().expect("Failed to parse"));
    for interval in buf {
        sum -= calculate_subsum(interval);
    }

    println!("{sum}");
}
