#pragma once

#include <vector>                            //include vector library for dynamic arrays
#include <set>                               //include set library for storing unique data in specific order
#include <unordered_map>                     //include unordered_map for storing unique data and mapped value 
#include <queue>                             //include Queue for storing messages
#include <iostream>                           //standard C++ library for input and output

#include "Node.h"                             //User defined Node library
#include "TextMessage.h"                      //User defined Textmessage library
#include "TextMessageCompare.cpp"             //User defined TextmessageCompare library

class MessageBus {                                            //class for messagebus
private:													 //private data members
	std::set<Node*> nodes;                                   //set which stores the nodes pointer
	std::unordered_map<std::string, std::vector<Node*>> subscriptions;        //unordered map to store message and node information
	std::priority_queue<TextMessage*, std::vector<TextMessage*>, TextMessageCompare> queue;         //priority queue to store the messages in priority
		
public:
	MessageBus() {}                                              //constructor of messagebus
	void registerTopic(const std::string&);                      //function to register  the topic
	void registerNode(Node*);                                    //function to register  the node
	void registerNodeForTopic(Node*, std::string);                //function to register  the node for topic
	void acceptMessage(TextMessage*);						      //function to accept message
	void printMessages();                                         //function to print message
	void handleMessages();                                         //function to handle message
};