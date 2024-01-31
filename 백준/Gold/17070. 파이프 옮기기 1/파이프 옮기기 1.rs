// 17070 파이프 옮기기 1

use std::io::Read;

#[derive(Debug)]
enum Pipe {
    Horizontal(usize, usize),
    Vertical(usize, usize),
    Diagonal(usize, usize),
}

fn horizontal_1(board: &[&[usize]], r: usize, c: usize) -> bool {
    if c + 1 < board.len() && board[r][c + 1] == 0 {
        return true;
    }

    false
}

fn horizontal_2(board: &[&[usize]], r: usize, c: usize) -> bool {
    if c + 1 < board.len()
        && r + 1 < board.len()
        && board[r][c + 1] == 0
        && board[r + 1][c + 1] == 0
        && board[r + 1][c] == 0
    {
        return true;
    }

    false
}

fn vertical_1(board: &[&[usize]], r: usize, c: usize) -> bool {
    if r + 1 < board.len() && board[r + 1][c] == 0 {
        return true;
    }

    false
}

fn vertical_2(board: &[&[usize]], r: usize, c: usize) -> bool {
    if c + 1 < board.len()
        && r + 1 < board.len()
        && board[r][c + 1] == 0
        && board[r + 1][c + 1] == 0
        && board[r + 1][c] == 0
    {
        return true;
    }

    false
}

fn diagonal_1(board: &[&[usize]], r: usize, c: usize) -> bool {
    if c + 1 < board.len() && board[r][c + 1] == 0 {
        return true;
    }

    false
}

fn diagonal_2(board: &[&[usize]], r: usize, c: usize) -> bool {
    if r + 1 < board.len() && board[r + 1][c] == 0 {
        return true;
    }

    false
}

fn diagonal_3(board: &[&[usize]], r: usize, c: usize) -> bool {
    if c + 1 < board.len()
        && r + 1 < board.len()
        && board[r][c + 1] == 0
        && board[r + 1][c + 1] == 0
        && board[r + 1][c] == 0
    {
        return true;
    }

    false
}

fn go(board: &[&[usize]], dp: &mut Vec<Vec<Vec<Option<usize>>>>, pipe: Pipe) -> usize {
    let (r, c, d) = match pipe {
        Pipe::Horizontal(r, c) => (r, c, 0),
        Pipe::Vertical(r, c) => (r, c, 1),
        Pipe::Diagonal(r, c) => (r, c, 2),
    };

    if let Some(count) = dp[r][c][d] {
        return count;
    }

    if r == board.len() - 1 && c == board.len() - 1 {
        return 1;
    }

    let mut count = 0;

    match pipe {
        Pipe::Horizontal(r, c) => {
            if horizontal_1(board, r, c) {
                count += go(board, dp, Pipe::Horizontal(r, c + 1));
            }

            if horizontal_2(board, r, c) {
                count += go(board, dp, Pipe::Diagonal(r + 1, c + 1));
            }
        }
        Pipe::Vertical(r, c) => {
            if vertical_1(board, r, c) {
                count += go(board, dp, Pipe::Vertical(r + 1, c));
            }

            if vertical_2(board, r, c) {
                count += go(board, dp, Pipe::Diagonal(r + 1, c + 1));
            }
        }
        Pipe::Diagonal(r, c) => {
            if diagonal_1(board, r, c) {
                count += go(board, dp, Pipe::Horizontal(r, c + 1));
            }

            if diagonal_2(board, r, c) {
                count += go(board, dp, Pipe::Vertical(r + 1, c));
            }

            if diagonal_3(board, r, c) {
                count += go(board, dp, Pipe::Diagonal(r + 1, c + 1));
            }
        }
    }

    dp[r][c][d] = Some(count);

    count
}

fn main() {
    let mut input = String::new();
    std::io::stdin()
        .read_to_string(&mut input)
        .expect("Failed to read from stdin");

    let mut input = input
        .split_whitespace()
        .map(|str| str.parse::<usize>().expect("Failed to parse number"));

    let n = input.next().expect("Failed to read n");

    let board = input.collect::<Vec<usize>>();
    let board = board.chunks(n).collect::<Vec<&[usize]>>();
    let mut dp: Vec<Vec<Vec<Option<usize>>>> = vec![vec![vec![None; 3]; n]; n];
    go(&board, &mut dp, Pipe::Horizontal(0, 1));
    println!("{ans}", ans = dp[0][1][0].unwrap());
}
