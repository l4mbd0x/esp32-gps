#include <TinyGPS++.h>

// Don't use RX0 TX0 
#define RXD2 16
#define TXD2 17
HardwareSerial neogps(1);
TinyGPSPlus gps;

void setup() {
  Serial.begin(9600);
  neogps.begin(9600, SERIAL_8N1, RXD2, TXD2);  
  delay(2000);
}

void loop() {
  boolean newData = false;
  for ( unsigned long start = millis() ; millis() - start < 1000; ) {
    while ( neogps.available() ) {
      gps.encode( neogps.read() );
    }
  }

  if (gps.location.isValid() == 1) {
    newData = true;
    Serial.printf("Detected Satellite: %d\n\n", gps.satellites.value());
    
    Serial.printf("Lat:        %.4lf    Lng: %.4lf\n", gps.location.lat(), gps.location.lng());
    Serial.printf("Speed(km/h): %.4lf     Altitude: %.4lf\n", gps.speed.kmph(), gps.altitude.meters());
    Serial.printf("Date:        %d/%d/%d", gps.date.day(), gps.date.month(), gps.date.year());
    Serial.printf(" Hour (UTC-3): %d:%d:%d\n", gps.time.hour()-3, gps.time.minute(), gps.time.second());
    Serial.println("---------------------------");   
  } else {
    Serial.printf("Finding satellites...\n");
    delay(5000);
  }

  if ( newData == true ) {   
    newData = false;
  } else if ( newData == false ) {
    Serial.println(" No Data, no satellite found\n");
  }    
}

