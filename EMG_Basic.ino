long data;
float rest =0 ;

long data1 = 0;
long data2 = 0;
long data3 = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  data = analogRead(A0);

  int numRead = 80;
  long senseSum = 0;
  for (int k = 0; k < numRead; k++){  //Find the average from every 80 data for smoothing
    senseSum += (analogRead(A0));
    //delay(1);
  }
  long senseAve = senseSum/ numRead;
  Serial.print(senseAve);
  Serial.print(",");
  Serial.println(peak(senseAve));

}

long peak(long value){  // if you only want to find the peak value
  data1 = data2;
  data2 = data3;
  data3 = value;

  if (data1 < data2 && data2 > data3){
    return data2;
  }
}
