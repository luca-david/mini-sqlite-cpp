#include "commandParser.h"


CommandParser::CommandParser()
{

}

void CommandParser::extractTableColumns(string input)
{
	//define the regex pattern to match groups between parantheses
	std::regex pattern(R"/(\(\s*(\w+)\s*,\s*(integer|text|float)\s*,\s*([^,]+)\s*,\s*([^,]+)\s*\))/");
	std::smatch matches;

	//create an iterator to search through the input string
	auto begin = std::sregex_iterator(input.begin(), input.end(), pattern);
	auto end = std::sregex_iterator();

	//iterate through all matches and print the captured groups
	for (auto it = begin; it != end; ++it)
	{
		matches = *it;
		std::cout << "\t- Name: " << matches[1] << "\n";
		std::cout << "\t  Type: " << matches[2] << "\n";
		std::cout << "\t  Size: " << matches[3] << "\n";
		std::cout << "\t  Dflt: " << matches[4] << "\n";
	}
}

// CREATE TABLE table_name [IF NOT EXISTS] ((column_1_name,type,size, default_value), (column_2_name,type,size, default_value), ...)
void CommandParser::createTable(std::string input) {
	std::cout << "> " << input << std::endl;

	const std::regex pattern("CREATE TABLE (\\w+){1} (IF NOT EXISTS )?\\((.*)\\)");
	std::smatch match;

	if (std::regex_search(input, match, pattern)) {
		std::cout << "Table: " << match[1] << std::endl;
		std::cout << "Idempotent: " << (match[2].length() ? "no" : "yes") << std::endl;
		std::cout << "Column definitions: " << std::endl;
		extractTableColumns(match[3]);
	}
	else {
		std::cout << "Invalid input" << std::endl;
	}

	std::cout << std::endl;
}

// DROP TABLE table_name
void CommandParser::dropTable(std::string input)
{
	std::cout << ">" << input << std::endl;

	const std::regex pattern("DROP TABLE (\\w+){1}");
	std::smatch match;

	if (std::regex_search(input, match, pattern))
	{
		std::cout << "Table: " << match[1] << std::endl;
	}
	else
	{
		std::cout << "Invalid input: " << std::endl;
	}

	std::cout << std::endl;

}

// DISPLAY TABLE table_name
void CommandParser::displayTable(std::string input)
{
	std::cout << ">" << input << std::endl;
	
	const std::regex pattern("DISPLAY TABLE (\\w+){1}");
	std::smatch match;

	if (std::regex_search(input, match, pattern)) {
		std::cout << "Table: " << match[1] << std::endl;
	}
	else {
		std::cout << "Invalid input" << std::endl;
	}

	std::cout << std::endl;

}


