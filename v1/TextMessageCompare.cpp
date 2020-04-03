#include <iostream>                  //standard C++ library for input and output

#include "TextMessage.h"			//include standard user defined library

class TextMessageCompare {            //TextMessageCokmpare class initialisation
public:
	bool operator()(TextMessage* a, TextMessage* b) {                  //function checks the priority of the message
		return (a->getPriority() > b->getPriority());
	}
};