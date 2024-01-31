// 2579 계단 오르기
use std::io;
use std::io::Read;

fn go(stairs: &[i32], dp: &mut [i32], current: Option<usize>) -> i32 {
    if current.is_none() {
        return i32::MIN;
    }

    let current = current.unwrap();
    if current == 0 {
        dp[current] = stairs[0];
        return dp[current];
    } else if current == 1 {
        dp[current] = stairs[0] + stairs[1];
        return dp[current];
    } else if current == 2 {
        dp[current] = (stairs[0] + stairs[2]).max(stairs[1] + stairs[2]);
        return dp[current];
    }

    if dp[current] != -1 {
        return dp[current];
    }

    let case1 = go(stairs, dp, current.checked_sub(3)) + stairs[current] + stairs[current - 1];
    let case2 = go(stairs, dp, current.checked_sub(2)) + stairs[current];

    dp[current] = case1.max(case2);

    dp[current]
}

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();

    let stairs: Vec<i32> = input
        .split_whitespace()
        .skip(1)
        .map(|str| str.parse().unwrap())
        .collect();
    let mut dp: Vec<i32> = vec![-1; stairs.len()];
    let output = go(&stairs, &mut dp, Some(stairs.len() - 1));

    println!("{output}");
}
