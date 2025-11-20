#include "commandParser.h"

CommandType CommandParser::getCommandType(const string& input)
{
	if (input.find("CREATE TABLE") == 0) //.find() searches the string for the first occurence of the sequence specified by args
	{
		return CommandType::CREATE_TABLE;
	}

	else if (input.find("DROP TABLE") == 0)
	{
		return CommandType::DROP_TABLE;
	}
	
	else if (input.find("INSERT") == 0)
	{
		return CommandType::INSERT_CMD;
	}

	else if (input.find("SELECT") == 0)
	{
		return CommandType::SELECT_CMD;
	}

	else if (input.find("DELETE") == 0)
	{
		return CommandType::DELETE_CMD;
	}

	else
	{
		return CommandType::UNKNOWN_CMD;
	}

}