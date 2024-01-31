// 9095 1, 2, 3 더하기
use std::io;
use std::fmt::Write;

fn op(dp: &mut [usize; 11], n: usize) -> usize {
    if 0 < dp[n] { return dp[n] }

    dp[n] = op(dp, n - 1) + op(dp, n - 2) + op(dp, n - 3);

    dp[n]
}

fn main() {
    let mut input = String::new();
    let mut output = String::new();
    io::stdin().read_line(&mut input).unwrap();

    let tc: usize = input.trim().parse().unwrap();

    let mut dp = [ 0usize; 11 ];
    dp[1] = 1; // 1 = (1)
    dp[2] = 2; // 2 = (1, 1), (2)
    dp[3] = 4; // 3 = (1, 1, 1), (1, 2), (2, 1), (3)

    for _ in 0..tc {
        let mut n = String::new();
        io::stdin().read_line(&mut n).unwrap();
        let n:usize = n.trim().parse().unwrap();

        let ans = op(&mut dp, n);
        writeln!(output, "{ans}").unwrap();
    }

    println!("{output}");
}
