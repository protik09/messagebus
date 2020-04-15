//==============================================================
// Filename : MessageBus.cpp
// Authors : Dharanish NH, Protik Banerji
// Version : 1.0
// License : MIT
// Description : ImageMessage class member function prototypes
//==============================================================
#pragma once									// Preprocessor definition for header guard
#include "Message.h"							//include user defined Message library
#include "base64.h"								//include user defined base64 library
#include <vector>							    //include vector library

class ImageMessage : public Message {           // ImageMessage class initialisation inherits Message
private:										// Private data members
	std::string base64encoded;                  // base64encoded variable of type string
public:
	ImageMessage(int priority, const std::string& from, const std::string& topic, unsigned char* data, int length) : Message(priority, from, topic) {
		base64encoded=base64_encode(data, length);
	};
	ImageMessage(int priority, const std::string& from, const std::string& topic, std::string base64encoded) : Message(priority, from, topic),base64encoded(base64encoded){} //constructor initialisation
	std::vector<unsigned char> getImage();							//Function to get Image 
	virtual std::string toString();                                 // Function to convert into string and concatenate information
};

