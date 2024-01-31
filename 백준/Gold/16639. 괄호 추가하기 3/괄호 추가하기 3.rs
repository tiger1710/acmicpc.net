// 16639 괄호 추가하기 3

use std::io::Read;

fn main() {
    let mut input = String::new();
    std::io::stdin()
        .read_to_string(&mut input)
        .expect("read error");
    let input = input
        .lines()
        .nth(1)
        .expect("line error")
        .chars()
        .collect::<Vec<_>>();
    let mut dp = vec![vec![None; input.len() + 1]; input.len() + 1];
    let ans = go(&input, &mut dp, 0, input.len());
    println!("{}", ans.1);
}

fn go(exp: &[char], dp: &mut [Vec<Option<(i32, i32)>>], from: usize, to: usize) -> (i32, i32) {
    if let Some(v) = dp[from][to] {
        return v;
    }

    if from == to - 1 {
        let m = exp[from].to_digit(10).unwrap() as i32;
        return (m, m);
    }

    for i in (from + 1..to).step_by(2) {
        let left = go(exp, dp, from, i);
        let right = go(exp, dp, i + 1, to);
        let op = exp[i];
        let res = match op {
            '+' => (left.0 + right.0, left.1 + right.1),
            '-' => (left.0 - right.1, left.1 - right.0),
            '*' => (
                (left.0 * right.0)
                    .min(left.0 * right.1)
                    .min(left.1 * right.0)
                    .min(left.1 * right.1),
                (left.0 * right.0)
                    .max(left.0 * right.1)
                    .max(left.1 * right.0)
                    .max(left.1 * right.1),
            ),
            _ => unreachable!(),
        };
        dp[from][to] = Some(match dp[from][to] {
            Some(v) => (i32::min(v.0, res.0), i32::max(v.1, res.1)),
            None => res,
        });
    }

    dp[from][to].unwrap()
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_go1() {
        let input = "1-9-1-9-1-9-1-9-1-9".chars().collect::<Vec<_>>();
        let mut dp = vec![vec![None; 20]; 20];
        go(&input, &mut dp, 0, 19);

        assert_eq!(dp[0][19].unwrap().1, 32);
    }

    #[test]
    fn test_go2() {
        let input = "3+8*7-9*2".chars().collect::<Vec<_>>();
        let mut dp = vec![vec![None; 10]; 10];
        assert_eq!(go(&input, &mut dp, 0, 9).1, 136);
    }

    #[test]
    fn test_go3() {
        let input = "8*3+5".chars().collect::<Vec<_>>();
        let mut dp = vec![vec![None; 6]; 6];
        assert_eq!(go(&input, &mut dp, 0, 5).1, 64);
    }

    #[test]
    fn test_go4() {
        let input = "8*3+5+2".chars().collect::<Vec<_>>();
        let mut dp = vec![vec![None; 8]; 8];
        assert_eq!(go(&input, &mut dp, 0, 7).1, 80);
    }

    #[test]
    fn test_go5() {
        let input = "1*2+3*4*5-6*7*8*9*0".chars().collect::<Vec<_>>();
        let mut dp = vec![vec![None; 20]; 20];
        assert_eq!(go(&input, &mut dp, 0, 19).1, 100);
    }

    #[test]
    fn test_go6() {
        let input = "1*2+3*4*5-6*7*8*9*9".chars().collect::<Vec<_>>();
        let mut dp = vec![vec![None; 20]; 20];
        assert_eq!(go(&input, &mut dp, 0, 19).1, 426384);
    }
}
