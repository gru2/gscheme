#ifndef __GSPARSER_H
#define __GSPARSER_H

#include <string>

class SourceCodePosition;
class ErrorReporter;
class InputStream;

class GSParser
{
public:
	GSParser();
	~GSParser();

	enum TokenType { TT_IDENTIFIER = 256, TT_INTEGER, TT_TRUE, TT_FALSE, TT_STRING,
		TT_EOF };

	int lex();

	SourceCodePosition *getSourceCodePosition() const
		{ return sourceCodePosition; }
	void setSourceCodePosition(SourceCodePosition *x)
		{ x = sourceCodePosition; }
	ErrorReporter *getErrorReporter() const { return errorReporter; }
	void setErrorReporter(ErrorReporter *x) { errorReporter = x; }
	InputStream *getInputStream() const { return inputStream; }
	void setInputStream(InputStream *x) { inputStream = x; }
protected:
	void eatWhiteSpaceAndComments();
	bool eatWhiteSpace();
	bool eatComments();
	bool tryParseInteger();
	bool tryParseUnsignedInteger();
	bool tryParseString();
	bool tryParseBool(int &token);
	void error(const std::string &msg);

	SourceCodePosition *sourceCodePosition;
	ErrorReporter *errorReporter;
	InputStream *inputStream;
	int integerValue;
	std::string stringValue;
};

#endif
