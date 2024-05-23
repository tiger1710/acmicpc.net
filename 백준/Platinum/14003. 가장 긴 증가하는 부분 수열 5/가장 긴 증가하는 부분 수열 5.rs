use std::io::stdin;

fn main() {
    let mut buf = String::new();
    stdin().read_line(&mut buf).expect("Failed to read line");

    let n: usize = buf.trim().parse().expect("Not a number");
    let mut buf = String::new();
    stdin().read_line(&mut buf).expect("Failed to read line");
    let series: Vec<isize> = buf.split_whitespace().map(|str| str.parse().expect("Not a number")).collect();

    let mut lis_arr = Vec::new();
    let mut lis_idx = vec![0usize; n];
    lis_arr.push(series[0]);

    for (i, a_i) in series.iter().enumerate().skip(1) {
        let new = lis_arr.partition_point(|m| m < a_i);
        if lis_arr.get(new).is_some() {
            lis_arr[new] = *a_i;
            lis_idx[i] = new;
        } else {
            lis_arr.push(*a_i);
            lis_idx[i] = lis_arr.len() - 1;
        }
    }

    let lis_len = lis_arr.len();
    let mut lis = Vec::new();
    let mut idx = (lis_arr.len() - 1) as isize;
    for (org_idx, i) in lis_idx.iter().enumerate().rev() {
        if *i == idx as usize{
            lis.push(series[org_idx]);
            idx -= 1;
        }
    }

    println!("{lis_len}");
    for i in lis.iter().rev() {
        print!("{i} ");
    }
}
