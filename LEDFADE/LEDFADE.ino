//4x4x4 LED Cube Show 1
//This one was written by someone else, i dont know who, however if you want credit, message me!

#include <avr/pgmspace.h> // allows use of PROGMEM to store patterns in flash

#define CUBESIZE 4
#define PLANESIZE CUBESIZE*CUBESIZE
#define PLANETIME 2000 // time each plane is displayed in us -> 100 Hz refresh
#define TIMECONST 10// multiplies DisplayTime to get ms - why not =100?

// LED Pattern Table in PROGMEM - last column is display time in 100ms units
// TODO this could be a lot more compact but not with binary pattern representation
const unsigned char PROGMEM PatternTable[] = {
// blink on and off
//Floor:
//1            1         1          1           2          2          2           2           3         3           3          3          4           4          4          4  
//Row:
//1            2         3          4           1          2          3           4           1         2           3          4           1          2          3          4
B0000,B0000,B0000,B1111   ,B0000,B0000,B0000,B1111   ,B0000,B0000,B0000,B1111   ,B0000,B0000,B0000,B1111   , 8,
B0000,B0000,B1111,B1111   ,B0000,B0000,B1111,B1111   ,B0000,B0000,B1111,B1111   ,B0000,B0000,B1111,B1111   , 8,
B0000,B1111,B1111,B1111   ,B0000,B1111,B1111,B1111   ,B0000,B1111,B1111,B1111   ,B0000,B1111,B1111,B1111   , 8,
B1111,B1111,B1111,B1111   ,B1111,B1111,B1111,B1111   ,B1111,B1111,B1111,B1111   ,B1111,B1111,B1111,B1111   , 8,
B1111,B1111,B1111,B0000   ,B1111,B1111,B1111,B0000   ,B1111,B1111,B1111,B0000   ,B1111,B1111,B1111,B0000   , 8,
B1111,B1111,B0000,B0000   ,B1111,B1111,B0000,B0000   ,B1111,B1111,B0000,B0000   ,B1111,B1111,B0000,B0000   , 8,
B1111,B0000,B0000,B0000   ,B1111,B0000,B0000,B0000   ,B1111,B0000,B0000,B0000   ,B1111,B0000,B0000,B0000   , 8,
B0000,B0000,B0000,B0000   ,B0000,B0000,B0000,B0000   ,B0000,B0000,B0000,B0000   ,B0000,B0000,B0000,B0000   , 8,

B0000,B0000,B0000,B1111   ,B0000,B0000,B0000,B1111   ,B0000,B0000,B0000,B1111   ,B0000,B0000,B0000,B1111   , 8,
B0000,B0000,B1111,B1111   ,B0000,B0000,B1111,B1111   ,B0000,B0000,B1111,B1111   ,B0000,B0000,B1111,B1111   , 8,
B0000,B1111,B1111,B1111   ,B0000,B1111,B1111,B1111   ,B0000,B1111,B1111,B1111   ,B0000,B1111,B1111,B1111   , 8,
B1111,B1111,B1111,B1111   ,B1111,B1111,B1111,B1111   ,B1111,B1111,B1111,B1111   ,B1111,B1111,B1111,B1111   , 8,
B1111,B1111,B1111,B0000   ,B1111,B1111,B1111,B0000   ,B1111,B1111,B1111,B0000   ,B1111,B1111,B1111,B0000   , 8,
B1111,B1111,B0000,B0000   ,B1111,B1111,B0000,B0000   ,B1111,B1111,B0000,B0000   ,B1111,B1111,B0000,B0000   , 8,
B1111,B0000,B0000,B0000   ,B1111,B0000,B0000,B0000   ,B1111,B0000,B0000,B0000   ,B1111,B0000,B0000,B0000   , 8,
B0000,B0000,B0000,B0000   ,B0000,B0000,B0000,B0000   ,B0000,B0000,B0000,B0000   ,B0000,B0000,B0000,B0000   , 8,

B1111,B1111,B1111,B1111   ,B0000,B0000,B0000,B0000   ,B0000,B0000,B0000,B0000   ,B0000,B0000,B0000,B0000   , 8,
B1111,B1111,B1111,B1111   ,B1111,B1111,B1111,B1111   ,B0000,B0000,B0000,B0000   ,B0000,B0000,B0000,B0000   , 8,
B1111,B1111,B1111,B1111   ,B1111,B1111,B1111,B1111   ,B1111,B1111,B1111,B1111   ,B0000,B0000,B0000,B0000   , 8,
B1111,B1111,B1111,B1111   ,B1111,B1111,B1111,B1111   ,B1111,B1111,B1111,B1111   ,B1111,B1111,B1111,B1111   , 8,
B0000,B0000,B0000,B0000   ,B1111,B1111,B1111,B1111   ,B1111,B1111,B1111,B1111   ,B1111,B1111,B1111,B1111   , 8,
B0000,B0000,B0000,B0000   ,B0000,B0000,B0000,B0000   ,B1111,B1111,B1111,B1111   ,B1111,B1111,B1111,B1111   , 8,
B0000,B0000,B0000,B0000   ,B0000,B0000,B0000,B0000   ,B0000,B0000,B0000,B0000   ,B1111,B1111,B1111,B1111   , 8,
B0000,B0000,B0000,B0000   ,B0000,B0000,B0000,B0000   ,B0000,B0000,B0000,B0000   ,B0000,B0000,B0000,B0000   , 8,

B1111,B1111,B1111,B1111   ,B0000,B0000,B0000,B0000   ,B0000,B0000,B0000,B0000   ,B0000,B0000,B0000,B0000   , 8,
B1111,B1111,B1111,B1111   ,B1111,B1111,B1111,B1111   ,B0000,B0000,B0000,B0000   ,B0000,B0000,B0000,B0000   , 8,
B1111,B1111,B1111,B1111   ,B1111,B1111,B1111,B1111   ,B1111,B1111,B1111,B1111   ,B0000,B0000,B0000,B0000   , 8,
B1111,B1111,B1111,B1111   ,B1111,B1111,B1111,B1111   ,B1111,B1111,B1111,B1111   ,B1111,B1111,B1111,B1111   , 8,
B0000,B0000,B0000,B0000   ,B1111,B1111,B1111,B1111   ,B1111,B1111,B1111,B1111   ,B1111,B1111,B1111,B1111   , 8,
B0000,B0000,B0000,B0000   ,B0000,B0000,B0000,B0000   ,B1111,B1111,B1111,B1111   ,B1111,B1111,B1111,B1111   , 8,
B0000,B0000,B0000,B0000   ,B0000,B0000,B0000,B0000   ,B0000,B0000,B0000,B0000   ,B1111,B1111,B1111,B1111   , 8,
B0000,B0000,B0000,B0000   ,B0000,B0000,B0000,B0000   ,B0000,B0000,B0000,B0000   ,B0000,B0000,B0000,B0000   , 8,
// this is a dummy element for end of table (duration=0) aka !!!DO NOT TOUCH!!!
B0000, B0000, B0000, B0000, B0000, B0000, B0000, B0000, B0000, B0000, B0000, B0000, B0000, B0000, B0000, B0000, 0
};

