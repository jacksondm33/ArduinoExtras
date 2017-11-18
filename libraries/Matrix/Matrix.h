#ifndef Matrix_h
#define Matrix_h

class Matrix
{
  public:
    Matrix(unsigned char* _cols, unsigned char* _rows);
    void setPixel(unsigned char x, unsigned char y, unsigned char val);
    void clear();
    static void update();
    void startUpdateManager(unsigned char interrupt_pin, unsigned char interrupt);
    void stopUpdateManager(unsigned char interrupt_pin, unsigned char interrupt);
    void printSymbol(unsigned char* symbol);
    void printPixels();
    void displaySymbol(unsigned char* symbol);
    unsigned char* getNewSymbol();
    unsigned char* getEditableSymbol(const unsigned char* const symbol);
    unsigned char* combineSymbols(unsigned char* symbol1, unsigned char* symbol2);
    unsigned char* shiftSymbol(unsigned char* symbol, char shift_right, char shift_up);
    unsigned char* transitionY(unsigned char* symbol1, unsigned char* symbol2, char shift_up);
    unsigned char* transitionX(unsigned char* symbol1, unsigned char* symbol2, char shift_right);
    unsigned char getColVal(unsigned char row, unsigned char col);
    void display2Number(unsigned char number);
    void timer2Number(unsigned char start_time);
    void alphabet();
    unsigned char* cols;
    unsigned char* rows;
    unsigned char* pixels;
    volatile unsigned char col;
    static Matrix* matrix;

    static const unsigned char D_0_0;
    static const unsigned char D_0_1;
    static const unsigned char D_0_2;
    static const unsigned char D_0_3;
    static const unsigned char D_0_4;
    static const unsigned char D_0_5;
    static const unsigned char D_0_6;
    static const unsigned char D_0_7;

    static const unsigned char D_1_0;
    static const unsigned char D_1_1;
    static const unsigned char D_1_2;
    static const unsigned char D_1_3;
    static const unsigned char D_1_4;
    static const unsigned char D_1_5;
    static const unsigned char D_1_6;
    static const unsigned char D_1_7;

    static const unsigned char D_2_0;
    static const unsigned char D_2_1;
    static const unsigned char D_2_2;
    static const unsigned char D_2_3;
    static const unsigned char D_2_4;
    static const unsigned char D_2_5;
    static const unsigned char D_2_6;
    static const unsigned char D_2_7;

    static const unsigned char D_3_0;
    static const unsigned char D_3_1;
    static const unsigned char D_3_2;
    static const unsigned char D_3_3;
    static const unsigned char D_3_4;
    static const unsigned char D_3_5;
    static const unsigned char D_3_6;
    static const unsigned char D_3_7;

    static const unsigned char D_4_0;
    static const unsigned char D_4_1;
    static const unsigned char D_4_2;
    static const unsigned char D_4_3;
    static const unsigned char D_4_4;
    static const unsigned char D_4_5;
    static const unsigned char D_4_6;
    static const unsigned char D_4_7;

    static const unsigned char D_5_0;
    static const unsigned char D_5_1;
    static const unsigned char D_5_2;
    static const unsigned char D_5_3;
    static const unsigned char D_5_4;
    static const unsigned char D_5_5;
    static const unsigned char D_5_6;
    static const unsigned char D_5_7;

    static const unsigned char D_6_0;
    static const unsigned char D_6_1;
    static const unsigned char D_6_2;
    static const unsigned char D_6_3;
    static const unsigned char D_6_4;
    static const unsigned char D_6_5;
    static const unsigned char D_6_6;
    static const unsigned char D_6_7;

    static const unsigned char D_7_0;
    static const unsigned char D_7_1;
    static const unsigned char D_7_2;
    static const unsigned char D_7_3;
    static const unsigned char D_7_4;
    static const unsigned char D_7_5;
    static const unsigned char D_7_6;
    static const unsigned char D_7_7;

    static const unsigned char D_8_0;
    static const unsigned char D_8_1;
    static const unsigned char D_8_2;
    static const unsigned char D_8_3;
    static const unsigned char D_8_4;
    static const unsigned char D_8_5;
    static const unsigned char D_8_6;
    static const unsigned char D_8_7;

    static const unsigned char D_9_0;
    static const unsigned char D_9_1;
    static const unsigned char D_9_2;
    static const unsigned char D_9_3;
    static const unsigned char D_9_4;
    static const unsigned char D_9_5;
    static const unsigned char D_9_6;
    static const unsigned char D_9_7;

