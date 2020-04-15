//==================================================================
// Filename : TextMessageCompare.cpp
// Authors : Dharanish NH, Protik Banerji
// Version : 1.0
// License : MIT
// Description : TextMessageCompare class member function defintions
//==================================================================

#include <iostream> // Standard C++ library for input and output

#include "TextMessage.h" //include Library with the Textmessage members and functions

// TextMessageCompare class initialisation
class TextMessageCompare
{ 
public:
	// Overload the () operator to return the result of comparing the priorities
	// of TextMessage A and B
	bool operator()(TextMessage *a, TextMessage *b)
	{ 
		return (a->getPriority() > b->getPriority());
	}
};