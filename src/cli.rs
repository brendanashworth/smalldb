// Command line interface module.
pub enum Color {
	Default,
	Error,
	System
}

pub fn printLine(line: &str, color: Color) {
	setTextColor(color);
	logConsole(line);
	logConsole("\r\n");
	setTextColor(Default);
}

pub fn printText(line: &str, color: Color) {
	setTextColor(color);
	logConsole(line);
	setTextColor(Default);
}

// Sets the text color to the specified text.
fn setTextColor(color: Color) {
	match color {
		Default => print!("\x1B[0m"),
		Error => print!("\x1B[31m"),
		System => print!("\x1B[36m")
	}
}

// Logs a line to the console.
fn logConsole(line: &str) {
	print!("{}", line);
}
