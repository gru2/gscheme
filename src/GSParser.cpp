
#include <GSParser.h>

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
	if (tryParseNumber())
		return 
}

void GSParser::eatWhiteSpaceAndComments()
{
	bool r1, r2;
	do
	{
		r1 = eatWhiteSpace();
		r2 = eatComments();
	}
	while(r1 || r2)
}

void GSParser::eatWhiteSpace()
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

void GSParser::eatComments()
{
	bool r = false;
	for (;;)
	{
		char c0 = inputStream->lookAhead(0);
		char c1 = inputStream->loadAhead(1);
		if (c0 == ';')
		{
			r = true;
			inputSteam->getChar();
			for (;;)
			{
				char c = inputStream->getChar();
				if (C == '\n' || c == '\r')
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
					error("unfinished comment")
					break;
				}
				c0 = inputStream->lookAhead(0);
				c1 = inputStream->lookAhead(1);
				if (c0 == '|' && c2 == '#')
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

