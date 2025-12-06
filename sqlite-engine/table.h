#pragma once
#include "row.h"
#include <string>

using namespace std;

class Table
{	
	string tableName = "";
	string* columnNames = nullptr;
	string* columnTypes = nullptr;
	int columnCount = 0;
	Row* rows = nullptr;
	int rowCount = 0;
	int* list = nullptr;

public:
	/*void printRows();*/
	Table();
	~Table();
	

	//accessors
	string getName();
};