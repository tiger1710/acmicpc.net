use std::io::Read;

fn main() {
    let mut buf = String::new();
    std::io::stdin()
        .read_to_string(&mut buf)
        .expect("Failed to read from stdin");

    let mut buf = buf.split_whitespace().map(|str| str.parse().expect("Failed to parse number"));
    let n = buf.next().expect("Failed to read n");
    let m = buf.next().expect("Failed to read m");

    let mut dist = vec![vec![n; n]; n];
    for _ in 0..m {
        let a = buf.next().expect("Failed to read a") - 1;
        let b = buf.next().expect("Failed to read b") - 1;
        dist[a][b] = 1;
        dist[b][a] = 1;
    }

    for i in 0..n {
        dist[i][i] = 0;
    }

    for bypass in 0..n {
        for i in 0..n {
            for k in 0..n {
                dist[i][k] = dist[i][k].min(dist[i][bypass] + dist[bypass][k]);
            }
        }
    }

    let mut ans = usize::MAX;
    let mut person = 0;
    for (i, v) in dist.iter().enumerate() {
        let s = v.iter().sum();
        if s < ans {
            ans = s;
            person = i + 1;
        }
    
    }
    println!("{person}");
}
