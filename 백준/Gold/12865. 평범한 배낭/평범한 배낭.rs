use std::io::stdin;

fn go(dp: &mut Vec<Vec<Option<usize>>>, stuff: &[(usize, usize)], n: usize, k: usize) -> usize {
    if stuff.len() == n || k == 0 {
        return 0;
    }

    if let Some(m) = dp[n][k] {
        return m;
    }

    let (w, v) = stuff[n];

    if w <= k {
        dp[n][k] = Some(go(dp, stuff, n + 1, k - w) + v);
    }

    dp[n][k] = Some(go(dp, stuff, n + 1, k)).max(dp[n][k]);

    dp[n][k].expect("Failed to get dp[n][k]")
}

fn main() {
    /* 4 7
     * 6 13
     * 4 8
     * 3 6
     * 5 12
     */
    let mut buf = String::new();
    stdin().read_line(&mut buf).expect("Failed to read line");

    let mut buf = buf
        .split_whitespace()
        .map(|str| str.parse().expect("parse error"));
    let n: usize = buf.next().expect("Failed to get n");
    let k = buf.next().expect("Failed to get k");

    let mut stuff = vec![];
    for _ in 0..n {
        let mut buf = String::new();
        stdin().read_line(&mut buf).expect("Failed to read line");
        let mut buf = buf
            .split_whitespace()
            .map(|str| str.parse().expect("parse error"));

        let w: usize = buf.next().expect("Failed to get w");
        let v = buf.next().expect("Failed to get v");

        stuff.push((w, v));
    }

    let mut dp = vec![vec![None; k + 1]; n];
    let ans = go(&mut dp, &stuff, 0, k);
    println!("{ans}");
}
