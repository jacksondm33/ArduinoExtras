#include "Arduino.h"
#include "SongPlayer.h"

const float* SongPlayer::oct1 = new float[12]{32.7032, 34.6478, 36.7081, 38.8909, 41.2034, 43.6535, 46.2493, 48.9994, 51.9131, 55.0000, 58.2705, 61.7354};
const float* SongPlayer::oct2 = new float[12]{65.4064, 69.2957, 73.4162, 77.7817, 82.4069, 87.3071, 92.4986, 97.9989, 103.826, 110.000, 116.541, 123.471};
const float* SongPlayer::oct3 = new float[12]{130.813, 138.591, 146.832, 155.563, 164.814, 174.614, 184.997, 195.998, 207.652, 220.000, 233.082, 246.942};
const float* SongPlayer::oct4 = new float[12]{261.626, 277.183, 293.665, 311.127, 329.628, 349.228, 369.994, 391.995, 415.305, 440.000, 466.164, 493.883};
const float* SongPlayer::oct5 = new float[12]{523.251, 554.365, 587.330, 622.254, 659.255, 698.456, 739.989, 783.991, 830.609, 880.000, 932.328, 987.767};
const float* SongPlayer::oct6 = new float[12]{1046.50, 1108.73, 1174.66, 1244.51, 1318.51, 1396.91, 1479.98, 1567.98, 1661.22, 1760.00, 1864.66, 1975.53};
const float* SongPlayer::oct7 = new float[12]{2093.00, 2217.46, 2349.32, 2489.02, 2637.02, 2793.83, 2959.96, 3135.96, 3322.44, 3520.00, 3729.31, 3951.07};

const float** SongPlayer::octaves = new const float*[7]{oct1, oct2, oct3, oct4, oct5, oct6, oct7};

const char SongPlayer::c = 0;
const char SongPlayer::c_d = 1;
const char SongPlayer::d = 2;
const char SongPlayer::d_e = 3;
const char SongPlayer::e = 4;
const char SongPlayer::f = 5;
const char SongPlayer::f_g = 6;
const char SongPlayer::g = 7;
const char SongPlayer::g_a = 8;
const char SongPlayer::a = 9;
const char SongPlayer::a_b = 10;
const char SongPlayer::b = 11;

const char SongPlayer::rest = 0.00;

const float SongPlayer::end_song = -1.00;

SongPlayer::SongPlayer(const char _speaker){
  speaker = _speaker;
}
void SongPlayer::playNote(float note, float length){
  if(note == rest){
    delay(length * 1000);
    return;
  }
  tone(speaker, note);
  delay(length * 1000);
  noTone(speaker);
}
void SongPlayer::setSong(float* _notes, float* _beats, int _tempo){
  notes = _notes;
  beats = _beats;
  tempo = _tempo;
}
void SongPlayer::playSong(){
  for(int i = 0;; i++){
    if(notes[i] == end_song){
      break;
    }
    playNote(notes[i], beats[i] * (1.00 / (((float) tempo) / 60.00)));
  }
}
