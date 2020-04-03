#pragma once

#include <string>                          //include string library
#include <stdexcept>                      //include stdexcept to define standard runtime exceptions

class TextMessage {						//TextMessage class initialisation
private:                                   //ptivate data members
	int priority;                             // priority variable which is integer type
	std::string from;                          // from variable which is string type to store from information
	std::string topic;						// topic variable which is string type to store topic information
	std::string text;						// text variable which is string type to store text information
public:
	TextMessage(int priority, std::string from, std::string topic, std::string text) :     //constructor intialisation
		priority(priority), from(from), topic(topic), text(text) {
		if (priority <= 0 || priority >= 16) throw std::runtime_error("Error in priority");    // checks priority if its not valid throws a runtime error message
	}
	
	int getPriority() const;                             //function to get priority information
	std::string getFrom() const;                         //function to get from information
	std::string getTopic() const;						 //function to get topic information
	std::string getText() const;						 //function to get text information
	std::string toString() const;						 //function to convert into string and concatenate information
};