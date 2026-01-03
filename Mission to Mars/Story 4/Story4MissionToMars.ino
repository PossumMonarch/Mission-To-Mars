int LEFT_REV = 12;
int LEFT_FWD = 11;
int LEFT_ENABLE = 10;
int RIGHT_ENABLE = 9;
int RIGHT_FWD = 8;
int RIGHT_REV = 7;
void setup()
{
  pinMode(LEFT_REV, OUTPUT);
  pinMode(RIGHT_REV, OUTPUT);
  pinMode(LEFT_ENABLE, OUTPUT);
  pinMode(RIGHT_ENABLE, OUTPUT);
  pinMode(LEFT_FWD, OUTPUT);
  pinMode(RIGHT_FWD, OUTPUT);
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

void stop (int delaytime)
{
digitalWrite (LEFT_REV, LOW);
digitalWrite (RIGHT_REV, LOW);
digitalWrite (LEFT_ENABLE, LOW);
digitalWrite (RIGHT_ENABLE, LOW);
digitalWrite (LEFT_FWD, LOW);
digitalWrite (RIGHT_FWD, LOW);
delay(delaytime);
}

void reverse (int delaytime)
{
digitalWrite (LEFT_REV, HIGH);
digitalWrite (RIGHT_REV, HIGH);
digitalWrite (LEFT_ENABLE, HIGH);
digitalWrite (RIGHT_ENABLE, HIGH);
digitalWrite (LEFT_FWD, LOW);
digitalWrite (RIGHT_FWD, LOW);
delay(delaytime);
}

void loop()
{
forward(5000);
stop (1000);
reverse (2000);
}