if(Serial.available()){ 
mode = Serial.read();
} 
if(mode=='u')
{while(1)
{
if(analogRead(A0)<500)
midforward();
/* if(analogRead(A1)<500)
{Serial.println("black");
midright();
}
 else 
 Serial.println("white"); 
 if(analogRead(A2)<500)
{Serial.println("black");
midleft();
}
 else 
 Serial.println("white"); */
 else if(LOW == digitalRead(signalPin12))
 {Serial.println("black");
 midleft();}
else if(LOW == digitalRead(signalPin13))
 midright();
 
}  }
