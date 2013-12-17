roduct features:
Ultrasonic ranging module HC - SR04 provides 2cm - 400cm non-contact measurement function, the ranging accuracy can reach to 3mm. The modules includes ultrasonic transmitters, receiver and control circuit. The basic principle of work:

     Using IO trigger for at least 10us high level signal,
     The Module automatically sends eight 40 kHz and detect whether there is a pulse signal back.
     IF the signal back, through high level , time of high output IO duration is the time from sending ultrasonic to returning. Test distance = (high level time×velocity of sound (340M/S) /2

C
Specifications:
    power supply :5V DC
    quiescent current : <2mA
    effectual angle: <15°
    ranging distance : 2cm – 500 cm
    resolution : 0.3 cm

There are 4 pins out of the module : VCC , Trig, Echo, GND . So it's a very easy interface for controller to use it ranging. The all process is : pull the Trig pin to high level  for more than 10us impulse , the module start ranging ; finish ranging , If you find an object in front , Echo pin will be high level , and based on the different distance,it will take the different duration of high level. So we can calculated the distance easily :

Distance = ((Duration of high level)*(Sonic :340m/s))/2

finally , look at the back of the module .All of the chip in the module have been burnish , maybe the author want to prevent the designed from plagiarism. But ultrasonic ranging module is nearly the same principle, so it's not hard to speculated that the role of the chip — I'm sure at least one 74series chip on it ; ) . It is not a difficult task to crack it , but … it's at so low a price , even cheaper than your copy.
