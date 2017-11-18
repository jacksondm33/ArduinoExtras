#include "Arduino.h"
#include "Matrix.h"

Matrix* Matrix::matrix;

const unsigned char Matrix::D_0_0 = 0b11110000;
const unsigned char Matrix::D_0_1 = 0b10010000;
const unsigned char Matrix::D_0_2 = 0b10010000;
const unsigned char Matrix::D_0_3 = 0b10010000;
const unsigned char Matrix::D_0_4 = 0b10010000;
const unsigned char Matrix::D_0_5 = 0b10010000;
const unsigned char Matrix::D_0_6 = 0b10010000;
const unsigned char Matrix::D_0_7 = 0b11110000;

const unsigned char Matrix::D_1_0 = 0b00010000;
const unsigned char Matrix::D_1_1 = 0b00010000;
const unsigned char Matrix::D_1_2 = 0b00010000;
const unsigned char Matrix::D_1_3 = 0b00010000;
const unsigned char Matrix::D_1_4 = 0b00010000;
const unsigned char Matrix::D_1_5 = 0b00010000;
const unsigned char Matrix::D_1_6 = 0b00010000;
const unsigned char Matrix::D_1_7 = 0b00010000;

const unsigned char Matrix::D_2_0 = 0b11110000;
const unsigned char Matrix::D_2_1 = 0b00010000;
const unsigned char Matrix::D_2_2 = 0b00010000;
const unsigned char Matrix::D_2_3 = 0b11110000;
const unsigned char Matrix::D_2_4 = 0b10000000;
const unsigned char Matrix::D_2_5 = 0b10000000;
const unsigned char Matrix::D_2_6 = 0b10000000;
const unsigned char Matrix::D_2_7 = 0b11110000;

const unsigned char Matrix::D_3_0 = 0b11110000;
const unsigned char Matrix::D_3_1 = 0b00010000;
const unsigned char Matrix::D_3_2 = 0b00010000;
const unsigned char Matrix::D_3_3 = 0b11110000;
const unsigned char Matrix::D_3_4 = 0b00010000;
const unsigned char Matrix::D_3_5 = 0b00010000;
const unsigned char Matrix::D_3_6 = 0b00010000;
const unsigned char Matrix::D_3_7 = 0b11110000;

const unsigned char Matrix::D_4_0 = 0b10010000;
const unsigned char Matrix::D_4_1 = 0b10010000;
const unsigned char Matrix::D_4_2 = 0b10010000;
const unsigned char Matrix::D_4_3 = 0b11110000;
const unsigned char Matrix::D_4_4 = 0b00010000;
const unsigned char Matrix::D_4_5 = 0b00010000;
const unsigned char Matrix::D_4_6 = 0b00010000;
const unsigned char Matrix::D_4_7 = 0b00010000;

const unsigned char Matrix::D_5_0 = 0b11110000;
const unsigned char Matrix::D_5_1 = 0b10000000;
const unsigned char Matrix::D_5_2 = 0b10000000;
const unsigned char Matrix::D_5_3 = 0b11110000;
const unsigned char Matrix::D_5_4 = 0b00010000;
const unsigned char Matrix::D_5_5 = 0b00010000;
const unsigned char Matrix::D_5_6 = 0b00010000;
const unsigned char Matrix::D_5_7 = 0b11110000;

const unsigned char Matrix::D_6_0 = 0b11110000;
const unsigned char Matrix::D_6_1 = 0b10000000;
const unsigned char Matrix::D_6_2 = 0b10000000;
const unsigned char Matrix::D_6_3 = 0b11110000;
const unsigned char Matrix::D_6_4 = 0b10010000;
const unsigned char Matrix::D_6_5 = 0b10010000;
const unsigned char Matrix::D_6_6 = 0b10010000;
const unsigned char Matrix::D_6_7 = 0b11110000;

