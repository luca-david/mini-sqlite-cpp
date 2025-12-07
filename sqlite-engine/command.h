#pragma once
#include <string>
#include <iostream>
#include "command-type.h"

#define DEFAULT_CAPACITY 10;

class Command {

	CommandType type;
	std::string* args = nullptr;
	int numberOfArgs = 0;
	int capacity = DEFAULT_CAPACITY;

public:
	//Command();
	Command(CommandType type);
	Command(Command& other);
	~Command();

	void operator+=(std::string str);
	void operator=(Command& other);
	bool operator==(Command& other);
	friend std::ostream& operator<<(std::ostream& console, const Command* Command);
	
	std::string* getArguments();
	std::string getArgument(int index);
	int getNumberOfArguments();
	int getCapacity();
	CommandType getCommandType();


};
