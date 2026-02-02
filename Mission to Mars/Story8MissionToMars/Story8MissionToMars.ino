
#include <NewPing.h>

#define TRIGGER_PIN  4  
#define ECHO_PIN     5  
#define MAX_DISTANCE 200 

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

int LEFT_REV = 12;
int LEFT_FWD = 11;
int LEFT_ENABLE = 10;
int RIGHT_ENABLE = 9;
int RIGHT_FWD = 8;
int RIGHT_REV = 7;

void setup() {
  Serial.begin(115200); 
  int distance = sonar.ping_cm();
}

void forward(int delaytime)
{
digitalWrite (LEFT_REV, LOW);
digitalWrite (RIGHT_REV, LOW);
digitalWrite (LEFT_ENABLE, HIGH);
digitalWrite (RIGHT_ENABLE, HIGH);
digitalWrite (LEFT_FWD, HIGH);
digitalWrite (RIGHT_FWD, HIGH);
delay(delaytime);
}

void stop(int delaytime)
{
digitalWrite (LEFT_REV, LOW);
digitalWrite (RIGHT_REV, LOW);
digitalWrite (LEFT_ENABLE, LOW);
digitalWrite (RIGHT_ENABLE, LOW);
digitalWrite (LEFT_FWD, LOW);
digitalWrite (RIGHT_FWD, LOW);
delay(delaytime);
}

void reverse(int delaytime)
{
digitalWrite (LEFT_REV, HIGH);
digitalWrite (RIGHT_REV, HIGH);
digitalWrite (LEFT_ENABLE, HIGH);
digitalWrite (RIGHT_ENABLE, HIGH);
digitalWrite (LEFT_FWD, LOW);
digitalWrite (RIGHT_FWD, LOW);
delay(delaytime);
}

void turnleft(int delaytime)
{
digitalWrite (LEFT_REV, LOW);
digitalWrite (RIGHT_REV, LOW);
digitalWrite (LEFT_ENABLE, LOW);
digitalWrite (RIGHT_ENABLE, HIGH);
digitalWrite (LEFT_FWD, LOW);
digitalWrite (RIGHT_FWD, HIGH);
delay(delaytime);
}

void loop() {
  delay(50);                     
  Serial.print("Ping: ");
  Serial.print(sonar.ping_cm()); 
  Serial.println("cm");
  forward(100000000000000000);
  if(sonar.ping_cm() < 12){
    stop(2000);
    reverse(2000);
    turnleft(850);
  }
}