const unsigned char Matrix::D_7_0 = 0b11110000;
const unsigned char Matrix::D_7_1 = 0b00010000;
const unsigned char Matrix::D_7_2 = 0b00010000;
const unsigned char Matrix::D_7_3 = 0b00010000;
const unsigned char Matrix::D_7_4 = 0b00010000;
const unsigned char Matrix::D_7_5 = 0b00010000;
const unsigned char Matrix::D_7_6 = 0b00010000;
const unsigned char Matrix::D_7_7 = 0b00010000;

const unsigned char Matrix::D_8_0 = 0b11110000;
const unsigned char Matrix::D_8_1 = 0b10010000;
const unsigned char Matrix::D_8_2 = 0b10010000;
const unsigned char Matrix::D_8_3 = 0b11110000;
const unsigned char Matrix::D_8_4 = 0b10010000;
const unsigned char Matrix::D_8_5 = 0b10010000;
const unsigned char Matrix::D_8_6 = 0b10010000;
const unsigned char Matrix::D_8_7 = 0b11110000;

const unsigned char Matrix::D_9_0 = 0b11110000;
const unsigned char Matrix::D_9_1 = 0b10010000;
const unsigned char Matrix::D_9_2 = 0b10010000;
const unsigned char Matrix::D_9_3 = 0b11110000;
const unsigned char Matrix::D_9_4 = 0b00010000;
const unsigned char Matrix::D_9_5 = 0b00010000;
const unsigned char Matrix::D_9_6 = 0b00010000;
const unsigned char Matrix::D_9_7 = 0b00010000;

const unsigned char Matrix::D_A_0 = 0b00010000;
const unsigned char Matrix::D_A_1 = 0b00010000;
const unsigned char Matrix::D_A_2 = 0b00101000;
const unsigned char Matrix::D_A_3 = 0b00101000;
const unsigned char Matrix::D_A_4 = 0b01111100;
const unsigned char Matrix::D_A_5 = 0b01000100;
const unsigned char Matrix::D_A_6 = 0b10000010;
const unsigned char Matrix::D_A_7 = 0b10000010;

const unsigned char Matrix::D_B_0 = 0b11111000;
const unsigned char Matrix::D_B_1 = 0b10000100;
const unsigned char Matrix::D_B_2 = 0b10000010;
const unsigned char Matrix::D_B_3 = 0b11111110;
const unsigned char Matrix::D_B_4 = 0b10000010;
const unsigned char Matrix::D_B_5 = 0b10000010;
const unsigned char Matrix::D_B_6 = 0b10000100;
const unsigned char Matrix::D_B_7 = 0b11111000;

const unsigned char Matrix::D_C_0 = 0b00111110;
const unsigned char Matrix::D_C_1 = 0b01000000;
const unsigned char Matrix::D_C_2 = 0b10000000;
const unsigned char Matrix::D_C_3 = 0b10000000;
const unsigned char Matrix::D_C_4 = 0b10000000;
const unsigned char Matrix::D_C_5 = 0b10000000;
const unsigned char Matrix::D_C_6 = 0b01000000;
const unsigned char Matrix::D_C_7 = 0b00111110;

const unsigned char Matrix::D_D_0 = 0b11111000;
const unsigned char Matrix::D_D_1 = 0b10000100;
const unsigned char Matrix::D_D_2 = 0b10000010;
const unsigned char Matrix::D_D_3 = 0b10000010;
const unsigned char Matrix::D_D_4 = 0b10000010;
const unsigned char Matrix::D_D_5 = 0b10000010;
const unsigned char Matrix::D_D_6 = 0b10000100;
const unsigned char Matrix::D_D_7 = 0b11111000;

const unsigned char Matrix::D_E_0 = 0b11111110;
const unsigned char Matrix::D_E_1 = 0b10000000;
const unsigned char Matrix::D_E_2 = 0b10000000;
const unsigned char Matrix::D_E_3 = 0b11111110;
const unsigned char Matrix::D_E_4 = 0b10000000;
const unsigned char Matrix::D_E_5 = 0b10000000;
const unsigned char Matrix::D_E_6 = 0b10000000;
const unsigned char Matrix::D_E_7 = 0b11111110;

