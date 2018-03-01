#include "Arduino.h"
#include "ReactGame.h"
#include <LiquidCrystal.h>

ReactGame::ReactGame(int bt1, int bt2, int led1, int led2, int led_main, String name1, String name2, int speaker, LiquidCrystal* lcd){
	pinMode(bt1, INPUT);
	pinMode(bt2, INPUT);
	pinMode(led1, OUTPUT);
	pinMode(led2, OUTPUT);
	pinMode(led_main, OUTPUT);
	pinMode(speaker, OUTPUT);
	_bt1 = bt1;
	_bt2 = bt2;
	_led1 = led1;
	_led2 = led2;
	_led_main = led_main;
	_speaker = speaker;
	_lcd = lcd;
	_name1 = name1;
	_name2 = name2;
}
void ReactGame::playGame(){
	_score1 = 0;
	_score2 = 0;
	_lcd->begin(16, 2);
	boolean con_point = true;
	delay(1000);
	while(true){
		con_point = true;
		_lcd->clear();
		_lcd->setCursor(0, 0);
		if(_score1 >= 11){
			_lcd->print(_name1 + " wins");
			_lcd->setCursor(0, 1);
			_lcd->print("Score: " + String(_score1) + "-" + String(_score2));
			break;
		}
		if(_score2 >= 11){
			_lcd->print(_name2 + " wins");
			_lcd->setCursor(0, 1);
			_lcd->print("Score: " + String(_score1) + "-" + String(_score2));
			break;
		}
		_lcd->print(_name1 + " score: " + String(_score1));
		_lcd->setCursor(0, 1);
		_lcd->print(_name2 + " score: " + String(_score2));
		int wait = random(1000, 10000);
		for(int i = 0; i < wait; i += 10){
			if(digitalRead(_bt1) == HIGH){
				winPoint(2);
				con_point = false;
				break;
			}
			if(digitalRead(_bt2) == HIGH){
				winPoint(1);
				con_point = false;
				break;
			}
			delay(10);
		}
		if(!con_point){
			continue;
		}
		digitalWrite(_led_main, HIGH);
		while(true){
			if(digitalRead(_bt1) == HIGH && digitalRead(_bt2) == HIGH){
				winPoint(0);
				break;
			}
			if(digitalRead(_bt1) == HIGH){
				winPoint(1);
				break;
			}
			if(digitalRead(_bt2) == HIGH){
				winPoint(2);
				break;
			}
			delay(1);
		}
	}
}
void ReactGame::winPoint(int player){
	digitalWrite(_led_main, LOW);
	if(player == 0){
		digitalWrite(_led1, HIGH);
		digitalWrite(_led2, HIGH);
		delay(1000);
		digitalWrite(_led1, LOW);
		digitalWrite(_led2, LOW);
		return;
	}
	if(player == 1){
		digitalWrite(_led1, HIGH);
		delay(1000);
		digitalWrite(_led1, LOW);
		_score1 += 1;
		return;
	}
	if(player == 2){
		digitalWrite(_led2, HIGH);
		delay(1000);
		digitalWrite(_led2, LOW);
		_score2 += 1;
		return;
	}
}
