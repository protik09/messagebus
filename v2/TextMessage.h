//==============================================================
// Filename : TextMessage.h
// Authors : Dharanish NH, Protik Banerji
// Version : 1.0
// License : MIT
// Description : TextMessage class member function prototypes
//==============================================================
#pragma once // Preprocessor definition for header guard

#include <string>            // include string library
#include "Message.h"         //Include user defined library

class TextMessage: public Message {              //TextMessage class initialisation inherits Message class
private:										 // Private data members
	std::string text;							 // Text variable which is string type to store text information
public:
	TextMessage(int priority, const std::string &from, const std::string &topic, const std::string &text) :
	Message(priority, from, topic), text(text){};    //constructor initialisation inherits message class
	std::string getText();							// Function to get text information
	virtual std::string toString();					// Virtual function to convert into string and concatenate information
};

