// チーズ (Cheese) 5558
use std::{collections::VecDeque, io::Read};

type Point = (usize, usize);

fn is_safe(town: &[Vec<char>], next: Point) -> bool {
    let (r, c) = next;

        r < town.len()
        && c < town[0].len()
        && town[r as usize][c as usize] != 'X'
}

fn can_eat_cheese(town: &[Vec<char>], curr: Point, eaten: usize) -> bool {
    let (r, c) = curr;

    town[r as usize][c as usize].is_ascii_digit()
        && town[r as usize][c as usize].to_digit(10).unwrap() == (eaten + 1) as u32
}

fn bfs(town: &[Vec<char>], start: Point) -> usize {
    let mut queue = VecDeque::new();
    let mut visited = vec![vec![false; town[0].len()]; town.len()];

    queue.push_back((start, 0));

    let mut total = 0;
    let mut moved = 0;

    while !queue.is_empty() {
        let len = queue.len();
        moved += 1;
        for _ in 0..len {
            let (curr, eaten) = queue.pop_front().unwrap();
            let (r, c) = curr;

            if can_eat_cheese(town, curr, eaten) {
                total += moved;
                moved = 0;
                queue.clear();
                queue.push_back((curr, eaten + 1));
                visited = vec![vec![false; town[0].len()]; town.len()];
                visited[r][c] = true;
                break;
            }

            let nexts = [
                (r + 1, c),
                (r.checked_sub(1).unwrap_or(r), c),
                (r, c + 1),
                (r, c.checked_sub(1).unwrap_or(c)),
            ];

            for (nr, nc) in nexts {
                if is_safe(town, (nr, nc)) && !visited[nr][nc] {
                    queue.push_back(((nr, nc), eaten));
                    visited[nr][nc] = true;
                }
            }
        }
    }

    total
}

fn main() {
    let mut input = String::new();
    std::io::stdin()
        .read_to_string(&mut input)
        .expect("read error");
    let mut input = input.split_whitespace();
    let h: usize = input
        .next()
        .expect("h error")
        .parse()
        .expect("h parse error");
    let w: usize = input
        .next()
        .expect("w error")
        .parse()
        .expect("w parse error");
    let n: usize = input
        .next()
        .expect("n error")
        .parse()
        .expect("n parse error");

    let mut town = Vec::<Vec<char>>::new();
    for _ in 0..h {
        let row = input.next().expect("row error").chars().collect();
        town.push(row);
    }

    let s = town
        .iter()
        .flatten()
        .enumerate()
        .find(|&(_, &c)| c == 'S')
        .expect("S not found");
    let s = (s.0 / w, s.0 % w);

    let ans = bfs(&town, s) - n;
    println!("{ans}");
}
