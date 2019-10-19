//Programme for ship movements.

const int pwm = 2 ;  //initializing pin 2 as pwm
const int in_1 = 8 ;
const int in_2 = 9 ;
const int in_3 = 10;
const int in_4 = 11;
int optimised_results;

class main {
  float toradians(float x){
    x=x/180 *3.14159;
    return x;}
 float distance_between_two_points (float lat1, float lat2,float lon1, float lon2){
float R = 6371e3; // metres
float a = toradians(lat1);
float b = toradians(lat2);
float c = toradians(lat2-lat1);
float d = toradians(lon2-lon1);

float e = sin(c /2) * sin(c /2) + cos(a) * cos(b) * sin(d / 2 ) * sin(d / 2);
float f = 2 * atan2(sqrt(e),sqrt(1-e));

return d = R * c;

}

int move(){
int i=optimised_results;
   return i;}



};

//For providing logic to L298 IC to choose the direction of the DC motor 

void setup()
{
pinMode(pwm,OUTPUT) ;   //we have to set PWM pin as output
pinMode(in_1,OUTPUT) ;  //Logic pins are also set as output
pinMode(in_2,OUTPUT) ;
pinMode(in_3,OUTPUT) ;  //Logic pins are also set as output
pinMode(in_4,OUTPUT) ;

float setup_drone();

}

void loop()
{

float detect_tide_direction();
float move_to_tide_direction();
float recive_moving_signal();
float optimize_moving_direction_between_two_decisions();
int i;
int move();


switch(i){

case 1:
digitalWrite(in_1,HIGH) ;
digitalWrite(in_2,LOW) ;
analogWrite(pwm,255) ;
delay(3000);

case 2:   

//For brake
digitalWrite(in_1,HIGH) ;
digitalWrite(in_2,HIGH) ;
delay(3000);

case 3:
//For Anti Clock-wise motion - IN_1 = LOW , IN_2 = HIGH
digitalWrite(in_1,LOW) ;
digitalWrite(in_2,HIGH) ;
delay(3000);

case 4:
digitalWrite(in_1,HIGH) ;
digitalWrite(in_2,HIGH) ;
delay(3000);

}
switch(i){

case 1:
digitalWrite(in_3,HIGH) ;
digitalWrite(in_4,LOW) ;
analogWrite(pwm,255) ;
delay(3000);


case 2:   

//For brake
digitalWrite(in_3,HIGH) ;
digitalWrite(in_4,HIGH) ;
delay(3000);

case 3:
//For Anti Clock-wise motion - IN_1 = LOW , IN_2 = HIGH
digitalWrite(in_3,LOW) ;
digitalWrite(in_4,HIGH) ;
delay(3000);

case 4:
digitalWrite(in_3,HIGH) ;
digitalWrite(in_4,HIGH) ;
delay(3000);}


 
}
