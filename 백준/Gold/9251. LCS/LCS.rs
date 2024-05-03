use std::io::stdin;

fn go(dp: &mut Vec<Vec<Option<usize>>>, str1: &[char], str2: &[char], i: usize, k: usize) -> usize {
    if i == str1.len() || k == str2.len() {
        return 0;
    }

    if let Some(v) = dp[i][k] {
        return v;
    }

    if str1[i] == str2[k] {
        let res = go(dp, str1, str2, i + 1, k + 1) + 1;
        dp[i][k] = Some(res);
        res
    } else {
        let res = go(dp, str1, str2, i + 1, k).max(go(dp, str1, str2, i, k + 1));
        dp[i][k] = Some(res);
        res
    }
}

fn main() {
    /*
     * ACAYKP
     * CAPCAK
     * 4
     */
    let mut buf = String::new();
    stdin().read_line(&mut buf).expect("Failed to read line");
    let str1: Vec<char> = buf.trim().chars().collect();
    let mut buf = String::new();
    stdin().read_line(&mut buf).expect("Failed to read line");
    let str2: Vec<char> = buf.trim().chars().collect();

    let mut dp = vec![vec![None; str2.len()]; str1.len()];
    let ans = go(&mut dp, &str1, &str2, 0, 0);
    println!("{ans}");
}
