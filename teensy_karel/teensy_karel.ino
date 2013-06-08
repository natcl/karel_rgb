// note 60 = r1
// note 64 = g1
// note 67 = b1
// note 72 = r2
// note 76 = g2
// note 79 = b2

// note 84 = w

const byte r1pin = 3;
const byte g1pin = 4;
const byte b1pin = 5;

const byte r2pin = 6;
const byte g2pin = 9;
const byte b2pin = 10;

const byte w1pin = 20;

int r1val = 256;
int g1val = 256;
int b1val = 256;
int r2val = 256;
int g2val = 256;
int b2val = 256;
int w1val = 256;

void setup() {
  pinMode(r1pin, OUTPUT);
  pinMode(g1pin, OUTPUT);
  pinMode(b1pin, OUTPUT);
  pinMode(r2pin, OUTPUT);
  pinMode(g2pin, OUTPUT);
  pinMode(w1pin, OUTPUT);
  analogWrite(r1pin, r1val);
  analogWrite(g1pin, g1val);
  analogWrite(b1pin, b1val);
  analogWrite(r2pin, r2val);
  analogWrite(g2pin, g2val);
  analogWrite(b2pin, b2val);
  analogWrite(w1pin, w1val);
  
  usbMIDI.setHandleNoteOn(OnNoteOn);
  usbMIDI.setHandleNoteOff(OnNoteOff);
  usbMIDI.setHandleVelocityChange(OnVelocityChange);
}

void loop() {
  
  Serial.begin(115200);
  usbMIDI.read();
  
  analogWrite(r1pin,r1val);
  analogWrite(g1pin,g1val);
  analogWrite(b1pin,b1val);
  analogWrite(r2pin,r2val);
  analogWrite(g2pin,g2val);
  analogWrite(b2pin,b2val);
  analogWrite(w1pin,w1val);
  
}

void OnNoteOn(byte channel, byte note, byte velocity) {
  switch (note) {
    case 60:
      r1val = 256-(velocity / 127. * 256.);
      break;
    case 64:
      g1val = 256-(velocity / 127. * 256.);
      break;
    case 67:
      b1val = 256-(velocity / 127. * 256.);
      break;
  }
}

void OnNoteOff(byte channel, byte note, byte velocity) {
  switch (note) {
    case 60:
      r1val = 256;
      break;
    case 64:
      g1val = 256;
      break;
    case 67:
      b1val = 256;
      break;
  }
}
  
void OnVelocityChange(byte channel, byte note, byte velocity) {
  switch (note) {
    case 60:
      r1val = 256-(velocity / 127. * 256.);
      break;
    case 64:
      g1val = 256-(velocity / 127. * 256.);
      break;
    case 67:
      b1val = 256-(velocity / 127. * 256.);
      break;
  }
}
