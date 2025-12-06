#pragma once
#include "table.h"
#include "commandParser.h"
#include "command.h"

class Database { 
	static Database* instance;
	Table* tables = nullptr;
	int count = 0;
	Database();
	~Database();
	Table** getTable(string name);
	void addTable(Table* table);
	bool createTable(Command* cmd);

public:
	
	static Database* getInstance();
	
	
	bool executeCommand(Command* cmd);
	
};