const int led = 3;
const int SensorPir = 2;

unsigned long waktu = millis(); //deklarasikan sengaja untuk set waktu
unsigned long akhir = 0; //deklarasikan sengaja untuk set waktu
bool aktif = false; //deklarasikan untuk set aktif atau mati

void setup(){
Serial.begin(9600);
pinMode(led, OUTPUT);
pinMode(SensorPir, INPUT_PULLUP);
attachInterrupt(digitalPinToInterrupt(SensorPir), deteksi, RISING);
//digunakan sebagai trigger fungsi deteksi dan mode rising
}

void deteksi(){
  Serial.println("GERAKAN TERDETEKSI"); //print pada serial monitor
  digitalWrite(led, HIGH); //menyalakan lampu
  aktif = true; //menyisipkan boolean untuk fungsi if
  akhir = millis(); //untuk set waktu
}

void loop(){
  waktu = millis();
  if(aktif &&(waktu - akhir > 2000)){
  Serial.println("TIDAK ADA GERAKAN");
  digitalWrite(led, LOW);
  aktif = false;
  }
}

