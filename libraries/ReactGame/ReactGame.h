#ifndef ReactGame_h
#define ReactGame_h

#include <LiquidCrystal.h>

class ReactGame
{
	public:
		ReactGame(int bt1, int bt2, int led1, int led2, int led_main, String name1, String name2, int speaker, LiquidCrystal* lcd);
		void playGame();
		void winPoint(int player);
	private:
		int _bt1;
		int _bt2;
		int _led1;
		int _led2;
		int _led_main;
		int _speaker;
		LiquidCrystal* _lcd;
		int _score1;
		int _score2;
		String _name1;
		String _name2;
};

#endif
