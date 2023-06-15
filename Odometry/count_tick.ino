static int pin_right_wheel = 4;
static int pin_left_wheel = 5;
static int vcc_pin = 10 ;
int value_left1, value_left2 = 0;
int value_right1, value_right2 = 0 ;
long unsigned x,y = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(pin_left_wheel, INPUT);
  pinMode(vcc_pin, OUTPUT);
  pinMode(pin_right_wheel, INPUT);
  Serial.begin(9600);
}

void loop() {
  value_left2 = value_left1 ; 
  value_right2 = value_right2 ;
  value_left1 = digitalRead(pin_left_wheel);
  value_right1 = digitalRead(pin_right_wheel);
  digitalWrite(vcc_pin, HIGH);
  if (value_left1 != value_left2){x+=1;Serial.print("tick Detected Left ");Serial.print(value_left1);Serial.print(" ");Serial.println(x);} 
  if (value_right1 != value_right2){y+=1;Serial.print("tick Detected Right ");Serial.print(value_right1);Serial.print(" ");Serial.println(y);} 
  

}
