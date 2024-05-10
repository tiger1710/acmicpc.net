use std::io::stdin;

fn switch(board: &mut [Vec<char>], r: isize, c: isize) {
    let d = [(0, 0), (1, 0), (-1, 0), (0, -1), (0, 1)];

    for (dr, dc) in d {
        let nr = r + dr;
        let nc = c + dc;

        if !(0..10).contains(&nr) || !(0..10).contains(&nc) {
            continue;
        }

        let nr = nr as usize;
        let nc = nc as usize;
        if board[nr][nc] == 'O' {
            board[nr][nc] = '#';
        } else {
            board[nr][nc] = 'O';
        }
    
    }
}

fn go(board: &mut [Vec<char>]) -> Result<usize, &str> {
    let mut count = 0;

    // from second row to last row
    for r in 1..10 {
        for c in 0..10 {
            if board[r - 1][c] == 'O' {
                count += 1;
                switch(board, r as isize, c as isize);
            }
        }
    }

    // check if last row is all '#'
    if board[9].iter().all(|light| *light == '#') {
        Ok(count)
    } else {
        Err("Failed")
    }
}

fn main() {
    let mut board = Vec::new();
    for _ in 0..10 {
        let mut buf = String::new();
        stdin().read_line(&mut buf).expect("Failed to read line");
        let row: Vec<char> = buf.trim().chars().collect();
        board.push(row);
    }

    let mut ans = None;
    for i in 0..1024 {
        let mut board = board.clone();
        let mut count = 0;

        for c in 0..10isize { // toggle first row
            if i & (1 << c) != 0 {
                count += 1;
                switch(&mut board, 0, c);
            }
        }

        match go(&mut board) {
            Ok(c) => {
                let m = ans.get_or_insert(c + count);
                *m = (*m).min(c + count);
            },
            Err(_) => continue,
        }
    }

    if let Some(ans) = ans {
        println!("{ans}");
    } else {
        println!("-1");
    }
}
