
volatile long steps;
volatile long prevSteps;
volatile long nowSteps;

volatile int dir=0;  // Extend=1, Retract=-1, Stop=0
volatile long prevTimer=0;
volatile long nowTimer =0;
const byte hallPinA = 2;
const byte hallPinB = 3;

#define TIMER_OFFSET_MS (50)
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(hallPinA), hall_detect, RISING);
  attachInterrupt(digitalPinToInterrupt(hallPinB), hall_detect, RISING);
  prevTimer = millis();
}

void loop() {
  // put your main code here, to run repeatedly:

  nowTimer = millis();
  nowSteps = steps;
  long timeDiff = nowTimer - prevTimer;
  if(timeDiff >= TIMER_OFFSET_MS)
  {
    
//    Serial.write("timeDiff=");
//    Serial.print(timeDiff);
//    Serial.write("-> ");
    // print here
    if(dir==-1)
    {
      Serial.print('R');
    } else if (dir == 0) {
      Serial.print('B');
    } else {
      Serial.print('E');
    }

    Serial.print(steps);
    long rate = 0;
    if(timeDiff > 0)
    {
      rate = (nowSteps - prevSteps) * 1000 / (timeDiff);
    }
    Serial.print(',');
    Serial.println(rate);
    prevTimer = nowTimer;
    prevSteps = nowSteps;

//    steps += dir*10; // Remove for productionpy 
  }
  


  if(Serial.available() > 0) {
    int incomingByte = Serial.read();

    switch(incomingByte) {
      case 'e':
      case 'E':
        // Extend mode
        dir = 1;
        break;
      case 'r':
      case 'R':
        // Retract mode 
        dir = -1;
        break;
      case 'B':
      case 'b':
        // Braking mode
        dir = 0;
        break;
      case 'Z':
      case 'z':
        // Zero count (retracted)
        steps = 0;
        break;
      default:
        Serial.write("Invalid entry: ");
        Serial.print(incomingByte);
        Serial.write("\n");      
    }
    
    
    
  }

}


void hall_detect()
{
  steps += (long) dir;
}
