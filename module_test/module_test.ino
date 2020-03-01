#define D0D 2
#define D1D 3
#define D2D 4
#define D3D 5

int D1=0,D2=0,D3=0,D4=0;                                   //12=B,,,,,,,11=A,,,,,,,,13=C

void setup() {
  // put your setup code here, to run once:
    pinMode(D0D, INPUT);
    pinMode(D1D, INPUT);
    pinMode(D2D, INPUT);
    pinMode(D3D, INPUT);
    Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
   Serial.println("hi");
   digitalread();
   serialprint();
  delay(2000);
}
void digitalread()
{
   D1=digitalRead(D0D);
   D2=digitalRead(D1D);
   D3=digitalRead(D2D);
   D4=digitalRead(D3D);
} 

void serialprint()
{   
   Serial.print(D1);
   Serial.print(D2);
   Serial.print(D3);
   Serial.print(D4);
}   
