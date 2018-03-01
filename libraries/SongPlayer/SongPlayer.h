#ifndef SongPlayer_h
#define SongPlayer_h

class SongPlayer
{
  public:
    SongPlayer(const char _speaker);
    void playNote(float note, float length);
    void setSong(float* notes, float* beats, int tempo);
    void playSong();

    static const float* oct1;
    static const float* oct2;
    static const float* oct3;
    static const float* oct4;
    static const float* oct5;
    static const float* oct6;
    static const float* oct7;

    static const float** octaves;

    static const char c;
    static const char c_d;
    static const char d;
    static const char d_e;
    static const char e;
    static const char f;
    static const char f_g;
    static const char g;
    static const char g_a;
    static const char a;
    static const char a_b;
    static const char b;

    static const char rest;

    static const float end_song;

    char speaker;
    float* notes;
    float* beats;
    int tempo;

  private:

};

#endif
