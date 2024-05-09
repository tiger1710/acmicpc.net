use std::{collections::HashMap, io::stdin};

const MOD: usize = 1_000_000_007;

fn go(n: usize, dp: &mut HashMap<usize, usize>) -> usize {
    if let Some(&ans) = dp.get(&n) {
        return ans;
    }

    if n % 2 == 0 {
        let f_n = go(n / 2, dp);
        let f_nm1 = go(n / 2 - 1, dp);

        dp.insert(n, (f_n * (f_n + (2 * f_nm1 % MOD)) % MOD) % MOD);
    } else {
        let f_n = go(n / 2, dp);
        let f_np1 = go(n / 2 + 1, dp);

        dp.insert(n, ((f_n * f_n % MOD) + (f_np1 * f_np1) % MOD) % MOD);
    }

    dp[&n]
}

fn main() {
    let mut buf = String::new();
    stdin().read_line(&mut buf).expect("Failed to read line");
    let n: usize = buf.trim().parse().expect("Failed to parse");
    let mut dp = HashMap::new();
    dp.insert(0, 0);
    dp.insert(1, 1);

    let ans = go(n, &mut dp);
    println!("{ans}");
}