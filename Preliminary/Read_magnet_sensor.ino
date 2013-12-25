const int lowBit = 2;
const int midBit = 3;
const int highBit = 4;

int currentState = 0;
int lastState = 0;

void setup(){
  
  Serial.begin(9600);
  
  pinMode(lowBit, INPUT);
  pinMode(midBit, INPUT);
  pinMode(highBit, INPUT);
  
}

void loop() {
  
  currentState = digitalRead( highBit );
  currentState  = currentState << 1;
  
  currentState += digitalRead( midBit );
  currentState = currentState << 1;
  
  currentState += digitalRead( lowBit );
  
  if( currentState != lastState ){
    lastState = currentState;
    Serial.println( currentState );
  }
  
  delay(100);
}
