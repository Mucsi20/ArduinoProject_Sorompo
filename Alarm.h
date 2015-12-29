class Alarm {
  unsigned long lastUpdate = 0;
  bool sound = false;
  int delay = -1;
  int pin;
  
  public:
    
  Alarm(int pin) {
    this->pin = pin;
    pinMode(pin, OUTPUT);
    lastUpdate = millis();
  }

  void alarm(int delay, int wait) {
    this->delay=delay;
    lastUpdate = millis() + wait;
	if (delay < 0) {
		sound = false;
	}
  }
  
  void update() {
    if (delay < 0) {
      return;
    }
    unsigned long c = millis();
    if (c - lastUpdate > delay) {
      if (sound == false) {
        sound = true;
        lastUpdate = millis();
        tone(pin,400,20);
      } else {
        sound = false;
        lastUpdate = millis();
      }
    }
  }
};