# Automatic Light Control System 
Simple Automatic Light Control System using Arduino Uno and LDR (Photoresistor)


## Features
- Real-time light intensity monitoring using LDR
- Automatic LED control
- Easy threshold calibration via Serial Monitor
- Beginner-friendly wiring and code

## Components Used
- Arduino Uno
- Photoresistor (LDR)
- 1kΩ Resistor
- LED
- Breadboard & Jumper wires

## Circuit Connection
- LDR: One leg to 5V, other leg to A0
- 1kΩ Resistor: Between A0 and GND
- LED: Positive to Pin 13, Negative to GND

## Code
```cpp

const int LDR_PIN = A0;
const int LED_PIN = 13;     

int threshold = 600;        

void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);   // LED OFF at start
  Serial.begin(9600);
  Serial.println("Automatic Light System (LED version) Started!");
}

void loop() {
  int ldrValue = analogRead(LDR_PIN);
  
  Serial.print("LDR Value: ");
  Serial.print(ldrValue);

  if (ldrValue < threshold) {
    digitalWrite(LED_PIN, HIGH);   // Dark → LED ON
    Serial.println("  → DARK → LED ON");
  } else {
    digitalWrite(LED_PIN, LOW);    // Bright → LED OFF
    Serial.println("  → BRIGHT → LED OFF");
  }

  delay(800);   // Check every 0.8 second
}



    Serial.println("  → DARK → LED ON");
  } else {
    digitalWrite(LED_PIN, LOW);    // Bright → LED OFF
    Serial.println("  → BRIGHT → LED OFF");
  }

  delay(800);   // Check every 0.8 second
}