const unsigned char Matrix::D_F_0 = 0b11111110;
const unsigned char Matrix::D_F_1 = 0b10000000;
const unsigned char Matrix::D_F_2 = 0b10000000;
const unsigned char Matrix::D_F_3 = 0b11111110;
const unsigned char Matrix::D_F_4 = 0b10000000;
const unsigned char Matrix::D_F_5 = 0b10000000;
const unsigned char Matrix::D_F_6 = 0b10000000;
const unsigned char Matrix::D_F_7 = 0b10000000;

const unsigned char Matrix::D_G_0 = 0b00111110;
const unsigned char Matrix::D_G_1 = 0b01000000;
const unsigned char Matrix::D_G_2 = 0b10000000;
const unsigned char Matrix::D_G_3 = 0b10011110;
const unsigned char Matrix::D_G_4 = 0b10000010;
const unsigned char Matrix::D_G_5 = 0b10000010;
const unsigned char Matrix::D_G_6 = 0b01000100;
const unsigned char Matrix::D_G_7 = 0b00111000;

const unsigned char Matrix::D_H_0 = 0b10000010;
const unsigned char Matrix::D_H_1 = 0b10000010;
const unsigned char Matrix::D_H_2 = 0b10000010;
const unsigned char Matrix::D_H_3 = 0b11111110;
const unsigned char Matrix::D_H_4 = 0b10000010;
const unsigned char Matrix::D_H_5 = 0b10000010;
const unsigned char Matrix::D_H_6 = 0b10000010;
const unsigned char Matrix::D_H_7 = 0b10000010;

const unsigned char Matrix::D_I_0 = 0b11111110;
const unsigned char Matrix::D_I_1 = 0b00010000;
const unsigned char Matrix::D_I_2 = 0b00010000;
const unsigned char Matrix::D_I_3 = 0b00010000;
const unsigned char Matrix::D_I_4 = 0b00010000;
const unsigned char Matrix::D_I_5 = 0b00010000;
const unsigned char Matrix::D_I_6 = 0b00010000;
const unsigned char Matrix::D_I_7 = 0b11111110;

const unsigned char Matrix::D_J_0 = 0b11111110;
const unsigned char Matrix::D_J_1 = 0b00010000;
const unsigned char Matrix::D_J_2 = 0b00010000;
const unsigned char Matrix::D_J_3 = 0b00010000;
const unsigned char Matrix::D_J_4 = 0b10010000;
const unsigned char Matrix::D_J_5 = 0b10010000;
const unsigned char Matrix::D_J_6 = 0b10010000;
const unsigned char Matrix::D_J_7 = 0b01100000;

const unsigned char Matrix::D_K_0 = 0b10000010;
const unsigned char Matrix::D_K_1 = 0b10001100;
const unsigned char Matrix::D_K_2 = 0b10110000;
const unsigned char Matrix::D_K_3 = 0b11000000;
const unsigned char Matrix::D_K_4 = 0b11000000;
const unsigned char Matrix::D_K_5 = 0b10110000;
const unsigned char Matrix::D_K_6 = 0b10001100;
const unsigned char Matrix::D_K_7 = 0b10000010;

const unsigned char Matrix::D_L_0 = 0b10000000;
const unsigned char Matrix::D_L_1 = 0b10000000;
const unsigned char Matrix::D_L_2 = 0b10000000;
const unsigned char Matrix::D_L_3 = 0b10000000;
const unsigned char Matrix::D_L_4 = 0b10000000;
const unsigned char Matrix::D_L_5 = 0b10000000;
const unsigned char Matrix::D_L_6 = 0b10000000;
const unsigned char Matrix::D_L_7 = 0b11111110;

const unsigned char Matrix::D_M_0 = 0b10000010;
const unsigned char Matrix::D_M_1 = 0b11000110;
const unsigned char Matrix::D_M_2 = 0b11000110;
const unsigned char Matrix::D_M_3 = 0b10101010;
const unsigned char Matrix::D_M_4 = 0b10101010;
const unsigned char Matrix::D_M_5 = 0b10010010;
const unsigned char Matrix::D_M_6 = 0b10010010;
const unsigned char Matrix::D_M_7 = 0b10010010;

