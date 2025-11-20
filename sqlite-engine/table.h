#pragma once
#include "row.h"
#include <string>
#include <vector>
using namespace std;

class Table
{	
	string tableName = "";
	vector<string> columnNames;
	vector<string> columnTypes;
	Row* rows = nullptr;
	int rowCount = 0;

public:
	void addRow(Row r);
	void printRows();
	Table();
	~Table();
	
	//constructor for table with schema
	Table(const string& name, const vector<string>& colNames, const vector<string>& colTypes);
	
	//accessors
	string getName();
	vector<string> getColumnNames();
	vector<string> getColumnTypes();
};