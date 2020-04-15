//==============================================================
// Filename : MessageBus.cpp
// Authors : Dharanish NH, Protik Banerji
// Version : 1.0
// License : MIT
// Description : MeasurementMessagebus class member function defintions
//==============================================================
#include "MeasurementMessage.h"							// Include user defined library

double MeasurementMessage::getMeasurement()		       //getMeasurement function definition
{
	return m;
}

 virtual std::string MeasurementMessage::toString() const          //toString function definition of type virtual

{                                                                 //toString function definition
	 return "MESSAGE " + std::to_string(Message::getPriority()) + " " + from + " " + Message::topic+" M " + m;     //concatenates info of priority,from,topic,measurement
}