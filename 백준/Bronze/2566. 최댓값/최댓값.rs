use std::io::Read;

fn main() {
    let mut input = String::new();
    std::io::stdin()
        .read_to_string(&mut input)
        .expect("Failed to read from stdin");

    let input = input
        .split_whitespace()
        .map(|str| str.parse::<usize>().expect("Failed to parse number"))
        .enumerate()
        .max_by(|(_, a), (_, b)| a.cmp(b))
        .expect("Failed to find max");

    let r = input.0 / 9 + 1;
    let c = input.0 % 9 + 1;
    let v = input.1;

    println!("{v}\n{r} {c}");
}
