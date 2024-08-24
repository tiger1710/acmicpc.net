use std::io::{stdin, Read};

fn get_t_cnt(it: &[usize], t: usize) -> usize {
    let mut total = 0;
    for cnt in it {
        total += cnt / t;
        if cnt % t != 0 {
            total += 1;
        }
    }
    total
}

fn main() {
    let mut buf = String::new();
    stdin()
        .read_to_string(&mut buf)
        .expect("Failed to read line");
    let mut buf = buf
        .split_whitespace()
        .map(|str| str.parse().expect("Failed to parse"));
    let n: usize = buf.next().expect("Input error");

    let t_size_list: Vec<_> = buf.clone().take(6).collect();
    let mut buf = buf.skip(6);
    let t = buf.next().expect("Input error");
    let p = buf.next().expect("Input error");
    let t_cnt = get_t_cnt(&t_size_list, t);
    let p_cnt = [n / p, n % p];

    println!(
        "{t_cnt}\n{p_cnt1} {p_cnt2}",
        t_cnt = t_cnt,
        p_cnt1 = p_cnt[0],
        p_cnt2 = p_cnt[1]
    );
}
