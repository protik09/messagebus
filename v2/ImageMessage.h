#pragma once
#include "Message.h"
#include "base64.h"
#include <vector>

class ImageMessage : public Message {
private:
	std::string base64encoded;
public:
	ImageMessage(int priority, const std::string& from, const std::string& topic, unsigned char* data, int length) : ... {
		base64encoded=base64_encode(data, length);
	};
	ImageMessage(int priority, const std::string& from, const std::string& topic, std::string base64encoded) : ... {}
	std::vector<unsigned char> getImage();
	virtual std::string toString();
};

