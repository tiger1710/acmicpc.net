use std::io::stdin;
use std::fmt::Write;

fn print_series(stack: &mut Vec<usize>, series: &[usize], visited: &mut Vec<bool>, n: usize, m: usize, output: &mut String) {
    if stack.len() == m {
        for k in stack.iter() {
            write!(output, "{k} ").expect("Failed to write");
        }
        writeln!(output).expect("Failed to write");
        return;
    }

    for i in 0..n {
        if visited[i] {
            continue;
        }

        stack.push(series[i]);
        visited[i] = true;
        print_series(stack, series, visited, n, m, output);
        stack.pop();
        visited[i] = false;
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

    let mut buf = String::new();
    stdin().read_line(&mut buf).expect("Failed to read line");
    let mut series: Vec<usize> = buf.split_whitespace().map(|str| str.parse().expect("Failed to parse")).collect();
    series.sort();
    let mut visited = vec![false; n];
    let mut stack = Vec::new();

    let mut output = String::new();
    print_series(&mut stack, &series, &mut visited, n, m, &mut output);
    println!("{output}");
}
