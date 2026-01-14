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

void left(int delaytime)
{
digitalWrite (LEFT_REV, LOW);
digitalWrite (RIGHT_REV, LOW);
analogWrite (LEFT_ENABLE, 200);
analogWrite (RIGHT_ENABLE, 100);
digitalWrite (LEFT_FWD, HIGH);
digitalWrite (RIGHT_FWD, HIGH);
delay(delaytime);
}

void right(int delaytime)
{
digitalWrite (LEFT_REV, LOW);
digitalWrite (RIGHT_REV, LOW);
analogWrite (LEFT_ENABLE, 100);
analogWrite (RIGHT_ENABLE, 200);
digitalWrite (LEFT_FWD, HIGH);
digitalWrite (RIGHT_FWD, HIGH);
delay(delaytime);
}

void loop()
{
forward(2000);
left(2000);
right(2000);
left(2000);
right(2000);
}