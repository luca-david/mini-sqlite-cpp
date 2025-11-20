#include "stringUtils.h"

void toUpper(string& command)
{
	for (int i = 0; i < command.length(); i++) //go through each letter of the command
	{
		if (command[i] >= 'a' && command[i] <= 'z') //if its lowercase
		{
			command[i] = command[i] - 32; //make it into uppercase
		}
	}
}