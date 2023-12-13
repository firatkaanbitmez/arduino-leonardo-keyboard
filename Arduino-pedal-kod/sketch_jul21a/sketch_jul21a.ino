int yagmur = 0;               // "yagmur" adında değişkenimizi oluşturup başlangıç için 0 değeri verdik.
int sensor = A0;              // Yağmur sensörümüzü Analog A0 pinimize tanımladık.

void setup() {
  pinMode(13, OUTPUT);
 pinMode(sensor, INPUT);     // Sensörümüzü giriş pini olarak tanımladık.
 Serial.begin(9600);         // Seri monitörü aktifleştirdik. 
 Serial.println("Yağış Durumu:");
 Serial.println("-------------");
}

void loop() {
yagmur = analogRead(A0);      // A0 pin değerini "yagmur" değişkenimize aktardık.

if(yagmur > 901){              // "yagmur" değişkenimizin değerini IF kontrol yapısıyla karşılaştırıyoruz.
Serial.println("Yagmur yok!");
delay(1000);
}
if(yagmur > 301 && yagmur <= 900){
Serial.println("Yagmur yagiyor!");
delay(1000);
digitalWrite(13, HIGH);
delay(1000);
digitalWrite(13, LOW);
delay(1000);
}
if(300 > yagmur){
Serial.println("Sağanak Yağış!");
delay(1000);
}
}
