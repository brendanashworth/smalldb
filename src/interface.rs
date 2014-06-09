#[link(name = "internal/interface")]
extern {
	fn runCommand();
}

pub fn run(command: ~str) {
	unsafe {
		runCommand();
	}
}