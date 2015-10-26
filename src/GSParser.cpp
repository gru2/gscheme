
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
