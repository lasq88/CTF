use rand::{Rng,SeedableRng};
use rand::rngs::StdRng;

fn get_rng() -> StdRng {
    let seed = 13371337;
    return StdRng::seed_from_u64(seed);
}

fn main() -> std::io::Result<()> {
    let mut rng = get_rng();
    for _ in 0..41 {
        print!("{:02x}", rng.gen::<u8>());
    }
    Ok(())
}