use std::io::stdin;
use std::fmt::Write;

fn go(graph: &[Vec<usize>], visited: &mut [bool], u: usize, parent: &mut [usize]) {
    visited[u] = true;
    for &v in &graph[u] {
        if visited[v] {
            continue;
        }

        parent[v] = u;
        go(graph, visited, v, parent);
    }
}

fn main() {
    let mut buf = String::new();
    stdin().read_line(&mut buf).expect("Failed to read line");
    let n = buf.trim().parse().expect("Failed to parse input");

    // input
    let mut graph = vec![vec![]; n];
    for _ in 0..n - 1 {
        let mut uv = String::new();
        stdin().read_line(&mut uv).expect("Failed to read line");
        let mut uv = uv
            .split_whitespace()
            .map(|str| str.parse().expect("Failed to parse input"));
        let u: usize = uv.next().expect("Failed to read input");
        let v = uv.next().expect("Failed to read input");

        graph[u - 1].push(v - 1);
        graph[v - 1].push(u - 1);
    }

    let mut parent = vec![0usize; n];
    go(&graph, &mut vec![false; n], 0, &mut parent);

    let mut output = String::new();
    for i in &parent[1..] {
        writeln!(output, "{i}", i = i + 1).expect("Failed to write output");
    }
    print!("{output}");
}
