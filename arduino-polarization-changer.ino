long totalDuration;
long relayOneSingleDuration;
long relayTwoSingleDuration;
long pauseSingleDuration;
long startTime;
long endTime;

void setup() {
  totalDuration = 240000;
  relayOneSingleDuration = 3000;
  relayTwoSingleDuration = 3000;
  pauseSingleDuration = 1000;

  pinMode(8, OUTPUT);
  digitalWrite(3, LOW);

  pinMode(3, OUTPUT);
  digitalWrite(3, HIGH);

  pinMode(2, OUTPUT);
  digitalWrite(2, HIGH);

  pinMode (4, OUTPUT);
  digitalWrite(4, HIGH);

  pinMode(7, INPUT_PULLUP);
}

void loop() {
  waitForButtonPress();
  startSwitching();
}

void waitForButtonPress(){
  while (digitalRead(7) == HIGH){
  }
}

void startSwitching(){
  startTime = millis();
  endTime = startTime + totalDuration;
  digitalWrite(8, HIGH);
  while (millis()<endTime) {
  doSingleRelayCycle(2, relayOneSingleDuration, pauseSingleDuration);
  doSingleRelayCycle(4, relayTwoSingleDuration, pauseSingleDuration);
  }
  digitalWrite(8, LOW);
}

void doSingleRelayCycle(int relayNr, long relayDuration, long pauseSingleDuration){
  switchRelay(relayNr);
  delay(relayDuration);
  switchRelay(relayNr);
  delay(pauseSingleDuration);
}

void switchRelay(int relayNr){
  if (digitalRead(relayNr)==HIGH) digitalWrite(relayNr, LOW);
  else if (digitalRead(relayNr)==LOW) digitalWrite(relayNr, HIGH);
}



  
  


 
 

