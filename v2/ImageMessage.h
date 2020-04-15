//==============================================================
// Filename : ImageMessage.h
// Authors : Dharanish NH, Protik Banerji
// Version : 1.0
// License : MIT
// Description : ImageMessage class member function prototypes
//==============================================================

#pragma once
#include "Message.h"
#include "base64.h"
#include <vector>

class ImageMessage : public Message {
private:
	std::string base64encoded;
public:
	ImageMessage(int priority, const std::string& from, const std::string& topic, unsigned char* data, int length) :
	Message(priority, from, topic) {
		base64encoded = base64_encode(data, length);
	};
	ImageMessage(int priority, const std::string& from, const std::string& topic, std::string base64encoded) :
	Message(priority, from, topic) {}
	// std::vector<unsigned char> getImage();
	std::string getImage(); // Change to string to write the base64encoded string to terminal.
	virtual std::string toString();
};

