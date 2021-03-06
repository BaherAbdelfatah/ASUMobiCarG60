
#define trig 3
#define echo 2
int duration=0;int distance=0 ;
int duration1,duration2,duration3,duration4,durationavg;
int l1=4;
int r1=5;
int l2=10;
int r2=11;
int l3=6;
int r3=7;
int l4=8;
int r4=9;
int i1;
int signalPin12 = 12; 
int signalPin13 = 13; 
char mode = 'g';
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
pinMode(l1,OUTPUT);
pinMode(r1,OUTPUT);
pinMode(l2,OUTPUT);
pinMode(r2,OUTPUT);
pinMode(l3,OUTPUT);
pinMode(r3,OUTPUT);
pinMode(l4,OUTPUT);
pinMode(r4,OUTPUT);
pinMode(trig,OUTPUT);
pinMode(echo,INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
   pinMode(signalPin12, INPUT);
   pinMode(signalPin13, INPUT);
   pinMode(A0, INPUT);
   pinMode(A1, INPUT);
   pinMode(A2, INPUT);
}
void forward(){
  digitalWrite(l1,1);
    digitalWrite(r1,0);
      digitalWrite(l2,0);
        digitalWrite(r2,1);
   digitalWrite(l3,1);
    digitalWrite(r3,0);
      digitalWrite(l4,0);
        digitalWrite(r4,1);
  }
  void midforward(){
  digitalWrite(l1,0);
    digitalWrite(r1,0);
      digitalWrite(l2,0);
        digitalWrite(r2,0);
   digitalWrite(l3,1);
    digitalWrite(r3,0);
      digitalWrite(l4,0);
        digitalWrite(r4,1);
  }
  void backward(){
  digitalWrite(l1,0);
    digitalWrite(r1,1);
      digitalWrite(l2,1);
        digitalWrite(r2,0);
  digitalWrite(l3,0);
    digitalWrite(r3,1);
      digitalWrite(l4,1);
        digitalWrite(r4,0);
  }
  void left(){
 digitalWrite(l1,0);
    digitalWrite(r1,1);
      digitalWrite(l2,0);
        digitalWrite(r2,1);
         digitalWrite(l3,1);
    digitalWrite(r3,0);
      digitalWrite(l4,1);
        digitalWrite(r4,0);
  }
  void right(){
 digitalWrite(l1,1);
    digitalWrite(r1,0);
      digitalWrite(l2,1);
        digitalWrite(r2,0);
         digitalWrite(l3,0);
    digitalWrite(r3,1);
      digitalWrite(l4,0);
        digitalWrite(r4,1);
  }
   void quarleft(){
  digitalWrite(l1,1);
    digitalWrite(r1,0);
      digitalWrite(l2,0);
        digitalWrite(r2,0);
         digitalWrite(l3,0);
    digitalWrite(r3,0);
      digitalWrite(l4,0);
        digitalWrite(r4,0);
  }
  void quarright(){
 digitalWrite(l1,0);
    digitalWrite(r1,0);
      digitalWrite(l2,0);
        digitalWrite(r2,1);
         digitalWrite(l3,0);
    digitalWrite(r3,0);
      digitalWrite(l4,0);
        digitalWrite(r4,0);
  }

  void midleft(){
  digitalWrite(l1,1);
    digitalWrite(r1,0);
      digitalWrite(l2,0);
        digitalWrite(r2,0);
         digitalWrite(l3,0);
    digitalWrite(r3,0);
      digitalWrite(l4,0);
        digitalWrite(r4,1);
  }
  void midright(){
 digitalWrite(l1,0);
    digitalWrite(r1,0);
      digitalWrite(l2,0);
        digitalWrite(r2,1);
         digitalWrite(l3,1);
    digitalWrite(r3,0);
      digitalWrite(l4,0);
        digitalWrite(r4,0);
  }
  
  void stoop(){
  digitalWrite(l1,0);
    digitalWrite(r1,0);
      digitalWrite(l2,0);
        digitalWrite(r2,0);
        digitalWrite(l3,0);
    digitalWrite(r3,0);
      digitalWrite(l4,0);
        digitalWrite(r4,0);
  }
  /*void test(){
  digitalWrite(l1,0);
    digitalWrite(r1,1);
      digitalWrite(l2,0);
        digitalWrite(r2,1);
         digitalWrite(l3,1);
    digitalWrite(r3,0);
      digitalWrite(l4,1);
        digitalWrite(r4,0);
  }*/
void loop() {
  // put your main code here, to run repeatedly:
//put the functions above here after using bluetooth
//test();

 digitalWrite(trig,LOW);
delayMicroseconds(5);
digitalWrite (trig,HIGH);
delayMicroseconds(20);
digitalWrite (trig,LOW);

duration = pulseIn(echo,HIGH);

distance = (duration/2)/28.5;
/*Serial.print("*h"+String(distance)+"*");
/*Serial.println(distance);
if(distance<20){stoop();}
*/
/*while(distance<8){stoop();delay(100);
right();
delay(200);
stoop();
break;
}*/
/*
if(distance<6){
stoop();delay(200);
right();
delay(400);
stoop();
}*/
if(analogRead(A0)<500)
Serial.println("black");
 else 
 Serial.println("white"); 
 if(analogRead(A1)<500)
Serial.println("black");
 else 
 Serial.println("white"); 
 if(analogRead(A2)<500)
Serial.println("black");
 else 
 Serial.println("white"); 
 if(LOW == digitalRead(signalPin12))
 Serial.println("black");
 else 
 Serial.println("white"); 
 if(LOW == digitalRead(signalPin13))
 Serial.println("black");
 else 
 Serial.println("white"); 
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
if(mode=='m')
{while(1)
{
  if(Serial.available()){ 
mode = Serial.read();
} 
if(mode=='a'){ // Forward
  Serial.println(mode);
forward();
}

if(mode=='d'){ // backward
  Serial.println(mode);
backward();
}
if(mode=='b'){ // right
  Serial.println(mode);
right();
}
if(mode=='e'){ // left
  Serial.println(mode);
left();
}
if(mode=='c'){ // stop
  Serial.println(mode);
stoop();
}
}
}

}
