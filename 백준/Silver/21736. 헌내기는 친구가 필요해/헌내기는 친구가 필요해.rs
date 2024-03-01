fn is_safe(campus: &[Vec<char>], r: isize, c: isize) -> bool {
    0 <= r && r < campus.len() as isize && 0 <= c && c < campus[0].len() as isize
}

fn go(campus: &[Vec<char>], visited: &mut [Vec<bool>], r: usize, c: usize) -> usize {
    visited[r][c] = true;

    let mut met = 0;
    for (dr, dc) in &[(-1, 0), (1, 0), (0, -1), (0, 1)] {
        let (nr, nc) = (r as isize + dr, c as isize + dc);
        if is_safe(campus, nr, nc)
            && !visited[nr as usize][nc as usize]
            && campus[nr as usize][nc as usize] != 'X'
        {
            if campus[nr as usize][nc as usize] == 'P' {
                met += 1;
            }
            met += go(campus, visited, nr as usize, nc as usize);
        }
    }

    met
}

fn main() {
    let mut buf = String::new();
    std::io::stdin()
        .read_line(&mut buf)
        .expect("Failed to read from stdin");

    let mut buf = buf
        .split_whitespace()
        .map(|str| str.parse::<usize>().expect("Failed to parse"));
    let n = buf.next().expect("Failed to read n");
    let m = buf.next().expect("Failed to read m");

    let mut i = (0, 0);
    let mut campus = Vec::new();
    let mut visited = vec![vec![false; m]; n];
    for r in 0..n {
        let mut buf = String::new();
        std::io::stdin()
            .read_line(&mut buf)
            .expect("Failed to read from stdin");
        let row: Vec<_> = buf.trim().chars().collect();
        campus.push(row);

        if let Some(c) = campus[r].iter().position(|&ch| ch == 'I') {
            i = (r, c);
        }
    }

    let ans = go(&campus, &mut visited, i.0, i.1);
    if ans == 0 {
        println!("TT");
    } else {
        println!("{ans}");
    }
}
