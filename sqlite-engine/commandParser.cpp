#include "commandParser.h"

CommandParser::CommandParser()
{

}

bool matchPattern(std::string input, std::string regexStr) {
	return std::regex_match(input, std::regex(regexStr));
}

Command* CommandParser::parseCommand(const string& input)
{
	if (matchPattern(input, "CREATE TABLE.*"))
	{
		return this->createTable(input);
	}

	else if (matchPattern(input, "DROP TABLE.*"))
	{
		return this->dropTable(input);
	}
	
	else if (matchPattern(input, "DISPLAY TABLE.*"))
	{
		return this->displayTable(input);
	}

	else if (matchPattern(input, "CREATE INDEX.*"))
	{
		return this->createIndex(input);
	}

	else if (matchPattern(input, "DROP INDEX.*"))
	{
		return this->dropIndex(input);
	}

	else if (matchPattern(input, "INSERT INTO.*"))
	{
		return this->insertRow(input);
	}

	else if (matchPattern(input, "DELETE FROM.*"))
	{
		return this->deleteRow(input);
	}

	else if (matchPattern(input, "SELECT.*"))
	{
		return this->selectRows(input);
	}

	else if (matchPattern(input, "UPDATE.*"))
	{
		return this->updateRow(input);
	}

	return nullptr;
}




void CommandParser::runRegex(string input, Command* cmd, std::regex pattern) {
	std::smatch matches;

	std::sregex_iterator begin = std::sregex_iterator(input.begin(), input.end(), pattern);
	std::sregex_iterator end = std::sregex_iterator();

	for (auto it = begin; it != end; ++it) {
		matches = *it;
		*cmd += matches.str();
	}
}


// CREATE TABLE table_name [IF NOT EXISTS] ((column_1_name,type,size, default_value), (column_2_name,type,size, default_value), ...)
Command* CommandParser::createTable(std::string input) {
	
	const std::regex pattern("CREATE TABLE (\\w+) \\s*(IF NOT EXISTS)?\\s*\\((.*)\\)");
	std::smatch match;

	if (!std::regex_search(input, match, pattern)) {
		return nullptr;
	}

	Command* cmd = new Command(CommandType::CREATE_TABLE); //we use pointer because it must be allocated on heap, not on the stack
	*cmd += match[1].str(); //adds title
	*cmd += match[2].str(); //adds if not exists
	runRegex(match[3], cmd, std::regex("[\\w.]+")); //adds definitions in groups of 4

	return cmd;
}

// DROP TABLE table_name
Command* CommandParser::dropTable(std::string input)
{
	const std::regex pattern("DROP TABLE (\\w+){1}");
	std::smatch match;

	if (!std::regex_search(input, match, pattern)) {
		return nullptr;
	}

	Command* cmd = new Command(CommandType::DROP_TABLE);
	*cmd += match[1].str();

	return cmd;
}

// DISPLAY TABLE table_name
Command* CommandParser::displayTable(std::string input) {
	
	const std::regex pattern("DISPLAY TABLE (\\w+)");
	std::smatch match;

	if (!std::regex_search(input, match, pattern)) {
		return nullptr;
	}

	Command* cmd = new Command(CommandType::DISPLAY_TABLE);
	*cmd += match[1];
	return cmd;
}

Command* CommandParser::createIndex(string input) {
	const std::regex pattern("CREATE INDEX (IF NOT EXISTS )?(\\w+){1} ON (\\w*){1} \\((\\w*){1}\\)");
	std::smatch match;

	if (!std::regex_search(input, match, pattern)) {
		return nullptr;
	}

	Command* cmd = new Command(CommandType::CREATE_INDEX);
	*cmd += match[1]; // if not exists
	*cmd += match[2]; // index name
	*cmd += match[3]; // table name
	*cmd += match[4]; // column name

	return cmd;
}

// DROP INDEX index_name
Command* CommandParser::dropIndex(std::string input) {
	const std::regex pattern("DROP INDEX (\\w+)");
	std::smatch match;

	if (!std::regex_search(input, match, pattern)) {
		return nullptr;
	}

	Command* cmd = new Command(CommandType::DROP_INDEX);
	*cmd += match[1]; // index name

	return cmd;
}

Command* CommandParser::insertRow(string input) {
	const std::regex pattern("INSERT INTO\\s(\\w*)\\sVALUES\\((.*)\\)");
	std::smatch match;

	if (!std::regex_search(input, match, pattern)) {
		return nullptr;
	}

	Command* cmd = new Command(CommandType::INSERT_CMD);
	*cmd += match[1]; // table name
	this->runRegex(match[2], cmd, std::regex("[\\w.]+")); // Values

	return cmd;
}

Command* CommandParser::deleteRow(string input) {
	const std::regex pattern("DELETE FROM\\s(\\w*)\\sWHERE\\s(\\w*)\\s?=\\s?(\\w*)\\s?");
	std::smatch match;

	if (!std::regex_search(input, match, pattern)) {
		return nullptr;
	}

	Command* cmd = new Command(CommandType::DELETE_CMD);
	*cmd += match[1]; // Table Name
	*cmd += match[2]; // Condition column
	*cmd += match[3]; // Condition Value

	return cmd;
}

Command* CommandParser::selectRows(string input) {
	const std::regex pattern("SELECT\\s(.*)\\sFROM\\s(\\w*)\\s?(WHERE.*)?");
	const std::regex where_pattern("WHERE\\s(\\w*)\\s=\\s(\\w*)");
	std::smatch match;
	std::smatch where_match;

	std::string selection, table, condition, conditionKey, conditionValue;

	if (!std::regex_search(input, match, pattern)) {
		// Invalid command
		return nullptr;
	}

	selection = match[1];
	table = match[2];
	condition = match[3];

	if (!condition.empty()) {
		if (std::regex_search(input, where_match, where_pattern)) {
			conditionKey = where_match[1];
			conditionValue = where_match[2];
		}
		else {
			// Invalid command
			return nullptr;
		}
	}

	Command* cmd = new Command(CommandType::SELECT_CMD);
	// *cmd += match[1]; // Selection
	this->runRegex(match[1], cmd, std::regex("[\\w.]+")); // Selection
	*cmd += match[2]; // Table Name
	*cmd += where_match[1]; // Condition Key
	*cmd += where_match[2]; // Condition Value

	return cmd;
}

Command* CommandParser::updateRow(string input) {
	const std::regex pattern("UPDATE\\s(\\w*)\\sSET\\s(\\w*)\\s=\\s(\\w*)\\sWHERE\\s(\\w*)\\s=\\s(\\w*)\\s?");
	std::smatch match;

	if (!std::regex_search(input, match, pattern)) {
		// Invalid command
		return nullptr;
	}

	Command* cmd = new Command(CommandType::UPDATE_CMD);
	*cmd += match[1]; // Table Name
	*cmd += match[2]; // Set column
	*cmd += match[3]; // Set Value
	*cmd += match[4]; // Condition column
	*cmd += match[5]; // Condition Value

	return cmd;
}
