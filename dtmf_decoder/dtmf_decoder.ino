#define pin1 5
#define pin2 6
#define pin3 9
#define pin4 10


#define D0D 1
#define D1D 2
#define D2D 3
#define D3D 4

int rspd=255,lspd=255,spdl=255,spdr=255,spd=0;
int D1=0,D2=0,D3=0,D4=0;                                   //12=B,,,,,,,11=A,,,,,,,,13=C
char key;

void decodekey();
void serialread();
void serialprint();
void digitalread();
void decodekey();
void calibrate();
void straight();
void sstop();
 //              --------------------SETUP----------------------
void setup() 
{

    pinMode(D0D, INPUT);
    pinMode(D1D, INPUT);
    pinMode(D2D, INPUT);
    pinMode(D3D, INPUT);
                         
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  Serial.begin(9600);

}
//              --------------------LOOP----------------------
void loop() 
{
 // serialread();
  digitalread();
  decodekey();
  serialprint();
  
  Serial.println(key);

}
//                  --------------------LOOP----------------------
//              --------------------CALIBRATION----------------------
void calibrate()
{ 
  analogWrite(pin1,spdl);
  analogWrite(pin2,lspd); 
  analogWrite(pin3,spdr);
  analogWrite(pin4,rspd); 
  spdr=255;
  rspd=255;
  spdl=255;
  lspd=255;
}
void straight()
{ spdl=255;
  spdr=255;
  analogWrite(pin1,spdl);
  analogWrite(pin2,0); 
  analogWrite(pin3,spdr);
  analogWrite(pin4,0); 
}
void sstop()
{   
  analogWrite(pin1,0);
  analogWrite(pin2,0); 
  analogWrite(pin3,0);
  analogWrite(pin4,0); 
  spdl=255;
  spdr=255;
  rspd=255;
  lspd=255;
}
//              --------------------READ----------------------
void serialread()
{   
   D1=Serial.read();
   D2=Serial.read();
   D3=Serial.read();
   D4=Serial.read();
}   
void serialprint()
{   
   Serial.print(D1);
   Serial.print(D2);
   Serial.print(D3);
   Serial.print(D4);
   }   
void digitalread()
{
   D1=digitalRead(D0D);
   D2=digitalRead(D1D);
   D3=digitalRead(D2D);
   D4=digitalRead(D3D);
}           
//               --------------------DECODEKEY----------------------

void decodekey()
{
  if(D1==0)
  { 
    if(D2==0)
    {   
      if(D3==0)
      {         
                  if(D4==0)
                  {    
                  key='8';      // 0 0 0 0
                  }
                  else
                  {
                  key='4';      // 0 0 0 1
                  }
      }
        else
        {
          
                  if(D4==0)
                  {    
                  key='2';       // 0 0 1 0  
                  }
                  else
                  {
                  key='6';       // 0 0 1 1
                  }
         }
      }
      else
      {
        if(D3==0)
      {         
                  if(D4==0)     // 0 1 0 0
                  {    
                  key='9';
                  }
                  else
                  {
                  key='5';      // 0 1 0 1
                  }
      }
        else
        {
          
                  if(D4==0)
                  {    
                  key='3';        // 0 1 1 0
                  }
                  else
                  {
                  key= '7' ;      // 0 1 1 1            
                  }
         }
      }
     
  }
}

