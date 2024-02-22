// 14940 쉬운 최단거리

use std::collections::HashMap;
use std::fmt::Write;
use std::io::Read;

fn main() {
    let mut buf = String::new();
    let mut output = String::new();
    std::io::stdin()
        .read_to_string(&mut buf)
        .expect("read error");
    let mut buf = buf.split_whitespace();

    let n = buf
        .next()
        .expect("n error")
        .parse::<usize>()
        .expect("parse error");
    let m = buf
        .next()
        .expect("m error")
        .parse::<usize>()
        .expect("parse error");

    let mut hm = HashMap::new();

    for _ in 0..n {
        let site = buf.next().expect("site error");
        let password = buf.next().expect("password error");
        hm.insert(site, password);
    }

    for _ in 0..m {
        let site = buf.next().expect("site error");
        let password = hm.get(&site).expect("hm get error");
        writeln!(output, "{password}").expect("write error");
    }

    println!("{output}");
}
