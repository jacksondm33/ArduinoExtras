#ifndef Encoder_h
#define Encoder_h

class Encoder
{
  public:
    Encoder(int clk, int dt);
    int getChange();
  private:
    int _clk;
    int _dt;
};

#endif
