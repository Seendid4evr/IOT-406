#define LED_RED 13
#define LED_YELLOW 12
#define LED_GREEN 8

void setup(){
  Serial.begin(9600);     // Communication started with  9600 baud
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
}

void loop(){
  int sensor=analogRead(A0); // Incoming analog  signal read and appointed sensor
  Serial.println(sensor);   //Wrote serial port

  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_YELLOW, LOW);
  digitalWrite(LED_RED, LOW);

  if(sensor>20 && sensor<=100){
    	digitalWrite(LED_GREEN, HIGH);
  }
  else if(sensor>100 && sensor<=200){
    	digitalWrite(LED_YELLOW, HIGH);
  }
  else if(sensor>200){
    	digitalWrite(LED_RED, HIGH);
  }
}


