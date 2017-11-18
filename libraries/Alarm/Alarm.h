#ifndef Alarm_h
#define Alarm_h

#include <Encoder.h>
#include <LiquidCrystal.h>

class Alarm
{
  public:
    Alarm(int x_pin, int y_pin, int z_pin, int safe_led, int alarm_led, int pass_bt, int pass, int speaker, Encoder* encoder, LiquidCrystal* lcd);
    void armAlarm();
    void setAlarm(int alarm_freq);
    void unsetAlarm();
  private:
    int _x_pin;
    int _y_pin;
    int _z_pin;
    int _safe_led;
    int _alarm_led;
    int _pass_bt;
    int _pass;
    int _speaker;
    Encoder* _encoder;
    LiquidCrystal* _lcd;
};

#endif
