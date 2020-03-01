int rspd =150, lspd = 150, spdl = 150, spdr = 150, pin1 = 5, pin2 = 6, pin3 = 9, pin4 = 10;
int val = 0;
int i = 0, j = 0, l = 0, k = 0, cnt = 0;
float spd = 0.0;


void sstop();
void calibrate();
void straight();
void setup() {
  Serial.begin(9600);
}
void loop()
{

  spdr = 0;
  rspd = 150;
  spdl = 0;
  lspd = 150;
  calibrate();
  }

void calibrate()
{
  analogWrite(pin1, spdl);
  analogWrite(pin2, lspd);
  analogWrite(pin3, spdr);
  analogWrite(pin4, rspd);

  spdr = 150;
  rspd = 150;
  spdl = 150;
  lspd = 150;
}

void straight()

{
  analogWrite(pin1, spdl);
  analogWrite(pin2, 0);
  analogWrite(pin3, spdr);
  analogWrite(pin4, 0);
}

void sstop()
{
  analogWrite(pin1, 0);
  analogWrite(pin2, 0);
  analogWrite(pin3, 0);
  analogWrite(pin4, 0);
  spdl = 150;
  spdr = 150;
  rspd = 150;
  lspd = 150;
}

