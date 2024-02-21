// 1074 Z


fn go(n: usize, r: usize, c: usize) -> usize {
    if n == 0 {
        return 0;
    }

    let q = 1usize << (n - 1);
    let m = 1usize << (n);

    if r < q && c < q {
        return go(n - 1, r, c);
    }
    if r < q && c < m {
        return q * q + go(n - 1, r, c - q);
    }
    if r < m && c < q {
        return 2 * q * q + go(n - 1, r - q, c);
    } 

    3 * q * q + go(n - 1, r - q, c - q)
}

fn main() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).expect("read error");
    let mut input = input
        .split_whitespace()
        .map(|str| str.parse().expect("parse error"));

    let n: usize = input.next().expect("n error");
    let r = input.next().expect("r error");
    let c = input.next().expect("c error");

    let ans = go(n, r, c);
    println!("{ans}");
}
