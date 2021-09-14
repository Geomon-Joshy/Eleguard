int e=0;
#include <TMRpcm.h> //These are the libraries used.
TMRpcm tmrpcm;
#include <SD.h> //library for reading the SD module(audio will be stored here).
void setup() {
pinMode( 2, OUTPUT); //Trig pin connected to all ultrasonic sensors.
pinMode( 3, INPUT); //echo pin 1 
pinMode( 4, INPUT); //echo pin 2
pinMode( 5, INPUT); //echo pin 3
pinMode( 6, INPUT); //echo pin 4
pinMode(A5,INPUT); //set switch- used to uplod data (about the area ) into aurdino
pinMode(7, OUTPUT);
//alert led , sound - these sets of when they detect elephants
pinMode(A0, INPUT); //led set - this led will blink when data is being uploded to computer.
Serial.begin(9600);
Serial.println("Initializing SD card..."); //sd card pin cs-8, sck-13, miso-12
if (!SD.begin(8)) {
Serial.println(" failed!"); //sd card failed
return;
}
else
{
Serial.println("success"); //sd card worked
return;
}
tmrpcm.speakerPin=9; //audio pin
}
void loop() {
int r[10],a,b,c,d,i; //variables
int w=0,x=0,y=0,z=0,s=0,q; //variables
for(i=3;i<7;i++) //looping the circuit till data is taken in on all sensors.
{
digitalWrite(2, LOW);  //triggerpin pulse
delayMicroseconds(2);
digitalWrite(2, HIGH);
delayMicroseconds(10);
digitalWrite(2, LOW);
r[i] = pulseIn(i, HIGH);
}
q=digitalRead(A0);// the value  of data set switch (A0) is assigned to a variable'q'
while(q==HIGH) // When the value of q is high (that is the switch is set) data in the sensors is stored into the microcontroller.
{
a=r[3];
b=r[4];
c=r[5];
d=r[6];
e=1; //This variable is set the ensure that the rest of the code won't be active unlles a data is entered.
digitalWrite(A5,HIGH); //set led-blinks
delay(1000);
digitalWrite(A5,LOW);
}
tmrpcm.setVolume(5); //setting volume of the speaker
while(e==1) //checking if data has been set, if yes the data that is set is compared with the live data from the sensores.
{
if(r[3]<a-50)
{
w=1;
}
if(b-50>r[4]&&(r[3]-500<r[4]<r[3]+500))
{
x=1;
}
if(c-50>r[5])
{
y=1;
}
if(d-50>r[6]&&(r[5]-500<r[6]<r[5]+500))
{
z=1;
}
s=w+x+y+z;
switch(s)
{
case 0:
digitalWrite(7,LOW);
break;
case 1:
digitalWrite(7,LOW);
break;
case 2:
if(w==x || y==z)
{
tmrpcm.play("bull.wav"); //bull audio
digitalWrite(7,HIGH);
//alert led , sound
delay(1000);
digitalWrite(7,LOW);
break;
}
else
break;
case 3:
tmrpcm.play("bull.wav"); //bull audio
digitalWrite(7,HIGH);
//alert led , sound
delay(1000);
digitalWrite(7,LOW);
break;
case 4:
tmrpcm.play("herd.wav"); //herd audio
digitalWrite(7,HIGH);
//alert led , sound
break;
default :
Serial.print("ERROR!!!");
break;
}
}
}
