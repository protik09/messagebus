//==============================================================
// Filename : TextMessage.h
// Authors : Dharanish NH, Protik Banerji
// Version : 1.0
// License : MIT
// Description : TextMessage class member function defintions
//==============================================================

#pragma once // Preprocessor definition for header guard

#include <string>	 // include string library
#include <stdexcept> // include stdexcept to define standard runtime exceptions

class TextMessage
{					   // TextMessage class initialisation
private:			   // Private data members
	int priority;	   // Priority variable which is integer type
	std::string from;  // From variable which is string type to store from information
	std::string topic; // Topic variable which is string type to store topic information
	std::string text;  // Text variable which is string type to store text information
public:
	TextMessage(int priority, std::string from, std::string topic, std::string text) : // Constructor intialisation
	priority(priority), from(from), topic(topic), text(text)
	{
		if (priority <= 0 || priority >= 16)
			throw std::runtime_error("Error in priority"); // Checks priority if its not valid throws a runtime error message
	}

	int getPriority() const;	  // Function to get priority information
	std::string getFrom() const;  // Function to get from information
	std::string getTopic() const; // Function to get topic information
	std::string getText() const;  // Function to get text information
	std::string toString() const; // Function to convert into string and concatenate information
};
