//Programme for ship movements.

const int pwm = 2 ;  //initializing pin 2 as pwm
const int in_1 = 8 ;
const int in_2 = 9 ;


//For providing logic to L298 IC to choose the direction of the DC motor 

void setup()
{
pinMode(pwm,OUTPUT) ;   //we have to set PWM pin as output
pinMode(in_1,OUTPUT) ;  //Logic pins are also set as output
pinMode(in_2,OUTPUT) ;
}

void loop()
{
//For Clock wise motion , in_1 = High , in_2 = Low

digitalWrite(in_1,HIGH) ;
digitalWrite(in_2,LOW) ;
analogWrite(pwm,255) ;


//Clockwise for 3 secs
delay(3000) ;     

//For brake
digitalWrite(in_1,HIGH) ;
digitalWrite(in_2,HIGH) ;
delay(1000) ;

//For Anti Clock-wise motion - IN_1 = LOW , IN_2 = HIGH
digitalWrite(in_1,LOW) ;
digitalWrite(in_2,HIGH) ;
delay(3000) ;

//For brake
digitalWrite(in_1,HIGH) ;
digitalWrite(in_2,HIGH) ;
delay(1000) ;
 }



//gps on the ship




const int set_distance = 0.1 ;//max distance between two boat.


//#include <Adafruit_GPS.h>
//#include <Adafruit_GPS.h>
//We can now create our Software Serial object after including the library
#include <math.h>
SoftwareSerial mySerial(3, 2);
int mySerial;
//And finally attach our Serial object pins to our GPS module
//Adafruit_GPS GPS(&mySerial);

void setup() {
Serial.begin(115200); //This baud rate will help a lot in printing all of the data that comes from the GPS Module to the serial monitor
GPS.begin(9600); 
//These lines configure the GPS Module
GPS.sendCommand(PMTK_SET_NMEA_OUTPUT_RMCGGA); //Sets output to only RMC and GGA sentences
GPS.sendCommand(PMTK_SET_NMEA_UPDATE_1HZ); //Sets the output to 1/second. If you want you can go higher/lower
GPS.sendCommand(PGCMD_ANTENNA); //Can report if antenna is connected or not
}

void loop() {
//Now we will start our GPS module, parse (break into parts) the Last NMEA sentence 
GPS.parse(GPS.lastNMEA()); //This is going to parse the last NMEA sentence the Arduino has received, breaking it down into its constituent parts.
GPS.newNMEAreceived(); //This will return a boolean TRUE/FALSE depending on the case.
//Print the current date/time/etc
    Serial.print("\nTime: ");
    Serial.print(GPS.hour, DEC); Serial.print(':');
    Serial.print(GPS.minute, DEC); Serial.print(':');
    Serial.print(GPS.seconds, DEC); Serial.print('.');
    Serial.println(GPS.milliseconds);
    Serial.print("Date: ");
    Serial.print(GPS.day, DEC); Serial.print('/');
    Serial.print(GPS.month, DEC); Serial.print("/20");
    Serial.println(GPS.year, DEC);
    Serial.print("Fix: "); Serial.print((int)GPS.fix);
    Serial.print(" quality: "); Serial.println((int)GPS.fixquality);
//If GPS module has a fix, line by line prints the GPS information
    if (GPS.fix) {
      Serial.print("Location: ");
      Serial.print(GPS.latitude, 4); Serial.print(GPS.lat);
      Serial.print(", ");
      Serial.print(GPS.longitude, 4); Serial.println(GPS.lon);
      Serial.print("Location (in degrees, works with Google Maps): ");
      Serial.print(GPS.latitudeDegrees, 4);
      Serial.print(", ");
      Serial.println(GPS.longitudeDegrees, 4);
      Serial.print("Speed (knots): "); Serial.println(GPS.speed);
      Serial.print("Angle: "); Serial.println(GPS.angle);
      Serial.print("Altitude: "); Serial.println(GPS.altitude);
      Serial.print("Satellites: "); Serial.println((int)GPS.satellites);
    }

}

public class Main {
  public static int distance_between_two_points (float lat1, float lat2,float lon1, float lon2){
float R = 6371e3; // metres
float a = math.toradians(lat1);
float b = math.toradians(lat2);
float c = math.toradians(lat2-lat1);
float d = math.toRadians(lon2-lon1);

float a = math.sin(c /2) * math.sin(c /2) + math.cos(a) * math.cos(b) * math.sin(d / 2 ) * math.sin(d / 2);
float c = 2 * Math.atan2(Math.sqrt(a), Math.sqrt(1-a));

return d = R * c;
}
}

public class Main {
    public static void Adjust_distance() {
       if( distance_between_two_points > set_distance)
       move_towards_each_other()
       
    }
}
