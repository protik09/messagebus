//==============================================================
// Filename : ImageMessage.h
// Authors : Dharanish NH, Protik Banerji
// Version : 1.0
// License : MIT
// Description : ImageMessage class member function prototypes
//==============================================================

#pragma once
#include "Message.h"						// include standard user defined library
#include "base64.h"							// include standard user defined library
#include <vector>							// include standard vector library for storing values in vector

class ImageMessage : public Message {       //ImageMessage class initialisation inherits Message class
private:									//Private data members
	std::string base64encoded;				//base64 encoded of type string
public:
	ImageMessage(int priority, const std::string& from, const std::string& topic, unsigned char* data, int length) :
	Message(priority, from, topic) {
		base64encoded = base64_encode(data, length);
	};  //constructor initialisation to get base64encoded string
	ImageMessage(int priority, const std::string& from, const std::string& topic, std::string base64encoded) :
	Message(priority, from, topic){} //constructor initialisation inherits Message class
	// std::vector<unsigned char> getImage();
	std::string getImage(); // Change to string to write the base64encoded string to terminal.
	virtual std::string toString();
};

