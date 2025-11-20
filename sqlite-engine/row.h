//This is for the row structure and the list of values it contains

#pragma once
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Row
{
	int id = 0;
	string name = "";
	float price = 0.00f;

public:
	void setId(int id);
	void setName(string name);
	void setPrice(float price);
	void print();

	Row();

	Row(int id, string name, float price);
};