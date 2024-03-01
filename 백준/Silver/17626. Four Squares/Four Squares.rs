

fn go(n: usize, dp: &mut [Option<usize>]) -> usize {
    if let Some(v) = dp[n] {
        return v;
    }

    let mut sq = 1;
    while sq * sq <= n {
        sq += 1;
    }

    let mut m = 4;
    for i in (1..sq).rev() {
        m = m.min(go(n - i * i, dp));
    }

    dp[n] = Some(m + 1);
    m + 1
}

fn main() {
    let mut buf = String::new();
    std::io::stdin().read_line(&mut buf).expect("Failed to read from stdin");
    let buf: usize = buf.trim().parse().expect("Failed to parse input");
    
    let mut dp = vec![None; buf + 1];
    dp[0] = Some(0);
    dp[1] = Some(1);


    let ans = go(buf, &mut dp);
    println!("{ans}");
}
