use std::cmp::Ordering;
use std::collections::binary_heap;

#[derive(Clone)]
struct Edge {
    node: usize,
    cost: usize,
}

#[derive(Copy, Clone, Eq, PartialEq)]
struct State {
    cost: usize,
    skip: usize,
    position: usize,
}

impl Ord for State {
    fn cmp(&self, other: &Self) -> Ordering {
        other
            .cost
            .cmp(&self.cost)
            .then_with(|| self.skip.cmp(&other.skip))
            .then_with(|| self.position.cmp(&other.position))
    }
}

impl PartialOrd for State {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

fn go(road: &[Vec<Edge>], skip: usize) -> usize {
    let mut dist = vec![vec![usize::MAX; skip + 1]; road.len()];
    let mut heap = binary_heap::BinaryHeap::new();
    let goal = road.len() - 1;

    dist[0][skip] = 0;
    heap.push(State {
        cost: 0,
        position: 0,
        skip,
    });

    while let Some(State {
        cost,
        position,
        skip,
    }) = heap.pop()
    {
        if dist[position][skip] < cost {
            continue;
        }

        for edge in &road[position] {
            let next = State {
                cost: cost + edge.cost,
                position: edge.node,
                skip,
            };

            if next.cost < dist[next.position][next.skip] {
                dist[next.position][next.skip] = next.cost;
                heap.push(next);
            }

            if 0 < skip {
                let next_skip = State {
                    cost,
                    position: edge.node,
                    skip: skip - 1,
                };
                if next_skip.cost < dist[next_skip.position][next_skip.skip] {
                    dist[next_skip.position][next_skip.skip] = next_skip.cost;
                    heap.push(next_skip);
                }
            }
        }
    }

    *dist[goal].iter().min().expect("Failed to find minimum cost")
}

fn main() {
    let mut input = String::new();
    std::io::stdin()
        .read_line(&mut input)
        .expect("Failed to read line");

    let mut it = input
        .split_whitespace()
        .map(|s| s.parse().expect("Failed to parse input"));
    let n = it.next().expect("Failed to read n");
    let m = it.next().expect("Failed to read m");
    let k = it.next().expect("Failed to read k");

    let mut graph = vec![Vec::new(); n];
    for _ in 0..m {
        let mut input = String::new();
        std::io::stdin()
            .read_line(&mut input)
            .expect("Failed to read line");

        let mut it = input
            .split_whitespace()
            .map(|s| s.parse().expect("Failed to parse input"));

        let u: usize = it.next().expect("Failed to read u");
        let v = it.next().expect("Failed to read v");
        let w = it.next().expect("Failed to read w");

        graph[u - 1].push(Edge {
            node: v - 1,
            cost: w,
        });
        graph[v - 1].push(Edge {
            node: u - 1,
            cost: w,
        });
    }

    let result = go(&graph, k);
    println!("{result}");
}
