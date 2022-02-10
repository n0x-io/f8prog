/* keycodes taken from https://usb.org/sites/default/files/hut1_22.pdf 
 * See also: https://github.com/benblazak/ergodox-firmware/blob/master/src/lib/usb/usage-page/keyboard.h 
 * */

#define KEY_ErrorRollOver           0x01
#define KEY_POSTFail                0x02
#define KEY_ErrorUndefined          0x03
#define KEY_a_A                     0x04
#define KEY_b_B                     0x05
#define KEY_c_C                     0x06
#define KEY_d_D                     0x07
#define KEY_e_E                     0x08
#define KEY_f_F                     0x09
#define KEY_g_G                     0x0A
#define KEY_h_H                     0x0B
#define KEY_i_I                     0x0C
#define KEY_j_J                     0x0D
#define KEY_k_K                     0x0E
#define KEY_l_L                     0x0F
#define KEY_m_M                     0x10
#define KEY_n_N                     0x11
#define KEY_o_O                     0x12
#define KEY_p_P                     0x13
#define KEY_q_Q                     0x14
#define KEY_r_R                     0x15
#define KEY_s_S                     0x16
#define KEY_t_T                     0x17
#define KEY_u_U                     0x18
#define KEY_v_V                     0x19
#define KEY_w_W                     0x1A
#define KEY_x_X                     0x1B
#define KEY_y_Y                     0x1C
#define KEY_z_Z                     0x1D
#define KEY_1_Exclamation           0x1E
#define KEY_2_At                    0x1F
#define KEY_3_Pound                 0x20
#define KEY_4_Dollar                0x21
#define KEY_5_Percent               0x22
#define KEY_6_Caret                 0x23
#define KEY_7_Ampersand             0x24
#define KEY_8_Asterisk              0x25
#define KEY_9_LeftParenthesis       0x26
#define KEY_0_RightParenthesis      0x27
#define KEY_ReturnEnter             0x28
#define KEY_Escape                  0x29
#define KEY_DeleteBackspace         0x2A
#define KEY_Tab                     0x2B
#define KEY_Spacebar                0x2C
#define KEY_Dash_Underscore         0x2D
#define KEY_Equal_Plus              0x2E
#define KEY_LeftBracket_LeftBrace   0x2F
#define KEY_RightBracket_RightBrace 0x30
#define KEY_Backslash_Pipe          0x31
#define KEY_NonUS_Pound_Tilde       0x32
#define KEY_Semicolon_Colon         0x33
#define KEY_SingleQuote_DoubleQuote 0x34
#define KEY_GraveAccent_Tilde       0x35
#define KEY_Comma_LessThan          0x36
#define KEY_Period_GreaterThan      0x37
#define KEY_Slash_Question          0x38
#define KEY_CapsLock                0x39
#define KEY_F1                      0x3A
#define KEY_F2                      0x3B
#define KEY_F3                      0x3C
#define KEY_F4                      0x3D
#define KEY_F5                      0x3E
#define KEY_F6                      0x3F
#define KEY_F7                      0x40
#define KEY_F8                      0x41
#define KEY_F9                      0x42
#define KEY_F10                     0x43
#define KEY_F11                     0x44
#define KEY_F12                     0x45
#define KEY_PrintScreen             0x46
#define KEY_ScrollLock              0x47
#define KEY_Pause                   0x48
#define KEY_Insert                  0x49
#define KEY_Home                    0x4A
#define KEY_PageUp                  0x4B
#define KEY_DeleteForward           0x4C
#define KEY_End                     0x4D
#define KEY_PageDown                0x4E
#define KEY_RightArrow              0x4F
#define KEY_LeftArrow               0x50
#define KEY_DownArrow               0x51
#define KEY_UpArrow                 0x52

#define KEYPAD_NumLock_Clear        0x53
#define KEYPAD_Slash                0x54
#define KEYPAD_Asterisk             0x55
#define KEYPAD_Minus                0x56
#define KEYPAD_Plus                 0x57
#define KEYPAD_ENTER                0x58
#define KEYPAD_1_End                0x59
#define KEYPAD_2_DownArrow          0x5A
#define KEYPAD_3_PageDown           0x5B
#define KEYPAD_4_LeftArrow          0x5C
#define KEYPAD_5                    0x5D
#define KEYPAD_6_RightArrow         0x5E
#define KEYPAD_7_Home               0x5F
#define KEYPAD_8_UpArrow            0x60
#define KEYPAD_9_PageUp             0x61
#define KEYPAD_0_Insert             0x62
#define KEYPAD_Period_Delete        0x63

#define KEY_NonUS_Backslash_Pipe    0x64
#define KEY_Application             0x65
#define KEY_Power                   0x66

#define KEYPAD_Equal                0x67

