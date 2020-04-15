//==============================================================
// Filename : MessageBus.h
// Authors : Dharanish NH, Protik Banerji
// Version : 1.0
// License : MIT
// Description : Messagebus class member function prototypes
//==============================================================

#pragma once // Preprocessor definition for header guard

#include <vector>		 // include vector library for dynamic arrays
#include <set>			 // include set library for storing unique data in specific order
#include <unordered_map> // include unordered_map for storing unique data and mapped value
#include <queue>		 // include Queue for storing messages
#include <iostream>		 // standard C++ library for input and output

#include "Node.h"				  // User defined Node library
#include "TextMessage.h"		  // User defined Textmessage library
#include "TextMessageCompare.cpp" // User defined TextmessageCompare library

class MessageBus
{																							  // Class for messagebus
private:																					  // Private data members
	std::set<Node *> nodes;																	  // Set which stores the nodes pointer
	std::unordered_map<std::string, std::vector<Node *>> subscriptions;						  // Unordered map to store message and node information
	std::priority_queue<TextMessage *, std::vector<TextMessage *>, TextMessageCompare> queue; // Priority queue to store the messages in priority

	// Comments below follow the rule of the what the Function claims to be from it's function name.
public:
	MessageBus() {}									// Empty constructor of messagebus
	void registerTopic(const std::string &);		// Function to register the topic
	void registerNode(Node *);						// Function to register the node
	void registerNodeForTopic(Node *, std::string); // Function to register the node for topic
	void acceptMessage(TextMessage *);				// Function to accept message
	void printMessages();							// Function to print message
	void handleMessages();							// Function to handle message
};
