// PWM.c
// FOSC = 1 MHz
// CCP1 using TMR2, DC = 50%, RC5 and RC4
// TMR2 uses FOSC/4. N = 128, M = 1, use maximum period
// PWM5 using TMR4, DC = 30%, RC7
// TMR4 uses FOSC/4. N = 64, M = 1, use maximum period
// button on RD1, LED on RD2 

#include "mcc_generated_files/mcc.h"
#include <stdio.h>    // C Library for printf() 
#include <math.h>     // C Library for pow(x,n) 
#include "buttons.h"
#include "putty.h"
#include "myUART.h"


void main(void)
{
    SYSTEM_Initialize();
    clearPuTTY();
    
    int key;  
    unsigned int n = 0, m = 0, counter = 0, has_switch1_changed = 0;
    float T, f, TON;
   
       PWM5_LoadDutyValue(0); 
    while (1)     
    {
        key = 12;// no key press
      column1RC6_SetHigh(); //column 1 in powered up
      column2RC5_SetLow();
      column3RC4_SetLow();
      PWM5_LoadDutyValue(0);      
        
          while(row1_RD6_GetValue()){
                    printf("you pressed 1 \n\r");
                    PWM5_LoadDutyValue(477); // change CCPR1H:CCPRxL
                    T2CONbits.CKPS = 2;
                    T2PR = 0xEE;// change PWM5DCH:PWM5DCL
                    n = T2CONbits.CKPS;     // prescaler setting, N = 2^n
                   row1_RD6_GetValue();
          }
                        
          while(row2_RD5_GetValue()){
                    printf("you pressed 4 \n\r");
                    PWM5_LoadDutyValue(425); // change CCPR1H:CCPRxL
                    T2CONbits.CKPS = 2;
                    T2PR = 0xD4;// change PWM5DCH:PWM5DCL
                    n = T2CONbits.CKPS;     // prescaler setting, N = 2^n
                    row2_RD5_GetValue();           
          }
                  
          while(row3_RD4_GetValue()){
                    printf("you pressed 7\n\r");
                    PWM5_LoadDutyValue(377); // change CCPR1H:CCPRxL
                    T2CONbits.CKPS = 2;
                    T2PR = 0xBD;// change PWM5DCH:PWM5DCL
                    n = T2CONbits.CKPS;     // prescaler setting, N = 2^n
                    row3_RD4_GetValue();
             
          }
               
          while(row4_RC7_GetValue()){
                    printf("you pressed *\n\r");
                    PWM5_LoadDutyValue(357); // change CCPR1H:CCPRxL
                    T2CONbits.CKPS = 2;
                    T2PR = 0xB2;// change PWM5DCH:PWM5DCL
                    n = T2CONbits.CKPS;     // prescaler setting, N = 2^n
                    row4_RC7_GetValue();
              
          }
      
         
      column1RC6_SetLow(); // column 2 is powered up
      column2RC5_SetHigh();
      column3RC4_SetLow();
   
          while(row1_RD6_GetValue()){
              printf("you pressed 2\n\r");
              PWM5_LoadDutyValue(317); // change CCPR1H:CCPRxL
                    T2CONbits.CKPS = 2;
                    T2PR = 0x9E;// change PWM5DCH:PWM5DCL
                    n = T2CONbits.CKPS;     // prescaler setting, N = 2^n            
          }         row1_RD6_GetValue();
          
          while(row2_RD5_GetValue()){
                    printf("you pressed 5\n\r");
                    PWM5_LoadDutyValue(283); // change CCPR1H:CCPRxL
                    T2CONbits.CKPS = 2;
                    T2PR = 0x8D;// change PWM5DCH:PWM5DCL
                    n = T2CONbits.CKPS;     // prescaler setting, N = 2^n                           
          }         row2_RD5_GetValue();     
        
          while(row3_RD4_GetValue()){
                    printf("you pressed 8\n\r");
                    PWM5_LoadDutyValue(505); // change CCPR1H:CCPRxL
                    T2CONbits.CKPS = 1;
                    T2PR = 0xFC;// change PWM5DCH:PWM5DCL
                    n = T2CONbits.CKPS;     // prescaler setting, N = 2^n  
                    row3_RD4_GetValue();
          }                               
          while(row4_RC7_GetValue()){
                    printf("you pressed 0\n\r");
                    PWM5_LoadDutyValue(477); // change CCPR1H:CCPRxL
                    T2CONbits.CKPS = 1;
                    T2PR = 0xEE;// change PWM5DCH:PWM5DCL
                    n = T2CONbits.CKPS;     // prescaler setting, N = 2^n                         
          }         row4_RC7_GetValue();
          
      column1RC6_SetLow();   // column 3 is powered up
      column2RC5_SetLow();
      column3RC4_SetHigh();
         
   
          while(row1_RD6_GetValue()){
                    printf("you pressed 3\n\r");
                    PWM5_LoadDutyValue(425); // change CCPR1H:CCPRxL
                    T2CONbits.CKPS = 1;
                    T2PR = 0xD4;// change PWM5DCH:PWM5DCL
                    n = T2CONbits.CKPS;     // prescaler setting, N = 2^n             
                    row1_RD6_GetValue();
          }      
      
          while(row2_RD5_GetValue()){
                    printf("you pressed 6\n\r");
                    PWM5_LoadDutyValue(377); // change CCPR1H:CCPRxL
                    T2CONbits.CKPS = 1;
                    T2PR = 0xBD;// change PWM5DCH:PWM5DCL
                    n = T2CONbits.CKPS;     // prescaler setting, N = 2^n   
                    row2_RD5_GetValue();
          } 
      
          while(row3_RD4_GetValue()){
              printf("you pressed 9\n\r");
              PWM5_LoadDutyValue(357); // change CCPR1H:CCPRxL
                    T2CONbits.CKPS = 1;
                    T2PR = 0xB2;// change PWM5DCH:PWM5DCL
                    n = T2CONbits.CKPS;     // prescaler setting, N = 2^n 
                    row3_RD4_GetValue();
          } 
      
          while(row4_RC7_GetValue()){
              printf("you pressed # \n\r");
              PWM5_LoadDutyValue(317); // change CCPR1H:CCPRxL
                    T2CONbits.CKPS = 1;
                    T2PR = 0x9E;// change PWM5DCH:PWM5DCL
                    n = T2CONbits.CKPS;     // prescaler setting, N = 2^n  
                    row4_RC7_GetValue();
          }                                   
     DELAY_milliseconds(50);
      }
      
}      
    
