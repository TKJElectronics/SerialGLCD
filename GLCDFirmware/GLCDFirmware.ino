#include <glcd.h>
#include <fonts/allFonts.h>

//#define DEBUG

byte c;
byte x1;
byte y1;
byte x2;
byte y2;
int color;
byte width;
byte height;
byte radius;

void setup() {
  GLCD.Init();   // initialise the library, non inverted writes pixels onto a clear screen
  GLCD.SelectFont(System5x7); // font for the default text area
  GLCD.ClearScreen(); 
  Serial.begin(115200); // Set baudrate  
}

void  loop() {
  if(Serial.available()) {
    c = Serial.read();
    if(c == 0x7C) { // Enter command mode
      delay(1);
      c = Serial.read();
      //Serial.println(c,HEX);
      switch(c) {
      case 0x00: // Clear screen
        GLCD.ClearScreen();
        break;
      case 0x01: // Set invert or noninverted
        color = Serial.read();
        if (color == -1) // Nothing is send
          color = 0;       
        GLCD.SetDisplayMode(color); // Send 0x00 for non-inverted mode and 0x01 for inverted
        break;

      case 0x02: // Set cursor to given x,y-coordinates
        x1 = Serial.read();
        y1 = Serial.read();
        GLCD.GotoXY(x1, y1);
        break;       
      case 0x03: // Set cursor based on current font 
        x1 = Serial.read();
        y1 = Serial.read();
        GLCD.CursorTo(x1, y1);
        break;

      case 0x04: // Set pixel
        x1 = Serial.read();
        y1 = Serial.read();
        color = Serial.read();
        GLCD.SetDot(x1, y1, color);
        break;       
      case 0x05: // Set pixels
        x1 = Serial.read();
        y1 = Serial.read();
        x2 = Serial.read();
        y2 = Serial.read();         
        color = Serial.read();
        GLCD.SetPixels(x1, y1, x2, y2, color);
        break;       

      case 0x06: // Draw line
        x1 = Serial.read();
        y1 = Serial.read();
        x2 = Serial.read();
        y2 = Serial.read();          
        color = Serial.read();
        GLCD.DrawLine(x1,y1,x2,y2,color);
        break;
      case 0x07: // Draw vertical line
        x1 = Serial.read();
        y1 = Serial.read();
        height = Serial.read();          
        color = Serial.read();
        GLCD.DrawVLine(x1,y1,height,color);
        break;     
      case 0x08: // Draw horizontal line
        x1 = Serial.read();
        y1 = Serial.read();
        width = Serial.read();          
        color = Serial.read();
        GLCD.DrawHLine(x1,y1,width,color);
        break;

      case 0x09: // Draw Circle
        x1 = Serial.read();
        y1 = Serial.read();
        radius = Serial.read();          
        color = Serial.read();
        GLCD.DrawCircle(x1, y1, radius, color);
        break;        
      case 0x0A: // Draw filled Circle
        x1 = Serial.read();
        y1 = Serial.read();
        radius = Serial.read();          
        color = Serial.read();
        GLCD.FillCircle(x1, y1, radius, color);
        break;        

      case 0x0B: // Draw Box
        x1 = Serial.read();
        y1 = Serial.read();
        width = Serial.read();
        height = Serial.read();                     
        color = Serial.read();
        GLCD.DrawRect(x1, y1, width, height, color);
        break;    
      case 0x0C: // Draw Filled Box
        x1 = Serial.read();
        y1 = Serial.read();
        width = Serial.read();
        height = Serial.read();              
        color = Serial.read();
        GLCD.FillRect(x1, y1, width, height, color);
        break;   
      case 0x0D: // Draw Inverted Box
        x1 = Serial.read();
        y1 = Serial.read();
        width = Serial.read();
        height = Serial.read();
        GLCD.InvertRect(x1, y1, width, height);
        break;        
      case 0x0E: // Draw Box with round edges
        x1 = Serial.read();
        y1 = Serial.read();
        width = Serial.read();
        height = Serial.read(); 
        radius = Serial.read();                  
        color = Serial.read();
        GLCD.DrawRoundRect(x1, y1, width, height, radius, color);
        break;

        //default:
        //Serial.println("Command not supported");
      }
    } 
    else {
      GLCD.write(c);   
      #ifdef DEBUG
      Serial.write(c);
      #endif
    }
  }
}

