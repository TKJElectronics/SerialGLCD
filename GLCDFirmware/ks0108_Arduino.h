/*
 * ks0108_Arduino.h - User specific configuration for Arduino GLCD library 
 * This is a modified version for the SerialGLCD by Kristian Lauszus, TKJ Electronics 2012
 * Move into the glcd library folder like so: Arduino/libraries/glcd/config/ks0108_Arduino.h
 * Download the original library here: http://code.google.com/p/glcd-arduino/
 */

#ifndef GLCD_PIN_CONFIG_H
#define GLCD_PIN_CONFIG_H

/* Define name for pin configuration */
#define glcd_PinConfigName "ks0108-Arduino"

// Uncomment to set your pinout - remember to solder solderjumper too
//#define PinoutA
//#define PinoutB
#define PinoutC

#ifdef PinoutA
    /* Data pin definitions */
    #define glcdData0Pin        19
    #define glcdData1Pin        18
    #define glcdData2Pin        17
    #define glcdData3Pin        2
    #define glcdData4Pin        16
    #define glcdData5Pin        3
    #define glcdData6Pin        15
    #define glcdData7Pin        4

    /* Arduino pins used for Commands */
    #define glcdCSEL1        14
    #define glcdCSEL2        5

    #define glcdRW           10
    #define glcdDI           7
    #define glcdEN           8
    // Reset Bit
    #define glcdRES          6// Reset Bit
#else // PinoutB or PinoutC
    /* Data pin definitions */
    #define glcdData0Pin        2
    #define glcdData1Pin        16
    #define glcdData2Pin        3
    #define glcdData3Pin        15
    #define glcdData4Pin        4
    #define glcdData5Pin        14
    #define glcdData6Pin        5
    #define glcdData7Pin        6

    /* Arduino pins used for Commands */
    #ifdef PinoutB
        #define glcdCSEL1        7
        #define glcdCSEL2        10
    #else
        #define glcdCSEL1        10
        #define glcdCSEL2        7
    #endif

    #define glcdRW           18
    #define glcdDI           19
    #define glcdEN           17
    // Reset Bit
    #define glcdRES          8    // Reset Bit
#endif

#endif //GLCD_PIN_CONFIG_H
