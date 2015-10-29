
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

TokenType GSParser::lex()
{
}

void GSParser::eatWhiteSpaceAndComments()
{
	for (;;)
	{
		int c = inputStream->getChar();
		if (c == ' ' || c == '\t' || c == '\n' || c == '\r')
			continue;
		if (c == ';')
		{
			for (;;)
			{
				c = inputStream->getChar();
				if (C == '\n' || c == '\r')
					break;
				if (inputStream->isEof())
					break;
			}
			continue;
		}
	}
}
