use std::io;

struct Problem {
    r: usize,
    c: usize,
    paper: Vec<Vec<usize>>,
    visited: Vec<Vec<bool>>,
}

impl Problem {
    fn new(r: usize, c: usize) -> Problem {
        Problem {
            r,
            c,
            paper: Vec::new(),
            visited: vec![vec![false; c]; r],
        }
    }

    fn input(&mut self) {
        for _ in 0..self.r {
            let mut buf = String::new();
            io::stdin()
                .read_line(&mut buf)
                .expect("Failed to read line");
            let row = buf
                .split_whitespace()
                .map(|str| str.parse().expect("parse error"))
                .collect();
            self.paper.push(row);
        }
    }

    fn is_safe(&self, r: isize, c: isize) -> bool {
        (0..self.r as isize).contains(&r) && (0..self.c as isize).contains(&c)
    }

    fn shape_search(&mut self, r: isize, c: isize, depth: usize) -> usize {
        let mut total = 0;

        if depth == 3 {
            return self.paper[r as usize][c as usize];
        }

        let d = [(r - 1, c), (r + 1, c), (r, c - 1), (r, c + 1)];
        for (nr, nc) in d {
            if !self.is_safe(nr, nc) || self.visited[nr as usize][nc as usize] {
                continue;
            }

            self.visited[nr as usize][nc as usize] = true;

            total = total
                .max(self.paper[r as usize][c as usize] + self.shape_search(nr, nc, depth + 1));

            self.visited[nr as usize][nc as usize] = false;
        }

        total
    }

    fn t_shape(&self, r: isize, c: isize) -> usize {
        let mut total = 0;
        let t1 = [(r, c), (r, c + 1), (r, c + 2), (r + 1, c + 1)]; // ㅜ
        let t2 = [(r, c), (r, c + 1), (r, c + 2), (r - 1, c + 1)]; // ㅗ
        let t3 = [(r, c), (r + 1, c), (r + 2, c), (r + 1, c - 1)]; // ㅓ
        let t4 = [(r, c), (r + 1, c), (r + 2, c), (r + 1, c + 1)]; // ㅏ

        for t in [t1, t2, t3, t4] {
            let mut sum = 0;

            if t.iter().all(|(nr, nc)| self.is_safe(*nr, *nc)) {
                for (nr, nc) in t {
                    sum += self.paper[nr as usize][nc as usize];
                }
                total = total.max(sum);
            }
        }

        total
    }

    fn go(&mut self) -> usize {
        let mut max = 0;
        for r in 0..self.r {
            for c in 0..self.c {
                self.visited[r][c] = true;
                max = max.max(self.shape_search(r as isize, c as isize, 0));
                self.visited[r][c] = false;
                max = max.max(self.t_shape(r as isize, c as isize));
            }
        }

        max
    }
}

fn main() {
    let mut buf = String::new();
    io::stdin()
        .read_line(&mut buf)
        .expect("Failed to read line");
    let mut input = buf
        .split_whitespace()
        .map(|str| str.parse().expect("parse error"));
    let r: usize = input.next().expect("r error");
    let c = input.next().expect("c error");

    let mut problem = Problem::new(r, c);
    problem.input();

    let answer = problem.go();
    println!("{answer}");
}
