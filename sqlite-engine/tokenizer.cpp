#include "tokenizer.h"
#include <iostream>

Tokenizer::Tokenizer(int maxTokens)
{	
	this->tokens = new string[maxTokens];
	this->maxTokens = maxTokens;
	this->tokenCount = 0;
}


bool Tokenizer::isSpecialCharacter(char c)
{
	if (c == '(' || c == ')' || c == ',' || c == ' ') //handles special cases
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Tokenizer::addToken(const string& token)
{	
	if (this->tokenCount > this->maxTokens)
	{
		throw "Surpassed max number of tokens";
	}
	this->tokens[this->tokenCount] = token;
	this->tokenCount++;
}

void Tokenizer::tokenize(const string& input)
{
	//input: create table
	this->tokenCount = 0;
	string currentToken = "";

	for (int i = 0; i < input.length(); i++)
	{
		char c = input[i];
		if (isSpecialCharacter(c) == true)
		{	
			if (!currentToken.empty()) //if current token not empty
			{
				addToken(currentToken);
				currentToken = ""; //forgot to reset it
			}

			if (c == ' ')
			{
				//ignore spaces, dont create tokens for them
				continue;
			}

			else if (c == '(')
			{
				//check for double paranthesis
				if (input[i + 1] == '(' && i + 1 < input.length())
				{
					addToken("(("); //add double paranthesis
					i++; //skip next "("
				}
				else
				{
					addToken("("); //add single paranthesis
				}
			}

			else if (c == ')')
			{
				if (input[i + 1] == ')' && i + 1 < input.length())
				{
					addToken("))");
					i++;
				}
				else
				{
					addToken(")");
				}
			}

			else if (c == ',')
			{
				addToken(",");
			}
		}
		else
		{
			//we have a regular char
			currentToken = currentToken + c;
		}
	}
	//make sure we add the last token
	if (!currentToken.empty())
	{
		addToken(currentToken);
	}
}

Tokenizer::~Tokenizer()
{
	delete[] this->tokens;
}

string Tokenizer::getToken(int index)
{	
	if (index < 0 || index > this->tokenCount)
	{
		throw "Invalid index for getToken()";
	}
	return this->tokens[index];
}

int Tokenizer::getTokenCount()
{
	return this->tokenCount;
}

void Tokenizer::printTokens()
{	
	cout << endl << "Tokens: ";
	for (int i = 0; i < this->maxTokens; i++)
	{
		cout << this->tokens[i] << " ";
	}
	cout << endl << "Number of tokens: " << this->tokenCount;
}
