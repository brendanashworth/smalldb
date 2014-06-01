use std::io;

mod cli;
mod command;

fn main() {
	::cli::printLine("Booting smalldb...", ::cli::System);

	// Load

	::cli::printLine("Now running smalldb. ^C to quit.", ::cli::System);

	// Start listening on stdin

	::cli::printText("  Enter command > ", ::cli::Default);
	for _ in io::stdin().lines() {
		// Parse the command
		// DO SOMETHING
		::cli::printText("  Enter command > ", ::cli::Default);
	}

	// Shut down

	::cli::printLine("Shutting down...", ::cli::System);
}
