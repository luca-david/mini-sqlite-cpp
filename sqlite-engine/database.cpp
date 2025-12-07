#include "database.h"

Database::Database() {
}

Database::~Database() {
	delete[] this->tables;
}

Table** Database::getTable(string name) {
	for (int i = 0; i < this->count; i++) {
		string dbNames = tables[i].getName();
		if (name == dbNames) {
			return &tables;
		}
	}
	return nullptr;
}

void Database::addTable(Table* table) {
	
	Table* copy = new Table[this->count + 1];
	for (int i = 0; i < this->count; i++) {
		copy[i] = this->tables[i];
	}
	delete[] this->tables;
	copy[this->count] = *table;
	this->count++;

	this->tables = copy;
}

bool Database::createTable(Command* cmd) {
	//CREATE TABLE table_name [IF NOT EXISTS] ((column_1_name,type,size, default_value), (column_2_name,type,size, default_value), ...)
	string tableName = cmd->getArgument(0);
	//if not exists 
	bool ifNotExists = cmd->getArgument(1).length() > 0;
	
	return false;
}

bool Database::executeCommand(Command* cmd) {
	switch (cmd->getCommandType()) {
	case CommandType::CREATE_TABLE:
		return this->createTable(cmd);
	}
	return false;
}

Database* Database::instance = nullptr;

Database* Database::getInstance() {
	if (Database::instance == nullptr) {
		Database::instance = new Database();
	}
	return Database::instance;
}

int Database::getCount() {
	return this->count;
}

Database::Database(Database& other) {
	if (other.tables == nullptr) {
		this->tables = nullptr;
		this->count = 0;
	}
	else {
		this->count = other.count;
		delete[] this->tables;
		this->tables = new Table[this->count];
		for (int i = 0; i < this->count; i++) {
			this->tables[i] = other.tables[i];
		}
	}
}

void Database::operator=(Database& other) {
	if (other.tables == nullptr) {
		this->tables = nullptr;
		this->count = 0;
	}
	else {
		this->count = other.count;
		delete[] this->tables;
		this->tables = new Table[this->count];
		for (int i = 0; i < this->count; i++) {
			this->tables[i] = other.tables[i];
		}
	}
}

Table* Database::getTables() {
	if (this->tables == nullptr) {
		return nullptr;
	}
	Table* copy = new Table[this->count];
	for (int i = 0; i < this->count; i++) {
		copy[i] = this->tables[i];
	}
	return copy;
}

std::ostream& operator<<(std::ostream& console, Database& db) {
	console << std::endl << "Number of tables: " << db.count << std::endl;
	return console;
}

void Database::operator+=(int additionalTables) {
	this->tables += additionalTables;
}

bool Database::operator==(Database& other) {
	if (this == &other) {
		return true;
	}
	return false;
}