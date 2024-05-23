use std::io::stdin;
use std::fmt::Write;

fn main() {
    let mut buf = String::new();
    stdin().read_line(&mut buf).expect("Failed to read line");

    let n: usize = buf.trim().parse().expect("Not a number");
    let mut utility_pole = Vec::new();
    for _ in 0..n {
        let mut buf = String::new();
        stdin().read_line(&mut buf).expect("Failed to read line");
        let mut buf = buf
            .split_whitespace()
            .map(|str| str.parse().expect("Not a number"));

        let a: usize = buf.next().expect("Failed to get a");
        let b = buf.next().expect("Failed to get b");

        utility_pole.push((a - 1, b - 1));
    }

    utility_pole.sort();

    let mut lis_arr = Vec::new();
    let mut lis_idx = vec![0usize; n];
    lis_arr.push(utility_pole[0]);

    for (i, a_i) in utility_pole.iter().enumerate().skip(1) {
        let new = lis_arr.partition_point(|(_, t)| *t < a_i.1);
        if lis_arr.get(new).is_some() {
            lis_arr[new] = *a_i;
            lis_idx[i] = new;
        } else {
            lis_arr.push(*a_i);
            lis_idx[i] = lis_arr.len() - 1;
        }
    }

    let lis_len = lis_arr.len();
    let mut idx = (lis_arr.len() - 1) as isize;
    for (org_idx, i) in lis_idx.iter().enumerate().rev() {
        if *i == idx as usize{
            utility_pole.remove(org_idx);
            idx -= 1;
        }
    }

    let mut output = String::new();

    writeln!(output, "{}", n - lis_len).expect("Failed to write to output");
    for (i, _) in utility_pole {
        writeln!(output, "{}", i + 1).expect("Failed to write to output");
    }
    println!("{output}");
}
