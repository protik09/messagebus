#pragma once

#include <string>

class Message {
private:
	int priority;
	std::string from;
	std::string topic;

 public:
	Message(int priority, const std::string& from, const std::string& topic) : priority(priority), from(from), topic(topic) {}
	int getPriority();
	std::string getFrom();
	std::string getTopic();
	virtual std::string toString();
};

