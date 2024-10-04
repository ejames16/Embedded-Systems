#include "uop_msb.h"
using namespace uop_msb;

// Inputs
DigitalIn SW2(BTN1_PIN);
DigitalIn SW3(BTN2_PIN);

// Outputs
DigitalOut ledRed(TRAF_RED1_PIN);
DigitalOut ledYel(TRAF_YEL1_PIN);
DigitalOut ledGrn(TRAF_GRN1_PIN);

// Timers (modified version from Timer)
TimerCompat tmr_flash;
TimerCompat tmr_btn1;
TimerCompat tmr_btn2;

int main()
{
    //Start flashing timer
    tmr_flash.start();

    int btn1_bounce = 0;
    int btn1_pressed = 0;
    int btn2_bounce = 0;
    int btn2_pressed = 0;
    

    while (true) {

        //Wait for switch press and release (by BLOCKING)
        if (btn1_bounce == 0){
            if (SW2.read() == 1){
                btn1_pressed = 1;
                btn1_bounce = 1;
                tmr_btn1.start();
            }
            else if (SW2.read() == 0 and btn1_pressed){
                ledRed = !ledRed;
                btn1_pressed = 0;   
            }
        }
        else if (tmr_btn1.read_ms() > 50)
        {
            btn1_bounce = 0;
            tmr_btn1.stop();
            tmr_btn1.reset();
        }

        if (btn2_bounce == 0){
            if (SW3.read() == 1){
                btn2_pressed = 1;
                btn2_bounce = 1;
                tmr_btn2.start();
            }
            else if (SW3.read() == 0 and btn2_pressed){
                ledGrn = !ledGrn;
                btn2_pressed = 0;
            }
        }
        else if (tmr_btn2.read_ms() > 50)
        {
            btn2_bounce = 0;
            tmr_btn2.stop();
            tmr_btn2.reset();
        }
                 

        //Toggle Yellow LED
        
        if (tmr_flash.read_ms() >= 500)
        {
            ledYel = !ledYel;
            tmr_flash.reset();
        }
        
    }
}





