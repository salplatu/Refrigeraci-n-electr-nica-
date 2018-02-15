//----*****SALPLATU*****----//

int A = 27;   //Temperatura para que se inicie la refigeracion

// Declaracion de variables
float temp;
int tempera = 0; // Definimos la entrada en pin A0
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 9, 8, 7, 6);

int mos = 13;

void setup()
{
// Abre puerto serial y lo configura a 9600 bps
Serial.begin(9600);

lcd.begin(16, 2);           // Fijamos el numero de caracteres y filas
lcd.setCursor(4,0);
lcd.print("SALPLATU");  // Aqi va el mensaje de bienvenida

delay(5000);    //Se muestra el texto anterior 5 segundos
lcd.clear();
}
void loop()
{
lcd.begin(16, 2);           // Fijamos el numero de caracteres y filas
lcd.print("Temperatura");  // Aqi va el mensaje
lcd.setCursor(6, 2);    // Ponte en la line 1, posicion 6
lcd.print("Celcius") ;

// Lee el valor desde el sensor
temp = analogRead(tempera); 

// Convierte el valor a temperatura
temp = (5.00 * temp * 100.00)/1024.00; 

// Envia el dato al puerto serial
Serial.println(temp);
    
Serial.print(" grados Celsius\n");
    
lcd.setCursor(0, 1);    // Ponte en la line 1, posicion 6
lcd.print(temp);
    
delay(1000); //Actualizamoslavrable cada segundo

pinMode (mos, OUTPUT);
if (temp > A)
{
digitalWrite(mos,HIGH);
}

if (temp < A)
{
digitalWrite(mos,LOW);   
}     
}