const unsigned char Matrix::D_N_0 = 0b10000010;
const unsigned char Matrix::D_N_1 = 0b11000010;
const unsigned char Matrix::D_N_2 = 0b10100010;
const unsigned char Matrix::D_N_3 = 0b10010010;
const unsigned char Matrix::D_N_4 = 0b10001010;
const unsigned char Matrix::D_N_5 = 0b10000110;
const unsigned char Matrix::D_N_6 = 0b10000110;
const unsigned char Matrix::D_N_7 = 0b10000010;

const unsigned char Matrix::D_O_0 = 0b00111000;
const unsigned char Matrix::D_O_1 = 0b01000100;
const unsigned char Matrix::D_O_2 = 0b10000010;
const unsigned char Matrix::D_O_3 = 0b10000010;
const unsigned char Matrix::D_O_4 = 0b10000010;
const unsigned char Matrix::D_O_5 = 0b10000010;
const unsigned char Matrix::D_O_6 = 0b01000100;
const unsigned char Matrix::D_O_7 = 0b00111000;

const unsigned char Matrix::D_P_0 = 0b11111100;
const unsigned char Matrix::D_P_1 = 0b10000010;
const unsigned char Matrix::D_P_2 = 0b10000010;
const unsigned char Matrix::D_P_3 = 0b11111100;
const unsigned char Matrix::D_P_4 = 0b10000000;
const unsigned char Matrix::D_P_5 = 0b10000000;
const unsigned char Matrix::D_P_6 = 0b10000000;
const unsigned char Matrix::D_P_7 = 0b10000000;

const unsigned char Matrix::D_Q_0 = 0b00111000;
const unsigned char Matrix::D_Q_1 = 0b01000100;
const unsigned char Matrix::D_Q_2 = 0b10000010;
const unsigned char Matrix::D_Q_3 = 0b10000010;
const unsigned char Matrix::D_Q_4 = 0b10000010;
const unsigned char Matrix::D_Q_5 = 0b10001010;
const unsigned char Matrix::D_Q_6 = 0b01000100;
const unsigned char Matrix::D_Q_7 = 0b00111010;

const unsigned char Matrix::D_R_0 = 0b11111100;
const unsigned char Matrix::D_R_1 = 0b10000010;
const unsigned char Matrix::D_R_2 = 0b10000010;
const unsigned char Matrix::D_R_3 = 0b11111100;
const unsigned char Matrix::D_R_4 = 0b11000000;
const unsigned char Matrix::D_R_5 = 0b10110000;
const unsigned char Matrix::D_R_6 = 0b10001100;
const unsigned char Matrix::D_R_7 = 0b10000010;

const unsigned char Matrix::D_S_0 = 0b01111110;
const unsigned char Matrix::D_S_1 = 0b10000000;
const unsigned char Matrix::D_S_2 = 0b10000000;
const unsigned char Matrix::D_S_3 = 0b01111100;
const unsigned char Matrix::D_S_4 = 0b00000010;
const unsigned char Matrix::D_S_5 = 0b00000010;
const unsigned char Matrix::D_S_6 = 0b00000100;
const unsigned char Matrix::D_S_7 = 0b11111000;

const unsigned char Matrix::D_T_0 = 0b11111110;
const unsigned char Matrix::D_T_1 = 0b00010000;
const unsigned char Matrix::D_T_2 = 0b00010000;
const unsigned char Matrix::D_T_3 = 0b00010000;
const unsigned char Matrix::D_T_4 = 0b00010000;
const unsigned char Matrix::D_T_5 = 0b00010000;
const unsigned char Matrix::D_T_6 = 0b00010000;
const unsigned char Matrix::D_T_7 = 0b00010000;

