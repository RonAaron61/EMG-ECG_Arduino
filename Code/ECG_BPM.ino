long data;
long value1 = 0;
unsigned long times1 = 0;
unsigned long times2 = 0;
int bpm = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  data = analogRead(A0);

  int numRead = 80;
  long senseSum = 0;
  for (int k = 0; k < numRead; k++){  //Average of every 80 value
    senseSum += (analogRead(A0));
  }
  long senseAve = senseSum/ numRead;

  //For plotting (Serial plot)
  Serial.print(BPM(senseAve));
  Serial.print(",");
  Serial.println(senseAve);


  //Print BPM only (Serial monitor)
  //BPM(senseAve);
}


long BPM(long value){ 
  if (value1 > value){
    value1 -= 0.1;
  }
  else if(value1 < value){  //detect a heartbeat
    times2 = millis();
    bpm = 60000/(times2 - times1);
    if (bpm <=180){       // sometime the value get to high because it detect other value as the peak R value, usually it detect P or T value as the peak
      times1 = times2;
      //Serial.println(bpm);  //BPM value
    }
    value1 = value; // Peak value - R value from ECG
  }
  return value1;
}
