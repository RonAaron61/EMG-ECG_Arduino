/* 
 *  https://github.com/RonAaron61/EMG-ECG_Arduino
 *  
 *  Example code to move servo motor if the signal is above some threshold value
 *  you can replace this servo with yor desire code
 *  maybe for your hand robot or something
*/

#include <Servo.h>  //Library servo

Servo myServo;

long rest = 0;
long threshold = 0;
int post = 1;

void setup() {
  Serial.begin(9600);

  myServo.attach(3);
  myServo.write(0);
  
  delay(3000);
  long resting = 0;
  //Average value when your hand is resting
  for(int i=0; i < 200; i++){
    resting += (analogRead(A0));
  }
  rest = resting/200; //Average value of resting
  
  // === THRESHOLD === //
  threshold = rest * 5; //threshold
  
  delay(1000);
}

void loop() {
  int numRead = 80;
  long senseSum = 0;
  for (int k = 0; k < numRead; k++){
    senseSum += (analogRead(A0));
    //delay(1);
  }
  long senseAve = senseSum/ numRead;

  Serial.print(senseAve);
  Serial.print(" ");
  Serial.println(threshold);

  if (senseAve >= threshold){   //if emg signal is above threshold value
    if (post > 0){              //servo open
      myServo.write(180);
      post = post * -1; // -1
      delay(100);
    }                           //servo still open
    else if (post <0){
      myServo.write(180);
    }
  }

  else if (senseAve <= threshold){
    if (post < 0){              //servo close
      myServo.write(180);
      post = post *-1;  // 1
      delay(100);
    }
  }
}
