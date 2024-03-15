#include<SoftwareSerial.h>
SoftwareSerial mySerial(2,3);

#define m11 4
#define m12 5
#define m21 6
#define m22 7
#define m31 9
#define m32 10
#define m41 11
#define m42 12
char inputByte;
void setup()
{
  Serial.begin(9600);
  mySerial.begin(9600);
  pinMode(m11,OUTPUT);
  pinMode(m12,OUTPUT);
  pinMode(m21,OUTPUT);
  pinMode(m22,OUTPUT);
  pinMode(m31,OUTPUT);
  pinMode(m32,OUTPUT);
  pinMode(m41,OUTPUT);
  pinMode(m42,OUTPUT);
  delay(500);

digitalWrite(m11,LOW);
digitalWrite(m12,LOW);
digitalWrite(m21,LOW);
digitalWrite(m22,LOW);
digitalWrite(m31,LOW);
digitalWrite(m32,LOW);
digitalWrite(m41,LOW);
digitalWrite(m42,LOW);
}
void loop()
{
  if(mySerial.available()>0)
  {
    inputByte=mySerial.read();
    //serial.println(inputByte);
    if(inputByte=='f')
    {
      mySerial.println("FORWARD");
      Serial.println("FORWARD");
      digitalWrite(m11,HIGH);
      digitalWrite(m12,LOW);
      digitalWrite(m21,HIGH);
      digitalWrite(m22,LOW);
    }
    else if(inputByte=='b')
    {
     mySerial.println("REVERSE");
      Serial.println("REVERSE");
      digitalWrite(m11,LOW);
      digitalWrite(m12,HIGH);
      digitalWrite(m21,LOW);
      digitalWrite(m22,HIGH); 
    }
    else if(inputByte=='r')
    {
      mySerial.println("RIGHT");
      Serial.println("RIGH");
      digitalWrite(m11,HIGH);
      digitalWrite(m12,LOW);
      digitalWrite(m21,LOW);
      digitalWrite(m22,HIGH);
    }
     else if (inputByte == 'l')
    {
      mySerial.println("LEFT");
      Serial.println("LEFT");
      digitalWrite(m11,LOW);
      digitalWrite(m12,HIGH);
      digitalWrite(m21,HIGH);
      digitalWrite(m22,LOW);
    }
    else if(inputByte=='s')
    {
      mySerial.println("STOP");
      Serial.println("STOP");
      digitalWrite(m11,LOW);
      digitalWrite(m12,LOW);
      digitalWrite(m21,LOW);
      digitalWrite(m22,LOW);
      //digitalWrite(m31,low);
      //digitalWrite(m32,low);
      //digitalWrite(m41,low);
      //digitalWrite(m42,low);
    }
    else if(inputByte=='ss')
    {
      mySerial.println("SEED CULTIVATOR AND SEED SOWING ");
      digitalWrite(m31,LOW);
      digitalWrite(m32,LOW);
      digitalWrite(m41,LOW);
      digitalWrite(m42,LOW);
    }
    else if(inputByte=='1')
    {
      mySerial.println(" SEED SOWING START");
      digitalWrite(m31,HIGH);
      digitalWrite(m32,LOW);
    }
    else if(inputByte=='2')
    {
      mySerial.println(" SEED SOWING STOP");
      digitalWrite(m31,LOW);
      digitalWrite(m32,LOW);
    }
    else if(inputByte=='3')
    {
      mySerial.println(" CULTIVATOR START");
      digitalWrite(m41,HIGH);
      digitalWrite(m42,LOW);
    }
    else if(inputByte=='4')
    {
       mySerial.println(" CULTIVATOR STOP");
      digitalWrite(m41,LOW);
      digitalWrite(m42,LOW);
    }
    }
  }
  
