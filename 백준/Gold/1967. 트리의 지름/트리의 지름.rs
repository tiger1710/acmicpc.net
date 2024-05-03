use std::io::stdin;

fn dfs(graph: &[Vec<(usize, usize)>], visited: &mut [bool], dist: &mut [usize], u: usize) {
    visited[u] = true;

    for &(v, w) in &graph[u] {
        if visited[v] {
            continue;
        }

        dist[v] = dist[u] + w;
        dfs(graph, visited, dist, v);
    }
}

fn main() {
    let mut buf = String::new();
    stdin().read_line(&mut buf).expect("Failed to read line");
    let n: usize = buf.trim().parse().expect("Failed to parse");

    let mut graph = vec![vec![]; n];
    for _ in 0..(n - 1) {
        let mut buf = String::new();
        stdin().read_line(&mut buf).expect("Failed to read line");
        let mut buf = buf
            .split_whitespace()
            .map(|str| str.parse().expect("Failed to parse"));
        let u: usize = buf.next().expect("Failed to get u");
        let v = buf.next().expect("Failed to get v");
        let w = buf.next().expect("Failed to get w");
        graph[u - 1].push((v - 1, w));
        graph[v - 1].push((u - 1, w));
    }

    let mut visited = vec![false; n];
    let mut dist = vec![0; n];
    dfs(&graph, &mut visited, &mut dist, 0);
    let (v, _) = dist
        .iter()
        .enumerate()
        .max_by(|(_, a), (_, b)| a.cmp(b))
        .expect("Failed to get max distance");

    let mut visited = vec![false; n];
    let mut dist = vec![0; n];
    dfs(&graph, &mut visited, &mut dist, v);
    let (_, ans) = dist
        .iter()
        .enumerate()
        .max_by(|(_, a), (_, b)| a.cmp(b))
        .expect("Failed to get max distance");

    println!("{ans}");
}
