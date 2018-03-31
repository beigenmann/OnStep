// -------------------------------------------------------------------------------
// Configuration

// at startup this firmware will attempt to switch OnStep's baud rate to a faster speed and AFTER success, start WiFi, etc.
// valid baud rates are 115200, 57600, 38400, 28800, 19200, 9600

#define SERIAL_BAUD_DEFAULT 9600     // Default=9600, OnStep must be attached and running it's Serial1 interface this baud rate

#define SERIAL_BAUD 57600            // Default=57600, use 19200 for talking to OnStep on a Mega2560

#define PASSWORD "password"          // Default="password", Not currently used

#define SPECIAL_CHARS_ON          // Default=_ON, _OFF for standard ASCII special symbols (compatibility)
#define ADVANCED_CHARS_ON         // Default=_ON, _OFF for standard "RA/Dec" instead of symbols

// Auxillary switch/feature control; for example: SW0 "Cover" to open/close an OTA cover
// only unused OnStep Aux pins should be assigned!
#define SW0_OFF                   // For Aux0
#define SW1_OFF                   // For Aux1
#define SW2_OFF                   // For Aux2
#define SW3_OFF                   // For Aux3
#define SW4_OFF                   // For Aux4
#define SW5_OFF                   // For Aux5
#define SW6_OFF                   // For Aux6
#define SW7_OFF                   // For Aux7
#define SW8_OFF                   // For Aux8

// enter a MAC address for your controller below:
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

// the IP addresses below will be dependent on your local network:
IPAddress ip(192, 168, 1, 55);
IPAddress myDns(192,168, 1, 1);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);

// misc. options that are usually not changed
#define DEBUG_OFF                    // Turn _ON to allow Ethernet startup without OnStep attached (Serial port for debug at 9600 baud)
#define Ser Serial1                  // Default=Serial1, This is the hardware serial port where OnStep is attached

// -------------------------------------------------------------------------------
