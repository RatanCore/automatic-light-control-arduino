// Automatic LED Control using LDR (Photoresistor)


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