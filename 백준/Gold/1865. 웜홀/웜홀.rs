use std::io::stdin;

fn main() {
    let mut buf = String::new();
    stdin().read_line(&mut buf).expect("Failed to read line");
    let tc: usize = buf.trim().parse().expect("Failed to parse");

    for _ in 0..tc {
        let mut buf = String::new();
        stdin().read_line(&mut buf).expect("Failed to read line");
        let mut buf = buf
            .split_whitespace()
            .map(|str| str.parse().expect("Failed to parse"));

        let n: usize = buf.next().expect("Failed to get n");
        let m = buf.next().expect("Failed to get m");
        let w = buf.next().expect("Failed to get w");

        let mut world = vec![vec![]; n];
        for _ in 0..m {
            let mut buf = String::new();
            stdin().read_line(&mut buf).expect("Failed to read line");
            let mut buf = buf
                .split_whitespace()
                .map(|str| str.parse().expect("Failed to parse"));

            let s: usize = buf.next().expect("Failed to get x");
            let e = buf.next().expect("Failed to get y");
            let t = buf.next().expect("Failed to get t");

            world[s - 1].push((e - 1, t as isize));
            world[e - 1].push((s - 1, t as isize));
        }

        for _ in 0..w {
            let mut buf = String::new();
            stdin().read_line(&mut buf).expect("Failed to read line");
            let mut buf = buf
                .split_whitespace()
                .map(|str| str.parse().expect("Failed to parse"));

            let s: usize = buf.next().expect("Failed to get x");
            let e = buf.next().expect("Failed to get y");
            let t = buf.next().expect("Failed to get t");

            world[s - 1].push((e - 1, -(t as isize)));
        }

        let mut negative_cycle = false;
        let mut dist = vec![None; n];
        'outer: while let Some(not_visited) =  dist.iter().position(|&x| x.is_none()) {
            dist[not_visited] = Some(0);

            for i in 0..n {
                for u in 0..n {
                    for &(v, t) in &world[u] {
                        if let Some(min) = dist[u] {
                            let dist_v = dist[v].unwrap_or_else(|| {
                                dist[v] = Some(min + t);
                                min + t
                            });

                            if min + t < dist_v {
                                dist[v] = Some(min + t);

                                if i == n - 1 {
                                    negative_cycle = true;
                                    break 'outer;
                                }
                            }
                        }
                    }
                }
            }
        }

        if negative_cycle {
            println!("YES");
        } else {
            println!("NO");
        }
    }
}
