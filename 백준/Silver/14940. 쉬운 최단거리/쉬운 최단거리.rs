// 14940 쉬운 최단거리

use std::fmt::Write;
use std::io::Read;

fn is_safe(r: i32, c: i32, n: i32, m: i32) -> bool {
    0 <= r && r < n && 0 <= c && c < m
}

fn main() {
    let mut buf = String::new();
    let mut output = String::new();
    std::io::stdin()
        .read_to_string(&mut buf)
        .expect("read error");
    let mut buf = buf
        .split_whitespace()
        .map(|str| str.parse().expect("parse error"));

    let n: usize = buf.next().expect("n");
    let m = buf.next().expect("m");

    let map: Vec<_> = buf.collect();
    let p = map.iter().position(|&x| x == 2).expect("no 2");
    let p = (p / m, p % m);
    let map = map.chunks(m).collect::<Vec<_>>();

    let mut dist = vec![vec![std::isize::MAX; m]; n];

    let mut q = std::collections::VecDeque::new();
    q.push_back(p);
    dist[p.0][p.1] = 0;

    while let Some((r, c)) = q.pop_front() {
        let d = dist[r][c] + 1;
        for (dr, dc) in [(-1, 0), (1, 0), (0, -1), (0, 1)] {
            let (nr, nc) = (r as i32 + dr, c as i32 + dc);

            if !is_safe(nr, nc, n as i32, m as i32) {
                continue;
            }

            let (nr, nc) = (nr as usize, nc as usize);
            if map[nr][nc] == 0 || dist[nr][nc] <= d {
                continue;
            }

            dist[nr][nc] = d;
            q.push_back((nr, nc));
        }
    }

    for (i, row) in map.iter().enumerate() {
        for (j, &x) in row.iter().enumerate() {
            if x == 0 {
                write!(output, "0 ").expect("write error");
            } else {
                write!(
                    output,
                    "{} ",
                    if dist[i][j] == std::isize::MAX {
                        -1
                    } else {
                        dist[i][j]
                    }
                )
                .expect("write error");
            }
        }
        writeln!(output).expect("write error");
    }

    println!("{output}");
}