    static const unsigned char D_A_0;
    static const unsigned char D_A_1;
    static const unsigned char D_A_2;
    static const unsigned char D_A_3;
    static const unsigned char D_A_4;
    static const unsigned char D_A_5;
    static const unsigned char D_A_6;
    static const unsigned char D_A_7;

    static const unsigned char D_B_0;
    static const unsigned char D_B_1;
    static const unsigned char D_B_2;
    static const unsigned char D_B_3;
    static const unsigned char D_B_4;
    static const unsigned char D_B_5;
    static const unsigned char D_B_6;
    static const unsigned char D_B_7;

    static const unsigned char D_C_0;
    static const unsigned char D_C_1;
    static const unsigned char D_C_2;
    static const unsigned char D_C_3;
    static const unsigned char D_C_4;
    static const unsigned char D_C_5;
    static const unsigned char D_C_6;
    static const unsigned char D_C_7;

    static const unsigned char D_D_0;
    static const unsigned char D_D_1;
    static const unsigned char D_D_2;
    static const unsigned char D_D_3;
    static const unsigned char D_D_4;
    static const unsigned char D_D_5;
    static const unsigned char D_D_6;
    static const unsigned char D_D_7;

    static const unsigned char D_E_0;
    static const unsigned char D_E_1;
    static const unsigned char D_E_2;
    static const unsigned char D_E_3;
    static const unsigned char D_E_4;
    static const unsigned char D_E_5;
    static const unsigned char D_E_6;
    static const unsigned char D_E_7;

    static const unsigned char D_F_0;
    static const unsigned char D_F_1;
    static const unsigned char D_F_2;
    static const unsigned char D_F_3;
    static const unsigned char D_F_4;
    static const unsigned char D_F_5;
    static const unsigned char D_F_6;
    static const unsigned char D_F_7;

    static const unsigned char D_G_0;
    static const unsigned char D_G_1;
    static const unsigned char D_G_2;
    static const unsigned char D_G_3;
    static const unsigned char D_G_4;
    static const unsigned char D_G_5;
    static const unsigned char D_G_6;
    static const unsigned char D_G_7;

    static const unsigned char D_H_0;
    static const unsigned char D_H_1;
    static const unsigned char D_H_2;
    static const unsigned char D_H_3;
    static const unsigned char D_H_4;
    static const unsigned char D_H_5;
    static const unsigned char D_H_6;
    static const unsigned char D_H_7;

    static const unsigned char D_I_0;
    static const unsigned char D_I_1;
    static const unsigned char D_I_2;
    static const unsigned char D_I_3;
    static const unsigned char D_I_4;
    static const unsigned char D_I_5;
    static const unsigned char D_I_6;
    static const unsigned char D_I_7;

    static const unsigned char D_J_0;
    static const unsigned char D_J_1;
    static const unsigned char D_J_2;
    static const unsigned char D_J_3;
    static const unsigned char D_J_4;
    static const unsigned char D_J_5;
    static const unsigned char D_J_6;
    static const unsigned char D_J_7;

    static const unsigned char D_K_0;
    static const unsigned char D_K_1;
    static const unsigned char D_K_2;
    static const unsigned char D_K_3;
    static const unsigned char D_K_4;
    static const unsigned char D_K_5;
    static const unsigned char D_K_6;
    static const unsigned char D_K_7;

    static const unsigned char D_L_0;
    static const unsigned char D_L_1;
    static const unsigned char D_L_2;
    static const unsigned char D_L_3;
    static const unsigned char D_L_4;
    static const unsigned char D_L_5;
    static const unsigned char D_L_6;
    static const unsigned char D_L_7;

    static const unsigned char D_M_0;
    static const unsigned char D_M_1;
    static const unsigned char D_M_2;
    static const unsigned char D_M_3;
    static const unsigned char D_M_4;
    static const unsigned char D_M_5;
    static const unsigned char D_M_6;
    static const unsigned char D_M_7;

    static const unsigned char D_N_0;
    static const unsigned char D_N_1;
    static const unsigned char D_N_2;
    static const unsigned char D_N_3;
    static const unsigned char D_N_4;
    static const unsigned char D_N_5;
    static const unsigned char D_N_6;
    static const unsigned char D_N_7;

    static const unsigned char D_O_0;
    static const unsigned char D_O_1;
    static const unsigned char D_O_2;
    static const unsigned char D_O_3;
    static const unsigned char D_O_4;
    static const unsigned char D_O_5;
    static const unsigned char D_O_6;
    static const unsigned char D_O_7;

    static const unsigned char D_P_0;
    static const unsigned char D_P_1;
    static const unsigned char D_P_2;
    static const unsigned char D_P_3;
    static const unsigned char D_P_4;
    static const unsigned char D_P_5;
    static const unsigned char D_P_6;
    static const unsigned char D_P_7;

