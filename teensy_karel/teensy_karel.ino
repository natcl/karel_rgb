// note 60 = r1
// note 64 = g1
// note 67 = b1
// note 72 = r2
// note 76 = g2
// note 79 = b2

// note 84 = w

const byte NCHANNELS = 10; 
const byte PIN_ARRAY[] = {3,4,5,6,9,10,20,21,22,13}; 
const byte NOTE_ARRAY[] = {48,52,55,60,64,67,72,76,79,84};
const byte CTRL_ARRAY[] = {48,52,55,60,64,67,72,76,79,84};
int pin_values[] = {256,256,256,256,256,256,256,256,256,256};

void setup() {
  
  for (byte channel = 0; channel < NCHANNELS; channel++){
    pinMode(PIN_ARRAY[channel], OUTPUT);
    analogWrite(PIN_ARRAY[channel], pin_values[channel]);
  }

  usbMIDI.setHandleNoteOn(OnNoteOn);
  usbMIDI.setHandleNoteOff(OnNoteOff);
  usbMIDI.setHandleVelocityChange(OnVelocityChange);
  usbMIDI.setHandleControlChange(OnControlChange);
}

void loop() {
  
  Serial.begin(115200);
  usbMIDI.read();
  
  for (byte channel = 0; channel < NCHANNELS; channel++){
    analogWrite(PIN_ARRAY[channel], pin_values[channel]);
  }
}

void OnNoteOn(byte channel, byte note, byte velocity) {
  for (byte n = 0; n < NCHANNELS; n++){
    if (note == NOTE_ARRAY[n]) {
      pin_values[n] = 256-(velocity / 127. * 256.);
    } 
  }
}

void OnNoteOff(byte channel, byte note, byte velocity) {
  for (byte n = 0; n < NCHANNELS; n++){
    if (note == NOTE_ARRAY[n]) {
      pin_values[n] = 256;
    } 
  }
}
  
void OnVelocityChange(byte channel, byte note, byte velocity) {
  for (byte n = 0; n < NCHANNELS; n++){
    if (note == NOTE_ARRAY[n]) {
      pin_values[n] = 256-(velocity / 127. * 256.);
    } 
  }
}

void OnControlChange(byte channel, byte controller, byte value) {
  for (byte c = 0; c < NCHANNELS; c++){
    if (controller == CTRL_ARRAY[c]) {
      pin_values[c] = 256-(value / 127. * 256.);
    } 
  }
}
