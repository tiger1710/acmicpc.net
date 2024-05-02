use std::io::stdin;

fn pre_order(tree: &[char], i: usize) {
    if tree[i] == '.' {
        return;
    }

    let idx = tree[i] as usize - 'A' as usize;
    let left = idx * 2 + 1;
    let right = idx * 2 + 2;
    print!("{}", tree[i]);
    pre_order(tree, left);
    pre_order(tree, right);
}

fn in_order(tree: &[char], i: usize) {
    if tree[i] == '.' {
        return;
    }

    let idx = tree[i] as usize - 'A' as usize;
    let left = idx * 2 + 1;
    let right = idx * 2 + 2;
    in_order(tree, left);
    print!("{}", tree[i]);
    in_order(tree, right);
}

fn post_order(tree: &[char], i: usize) {
    if tree[i] == '.' {
        return;
    }

    let idx = tree[i] as usize - 'A' as usize;
    let left = idx * 2 + 1;
    let right = idx * 2 + 2;
    post_order(tree, left);
    post_order(tree, right);
    print!("{}", tree[i]);
}

fn main() {
    let mut buf = String::new();
    stdin().read_line(&mut buf).expect("Failed to read line");
    let n: usize = buf.trim().parse().expect("Failed to parse");

    let mut tree = ['.'; 55];
    tree[0] = 'A';
    for _ in 0..n {
        let mut buf = String::new();
        stdin().read_line(&mut buf).expect("Failed to read line");
        let mut buf = buf.split_whitespace().filter_map(|str| str.chars().next());
        let parent = buf.next().expect("Failed to get parent");
        let left = buf.next().expect("Failed to get left");
        let right = buf.next().expect("Failed to get right");

        let i = parent as usize - 'A' as usize;
        if left != '.' {
            tree[i * 2 + 1] = left;
        }
        if right != '.' {
            tree[i * 2 + 2] = right;
        }
    }

    pre_order(&tree, 0);
    println!();
    in_order(&tree, 0);
    println!();
    post_order(&tree, 0);
    println!();
}
