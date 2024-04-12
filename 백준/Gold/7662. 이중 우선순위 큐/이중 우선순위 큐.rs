use std::{
    cmp::Reverse,
    collections::{BinaryHeap, HashMap},
    io,
};

fn insert(
    min_heap: &mut BinaryHeap<Reverse<isize>>,
    max_heap: &mut BinaryHeap<isize>,
    count: &mut HashMap<isize, usize>,
    n: isize,
) {
    count.entry(n).and_modify(|c| *c += 1).or_insert(1);
    min_heap.push(Reverse(n));
    max_heap.push(n);
}

fn delete_min(min_heap: &mut BinaryHeap<Reverse<isize>>, count: &mut HashMap<isize, usize>) {
    while let Some(Reverse(v)) = min_heap.peek() {
        if let Some(c) = count.get(v) {
            if 0 < *c {
                count.entry(*v).and_modify(|c| *c -= 1);
                break;
            }

            min_heap.pop();
        }
    }
}

fn delete_max(max_heap: &mut BinaryHeap<isize>, count: &mut HashMap<isize, usize>) {
    while let Some(v) = max_heap.peek() {
        if let Some(c) = count.get(v) {
            if 0 < *c {
                count.entry(*v).and_modify(|c| *c -= 1);
                break;
            }

            max_heap.pop();
            continue;
        }
    }
}

fn go(k: usize) {
    let mut min_heap = BinaryHeap::new();
    let mut max_heap = BinaryHeap::new();
    let mut count = HashMap::new();

    for _ in 0..k {
        let mut buf = String::new();
        io::stdin()
            .read_line(&mut buf)
            .expect("Failed to read line");
        let mut buf = buf.split_whitespace();
        let op = buf.next().expect("No operation");
        let n: isize = buf
            .next()
            .expect("No number")
            .parse()
            .expect("Not a number");

        match op {
            "I" => insert(&mut min_heap, &mut max_heap, &mut count, n),
            "D" => match n {
                1 => delete_max(&mut max_heap, &mut count),
                -1 => delete_min(&mut min_heap, &mut count),
                _ => {}
            },
            _ => {}
        }
    }

    while let Some(Reverse(v)) = min_heap.peek() {
        if let Some(c) = count.get(v) {
            if 0 == *c {
                min_heap.pop();
            } else {
                break;
            }
        }
    }

    while let Some(v) = max_heap.peek() {
        if let Some(c) = count.get(v) {
            if 0 == *c {
                max_heap.pop();
            } else {
                break;
            }
        }
    }

    if min_heap.is_empty() || max_heap.is_empty() {
        println!("EMPTY");
        return;
    }

    println!("{} {}", max_heap.peek().unwrap(), min_heap.peek().unwrap().0);
}

fn main() {
    let mut buf = String::new();
    io::stdin()
        .read_line(&mut buf)
        .expect("Failed to read line");
    let t: usize = buf.trim().parse().expect("Not a number");

    for _ in 0..t {
        let mut buf = String::new();
        io::stdin()
            .read_line(&mut buf)
            .expect("Failed to read line");
        let k: usize = buf.trim().parse().expect("Not a number");

        go(k);
    }
}
