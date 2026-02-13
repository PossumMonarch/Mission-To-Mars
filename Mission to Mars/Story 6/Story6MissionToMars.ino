const int RIGHT_FEEDBACK = 2;
const int LEFT_FEEDBACK = 3;
int LEFT_REV = 12;
int LEFT_FWD = 11;
int LEFT_ENABLE = 10;
int RIGHT_ENABLE = 9;
int RIGHT_FWD = 8;
int RIGHT_REV = 7;
volatile int leftcounter = 0;
volatile int rightcounter = 0;

void setup() {
  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(LEFT_FEEDBACK), LeftMotorISR, RISING);
  attachInterrupt(digitalPinToInterrupt(RIGHT_FEEDBACK), RightMotorISR, RISING);
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

void LeftMotorISR() {
  leftcounter++;
}

void RightMotorISR() {
  rightcounter++;
}

void loop() {
Serial.print("Left Counter");
Serial.println(leftcounter);

Serial.print("Right Counter");
Serial.println(rightcounter);

forward(50);

if (leftcounter >= 870) {
  stop(2000)
  exit(0);
}

if (rightcounter >= 870) {
  stop(2000)
  exit(0);
}
}


