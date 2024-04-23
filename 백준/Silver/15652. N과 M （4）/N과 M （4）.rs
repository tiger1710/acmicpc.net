use std::io::stdin;

fn print_series(stack: &mut Vec<usize>, idx: usize, n: usize, m: usize) {
    if stack.len() == m {
        for k in stack.iter() {
            print!("{k} ");
        }
        println!();
        return;
    }

    for i in idx..=n {
        stack.push(i);
        print_series(stack, i, n, m);
        stack.pop();
    }
}

fn main() {
    let mut buf = String::new();
    stdin().read_line(&mut buf).expect("Failed to read line");
    let mut buf = buf.split_whitespace();
    let n = buf
        .next()
        .expect("Failed to read n")
        .parse()
        .expect("Failed to parse n");
    let m = buf
        .next()
        .expect("Failed to read m")
        .parse()
        .expect("Failed to parse m");

    let mut stack = Vec::new();
    print_series(&mut stack, 1, n, m);
}
