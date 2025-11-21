#pragma once
#include <string>
using namespace std;

class Tokenizer {
	string* tokens = nullptr;
	int tokenCount = 0;
	int maxTokens = 0;

public:
	//constructors
	Tokenizer(int maxTokens);
	
	//destructor
	~Tokenizer();

	void tokenize(const string& input);
	bool isSpecialCharacter(char c);
	void addToken(const string& token);

	//getters
	string getToken(int index);
	int getTokenCount();
	
	//print
	void printTokens();

};