const unsigned char Matrix::D_U_0 = 0b10000010;
const unsigned char Matrix::D_U_1 = 0b10000010;
const unsigned char Matrix::D_U_2 = 0b10000010;
const unsigned char Matrix::D_U_3 = 0b10000010;
const unsigned char Matrix::D_U_4 = 0b10000010;
const unsigned char Matrix::D_U_5 = 0b10000010;
const unsigned char Matrix::D_U_6 = 0b01000100;
const unsigned char Matrix::D_U_7 = 0b00111000;

const unsigned char Matrix::D_V_0 = 0b10000010;
const unsigned char Matrix::D_V_1 = 0b10000010;
const unsigned char Matrix::D_V_2 = 0b10000010;
const unsigned char Matrix::D_V_3 = 0b01000100;
const unsigned char Matrix::D_V_4 = 0b01000100;
const unsigned char Matrix::D_V_5 = 0b00101000;
const unsigned char Matrix::D_V_6 = 0b00101000;
const unsigned char Matrix::D_V_7 = 0b00010000;

const unsigned char Matrix::D_W_0 = 0b10010010;
const unsigned char Matrix::D_W_1 = 0b10010010;
const unsigned char Matrix::D_W_2 = 0b10010010;
const unsigned char Matrix::D_W_3 = 0b10101010;
const unsigned char Matrix::D_W_4 = 0b10101010;
const unsigned char Matrix::D_W_5 = 0b11000110;
const unsigned char Matrix::D_W_6 = 0b11000110;
const unsigned char Matrix::D_W_7 = 0b10000010;

const unsigned char Matrix::D_X_0 = 0b10000010;
const unsigned char Matrix::D_X_1 = 0b01000100;
const unsigned char Matrix::D_X_2 = 0b00101000;
const unsigned char Matrix::D_X_3 = 0b00010000;
const unsigned char Matrix::D_X_4 = 0b00101000;
const unsigned char Matrix::D_X_5 = 0b01000100;
const unsigned char Matrix::D_X_6 = 0b10000010;
const unsigned char Matrix::D_X_7 = 0b10000010;

const unsigned char Matrix::D_Y_0 = 0b10000010;
const unsigned char Matrix::D_Y_1 = 0b01000100;
const unsigned char Matrix::D_Y_2 = 0b00101000;
const unsigned char Matrix::D_Y_3 = 0b00010000;
const unsigned char Matrix::D_Y_4 = 0b00010000;
const unsigned char Matrix::D_Y_5 = 0b00010000;
const unsigned char Matrix::D_Y_6 = 0b00010000;
const unsigned char Matrix::D_Y_7 = 0b00010000;

const unsigned char Matrix::D_Z_0 = 0b11111110;
const unsigned char Matrix::D_Z_1 = 0b00000100;
const unsigned char Matrix::D_Z_2 = 0b00001000;
const unsigned char Matrix::D_Z_3 = 0b00010000;
const unsigned char Matrix::D_Z_4 = 0b00100000;
const unsigned char Matrix::D_Z_5 = 0b01000000;
const unsigned char Matrix::D_Z_6 = 0b10000000;
const unsigned char Matrix::D_Z_7 = 0b11111110;

