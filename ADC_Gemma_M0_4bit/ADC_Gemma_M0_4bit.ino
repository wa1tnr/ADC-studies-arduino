
// OTHIX

// 03 January 2017 - wa1tnr

// Read R2R ladder circuit at point Vout.
// see:
// [ https://en.wikipedia.org/wiki/Resistor_ladder#R%E2%80%932R_resistor_ladder_network_(digital_to_analog_conversion) ]
// or
// [ https://preview.tinyurl.com/enwik-r2r-ladder ]  // same, made tiny

void setup(void) {                
    Serial.begin(19200);
    while (!Serial) {
    }
    delay(1100);
    Serial.println("Serial comm established.");
    delay(1100);
    Serial.println("Exiting to endless loop.");
}

int sensorValue = 1;

void loop(void) {
    sensorValue = analogRead(A1);
    // Serial.println(sensorValue);
    delay(3);  // 300 for console

    // this already worked fine: // if((sensorValue > 594) & (sensorValue < 618)) Serial.println("BUTTON 1 min max");

    // inquiry:  difference between using &  when otherwise using &&  in a test.  Which one is appropriate.  Why.

/*
    Ranges

         505 to 527  Width: 23  adjacent channel Separation: 66 (594-527 = 67)
         594 to 618  Width: 25  Separation: 53 (672-618=54)
         672 to 688  Width: 17  Separation: 35 (724-688=36)
         724 to 741  Width: 18

         All determined by experiment.
*/

    if((sensorValue > 505) && (sensorValue < 527)) {
        Serial.println("BUTTON 0 min max");
    } else {
        int aaa = 1; // noop
        // Serial.println(sensorValue);
    }

    if((sensorValue > 594) && (sensorValue < 618)) {
        Serial.println("BUTTON 1 min max");
    } else {
        int aab = 1; // noop
        // Serial.println(sensorValue);
    }

    if((sensorValue > 672) && (sensorValue < 688)) {
        Serial.println("BUTTON 2 min max");
    } else {
        int aac = 1; // noop
        // Serial.println(sensorValue);
    }

    if((sensorValue > 724) && (sensorValue < 741)) {
        Serial.println("BUTTON 3 min max");
    } else {
        int aad = 1; // noop
        // Serial.println(sensorValue);
    }
} 
