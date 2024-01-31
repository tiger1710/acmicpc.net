// 1912 연속합
use std::{error::Error, io::Read};

fn go(sequence: &[i32], dp: &mut [Option<i32>], curr: usize) -> i32 {
    if sequence.len() - 1 == curr {
        dp[curr] = Some(sequence[curr]);
        return dp[curr].expect("None");
    }

    if let Some(val) = dp[curr] {
        return val;
    }

    dp[curr] = Some(sequence[curr].max(sequence[curr] + go(sequence, dp, curr + 1)));
    dp[curr].expect("None")
}

fn main() -> Result<(), Box<dyn Error>> {
    let mut input = String::new();
    std::io::stdin().read_to_string(&mut input)?;

    let sequence = input
        .split_whitespace()
        .skip(1)
        .map(|str| str.parse())
        .collect::<Result<Vec<i32>, _>>()?;
    let mut dp = vec![None; sequence.len()];

    go(&sequence, &mut dp, 0);

    let ans = dp.iter().max().expect("dp is empty").expect("dp is None");
    println!("{ans}");

    Ok(())
}
