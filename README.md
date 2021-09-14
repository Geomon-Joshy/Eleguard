# Eleguard
This project is done as a part of final year project towards bachelors of electronics at calicut university by :- <br>
**BINDHU JOY <br>
CHRISTEENA PAUL<br>
JINI K P <br>
SHINTU SURESH <br>
GEOMON JOSHY** <br>

## AIM
The motive of this project is to build an echo friendly , ecnomical device to minimise interactions between wikd elephants and human cultivations without causing any physicl or any other modes of loos to both parties.

## ABSTRACT
These days, Unhealthy interactions between elephants and human cultivations are really common. Allthough there are measure taken to prevent this they are not very effective. Hence we have build a device to do this.<br>
**B**ased on some information that we collected and what is on intrenet we understood few things:-
<ul>
<li> Herds of elephants enter crops because it is on their ancient paths to water holes.</li>
<li> Bull elephants in their musk period wander around searching for a mate .(Occurs only during a certain period of time)</li>
<li> Elephants wander in search of food. (Even though this seems to be the obvious reason in reality it is the most unlikely). only way to prevent this is aforestation</li>
</ul>
By putting the obvious factors into consideration we was able to design a device (Using simple ultra_sonic sensores and Arduino) to detect the precesence of elephants (Herds and  bulls separately). Using this information we trigger a 3-d speaker which produces sounds of watering hole (for herds of elephants) and female matting calls (For bull elephans).THe speakers are set in such a way that the sound seems to appearing from deep inside the forest and the elephants are tricked to be returning to the forest following the  imaginary voices from the speakers. 

## WORKING
### Hardware
<ul>
<li>ARDUINO UNO r3</li>
<li>ULTRASONIC SENSOR</li>
<li>MICROSD ADAPTER</li>
</ul>
ARDUINO UNO r3
<br>
Arduino Uno Rev3 is a microcontroller board based on the ATmega328P . It
has 14 digital input/output pins , 6 analog
inputs, It contains everything needed to support the
microcontroller; simply connect it to a computer with a USB cable or power it with a28
AC-to-DC adapter or battery to get started.. You can tinker with your Uno without
worrying too much about doing something wrong, worst case scenario you can replace
<br>
ULTRASONIC SENSOR
<br>
This ultrasonic sensor module can be used for measuring distance, object
sensor, motion sensors etc. High-sensitive modules can be used with33
microcontrollers to integrate with motion circuits to make robotic projects
and other distance, position & motion sensitive products.
The module sends eight 40Khz square wave pulses and automatically
detects whether it receives the returning signal. If there is a signal
returning, a high level pulse is sent on the echo pin. The length of this pulse
is the time it took the signal from first triggering to the return echo.
<br>
MICROSD ADAPTER
<br>
Micro SD Card Reader Module also called Micro SD Adaptor is designed for
dual I/O voltages. This Module is a simple solution for transferring data to
and from a standard SD card. The pinout is directly compatible with Arduino,
but can also be used with other microcontrollers. This module has SPI
interface which is compatible with any sd card and it uses 5V or 3.3V power35
supply which is compatible with Arduino UNO/Mega.SD module has various
applications such as data logger, audio, video, graphics. 
<br>
### Coding part
DATA SETTING
<br>

```c++
for(i=3;i<7;i++)
{
digitalWrite(2, LOW);
//triggerpin pulse
delayMicroseconds(2);
digitalWrite(2, HIGH);
delayMicroseconds(10);
digitalWrite(2, LOW);
r[i] = pulseIn(i, HIGH);
}
```                        

This part of the code is were the live data from the sensors is entered into a array <code>r[i]</code>.
The circuit is designed in such a way that the output. <code>pin 2</code> of arduino is connected to <code>Triggpin</code> of all the sensors. There will be a delay in the range of microseconds between the data intake of each sensors, But this will not be an issue while compared to the speed of elephants.\

``` c++
q=digitalRead(A0);
while(q==HIGH) //setting switch
{
a=r[3];
//setting distance
b=r[4];
c=r[5];
d=r[6];
e=1;
digitalWrite(A5,HIGH); //set led
delay(1000);
digitalWrite(A5,LOW);
}
```
This is the part of the circuit were the values from the 4 sensors is added to 4 variables <code>a b c d </code>  while a variable <code>q</code> is ``` 
HIGH ```. The value of ```q``` is ```digitalRead(A0)``` (That is q is the digitalvalue of the voltage in data set switch). The circuit is build in such a way that that the sensor data is entered in to permenent variables when a switch is pressed.
