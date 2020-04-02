#pragma once

#include <string>
#include <stdexcept>

class TextMessage {
private:
	int priority;
	std::string from;
	std::string topic;
	std::string text;
public:
	TextMessage(int priority, std::string from, std::string topic, std::string text) :
		priority(priority), from(from), topic(topic), text(text) {
		if (priority <= 0 || priority >= 16) throw std::runtime_error("Error in priority");
	}
	
	int getPriority() const;
	std::string getFrom() const;
	std::string getTopic() const;
	std::string getText() const;
	std::string toString() const;
};