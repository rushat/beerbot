#include <SpeedTrig.h>
#include <Servo.h>

Servo base, middle, pitch;

double pos_base=0, pos_middle=0, pos_pitch=0;
double pos_base_prev=95, pos_middle_prev=90, pos_pitch_prev=90;
double x, y;
char junk =' ';
int l=17;
boolean update;
void setup()
{
  base.attach(9);
  middle.attach(10);
  pitch.attach(11);
  //Initial Values
  base.write(95);
  middle.write(90);
  pitch.write(90);
  
  //Serial begin
  Serial.begin(9600);
  Serial.flush();
}

void loop()
{  Serial.println("Enter x coordinate: ");
    while(Serial.available()==0);
    x= Serial.parseFloat();
    while(Serial.available()>0)
    {  
      junk = Serial.read();
    }
    Serial.println(x);
    Serial.println("Enter y coordinate: ");
    while(Serial.available()==0);
    y=Serial.parseFloat();
    while(Serial.available()>0)
    {  
      junk = Serial.read();
    }
    Serial.println(y);
    if (sqrt(x*x + y*y) <= 2*l)
   {
     pos_middle = 2.0*acos((sqrt(x*x + y*y))/(2.0*l));
     pos_base = atan2(y,x)-(pos_middle/2.0);
     Serial.println(pos_base);
     if(pos_middle>=0 && pos_middle<=3.15 && pos_base>=0 && pos_base<=3.15)
     {
       update=1;
     }
     else
     {
       pos_middle = pos_middle_prev;
       pos_base=pos_base_prev;
       update=0;
     }
     
   }
  else
 {
   pos_middle = pos_middle_prev;
       pos_base=pos_base_prev;
       update=0;
 }
    if(pos_base_prev<pos_base)
      { for(int i=pos_base_prev; i<=pos_base; ++i)
          {base.write(i);
            delay(10);
          }
      }
    else
    {for(int i=pos_base_prev; i>=pos_base; --i)
          {base.write(i);
            delay(10);
          }
    }
    if(pos_middle_prev<pos_middle)
   {  for(int i=pos_middle_prev; i<=pos_base; ++i)
          {middle.write(i);
            delay(10);
          }
      }
    else
    {for(int i=pos_middle_prev; i>=pos_middle; --i)
          {middle.write(90-i);
            delay(10);
          }
    }
    //middle.write(90.0-(pos_middle*(180.0/3.14)));
    //delay(200);
    if(update==1)
    {
      pos_middle_prev=pos_middle;
      pos_base_prev=pos_base;
    }
    else
    {
      Serial.println("retry");
    }
    
    

}

