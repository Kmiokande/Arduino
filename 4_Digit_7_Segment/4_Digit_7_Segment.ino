#include "SevSeg.h"

SevSeg sevseg;  //Instantiate a seven segment object

void setup() {
  byte numDigits = 4;
  byte digitPins[] = {10, 11, 12, 13};
  byte segmentPins[] = {9, 2, 3, 5, 6, 8, 7, 4};
  bool resistorsOnSegments = true;  // 'false' means resistors are on digit pins
  bool updateWithDelaysIn = true;
  byte hardwareConfig = COMMON_CATHODE;
  
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments,
  updateWithDelaysIn);
  sevseg.setBrightness(90);
}

void loop() {
  sevseg.setNumber(3141, 3);
  sevseg.refreshDisplay();
}
