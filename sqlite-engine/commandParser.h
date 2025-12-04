#pragma once
#include "table.h"
#include "command-type.h"
using namespace std;

class CommandParser
{
	string command = "";
	bool isValid = 0;
	CommandType type = CommandType::UNKNOWN_CMD;

public:
	static CommandType getCommandType(const string& input);
};