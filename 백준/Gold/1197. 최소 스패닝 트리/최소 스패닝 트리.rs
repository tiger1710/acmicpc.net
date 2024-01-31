// 1197 최소 스패닝 트리

use std::{io::Read, collections::BinaryHeap, cmp::Reverse};

fn find(uf: &mut Vec<Option<isize>>, n: isize) -> isize {
    if let Some(p) = uf[n as usize] {
        uf[n as usize] = Some(find(uf, p));
        return uf[n as usize].expect("find error");
    } 

    n
}

fn union(uf: &mut Vec<Option<isize>>, a: isize, b: isize) -> bool {
    let a = find(uf, a);
    let b = find(uf, b);

    if a == b {
        return false;
    }

    uf[a as usize] = Some(b);

    true
}

fn main() {
    let mut input = String::new();
    std::io::stdin().read_to_string(&mut input).unwrap();
    let mut input = input.split_whitespace().map(|str| str.parse::<isize>().expect("parse error"));

    let v = input.next().expect("input error");
    let e = input.next().expect("input error");

    let mut edges = BinaryHeap::new();
    let mut uf = vec![None; v as usize];
    for _ in 0..e {
        let a = input.next().expect("input error") - 1;
        let b = input.next().expect("input error") - 1;
        let c = input.next().expect("input error");
        edges.push(Reverse((c, a, b)));
    }

    let mut cost = 0;
    while let Some(Reverse((c, a, b))) = edges.pop() {
        if find(&mut uf, a) != find(&mut uf, b) {
            union(&mut uf, a, b);
            cost += c;
        }
    }

    println!("{cost}");
}
