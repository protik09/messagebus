//==============================================================
// Filename : MeasurementMessage.cpp
// Authors : Dharanish NH, Protik Banerji
// Version : 1.0
// License : MIT
// Description : MeasurementMessage class member function defintions
//==============================================================

#include "MeasurementMessage.h" //include user defined MeasurementMessage header

// GetMeasurement function definition
double MeasurementMessage::getMeasurement()
{
	return m;
}

// toString function definition
std::string MeasurementMessage::toString()
{
	return "MESSAGE " + std::to_string(getPriority()) + " " + getFrom() + " " + getTopic() + " M " + std::to_string(m); //concatenates info of priority,from,topic,text
}
