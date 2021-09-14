# commercial vesion
This is the commercial version of the above project(NOTE!! this part has bugs and issues).
we have mannaged to add the circuit onto a PCB bord with the required interface. The code was trasfered from Arduino to ATMEGA328P.

![image](https://user-images.githubusercontent.com/88607869/133278567-0f7313dd-a012-486d-9407-eb1d113a47da.png)
<ul>
<li>This is the PCB of the commercial version of the project.</li>
<li>Reset button:- This button resets the program cycle of atmega.</li>
<li>Data set button :- when this button is pressed the data values in the sensors are stored and later
used for live comparison.</li>
<li>Sensor interface:- these are the pins where the ultrasonic sensors are connected with the PCB
board.</li>
<li>Atmega 382p: this is the microcontroller that is being used to run our program.This is the brain
of the system. This is where all the computation and working takes place.</li>
<li>Vin and GND:- The input voltage needed for the functioning of atmega is provided between
these points.</li>
<li>Lm7805 :- This is a voltage controller IC. It is used in the circuit to make sure that only a voltage
of 5V is passed through to the Atmega. This helps in protecting the system from voltage
fluctuations.</li>
<li>Oscillator :- This is a 16mhz crystal oscillator which provides the required clock signal for the
working of atmega.</li>
<li>Data set led :- This LEDblinks when data is being set.</li>
<li>Alert buzzer:- this buzzer goes out when the presence of an elephant is detected.</li>
<li>Alert Led:- this LEd blinks when the presence of an elephant is detected.</li>
<li>Alert pin:- these pins are connected to external devices to send alert message(premium version).</li>
<li>Audio jack:- Used to send output voice signals to external speakers.</li>
<li>Sd card interface:- this the interface between microSD adaptor and the PCB.</li>
<li>Sd status led:- This led blinks when the Sd adaptor is connected and active.</li>
<li>Extra pins are mounted for any ad-on devices.</li>
 </ul>
