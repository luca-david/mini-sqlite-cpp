#pragma once
#include "table.h"
#include "command-type.h"
using namespace std;

class CommandParser
{
public:
	static CommandType getCommandType(const string& input);
};