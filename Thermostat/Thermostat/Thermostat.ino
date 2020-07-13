/*
 Name:		Thermostat.ino
 Created:	7/13/2020 1:06:07 PM
 Author:	Luke
*/

#define CONVERTION_FACTOR 0.78125 // can't rember how I got this number but it works

// pins
const uint8_t potPin = A0;
const uint8_t csPin = 10;
const uint8_t relayPin = 8;

// Tempture range
const uint16_t maxTempK = 333.15; // 140 degres F
const uint16_t minTempK = 233.15; // -40 degres F


// the setup function runs once when you press reset or power the board
void setup() {
	Serial.begin(115200);

	analogReadResolution(14); // must be 14bit to work with CONVERTION_FACTOR

	pinMode(relayPin, OUTPUT);
	pinMode(csPin, OUTPUT);
}

// the loop function runs over and over again until power down or reset
void loop() {
	double tempF;
	double tempK;
	uint16_t rawPot;
	
	rawPot = analogRead(potPin);
	tempK = (sqrt(rawPot) * CONVERTION_FACTOR); // convet analog singal to degrees Kelvin
	Serial.print("temp[K]=");
	Serial.print(tempK);
	Serial.print("\traw=");
	Serial.println(rawPot);
}
