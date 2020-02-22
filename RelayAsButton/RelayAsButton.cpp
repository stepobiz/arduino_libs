#include "Arduino.h"
#include "RelayAsButton.h"

RelayAsButton::RelayAsButton(int pin, int buttonDelay): _pin(pin), _buttonDelay(buttonDelay) {
  clickAt = 0;
  pinMode(_pin, OUTPUT);
  digitalWrite(_pin, HIGH);
}

bool RelayAsButton::push(){
	if(clickAt > 0){
		return false;
	}
	clickAt = millis();
	digitalWrite(_pin, LOW);
	return true;
}

void RelayAsButton::check(){
	int difference = millis()-clickAt;
	if(difference > _buttonDelay){
		digitalWrite(_pin, HIGH);
		clickAt = 0;
	}
}