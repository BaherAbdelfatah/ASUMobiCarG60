
code: digitalWrite(trig,LOW);
delayMicroseconds(2);
digitalWrite (trig,HIGH);
delayMicroseconds(10);
digitalWrite (trig,LOW);

duration = pulseIn(echo,HIGH);
distance = (duration/2)/28.5;
Serial.println(distance);
/*Serial.println(distance);
if(distance<20){stoop();}
*/

if(distance<6){stoop(); delay(500);
right(); delay(250);
stoop(); delay(250);goto code;}
