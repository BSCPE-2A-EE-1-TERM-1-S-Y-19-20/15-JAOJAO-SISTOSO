int VoltIn = 5,              
    data1 = 0,              
    data2 = 0,
    data3 = 0;

float VoltOut1 = 0,           
      VoltOut2 = 0,
      VoltOut3 = 0;

float R0 = 1100,            
      Rstr1 = 0,
      Rstr2 = 0,
      Rstr3 = 0;

float Rstrs12 = 0,            
      Rstrs13 = 0,
      Rstrs23 = 0;
      
float Numerator;

void setup() {
Serial.begin( 9600 );
}

void loop() {
data1 = analogRead( A0 );
data2 = analogRead( A1 );
data3 = analogRead( A2 );

VoltOut1 = ( data1 * VoltIn ) / 1024.0;
VoltOut2 = ( data2 * VoltIn ) / 1024.0;
VoltOut3 = ( data3 * VoltIn ) / 1024.0;

Rstr1 = R0 * ( ( VoltOut2 / VoltOut1 ) - 1 );
Rstr2 = R0 * ( ( VoltOut3 / VoltOut1 ) - 1 ) - Rstr1;
Rstr3 = R0 * ( ( VoltIn / VoltOut1 ) - 1 ) - Rstr1 - Rstr2;

Numerator = ( Rstr1 * Rstr2 ) + ( Rstr1 * Rstr3 ) + ( Rstr2 * Rstr3 );

Rstrs12 = Numerator / Rstr3;
Rstrs13 = Numerator / Rstr2;
Rstrs23 = Numerator / Rstr1;

Serial.println();
Serial.println();
Serial.println();
Serial.println();
Serial.println();

Serial.print( "Resistor Values: " );
Serial.println();
Serial.print( "Resistor 1 = " );
Serial.println( Rstr1 );
Serial.print( "Resistor 2 = " );
Serial.println( Rstr2 );
Serial.print( "Resistor 3 = " );
Serial.println( Rstr3 );

Serial.println();
Serial.print( "Resistors 12 = " );
Serial.println( Rstrs12 );
Serial.print( "Resistors 13 = " );
Serial.println( Rstrs13 );
Serial.print( "Resistors 23 = " );
Serial.println( Rstrs23 );

delay (4000);

}
