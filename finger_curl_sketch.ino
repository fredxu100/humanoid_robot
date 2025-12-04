#include <Servo.h>


// Temporary Servo placeholders
Servo servo1;
Servo servo2;

bool open = true;

void setup() {
  //TEMPORARY MAKE SURE TO CHANGE
  servo1.attach(10); // attach servo to pin 1
  //servo2.attach(2); // attach servo to pin 2

  Serial.begin(9600);
  Serial.println("PRESS X + ENTER TO CLOSE/OPEN");
  Serial.println("--------------------");
}


void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0)
  {
    char s = Serial.read();
    if (s == 'X')
    {
      if (open) {
        // Close hand gradually
        for (int pos = 0; pos <= 255; pos++) { // 0° → 180°
          servo1.write(pos);
          //servo2.write(pos);
          delay(4); // adjust speed
        }
        open = false;
      }
      else{
        // Open hand gradually
        for (int pos = 255; pos >= 0; pos--) {
          servo1.write(pos);
          //servo2.write(pos);
          delay(4); // adjust speed
        }
        open = true;
      }
    }
  }
    
}
