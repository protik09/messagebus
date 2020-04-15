//==============================================================
// Filename : TextMessage.h
// Authors : Dharanish NH, Protik Banerji
// Version : 1.0
// License : MIT
// Description : Message class member function prototypes
//==============================================================
#pragma once                               // Preprocessor definition for header guard


#include <string>                          //Include Strinng Library

class Message {                            //Creating Message Class
private:								  //private data members
	int priority;	   // Priority variable which is integer type
	std::string from;  // From variable which is string type to store from information
	std::string topic; // Topic variable which is string type to store topic information

 public:
	Message(int priority, const std::string& from, const std::string& topic) : priority(priority), from(from), topic(topic) {}  // Constructor intialisation
	int getPriority() ;	  // Function to get priority information
	std::string getFrom() ;  // Function to get from information
	std::string getTopic() ; // Function to get topic information
	virtual std::string toString() ; // Function to convert into string and concatenate information
};

