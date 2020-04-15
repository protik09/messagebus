//==============================================================
// Filename : MessageBus.cpp
// Authors : Dharanish NH, Protik Banerji
// Version : 1.0
// License : MIT
// Description : Messagebus class member function defintions
//==============================================================

#include <map> // Include map library to store data in a mapped data type (subscriptions)

#include "MessageBus.h" // Include user defined function

// Messagebus member to register topic using string key
void MessageBus::registerTopic(const std::string &topic)
{
	subscriptions[topic] = std::vector<Node *>();
}
// Messagebus member to register a new node on the bus
void MessageBus::registerNode(Node *node)
{
	nodes.insert(node);
}

// Member function to for linking node and topic
void MessageBus::registerNodeForTopic(Node *node, std::string topic)
{
	// Read all node elements into a vector structure
	std::vector<Node *> elements = subscriptions[topic];
	// Add new node to the vector structure
	elements.push_back(node);
	// Write the modified node structure to the subscription map
	subscriptions[topic] = elements;
}

// Member function to store messages in the priority queue
void MessageBus::acceptMessage(Message *message)
{
	// Add message to the bottom of the priority queue
	queue.push(message);
}

// Messagebus member function to print message
void MessageBus::printMessages()
{
	while (!queue.empty()) // Checks if queue is not empty
	{
		Message tm = *(queue.top());		 // assigns the pointer data to a variable
		std::cout << tm.toString() << std::endl; // converts and prints in string format
		queue.pop();							 // removes the message after displaying
	}
}

// Member function to handle messages
void MessageBus::handleMessages()
{
	// Process priority queue till empty
	while (queue.size() != 0)
	{
		Message *message = queue.top(); // Message pointer holds the info of topmost data on queue

		std::vector<Node *> elements = subscriptions[message->getTopic()]; //Read all node elements into a vector structure

		// For all elements in a particular topic
		for (Node *node : elements)
		{
			node->acceptMessage(message); // Print the message located on the node element
		}
		queue.pop(); //removes the data from queue
	}
}

// Run method implementation for MessageBus
void MessageBus::run()
{
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
}