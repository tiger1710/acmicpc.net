use std::io::stdin;
use std::fmt::Write;

fn main() {
    let mut buf = String::new();
    stdin().read_line(&mut buf).expect("Failed to read line");
    let mut buf = buf
        .split_whitespace()
        .map(|str| str.parse().expect("Failed to parse"));

    let n: usize = buf.next().expect("Failed to get n");
    let m = buf.next().expect("Failed to get m");

    let mut table: Vec<Vec<usize>> = vec![];
    for _ in 0..n {
        let mut buf = String::new();
        stdin().read_line(&mut buf).expect("Failed to read line");
        let row = buf
            .split_whitespace()
            .map(|str| str.parse().expect("Failed to parse"))
            .collect();
        table.push(row);
    }

    let mut acc = vec![vec![0; n + 1]; n + 1];
    for r in 0..n {
        for c in 0..n {
            acc[r + 1][c + 1] = table[r][c] + acc[r][c + 1] + acc[r + 1][c] - acc[r][c];
        }
    }

    let mut output = String::new();
    for _ in 0..m {
        let mut buf = String::new();
        stdin().read_line(&mut buf).expect("Failed to read line");
        let mut buf = buf
            .split_whitespace()
            .map(|str| str.parse().expect("Failed to parse"));

        let r1: usize = buf.next().expect("Failed to get c1");
        let c1 = buf.next().expect("Failed to get r1");
        let r2 = buf.next().expect("Failed to get c2");
        let c2 = buf.next().expect("Failed to get r2");

        let result = acc[r2][c2] + acc[r1 - 1][c1 - 1] - acc[r1 - 1][c2] - acc[r2][c1 - 1];
        writeln!(output, "{result}").expect("Failed to write to output");
    }
    println!("{output}");
}
