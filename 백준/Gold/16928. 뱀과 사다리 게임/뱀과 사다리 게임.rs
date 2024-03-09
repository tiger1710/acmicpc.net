
use std::{collections::{HashMap, VecDeque}, io::Read};

fn main() {
    let mut buf = String::new();
    std::io::stdin()
        .read_to_string(&mut buf)
        .expect("Failed to read from stdin");

    let mut buf = buf
        .split_whitespace()
        .map(|str| str.parse().expect("Failed to parse number"));

    let n = buf.next().expect("Failed to read n");
    let m = buf.next().expect("Failed to read m");

    let mut ladder = HashMap::new();
    for _ in 0..n {
        let from = buf.next().expect("Failed to read from");
        let to = buf.next().expect("Failed to read to");
        ladder.insert(from, to);
    }

    let mut snake = HashMap::new();
    for _ in 0..m {
        let from = buf.next().expect("Failed to read from");
        let to = buf.next().expect("Failed to read to");
        snake.insert(from, to);
    }

    let mut queue = VecDeque::new();
    let mut visited = vec![false; 101];
    queue.push_back((1, 0));
    while let Some((pos, steps)) = queue.pop_front() {
        if pos == 100 {
            println!("{steps}");
            break;
        }

        for i in 1..=6 {
            let next = pos + i;
            if 100 < next || visited[next] {
                continue;
            }

            let next = match ladder.get(&next) {
                Some(&to) => to,
                None => next,
            };

            let next = match snake.get(&next) {
                Some(&to) => to,
                None => next,
            };

            queue.push_back((next, steps + 1));
            visited[next] = true;
        }
    }
}