#define KEY_F13                     0x68
#define KEY_F14                     0x69
#define KEY_F15                     0x6A
#define KEY_F16                     0x6B
#define KEY_F17                     0x6C
#define KEY_F18                     0x6D
#define KEY_F19                     0x6E
#define KEY_F20                     0x6F
#define KEY_F21                     0x70
#define KEY_F22                     0x71
#define KEY_F23                     0x72
#define KEY_F24                     0x73
#define KEY_Execute                 0x74
#define KEY_Help                    0x75
#define KEY_Menu                    0x76
#define KEY_Select                  0x77
#define KEY_Stop                    0x78
#define KEY_Again                   0x79
#define KEY_Undo                    0x7A
#define KEY_Cut                     0x7B
#define KEY_Copy                    0x7C
#define KEY_Paste                   0x7D
#define KEY_Find                    0x7E
#define KEY_Mute                    0x7F
#define KEY_VolumeUp                0x80
#define KEY_VolumeDown              0x81
#define KEY_LockingCapsLock         0x82
#define KEY_LockingNumLock          0x83
#define KEY_LockingScrollLock       0x84

#define KEYPAD_Comma                0x85
#define KEYPAD_EqualSign            0x86

#define KEY_International1          0x87
#define KEY_International2          0x88
#define KEY_International3          0x89
#define KEY_International4          0x8A
#define KEY_International5          0x8B
#define KEY_International6          0x8C
#define KEY_International7          0x8D
#define KEY_International8          0x8E
#define KEY_International9          0x8F
#define KEY_LANG1                   0x90
#define KEY_LANG2                   0x91
#define KEY_LANG3                   0x92
#define KEY_LANG4                   0x93
#define KEY_LANG5                   0x94
#define KEY_LANG6                   0x95
#define KEY_LANG7                   0x96
#define KEY_LANG8                   0x97
#define KEY_LANG9                   0x98
#define KEY_AlternateErase          0x99
#define KEY_SysReq_Attention        0x9A
#define KEY_Cancel                  0x9B
#define KEY_Clear                   0x9C
#define KEY_Prior                   0x9D
#define KEY_Return                  0x9E
#define KEY_Separator               0x9F
#define KEY_Out                     0xA0
#define KEY_Oper                    0xA1
#define KEY_Clear_Again             0xA2
#define KEY_CrSel_Props             0xA3
#define KEY_ExSel                   0xA4
//      (Reserved)            0xA5..0xAF
#define KEYPAD_00                   0xB0
#define KEYPAD_000                  0xB1

#define KEY_ThousandsSeparator      0xB2
#define KEY_DecimalSeparator        0xB3
#define KEY_CurrencyUnit            0xB4
#define KEY_CurrencySubunit         0xB5

#define KEYPAD_LeftParenthesis      0xB6
#define KEYPAD_RightParenthesis     0xB7
#define KEYPAD_LeftBrace            0xB8
#define KEYPAD_RightBrace           0xB9

#define KEYPAD_Tab                  0xBA
#define KEYPAD_Backspace            0xBB
#define KEYPAD_A                    0xBC
#define KEYPAD_B                    0xBD
#define KEYPAD_C                    0xBE
#define KEYPAD_D                    0xBF
#define KEYPAD_E                    0xC0
#define KEYPAD_F                    0xC1
#define KEYPAD_XOR                  0xC2
#define KEYPAD_Caret                0xC3
#define KEYPAD_Percent              0xC4
#define KEYPAD_LessThan             0xC5
#define KEYPAD_GreaterThan          0xC6
#define KEYPAD_Ampersand            0xC7
#define KEYPAD_AmpersandAmpersand   0xC8
#define KEYPAD_Pipe                 0xC9
#define KEYPAD_PipePipe             0xCA
#define KEYPAD_Colon                0xCB
#define KEYPAD_Pound                0xCC
#define KEYPAD_Space                0xCD
#define KEYPAD_At                   0xCE
#define KEYPAD_Exclamation          0xCF
#define KEYPAD_MemoryStore          0xD0
#define KEYPAD_MemoryRecall         0xD1
#define KEYPAD_MemoryClear          0xD2
#define KEYPAD_MemoryAdd            0xD3
#define KEYPAD_MemorySubtract       0xD4
#define KEYPAD_MemoryMultiply       0xD5
#define KEYPAD_MemoryDivide         0xD6
#define KEYPAD_PlusMinus            0xD7
#define KEYPAD_Clear                0xD8
#define KEYPAD_ClearEntry           0xD9
#define KEYPAD_Binary               0xDA
#define KEYPAD_Octal                0xDB
#define KEYPAD_Decimal              0xDC
#define KEYPAD_Hexadecimal          0xDD
//     (Reserved)             0xDE..0xDF
#define KEY_LeftControl             0xE0
#define KEY_LeftShift               0xE1
#define KEY_LeftAlt                 0xE2
#define KEY_LeftGUI                 0xE3
#define KEY_RightControl            0xE4
#define KEY_RightShift              0xE5
#define KEY_RightAlt                0xE6
#define KEY_RightGUI                0xE7