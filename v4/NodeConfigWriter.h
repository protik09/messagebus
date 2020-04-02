#pragma once
#include <iostream>

class NodeConfigWriter {
private:
	std::string dbLocation;

public:
	NodeConfigWriter(const std::string& dbLocation) : dbLocation(dbLocation) {}
	void clear();
	void writeNode(const std::string& node, const std::string& nodeAddress, int nodePort, const std::string& applicationAddress, int applicationPort);
	void writeTopic(const std::string& topic);
	void writeNodeTopic(const std::string&, const std::string& topic);
};