    static const unsigned char D_Q_0;
    static const unsigned char D_Q_1;
    static const unsigned char D_Q_2;
    static const unsigned char D_Q_3;
    static const unsigned char D_Q_4;
    static const unsigned char D_Q_5;
    static const unsigned char D_Q_6;
    static const unsigned char D_Q_7;

    static const unsigned char D_R_0;
    static const unsigned char D_R_1;
    static const unsigned char D_R_2;
    static const unsigned char D_R_3;
    static const unsigned char D_R_4;
    static const unsigned char D_R_5;
    static const unsigned char D_R_6;
    static const unsigned char D_R_7;

    static const unsigned char D_S_0;
    static const unsigned char D_S_1;
    static const unsigned char D_S_2;
    static const unsigned char D_S_3;
    static const unsigned char D_S_4;
    static const unsigned char D_S_5;
    static const unsigned char D_S_6;
    static const unsigned char D_S_7;

    static const unsigned char D_T_0;
    static const unsigned char D_T_1;
    static const unsigned char D_T_2;
    static const unsigned char D_T_3;
    static const unsigned char D_T_4;
    static const unsigned char D_T_5;
    static const unsigned char D_T_6;
    static const unsigned char D_T_7;

    static const unsigned char D_U_0;
    static const unsigned char D_U_1;
    static const unsigned char D_U_2;
    static const unsigned char D_U_3;
    static const unsigned char D_U_4;
    static const unsigned char D_U_5;
    static const unsigned char D_U_6;
    static const unsigned char D_U_7;

    static const unsigned char D_V_0;
    static const unsigned char D_V_1;
    static const unsigned char D_V_2;
    static const unsigned char D_V_3;
    static const unsigned char D_V_4;
    static const unsigned char D_V_5;
    static const unsigned char D_V_6;
    static const unsigned char D_V_7;

    static const unsigned char D_W_0;
    static const unsigned char D_W_1;
    static const unsigned char D_W_2;
    static const unsigned char D_W_3;
    static const unsigned char D_W_4;
    static const unsigned char D_W_5;
    static const unsigned char D_W_6;
    static const unsigned char D_W_7;

    static const unsigned char D_X_0;
    static const unsigned char D_X_1;
    static const unsigned char D_X_2;
    static const unsigned char D_X_3;
    static const unsigned char D_X_4;
    static const unsigned char D_X_5;
    static const unsigned char D_X_6;
    static const unsigned char D_X_7;

    static const unsigned char D_Y_0;
    static const unsigned char D_Y_1;
    static const unsigned char D_Y_2;
    static const unsigned char D_Y_3;
    static const unsigned char D_Y_4;
    static const unsigned char D_Y_5;
    static const unsigned char D_Y_6;
    static const unsigned char D_Y_7;

    static const unsigned char D_Z_0;
    static const unsigned char D_Z_1;
    static const unsigned char D_Z_2;
    static const unsigned char D_Z_3;
    static const unsigned char D_Z_4;
    static const unsigned char D_Z_5;
    static const unsigned char D_Z_6;
    static const unsigned char D_Z_7;

    static const unsigned char* const D_0;
    static const unsigned char* const D_1;
    static const unsigned char* const D_2;
    static const unsigned char* const D_3;
    static const unsigned char* const D_4;
    static const unsigned char* const D_5;
    static const unsigned char* const D_6;
    static const unsigned char* const D_7;
    static const unsigned char* const D_8;
    static const unsigned char* const D_9;
    static const unsigned char* const D_A;
    static const unsigned char* const D_B;
    static const unsigned char* const D_C;
    static const unsigned char* const D_D;
    static const unsigned char* const D_E;
    static const unsigned char* const D_F;
    static const unsigned char* const D_G;
    static const unsigned char* const D_H;
    static const unsigned char* const D_I;
    static const unsigned char* const D_J;
    static const unsigned char* const D_K;
    static const unsigned char* const D_L;
    static const unsigned char* const D_M;
    static const unsigned char* const D_N;
    static const unsigned char* const D_O;
    static const unsigned char* const D_P;
    static const unsigned char* const D_Q;
    static const unsigned char* const D_R;
    static const unsigned char* const D_S;
    static const unsigned char* const D_T;
    static const unsigned char* const D_U;
    static const unsigned char* const D_V;
    static const unsigned char* const D_W;
    static const unsigned char* const D_X;
    static const unsigned char* const D_Y;
    static const unsigned char* const D_Z;

    static const unsigned char** const numbers;
    static const unsigned char** const letters;

  private:

};

#endif
