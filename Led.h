class Led {
  unsigned long lastUpdate = 0;
  bool light = false;
  int delay = -1;
  int pin;
  
  public:
    
  Led(int pin) {
    this->pin = pin;
    pinMode(pin, OUTPUT);
    lastUpdate = millis();
  }

  void blink(int delay, int wait) {
    this->delay=delay;
    lastUpdate = millis() + wait;
	if (delay < 0) {
		light = false;
		digitalWrite(pin, LOW);
	}
  }
  
  void update() {
    if (delay < 0) {
      return;
    }
    unsigned long c = millis();
    if (c - lastUpdate > delay) {
      if (light == false) {
        light = true;
        lastUpdate = millis();
        digitalWrite(pin, HIGH);
      } else {
        light = false;
        lastUpdate = millis();
        digitalWrite(pin, LOW);
      }
    }
  }
};