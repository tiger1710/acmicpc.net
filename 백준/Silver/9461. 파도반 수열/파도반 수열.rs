use std::io::Read;

fn go(dp: &mut [Option<usize>], n: usize) -> usize {
    if let Some(len) = dp[n] {
        return len;
    }

    dp[n] = Some(go(dp, n - 1) + go(dp, n - 5));
    dp[n].unwrap()
}

fn main() {
    let mut buf = String::new();
    std::io::stdin()
        .read_to_string(&mut buf)
        .expect("read error");
    let mut buf = buf.split_whitespace();

    let t = buf
        .next()
        .expect("n error")
        .parse::<usize>()
        .expect("parse error");

    let mut dp = vec![None; 100];
    dp[0] = Some(1);
    dp[1] = Some(1);
    dp[2] = Some(1);
    dp[3] = Some(2);
    dp[4] = Some(2);
    dp[5] = Some(3);
    dp[6] = Some(4);
    dp[7] = Some(5); // 7 까지는 직접 계산해준다.

    for _ in 0..t {
        let n = buf
            .next()
            .expect("n error")
            .parse::<usize>()
            .expect("parse error")
            - 1;

        let ans = go(&mut dp, n);
        println!("{ans}");
    }
}
