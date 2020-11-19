//Pranay Maggo
//E19CSE283
 <Arduino_APDS9960.h>

#include <U8g2lib.h>
#include <Wire.h>

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);
int floornum=0;
int currentfloor=0;



void setup() {
  Serial.begin(9600);
 
 u8g2.begin();
 u8g2.setFont(u8g2_font_amstrad_cpc_extended_8u);

  if (!APDS.begin()) {
    Serial.println(F("Error initializing APDS9960 sensor!"));
  }

  // for setGestureSensitivity(..) a value between 1 and 100 is required.
  // Higher values makes the gesture recognition more sensible but less accurate
  // (a wrong gesture may be detected). Lower values makes the gesture recognition
  // more accurate but less sensible (some gestures may be missed).
  // Default is 80
  //APDS.setGestureSensitivity(80);

  Serial.println(F("Detecting gestures ..."));
}
void loop() {
  if (APDS.gestureAvailable()) {
    // a gesture was detected, read and print to serial monitor
     u8g2.clearBuffer();
    int gesture = APDS.readGesture();

    switch (gesture) {
      case GESTURE_UP:
     
        floornum ++;
        Serial.println(F("Detected UP gesture"));
         u8g2.setFont(u8g2_font_amstrad_cpc_extended_8u);
         u8g2.setCursor(90,17);
         u8g2.println("UP"); // display a message
         
         u8g2.setCursor(0,17);
         u8g2.println(F("FLOOR GO=")); 
         u8g2.println(floornum); // display a message
         
         u8g2.setFont(u8g2_font_open_iconic_arrow_4x_t);
         u8g2.drawGlyph(90, 60, 75); 
         u8g2.sendBuffer();
        
        break;

      case GESTURE_DOWN:
        Serial.println(F("Detected DOWN gesture"));
         u8g2.setFont(u8g2_font_amstrad_cpc_extended_8u);
         u8g2.setCursor(90,17);
         u8g2.println(F("DOWN")); // display a message
        
         floornum --;
         u8g2.setCursor(0,17);
         u8g2.println(F("FLOOR GO="));
         u8g2.println(floornum); // display a message
         
         u8g2.setFont(u8g2_font_open_iconic_arrow_4x_t);
         u8g2.drawGlyph(90, 60, 72); 
         u8g2.sendBuffer();
        break;

      case GESTURE_LEFT:
         u8g2.setFont(u8g2_font_amstrad_cpc_extended_8u);
         u8g2.setCursor(90,17);
         u8g2.println(F("OK")); // display a message

         u8g2.setCursor(10,27);
         u8g2.println(F("FLOOR="));
         u8g2.println(currentfloor); // display a message
         
         u8g2.setFont(u8g2_font_open_iconic_www_4x_t);
         u8g2.drawGlyph(90, 60, 73); 
         u8g2.sendBuffer();
        break;

      case GESTURE_RIGHT:
         u8g2.setFont(u8g2_font_amstrad_cpc_extended_8u);
         u8g2.setCursor(90,17);
         u8g2.println(F("STOP")); // display a message

         u8g2.setCursor(10,27);
         u8g2.println(F("FLOOR="));
         u8g2.println(currentfloor); // display a message
         
         stop();
         
         u8g2.setFont(u8g2_font_open_iconic_www_4x_t);
         u8g2.drawGlyph(90, 60, 74); 
         u8g2.sendBuffer();
        break;

      default:
      
        break;
        
    }

if(gesture==3){
  
    if(floornum > currentfloor){
      Serial.println(F("going UP "));
      liftup();
      delay(2000);
      currentfloor++;
      
      if(floornum= currentfloor){
        Serial.println(F("Reached"));
        stop();
      }}

       if(floornum < currentfloor){
      Serial.println(F("going UP "));
      liftdown();
      delay(2000);
      currentfloor--;
      
      if(floornum== currentfloor){
        Serial.println(F("Reached"));
        stop();
      }
      
    }
}
    
  }
}


void liftup(){
  
}

void liftdown(){
  

}

void stop(){

  
}
