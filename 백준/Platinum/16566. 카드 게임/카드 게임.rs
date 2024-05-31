use std::fmt::Write;
use std::io::stdin;

fn union(set: &mut Vec<Option<usize>>, a: usize, b: usize) {
    if set.len() <= b {
        return;
    }

    set[a] = Some(b);
}

fn find(set: &mut Vec<Option<usize>>, n: usize) -> usize {
    if set[n].is_none() {
        return n;
    }

    set[n] = Some(find(set, set[n].expect("find error")));
    return set[n].unwrap();
}

fn main() {
    let mut buf = String::new();
    stdin().read_line(&mut buf).expect("Failed to read line");

    let mut buf = String::new();
    stdin().read_line(&mut buf).expect("Failed to read line");
    let buf = buf
        .split_whitespace()
        .map(|str| str.parse().expect("Failed to parse number"));
    let mut cards: Vec<usize> = buf.collect();
    cards.sort();

    let mut buf = String::new();
    stdin().read_line(&mut buf).expect("Failed to read line");
    let buf = buf
        .split_whitespace()
        .map(|str| str.parse().expect("Failed to parse number"));

    let charles: Vec<usize> = buf.collect();
    let mut set = vec![None; cards.len()];

    let mut output = String::new();
    // println!("{cards:?}");
    for i in charles {
        let p = cards.partition_point(|n| *n <= i);
        let p = find(&mut set, p);
        union(&mut set, p, p + 1);
        writeln!(output, "{}", cards[p]).expect("Failed to write to output");
    }
    println!("{output}");
    
}
