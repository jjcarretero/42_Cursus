/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycodes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 12:24:16 by jcarrete          #+#    #+#             */
/*   Updated: 2021/02/11 21:42:28 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYCODES_H
# define KEYCODES_H

# ifdef __APPLE__
#  define KEY_SHIFT_L					0x101
#  define KEY_SHIFT_R					0x102
#  define KEY_CONTROL_L					0x100
#  define KEY_CONTROL_R					0x10D
#  define KEY_OPT_L						0x105
#  define KEY_OPT_R						0x106
#  define KEY_CMD_L						0x103
#  define KEY_CMD_R						0x104
#  define KEY_SPACE						0x31

#  define KEY_ESC						0x35
#  define KEY_F1						0x7A
#  define KEY_F2						0x78
#  define KEY_F3						0x63
#  define KEY_F4						0x76
#  define KEY_F5						0x60
#  define KEY_F6						0x61
#  define KEY_F7						0x62
#  define KEY_F8						0x64
#  define KEY_F9						0x65
#  define KEY_F10						0x6D
#  define KEY_F11						0x67
#  define KEY_F12						0x6F
#  define KEY_EJECT						0x92
#  define KEY_F13						0x69
#  define KEY_F14						0x6B
#  define KEY_F15						0x71
#  define KEY_F16						0x6A
#  define KEY_F17						0x40
#  define KEY_F18						0x4F
#  define KEY_F19						0x50

#  define KEY_AUX_FN					0x117
#  define KEY_AUX_PGUP					0x74
#  define KEY_AUX_START					0x73
#  define KEY_AUX_SUPR					0x75
#  define KEY_AUX_PGDN					0x79
#  define KEY_AUX_END					0x77
#  define KEY_AUX_LFAR					0x7B
#  define KEY_AUX_UPAR					0x7E
#  define KEY_AUX_RTAR					0x7C
#  define KEY_AUX_DNAR					0x7D

#  define KEY_NUM_LOCK					0x47
#  define KEY_NUM_EQUAL					0x51
#  define KEY_NUM_DIV					0x4B
#  define KEY_NUM_MULT					0x43
#  define KEY_NUM_SUB					0x4E
#  define KEY_NUM_ADD					0x45
#  define KEY_NUM_ENTER					0x4C
#  define KEY_NUM_DEC					0x41
#  define KEY_NUM_0						0x52
#  define KEY_NUM_1						0x53
#  define KEY_NUM_2						0x54
#  define KEY_NUM_3						0x55
#  define KEY_NUM_4						0x56
#  define KEY_NUM_5						0x57
#  define KEY_NUM_6						0x58
#  define KEY_NUM_7						0x59
#  define KEY_NUM_8						0x5B
#  define KEY_NUM_9						0x5C

#  define KEY_TAB						0x30
#  define KEY_CAPS_LOCK					0x110
#  define KEY_RETURN					0x33
#  define KEY_ENTER						0x24

#  define KEY_ORDINAL					0xA
#  define KEY_1							0x12
#  define KEY_2							0x13
#  define KEY_3							0x14
#  define KEY_4							0x15
#  define KEY_5							0x17
#  define KEY_6							0x16
#  define KEY_7							0x1A
#  define KEY_8							0x1C
#  define KEY_9							0x19
#  define KEY_0							0x1D
#  define KEY_APOSTROPHE				0x1B
#  define KEY_EXCLAMATION				0x18

#  define KEY_Q							0xC
#  define KEY_W							0xD
#  define KEY_E							0xE
#  define KEY_R							0xF
#  define KEY_T							0x11
#  define KEY_Y							0x10
#  define KEY_U							0x20
#  define KEY_I							0x22
#  define KEY_O							0x1F
#  define KEY_P							0x23
#  define KEY_GRAVE_ACCENT				0x21
#  define KEY_PLUS						0x1E

#  define KEY_A							0x0
#  define KEY_S							0x1
#  define KEY_D							0x2
#  define KEY_F							0x3
#  define KEY_G							0x5
#  define KEY_H							0x4
#  define KEY_J							0x26
#  define KEY_K							0x28
#  define KEY_L							0x25
#  define KEY_N_TILDE					0x29
#  define KEY_ACUTE_ACCENT				0x27
#  define KEY_CEDILLA					0x2A

#  define KEY_LESS_THAN					0x32
#  define KEY_Z							0x6
#  define KEY_X							0x7
#  define KEY_C							0x8
#  define KEY_V							0x9
#  define KEY_B							0xB
#  define KEY_N							0x2D
#  define KEY_M							0x2E
#  define KEY_COMMA						0x2B
#  define KEY_DOT						0x2F
#  define KEY_MINUS						0x2C

# elif defined __unix__
#  define KEY_SHIFT_L					0xFFE1
#  define KEY_SHIFT_R					0xFFE2
#  define KEY_CONTROL_L					0xFFE3
#  define KEY_CONTROL_R					0xFFE4
#  define KEY_ALT_L						0xFFE9
#  define KEY_ALT_R						0xFFEA
#  define KEY_CAPS_LOCK					0xFFE5
#  define KEY_SPACE						0x020

#  define KEY_ESC						0xFF1B
#  define KEY_F1						0xFFBE
#  define KEY_F2						0xFFBF
#  define KEY_F3						0xFFC0
#  define KEY_F4						0xFFC1
#  define KEY_F5						0xFFC2
#  define KEY_F6						0xFFC3
#  define KEY_F7						0xFFC4
#  define KEY_F8						0xFFC5
#  define KEY_F9						0xFFC6
#  define KEY_F10						0xFFC7
#  define KEY_F11						0xFFC8
#  define KEY_F12						0xFFC9
#  define KEY_PRT_SC					0xFF61
#  define KEY_SCR_LOCK					0xFF14
#  define KEY_PAUSE						0xFF13

#  define KEY_AUX_INSERT				0xFF63
#  define KEY_AUX_HOME					0xFF50
#  define KEY_AUX_PGDN					0xFF55
#  define KEY_AUX_SUPR					0xFFFF
#  define KEY_AUX_END					0xFF57
#  define KEY_AUX_PGUP					0xFF56
#  define KEY_AUX_LFAR					0xFF51
#  define KEY_AUX_UPAR					0xFF52
#  define KEY_AUX_RTAR					0xFF53
#  define KEY_AUX_DNAR					0xFF54

#  define KEY_NUM_LOCK					0xFF7F
#  define KEY_NUM_DIV					0xFFAF
#  define KEY_NUM_MULT					0xFFAA
#  define KEY_NUM_SUB					0xFFAD
#  define KEY_NUM_ADD					0xFFAB
#  define KEY_NUM_ENTER					0xFF8D
#  define KEY_NUM_DEL					0xFF9F
#  define KEY_NUM_0						0xFF9E
#  define KEY_NUM_1						0xFF9C
#  define KEY_NUM_2						0xFF99
#  define KEY_NUM_3						0xFF9B
#  define KEY_NUM_4						0xFF96
#  define KEY_NUM_5						0xFF9D
#  define KEY_NUM_6						0xFF98
#  define KEY_NUM_7						0xFF95
#  define KEY_NUM_8						0xFF97
#  define KEY_NUM_9						0xFF9A

#  define KEY_TAB						0xFF09
#  define KEY_CAP_LOCK					0xFFE5
#  define KEY_WIN_L						0xFFEB
#  define KEY_WIN_R						0xFFEC
#  define KEY_MENU						0xFF67
#  define KEY_RETURN					0xFF08
#  define KEY_ENTER						0xFF0D

#  define KEY_ORDINAL					0xBA
#  define KEY_1							0x31
#  define KEY_2							0x32
#  define KEY_3							0x33
#  define KEY_4							0x34
#  define KEY_5							0x35
#  define KEY_6							0x36
#  define KEY_7							0x37
#  define KEY_8							0x38
#  define KEY_9							0x39
#  define KEY_0							0x30
#  define KEY_APOSTROPHE				0x27
#  define KEY_EXCLAMATION				0xA1

#  define KEY_Q							0x71
#  define KEY_W							0x77
#  define KEY_E							0x65
#  define KEY_R							0x72
#  define KEY_T							0x74
#  define KEY_Y							0x79
#  define KEY_U							0x75
#  define KEY_I							0x69
#  define KEY_O							0x6F
#  define KEY_P							0x70
#  define KEY_GRAVE_ACCENT				0xFE50
#  define KEY_PLUS						0x2B

#  define KEY_A							0x61
#  define KEY_S							0x73
#  define KEY_D							0x64
#  define KEY_F							0x66
#  define KEY_G							0x67
#  define KEY_H							0x68
#  define KEY_J							0x6A
#  define KEY_K							0x6B
#  define KEY_L							0x6C
#  define KEY_N_TILDE					0xF1
#  define KEY_ACUTE_ACCENT				0xFE51
#  define KEY_CEDILLA					0xE7

#  define KEY_Z							0x7A
#  define KEY_X							0x78
#  define KEY_C							0x63
#  define KEY_V							0x76
#  define KEY_B							0x62
#  define KEY_N							0x6E
#  define KEY_M							0x6D
#  define KEY_COMMA						0x2C
#  define KEY_DOT						0x2E
#  define KEY_MINUS						0x2D
# endif
#endif
