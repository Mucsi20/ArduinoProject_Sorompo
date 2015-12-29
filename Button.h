class Button {
	unsigned long lastPress;
	int pin;
	
	public:
	
	Button(int pin) {
		pinMode(pin, INPUT);
		this->pin = pin;
		lastPress = millis();
	}
	
	bool isPressed() {
		unsigned long c = millis();
		if (c - lastPress > 300 && digitalRead(pin) == HIGH) {
			lastPress = millis();
			return true;
		}
		return false;
	}
};