const unsigned char* const Matrix::D_0 = new unsigned char[8]{D_0_0, D_0_1, D_0_2, D_0_3, D_0_4, D_0_5, D_0_6, D_0_7};
const unsigned char* const Matrix::D_1 = new unsigned char[8]{D_1_0, D_1_1, D_1_2, D_1_3, D_1_4, D_1_5, D_1_6, D_1_7};
const unsigned char* const Matrix::D_2 = new unsigned char[8]{D_2_0, D_2_1, D_2_2, D_2_3, D_2_4, D_2_5, D_2_6, D_2_7};
const unsigned char* const Matrix::D_3 = new unsigned char[8]{D_3_0, D_3_1, D_3_2, D_3_3, D_3_4, D_3_5, D_3_6, D_3_7};
const unsigned char* const Matrix::D_4 = new unsigned char[8]{D_4_0, D_4_1, D_4_2, D_4_3, D_4_4, D_4_5, D_4_6, D_4_7};
const unsigned char* const Matrix::D_5 = new unsigned char[8]{D_5_0, D_5_1, D_5_2, D_5_3, D_5_4, D_5_5, D_5_6, D_5_7};
const unsigned char* const Matrix::D_6 = new unsigned char[8]{D_6_0, D_6_1, D_6_2, D_6_3, D_6_4, D_6_5, D_6_6, D_6_7};
const unsigned char* const Matrix::D_7 = new unsigned char[8]{D_7_0, D_7_1, D_7_2, D_7_3, D_7_4, D_7_5, D_7_6, D_7_7};
const unsigned char* const Matrix::D_8 = new unsigned char[8]{D_8_0, D_8_1, D_8_2, D_8_3, D_8_4, D_8_5, D_8_6, D_8_7};
const unsigned char* const Matrix::D_9 = new unsigned char[8]{D_9_0, D_9_1, D_9_2, D_9_3, D_9_4, D_9_5, D_9_6, D_9_7};
const unsigned char* const Matrix::D_A = new unsigned char[8]{D_A_0, D_A_1, D_A_2, D_A_3, D_A_4, D_A_5, D_A_6, D_A_7};
const unsigned char* const Matrix::D_B = new unsigned char[8]{D_B_0, D_B_1, D_B_2, D_B_3, D_B_4, D_B_5, D_B_6, D_B_7};
const unsigned char* const Matrix::D_C = new unsigned char[8]{D_C_0, D_C_1, D_C_2, D_C_3, D_C_4, D_C_5, D_C_6, D_C_7};
const unsigned char* const Matrix::D_D = new unsigned char[8]{D_D_0, D_D_1, D_D_2, D_D_3, D_D_4, D_D_5, D_D_6, D_D_7};
const unsigned char* const Matrix::D_E = new unsigned char[8]{D_E_0, D_E_1, D_E_2, D_E_3, D_E_4, D_E_5, D_E_6, D_E_7};
const unsigned char* const Matrix::D_F = new unsigned char[8]{D_F_0, D_F_1, D_F_2, D_F_3, D_F_4, D_F_5, D_F_6, D_F_7};
const unsigned char* const Matrix::D_G = new unsigned char[8]{D_G_0, D_G_1, D_G_2, D_G_3, D_G_4, D_G_5, D_G_6, D_G_7};
const unsigned char* const Matrix::D_H = new unsigned char[8]{D_H_0, D_H_1, D_H_2, D_H_3, D_H_4, D_H_5, D_H_6, D_H_7};
const unsigned char* const Matrix::D_I = new unsigned char[8]{D_I_0, D_I_1, D_I_2, D_I_3, D_I_4, D_I_5, D_I_6, D_I_7};
const unsigned char* const Matrix::D_J = new unsigned char[8]{D_J_0, D_J_1, D_J_2, D_J_3, D_J_4, D_J_5, D_J_6, D_J_7};
const unsigned char* const Matrix::D_K = new unsigned char[8]{D_K_0, D_K_1, D_K_2, D_K_3, D_K_4, D_K_5, D_K_6, D_K_7};
const unsigned char* const Matrix::D_L = new unsigned char[8]{D_L_0, D_L_1, D_L_2, D_L_3, D_L_4, D_L_5, D_L_6, D_L_7};
const unsigned char* const Matrix::D_M = new unsigned char[8]{D_M_0, D_M_1, D_M_2, D_M_3, D_M_4, D_M_5, D_M_6, D_M_7};
const unsigned char* const Matrix::D_N = new unsigned char[8]{D_N_0, D_N_1, D_N_2, D_N_3, D_N_4, D_N_5, D_N_6, D_N_7};
const unsigned char* const Matrix::D_O = new unsigned char[8]{D_O_0, D_O_1, D_O_2, D_O_3, D_O_4, D_O_5, D_O_6, D_O_7};
const unsigned char* const Matrix::D_P = new unsigned char[8]{D_P_0, D_P_1, D_P_2, D_P_3, D_P_4, D_P_5, D_P_6, D_P_7};
const unsigned char* const Matrix::D_Q = new unsigned char[8]{D_Q_0, D_Q_1, D_Q_2, D_Q_3, D_Q_4, D_Q_5, D_Q_6, D_Q_7};
const unsigned char* const Matrix::D_R = new unsigned char[8]{D_R_0, D_R_1, D_R_2, D_R_3, D_R_4, D_R_5, D_R_6, D_R_7};
const unsigned char* const Matrix::D_S = new unsigned char[8]{D_S_0, D_S_1, D_S_2, D_S_3, D_S_4, D_S_5, D_S_6, D_S_7};
const unsigned char* const Matrix::D_T = new unsigned char[8]{D_T_0, D_T_1, D_T_2, D_T_3, D_T_4, D_T_5, D_T_6, D_T_7};
const unsigned char* const Matrix::D_U = new unsigned char[8]{D_U_0, D_U_1, D_U_2, D_U_3, D_U_4, D_U_5, D_U_6, D_U_7};
const unsigned char* const Matrix::D_V = new unsigned char[8]{D_V_0, D_V_1, D_V_2, D_V_3, D_V_4, D_V_5, D_V_6, D_V_7};
const unsigned char* const Matrix::D_W = new unsigned char[8]{D_W_0, D_W_1, D_W_2, D_W_3, D_W_4, D_W_5, D_W_6, D_W_7};
const unsigned char* const Matrix::D_X = new unsigned char[8]{D_X_0, D_X_1, D_X_2, D_X_3, D_X_4, D_X_5, D_X_6, D_X_7};
const unsigned char* const Matrix::D_Y = new unsigned char[8]{D_Y_0, D_Y_1, D_Y_2, D_Y_3, D_Y_4, D_Y_5, D_Y_6, D_Y_7};
const unsigned char* const Matrix::D_Z = new unsigned char[8]{D_Z_0, D_Z_1, D_Z_2, D_Z_3, D_Z_4, D_Z_5, D_Z_6, D_Z_7};

