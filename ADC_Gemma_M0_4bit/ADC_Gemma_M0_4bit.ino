
// KEFMALG  OTHIX

// 03 January 2017 - wa1tnr

// Thu Jan  4 19:16:23 UTC 2018
// Wed Jan  3 20:33:35 UTC 2018

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
    delay(300);  // 300 for console

    // this already worked fine: // if((sensorValue > 594) & (sensorValue < 618)) Serial.println("BUTTON 1 min max");

    // inquiry:  difference between using &  when otherwise using &&  in a test.  Which one is appropriate.  Why.

/*
    Ranges

         505 to 527  Width: 23  adjacent channel Separation: 66 (594-527 = 67)
         594 to 618  Width: 25  Separation: 53 (672-618=54)
         672 to 688  Width: 17  Separation: 35 (724-688=36)
         724 to 741  Width: 18

         All determined by experiment.

   Later

   a0: 159-170   a1: 399-410   a2: 544-553   a3: 633-642
   a0: 152-172   a1: 397-412   a2: 543-553   a3: 635-644  a4: 696-705

   Maybe the bits get squeezed downward when I add the next leg. ;) << nope

   Discussion

   Decreasing R1 moved the reference point for a0 quite a bit; less so
   for the other bits.


   By dropping R1 from 100k to 18k ohms:

   a0 went from 505-527 (canonical R2/R ladder) to
                152-172

   a1 went from 594-618 (canonical) to
                397-412

   a2 went from 672-688 (canonical) to
                543-553

   a3 went from 724-741 (canonical) to
                635-644

   a4 (intro)   696-705 which is still lower than a3, canonical.

   a4 has no comparison as that part of the circuit was not built,
   when the higher return numbers were obtained for a0--a3.

   So, a headroom of ~97 units of ADC reporting (whatever it is)
   was acquired by lowering (only) R1 to a reference level beneath
   what it was in a canonical R2/R ladder.  741 (top value seen
   reported) became 644, which would seem to leave a lot of room
   to get up to 1000 units (seen when the ADC pin was left floating,
   with the test program running).
   
   4-bit chords (contiguous binary series):

   1 0 0 0  0    170
   0 1 0 0  0    410
   1 1 0 0  0    498
   0 0 1 0  0    549
   1 0 1 0  0    614
   0 1 1 0  0    703
   1 1 1 0  0    741
   0 0 0 1  0    636
   1 0 0 1  0    699
   0 1 0 1  0    771
   1 1 0 1  0    806
   0 0 1 1  0    789
   1 0 1 1  0    824
   0 1 1 1  0    860
   1 1 1 1  0    885

   0 0 0 0  1    700
   1 0 0 0  1    750
   0 1 0 0  1    815
   1 1 0 0  1    843
   0 0 1 0  1    839
   1 0 1 0  1    872
   0 1 1 0  1    892
   1 1 1 0  1    915
   0 0 0 1  1    850
   1 0 0 1  1    877
   0 1 0 1  1    903
   1 1 0 1  1    922
   0 0 1 1  1    912
   1 0 1 1  1    925
   0 1 1 1  1    944
   1 1 1 1  1    959

*/

    Serial.println(sensorValue);

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
