// 14503 로봇 청소기

/*
 * 로봇 청소기는 다음과 같이 작동한다.
 * 1. 현재 칸이 아직 청소되지 않은 경우, 현재 칸을 청소한다.
 * 2. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우,
 *  2-1. 바라보는 방향을 유지한 채로 한 칸 후진할 수 있다면 한 칸 후진하고 1번으로 돌아간다.
 *  2-2. 바라보는 방향의 뒤쪽 칸이 벽이라 후진할 수 없다면 작동을 멈춘다.
 * 3. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우,
 *  3-1. 반시계 방향으로 90º 회전한다.
 *  3-2. 바라보는 방향을 기준으로 앞쪽 칸이 청소되지 않은 빈 칸인 경우 한 칸 전진한다.
 *  3-3. 1번으로 돌아간다.
 *
 */

use std::io::Read;

#[derive(Clone, Copy)]
enum Direction {
    North,
    East,
    South,
    West,
}

struct Robot {
    r: i32,
    c: i32,
    d: Direction,
}

impl Robot {
    fn turn_left(&mut self) {
        self.d = match self.d {
            Direction::North => Direction::West,
            Direction::East => Direction::North,
            Direction::South => Direction::East,
            Direction::West => Direction::South,
        }
    }

    fn check_front(&self, cleaned: &[Vec<i32>]) -> bool {
        match self.d {
            Direction::North => cleaned[(self.r - 1) as usize][self.c as usize] == 0,
            Direction::East => cleaned[self.r as usize][(self.c + 1) as usize] == 0,
            Direction::South => cleaned[(self.r + 1) as usize][self.c as usize] == 0,
            Direction::West => cleaned[self.r as usize][(self.c - 1) as usize] == 0,
        }
    }

    fn move_front(&mut self) {
        match self.d {
            Direction::North => self.r -= 1,
            Direction::East => self.c += 1,
            Direction::South => self.r += 1,
            Direction::West => self.c -= 1,
        }
    }

    fn move_back(&mut self, room: &[Vec<i32>]) -> Result<(), ()> {
        match self.d {
            Direction::North => {
                if room[(self.r + 1) as usize][self.c as usize] == 1 {
                    Err(())
                } else {
                    self.r += 1;
                    Ok(())
                }
            }
            Direction::East => {
                if room[self.r as usize][(self.c - 1) as usize] == 1 {
                    Err(())
                } else {
                    self.c -= 1;
                    Ok(())
                }
            }
            Direction::South => {
                if room[(self.r - 1) as usize][self.c as usize] == 1 {
                    Err(())
                } else {
                    self.r -= 1;
                    Ok(())
                }
            }
            Direction::West => {
                if room[self.r as usize][(self.c + 1) as usize] == 1 {
                    Err(())
                } else {
                    self.c += 1;
                    Ok(())
                }
            }
        }
    }

    fn all_cleaned(&self, cleaned: &[Vec<i32>]) -> bool {
        cleaned[(self.r + 1) as usize][self.c as usize] == 1
            && cleaned[(self.r - 1) as usize][self.c as usize] == 1
            && cleaned[self.r as usize][(self.c + 1) as usize] == 1
            && cleaned[self.r as usize][(self.c - 1) as usize] == 1
    }
}

fn main() {
    let mut input = String::new();
    // let mut output = String::new();
    std::io::stdin()
        .read_to_string(&mut input)
        .expect("read error");
    let mut input = input
        .split_whitespace()
        .map(|str| str.parse::<i32>().expect("parse error"));

    let _n = input.next().expect("n error");
    let m = input.next().expect("m error");

    let start_r = input.next().expect("start_r error");
    let start_c = input.next().expect("start_c error");
    let start_d = input.next().expect("start_d error");

    let robot = Robot {
        r: start_r,
        c: start_c,
        d: match start_d {
            0 => Direction::North,
            1 => Direction::East,
            2 => Direction::South,
            3 => Direction::West,
            _ => panic!("start_d error"),
        },
    };

    let room = input.collect::<Vec<i32>>();
    let room: Vec<_> = room
        .chunks(m as usize)
        .map(|chunk| chunk.to_owned())
        .collect();
    let mut cleaned = room.clone();
    let res = go(robot, &room, &mut cleaned);
    println!("{res}");
}

fn go(mut robot: Robot, room: &[Vec<i32>], cleaned: &mut [Vec<i32>]) -> i32 {
    let mut count = 0;

    loop {
        // 1
        if cleaned[robot.r as usize][robot.c as usize] == 0 {
            cleaned[robot.r as usize][robot.c as usize] = 1;
            count += 1;
        }

        // 2
        if robot.all_cleaned(cleaned) {
            if let Ok(()) = robot.move_back(room) {
                continue;
            } else {
                break;
            }
        }

        // 3
        robot.turn_left();
        if robot.check_front(&cleaned) {
            robot.move_front();
        }
    }

    count
}
