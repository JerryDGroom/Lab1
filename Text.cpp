#include "Text.h"
#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>

using namespace std;

Text::Text (const char* charSeq){
	bufferSize = strlen (charSeq) + 1;
	buffer = new char[bufferSize];
	strcpy(buffer, charSeq);
}

Text::Text (const Text& other){
	bufferSize = other.getLength();
	buffer = new char[bufferSize];
	strcpy(buffer, other.getLetters());
}

void Text::operator = (const Text& other){
	if(buffer != other.getLetters()){
	bufferSize = other.getLength();
	buffer = new char[bufferSize];
	strcpy(buffer, other.getLetters());
	}
}

char Text::operator [] (int n) const{
	if (n < bufferSize){
		return buffer[n];
	} else {
		return '\0';
	}
}

int Text::getLength()const{
	return (bufferSize - 1);
}

char* Text::getLetters()const{
	return buffer;
}

void Text::clear(){
	buffer[0] = '\0';
}

Text::~Text(){
	delete buffer;
}

void Text::showStructure()const{
cout << buffer << endl;
}

// ******** Individual Stuff **********

//Text Text::toUpper( const Text& other ) const{
//	int i = 0;
//	Text word = other;
//	char c;
//	while (word[i]){
//		other = word[i];
//		word[i] = toUpper(c);
//		i++;
//	}
//
//}
//
//Text Text::toLower(const Text& other) const{
//	int i = 0;
//	char* word = other;
//	char c;
//	while (word[i]){
//		c=word[i];
//		word[i] = toLower(c);
//		i++;
//	}
//
//}
// **************************  TEXTIO.CPP STUFF ***************************************
istream & operator >> ( istream &input, Text &inputText )

// Text input function. Extracts a string from istream input and
// returns it in inputText. Returns the state of the input stream.

{
    const int textBufferSize = 256;     // Large (but finite)
    char textBuffer [textBufferSize];   // text buffer

    // Read a string into textBuffer, setw is used to prevent buffer
    // overflow.

    input >> setw(textBufferSize) >> textBuffer;

    // Apply the Text(char*) constructor to convert textBuffer to
    // a string. Assign the resulting string to inputText using the
    // assignment operator.

    inputText = textBuffer;

    // Return the state of the input stream.

    return input;
}

//--------------------------------------------------------------------

ostream & operator << ( ostream &output, const Text &outputText )

// Text output function. Inserts outputText in ostream output.
// Returns the state of the output stream.

{
   output << outputText.buffer;
   return output;
}
