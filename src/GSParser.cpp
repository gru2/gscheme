
#include <GSParser.h>
#include <InputStream.h>
#include <stdlib.h>

GSParser::GSParser()
{
	sourceCodePosition = 0;
	errorReporter = 0;
	inputStream = 0;
}

GSParser::~GSParser()
{
}

int GSParser::lex()
{
	eatWhiteSpaceAndComments();
	if (tryParseInteger())
		return TT_INTEGER;
	char c = inputStream->lookAhead(0);
	if (c == '(' || c == ')')
		return c;
}

void GSParser::eatWhiteSpaceAndComments()
{
	bool r1, r2;
	do
	{
		r1 = eatWhiteSpace();
		r2 = eatComments();
	}
	while(r1 || r2);
}

bool GSParser::eatWhiteSpace()
{
	bool r = false;
	for (;;)
	{
		char c = inputStream->lookAhead(0);
		if (c == ' ' || c == '\t' || c == '\n' || c == '\r')
		{
			r = true;
			inputStream->getChar();
			continue;
		}
		return r;
	}
}

bool GSParser::eatComments()
{
	bool r = false;
	for (;;)
	{
		char c0 = inputStream->lookAhead(0);
		char c1 = inputStream->lookAhead(1);
		if (c0 == ';')
		{
			r = true;
			inputStream->getChar();
			for (;;)
			{
				char c = inputStream->getChar();
				if (c == '\n' || c == '\r')
					break;
				if (inputStream->isEof())
					break;
			}
			continue;
		}
		if (c0 == '#' && c1 == '|')
		{
			r = true;
			inputStream->getChar();
			inputStream->getChar();
			for (;;)
			{
				if (inputStream->isEof())
				{
					error("unfinished comment");
					break;
				}
				c0 = inputStream->lookAhead(0);
				c1 = inputStream->lookAhead(1);
				if (c0 == '|' && c1 == '#')
				{
					inputStream->getChar();
					inputStream->getChar();
					break;
				}
				inputStream->getChar();
			}
		}
		return r;
	}
}

bool GSParser::tryParseInteger()
{
	int position = inputStream->getPosition();
	char c = inputStream->lookAhead(0);
	int sign = 1;
	if (c == '+')
		inputStream->getChar();
	if (c == '-')
	{
		inputStream->getChar();
		sign = -1;
	}
	if (tryParseUnsignedInteger())
	{
		integerValue *= sign;
		return true;
	}
	inputStream->setPosition(position);
	return false;
}

bool GSParser::tryParseUnsignedInteger()
{
	char c = inputStream->lookAhead(0);
	if (c < '0' || c > '9')
		return false;
	buffer.clear();
	for (;;)
	{
		c = inputStream->lookAhead(0);
		if (c < '0' || c > '9')
			break;
		c = inputStream->getChar();
		buffer.push_back(c);
	}
	integerValue = atoi(buffer.c_str());
	return true;
}

bool GSParser::tryParseString()
{
	char c = inputStream->lookAhead(0);
	if (c != '\"')
		return false;
	inputStream->getChar();
	stringValue.clear();
}

bool GSParser::tryParseBool(int &token)
{
}

void GSParser::error(const std::string &msg)
{
}