const unsigned char** const Matrix::numbers = new const unsigned char*[10]{D_0, D_1, D_2, D_3, D_4, D_5, D_6, D_7, D_8, D_9};
const unsigned char** const Matrix::letters = new const unsigned char*[26]{D_A, D_B, D_C, D_D, D_E, D_F, D_G, D_H, D_I, D_J, D_K, D_L, D_M, D_N, D_O, D_P, D_Q, D_R, D_S, D_T, D_U, D_V, D_W, D_X, D_Y, D_Z};

Matrix::Matrix(unsigned char* _rows, unsigned char* _cols){
  rows = _rows;
  cols = _cols;
  for(unsigned char i = 0; i < 8; i++){
    pinMode(rows[i], INPUT);
    pinMode(cols[i], OUTPUT);
    digitalWrite(rows[i], LOW);
    digitalWrite(cols[i], HIGH);
    pixels[i] = 0b00000000;
  }
  clear();
  col = 0;
}
void Matrix::setPixel(unsigned char y, unsigned char x, unsigned char val){
  if(val == 1){
    pixels[y] |= (0b10000000 >> x);
  }else if(val == 0){
    pixels[y] &= (0b01111111 >> x);
  }
}
void Matrix::clear(){
  for(unsigned char i = 0; i < 8; i++){
    digitalWrite(rows[i], LOW);
    digitalWrite(cols[i], HIGH);
  }
}
void Matrix::update(){
  digitalWrite(Matrix::matrix->cols[Matrix::matrix->col], HIGH);
  Matrix::matrix->col++;
  if(Matrix::matrix->col == 8){
    Matrix::matrix->col = 0;
  }
  for(unsigned char i = 0; i < 8; i++){
    if(Matrix::matrix->getColVal(Matrix::matrix->pixels[i], Matrix::matrix->col) == 1){
      digitalWrite(Matrix::matrix->rows[i], HIGH);
    }else{
      digitalWrite(Matrix::matrix->rows[i], LOW);
    }
  }
  digitalWrite(Matrix::matrix->cols[Matrix::matrix->col], LOW);
}
void Matrix::startUpdateManager(unsigned char interrupt_pin, unsigned char interrupt){
  Matrix::matrix = this;
  pinMode(interrupt_pin, OUTPUT);
  tone(interrupt_pin, 500);
  attachInterrupt(interrupt, Matrix::update, RISING);
}
void Matrix::stopUpdateManager(unsigned char interrupt_pin, unsigned char interrupt){
  noTone(interrupt_pin);
  detachInterrupt(interrupt);
}
void Matrix::printSymbol(unsigned char* symbol){
  for(unsigned char i = 0; i < 8; i++){
    for(unsigned char j = 0; j < 8; j++){
      Serial.print((int) getColVal(symbol[i], j));
      Serial.print(" ");
    }
    Serial.println();
  }
  Serial.println();
}
void Matrix::printPixels(){
  for(unsigned char i = 0; i < 8; i++){
    for(unsigned char j = 0; j < 8; j++){
      Serial.print((int) getColVal(pixels[i], j));
      Serial.print(" ");
    }
    Serial.println();
  }
  Serial.println();
}
void Matrix::displaySymbol(unsigned char* symbol){
  for(unsigned char i = 0; i < 8; i++){
    pixels[i] = symbol[i];
  }
}
unsigned char* Matrix::getNewSymbol(){
  unsigned char* temp_symbol = new unsigned char[8];
  return temp_symbol;
}
unsigned char* Matrix::getEditableSymbol(const unsigned char* symbol){
  unsigned char* temp_symbol = getNewSymbol();
  for(unsigned char i = 0; i < 8; i++){
    temp_symbol[i] = symbol[i];
  }
  return temp_symbol;
}
unsigned char* Matrix::combineSymbols(unsigned char* symbol1, unsigned char* symbol2){
  unsigned char* temp_symbol = getNewSymbol();
  for(unsigned char i = 0; i < 8; i++){
    temp_symbol[i] = symbol1[i] | symbol2[i];
  }
  return temp_symbol;
}
unsigned char* Matrix::shiftSymbol(unsigned char* symbol, char shift_up, char shift_right){
  unsigned char* temp_symbol = getNewSymbol();
  for(unsigned char i = 0; i < 8; i++){
    if(i < (-shift_up) || i >= (8 - shift_up)){
      temp_symbol[i] = 0b00000000;
    }else{
      if(shift_right >= 0){
        temp_symbol[i] = symbol[shift_up + i] >> shift_right;
      }else{
        temp_symbol[i] = symbol[shift_up + i] << -shift_right;
      }
    }
  }
  return temp_symbol;
}
unsigned char* Matrix::transitionY(unsigned char* symbol1, unsigned char* symbol2, char shift_up){
  return combineSymbols(shiftSymbol(symbol1, shift_up, 0), shiftSymbol(symbol2, (shift_up - 8), 0));
}
unsigned char* Matrix::transitionX(unsigned char* symbol1, unsigned char* symbol2, char shift_right){
  return combineSymbols(shiftSymbol(symbol1, 0, shift_right), shiftSymbol(symbol2, 0, (shift_right - 8)));
}
unsigned char Matrix::getColVal(unsigned char row, unsigned char col){
  return (row & (0b10000000 >> col)) >> (7 - col);
}
void Matrix::display2Number(unsigned char number){
  unsigned char num1 = number / 10;
  unsigned char num2 = number - num1 * 10;
  unsigned char* num1_symbol = getEditableSymbol(numbers[num1]);
  unsigned char* num2_symbol = getEditableSymbol(numbers[num2]);
  displaySymbol(combineSymbols(num1_symbol, shiftSymbol(num2_symbol, 0, 4)));
  delete(num1_symbol);
  delete(num2_symbol);
}
void Matrix::timer2Number(unsigned char start_time){
  for(unsigned char i = start_time; i > 0; i--){
    display2Number(i);
    delay(1000);
  }
}
void Matrix::alphabet(){
  for(unsigned char i = 0; i < 26; i++){
    displaySymbol(getEditableSymbol(Matrix::letters[i]));
    delay(1000);
  }
}
