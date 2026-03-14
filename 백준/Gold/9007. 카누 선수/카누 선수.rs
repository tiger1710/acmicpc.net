use std::io::{self, Read};

struct Scanner<'a> {
    it: std::str::SplitAsciiWhitespace<'a>,
}

impl<'a> Scanner<'a> {
    fn new(s: &'a str) -> Self {
        Self {
            it: s.split_ascii_whitespace(),
        }
    }
    fn next<T: std::str::FromStr>(&mut self) -> T {
        self.it.next().unwrap().parse().ok().expect("Parse error")
    }
}

fn get_sorted_sums(sc: &mut Scanner, n: usize) -> Vec<isize> {
    let v1: Vec<isize> = (0..n).map(|_| sc.next()).collect();
    let v2: Vec<isize> = (0..n).map(|_| sc.next()).collect();

    let mut sums: Vec<_> = v1
        .into_iter()
        .flat_map(|i| v2.iter().map(move |j| i + j))
        .collect();

    sums.sort_unstable();
    sums
}

fn solve() {
    let mut input = String::new();
    io::stdin()
        .read_to_string(&mut input)
        .expect("Failed to read input");
    let mut sc = Scanner::new(&input);

    let t: usize = sc.next();

    for _ in 0..t {
        let k: isize = sc.next();
        let n: usize = sc.next();

        let a = get_sorted_sums(&mut sc, n);
        let b = get_sorted_sums(&mut sc, n);

        let mut ans = ((k - (a[0] + b[0])).abs(), a[0] + b[0]);

        for wa in a {
            let target = k - wa;
            let idx = b.partition_point(|&x| x < target);

            if let Some(&wb) = idx.checked_sub(1).and_then(|i| b.get(i)) {
                let candidate = ((k - (wa + wb)).abs(), wa + wb);

                if candidate < ans {
                    ans = candidate;
                }
            }

            if let Some(&wb) = b.get(idx) {
                let candidate = ((k - (wa + wb)).abs(), wa + wb);
                if candidate < ans {
                    ans = candidate;
                }
            }
        }

        println!("{}", ans.1);
    }
}

fn main() {
    solve();
}
