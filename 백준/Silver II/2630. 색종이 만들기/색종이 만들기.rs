// 2630 색종이 만들기

fn go(paper: &[Vec<usize>], n: usize) -> (usize, usize) {
    let ans = (0, 0);

    if paper.iter().flatten().all(|color| *color == 0) {
        return (1, 0);
    }
    if paper.iter().flatten().all(|color| *color == 1) {
        return (0, 1);
    }

    let first = paper[0..(n / 2)]
        .iter()
        .map(|row| row[0..(n / 2)].to_vec())
        .collect::<Vec<_>>();
    let first = go(&first, n / 2);
    let ans = (ans.0 + first.0, ans.1 + first.1);

    let second = paper[0..(n / 2)]
        .iter()
        .map(|row| row[(n / 2)..n].to_vec())
        .collect::<Vec<_>>();
    let second = go(&second, n / 2);
    let ans = (ans.0 + second.0, ans.1 + second.1);

    let third = paper[(n / 2)..n]
        .iter()
        .map(|row| row[0..(n / 2)].to_vec())
        .collect::<Vec<_>>();
    let third = go(&third, n / 2);
    let ans = (ans.0 + third.0, ans.1 + third.1);

    let fourth = paper[(n / 2)..n]
        .iter()
        .map(|row| row[(n / 2)..n].to_vec())
        .collect::<Vec<_>>();
    let fourth = go(&fourth, n / 2);
    (ans.0 + fourth.0, ans.1 + fourth.1)
}

fn main() {
    let mut n = String::new();
    std::io::stdin().read_line(&mut n).expect("read error");
    let n = n.trim().parse().expect("parse error");
    let mut paper = Vec::new();

    for _ in 0..n {
        let mut row = String::new();
        std::io::stdin().read_line(&mut row).expect("read error");
        let row = row
            .split_whitespace()
            .map(|str| str.parse().expect("parse error"))
            .collect();
        paper.push(row);

    }

    let (white, blue) = go(&paper, n);
    println!("{white}\n{blue}");
}