/*
** Defining pins in array makes it easier to rearrange how cube is wired
** Adjust numbers here until LEDs flash in order - L to R, T to B
** Note that analog inputs 0-5 are also digital outputs 14-19!
** Pin DigitalOut0 (serial RX) and AnalogIn5 are left open for future apps
*/




int LEDPin[] = {10, 13, 12, 11, A0, 9, 8, 7, 6, 5, 4, A5, 2, A4, 3, 0};
int PlanePin[] = {1, A2, A1, A3}; 





// initialization
void setup()
{
int pin; // loop counter
// set up LED pins as output (active HIGH)
for (pin=0; pin<PLANESIZE; pin++) {
pinMode( LEDPin[pin], OUTPUT );
}
// set up plane pins as outputs (active LOW)
for (pin=0; pin<CUBESIZE; pin++) {
pinMode( PlanePin[pin], OUTPUT );
}
}

// display pattern in table until DisplayTime is zero (then repeat)
void loop()
{
// declare variables
byte PatternBuf[PLANESIZE]; // saves current pattern from PatternTable
int PatternIdx;
byte DisplayTime; // time*100ms to display pattern
unsigned long EndTime;
int plane; // loop counter for cube refresh
int patbufidx; // indexes which byte from pattern buffer
int ledrow; // counts LEDs in refresh loop
int ledcol; // counts LEDs in refresh loop
int ledpin; // counts LEDs in refresh loop

// Initialize PatternIdx to beginning of pattern table
PatternIdx = 0;
// loop over entries in pattern table - while DisplayTime>0
do {
// read pattern from PROGMEM and save in array
memcpy_P( PatternBuf, PatternTable+PatternIdx, PLANESIZE );
PatternIdx += PLANESIZE;
// read DisplayTime from PROGMEM and increment index
DisplayTime = pgm_read_byte_near( PatternTable + PatternIdx++ );
// compute EndTime from current time (ms) and DisplayTime
EndTime = millis() + ((unsigned long) DisplayTime) * TIMECONST;

// loop while DisplayTime>0 and current time < EndTime
while ( millis() < EndTime ) {
patbufidx = 0; // reset index counter to beginning of buffer
// loop over planes
for (plane=0; plane<CUBESIZE; plane++) {
// turn previous plane off
if (plane==0) {
digitalWrite( PlanePin[CUBESIZE-1], LOW );
} else {
digitalWrite( PlanePin[plane-1], LOW );
}

// load current plane pattern data into ports
ledpin = 0;
for (ledrow=0; ledrow<CUBESIZE; ledrow++) {
for (ledcol=0; ledcol<CUBESIZE; ledcol++) {
digitalWrite( LEDPin[ledpin++], PatternBuf[patbufidx] & (1 << ledcol) );
}
patbufidx++;
}

// turn current plane on
digitalWrite( PlanePin[plane], HIGH );
// delay PLANETIME us
delayMicroseconds( PLANETIME );
} // for plane
} // while <EndTime
} while (DisplayTime > 0); // read patterns until time=0 which signals end
}


