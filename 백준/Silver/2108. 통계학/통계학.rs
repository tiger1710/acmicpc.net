// 2108 통계학

use std::io::{self, Read};
/*
첫째 줄에는 산술평균을 출력한다. 소수점 이하 첫째 자리에서 반올림한 값을 출력한다.

둘째 줄에는 중앙값을 출력한다.

셋째 줄에는 최빈값을 출력한다. 여러 개 있을 때에는 최빈값 중 두 번째로 작은 값을 출력한다.

넷째 줄에는 범위를 출력한다.
 */

fn main() {
    let mut input = String::new();
    io::stdin()
        .read_to_string(&mut input)
        .expect("Failed to read from stdin");

    let mut nums: Vec<isize> = input.split_whitespace().skip(1).map(|str| str.parse().expect("parse error")).collect();
    nums.sort();

    let sum = nums.iter().sum::<isize>();
    let avg = (sum as f64 / nums.len() as f64).round() as isize;
    let mid = nums[nums.len() / 2];

    let mut map = std::collections::HashMap::new();
    for num in nums.iter() {
        let count = map.entry(num).or_insert(0usize);
        *count += 1;
    }

    let max_v = map.iter().map(|(_, v)| v).max().expect("map is empty");
    let mut v: Vec<_> = map.iter().filter_map(|(k, v)| (v == max_v).then_some(k)).collect();
    v.sort();
    let mode = v.get(1).unwrap_or(v.get(0).expect("v is empty"));
    let range = (nums.iter().max().expect("nums is empty") - nums.iter().min().expect("nums is empty")).abs();

    println!("{avg}");
    println!("{mid}");
    println!("{mode}");
    println!("{range}");
}
