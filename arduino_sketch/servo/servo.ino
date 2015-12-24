#include <Servo.h> 
 
Servo base;
Servo middle;
Servo pitch;

float pos_base = 95; 
float pos_middle = 90;
int pos_pitch = 90;
int i; 
void setup() 
{ 
  base.attach(9);
  middle.attach(10);
  pitch.attach(11);
  base.write(95);
  middle.write(90);
  pitch.write(90);
} 
 
 
void loop() 
{ 
/*  pos_base = 90   ;   
  pos_middle = 0;
  pos_pitch = (pos_base+5)+pos_middle-90;                          
  base.write(pos_base+5); 
  middle.write(90 - pos_middle);
  pitch.write(90+pos_pitch);
*/

for(i  = 60; i<120;++i)
{
  pos_base=i+5;
  pos_middle = 90-(180-2*i);
  base.write(pos_base);
  middle.write(pos_middle);
  pitch.write((pos_base+5)+ (180-2*i));
  delay(30);
}
for(i  = 120; i>60;--i)
{
  pos_base=i+5;
  pos_middle= 90-(180-2*i);
  base.write(pos_base);
  middle.write(pos_middle);
  pitch.write((pos_base+5)+ (180-2*i));
  delay(30);
}


}
