#pragma once
#include "row.h"
using namespace std;

class Table
{
	Row* rows = nullptr;
	int rowCount = 0;

public:
	void addRow(Row r);
	void printRows();
	Table();
	~Table();
};