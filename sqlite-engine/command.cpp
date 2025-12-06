#include "command.h"

//ctor for standard capacity

//Command::Command() {}


std::string to_string(CommandType ct) {
	switch (ct) {
	case CommandType::CREATE_TABLE: return "CREATE_TABLE";
	case CommandType::CREATE_INDEX: return "CREATE_INDEX";
	case CommandType::DROP_TABLE: return "DROP_TABLE";
	case CommandType::DROP_INDEX: return "DROP_INDEX";
	case CommandType::DISPLAY_TABLE: return "DISPLAY_TABLE";
	case CommandType::INSERT_CMD: return "INSERT_ROW";
	case CommandType::SELECT_CMD: return "SELECT";
	case CommandType::UPDATE_CMD: return "UPDATE";
	case CommandType::DELETE_CMD: return "DELETE";
	default: return "Unknown";
	}
}

// Specialize the << operator for the Color enum
std::ostream& operator<<(std::ostream& os, CommandType ct) {
	os << to_string(ct);
	return os;
}

std::ostream& operator<<(std::ostream& console, const Command* command) {
	if (command == nullptr) {
		console << "Nullptr Command Object";
		return console;
	}
	console << command->type << " ";
	for (int i = 0; i < command->numberOfArgs; i++) {
		console << "'" << command->args[i] << "' ";
	}
	return console;
}

Command::Command(CommandType type) {
	this->type = type;
	//initialize string pointer
	this->args = new std::string[capacity];
}

void Command::operator+=(std::string str) { //adds an argument to the command
	//allocate memory dynamically for args
	if (numberOfArgs + 1 > this->capacity)
	{
		this->capacity += DEFAULT_CAPACITY;
		std::string* copy = new std::string[this->capacity];
		for (int i = 0; i < numberOfArgs; i++) {
			copy[i] = this->args[i];
		}
		//avoid mem leak
		delete[] this->args;
		this->args = copy;
	}
	this->args[this->numberOfArgs] = str;
	this->numberOfArgs++;
}

std::string* Command::getArguments() {
	if (this->args == nullptr)
	{
		return nullptr;
	}

	std::string* copy = new std::string[this->numberOfArgs];
	for (int i = 0; i < this->numberOfArgs; i++) {
		copy[i] = this->args[i];
	}

	return copy;
}

int Command::getNumberOfArguments() {
	return this->numberOfArgs;
}

int Command::getCapacity() {
	return this->capacity;
}

Command::~Command() {
	delete[] this->args;
}

Command::Command(Command& other) {
	this->type = other.type;
	this->numberOfArgs = other.numberOfArgs;
	if (other.args == nullptr) {
		this->args = nullptr;
	}
	else {
		for (int i = 0; i < numberOfArgs; i++) {
			this->args[i] = other.args[i];
		}
	}
	this->capacity = other.capacity;
}

//void Command::operator=(Command& other) {
//	//check if the object are the same
//	if (this == &other) {
//		return;
//	}	
//	this->type = other.type;
//	this->numberOfArgs = other.numberOfArgs;
//
//	//delete[] this->args;
//
//	if (other.args == nullptr) {
//		this->args = nullptr;
//	}
//
//	//initialize this->args
//}

CommandType Command::getCommandType() {
	return this->type;
}

std::string Command::getArgument(int index) {
	return this->args[index];
}


