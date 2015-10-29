#ifndef __GSPARSER_H
#define __GSPARSER_H

class SourceCodePosition;
class ErrorReporter;
class InputStream;

class GSParser
{
public:
	GSParser();
	~GSParser();

	enum TokenType { TT_IDENTIFIER = 256, TT_INTEGER, TT_BOOL, TT_STRING,
		TT_EOF };

	TokenType lex();

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

	SourceCodePosition *sourceCodePosition;
	ErrorReporter *errorReporter;
	InputStream *inputStream;
};

#endif
