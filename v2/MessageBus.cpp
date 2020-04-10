#include <map>                                 //include map library to store data in mapped fashion

#include "MessageBus.h"                       //include user defined function

void MessageBus::registerTopic(const std::string& topic)               //function to register topic accepts string data
{
	subscriptions[topic] = std::vector<Node*>();                       
}

void MessageBus::registerNode(Node* node) {                           //function creates new nodes
	nodes.insert(node);
}

void MessageBus::registerNodeForTopic(Node* node, std::string topic) {         //function to for linking node and topic
	std::vector<Node*> elements = subscriptions[topic];
	elements.push_back(node);
	subscriptions[topic] = elements;
}

void MessageBus::acceptMessage(TextMessage* message) {                          //function to store messages in queue
	queue.push(message);
}

void MessageBus::printMessages() {                                             //function to print message
	while (!queue.empty()) {                                                   //checks if queue is not empty 
		TextMessage tm = *(queue.top());                                       //assigns the pointer data to a variable
		std::cout << tm.toString() << std::endl;                               //converts and prints in string format
		queue.pop();                                                            //removes the message after displayiing
	}
}

void MessageBus::handleMessages() {                                             //handleMessages funcction definition 
	while (queue.size()!=0) {                                                   //loop until queue gets empty
		TextMessage* message = queue.top();                                     //message pointer holds the info of topmost data on queue
		
 		std::vector<Node*> elements = subscriptions[message->getTopic()];            //stores topic information in vector elements

		for (Node* node : elements) {                                                //prints all the information in the elements
			node->acceptMessage(message);
		}
		queue.pop();                                                              //removes the data from queue
	}
}