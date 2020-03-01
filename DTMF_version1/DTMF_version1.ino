int spd=85;
int rspd=spd,lspd=spd,spdl=spd,spdr=spd;
int D1=0,D2=0,D3=0,D4=0;
 void setup() 
{

    pinMode(2, INPUT);
    pinMode(3, INPUT);
    pinMode(4, INPUT);
    pinMode(7, INPUT);
                         
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  Serial.begin(9600);

}
void loop() 
{  
   D1=digitalRead(2);
   D2=digitalRead(3);
   D3=digitalRead(4);
   D4=digitalRead(7);
 
  
  if(D1==0)
  { 
    if(D2==0)
    {   
      if(D3==0)
      {         
                  if(D4==0)
                  {    
                  }
                  else
                  {
                    
  analogWrite(10,0);
  analogWrite(11,spd); 
  analogWrite(5,0);
  analogWrite(6,spd);
                  }
      }
        else
        {
          
                  if(D4==0)
                  {    
                      
                  analogWrite(10,0);
                  analogWrite(11,(spd)); 
              analogWrite(5,(spd));
                    analogWrite(6,0); 
                 
           
                  }
                }
      }
      else
      {
        if((D3==0)&&(D4==0))
      {                 
                 analogWrite(10,spd);
                 analogWrite(11,0); 
                 analogWrite(5,spd);
                 analogWrite(6,0);                
      }
        else
        {
          
                  if(D4==0)
                  {    
  analogWrite(10,(spd));
  analogWrite(11,0); 
  analogWrite(5,0);
  analogWrite(6,(spd)); 
                  }
                 
         }
      }
     
  }
  else
  { 
    if(D2==0)
    {
     
      if(D3==0)
      {         
                  if(D4==0)
                  {    
  analogWrite(10,0);
  analogWrite(11,0); 
  analogWrite(5,spd);
  analogWrite(6,0); 
                  }
                 
      }
        else
        {
          
                  if(D4==0)
                  {    
                  
  analogWrite(10,0);
  analogWrite(11,0); 
  analogWrite(5,0);
  analogWrite(6,0); 
  }
         }
      }
      else
      {
        if(D3==0)   
      {         
                  if(D4==0)
                  {    
  analogWrite(10,spd);
  analogWrite(11,0); 
  analogWrite(5,0);
  analogWrite(6,0); 
                  }
         }
       
      }      

  }}
