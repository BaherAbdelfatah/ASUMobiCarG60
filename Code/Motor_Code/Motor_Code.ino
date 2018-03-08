int l1=3;
int r1=5;
int l2=10;
int r2=11;
int l3=6;
int r3=7;
int l4=8;
int r4=9;
int mode = 'g';
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
if(Serial.available()>0){ 
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
