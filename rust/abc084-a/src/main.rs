use std::io;

fn read_line() -> String {
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    s
}

macro_rules! from_line {
    ($($a:ident : $t:ty),+) => {
        $(let $a: $t;)+
        {
            let _line = read_line();
            let mut _it = _line.trim().split_whitespace();
            $($a = _it.next().unwrap().parse().unwrap();)+
                assert!(_it.next().is_none());
        }
    };
}

fn digit_sum(n: i64) -> i64 {
    let mut sum = 0;
    let mut tmp_n = n;

    loop {
        sum += tmp_n % 10;
        tmp_n = tmp_n / 10;

        if tmp_n == 0 {
            break;
        }
    }
    sum
}

fn main() {
    from_line!(m: i64);
    println!("{}", 48 - m);
}
