#pragma once

#include <string>
#include "Message.h"

class TextMessage: public Message {
private:
	std::string text;
public:
	TextMessage(int priority, const std::string& from, const std::string& topic, const std::string& text) : ..., text(text) {};
	std::string getText();
	virtual std::string toString();
};

