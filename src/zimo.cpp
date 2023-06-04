#include <stdio.h>
#include "hanzi.h"

/*
        宋体小四 16*16
*/
int size_si[2] = {16, 16};

char cai[] = { //蔡
	0x04,0x40,0xFF,0xFE,0x04,0x40,0x10,0x80,0x1E,0xF8,0x22,0x88,0x54,0x50,0x28,0x20,
	0x17,0xD8,0x20,0x06,0xDF,0xF0,0x01,0x00,0x11,0x10,0x21,0x08,0x45,0x04,0x02,0x00
};

char yu[] = { //宇
	0x02,0x00,0x01,0x00,0x7F,0xFE,0x40,0x02,0x80,0x04,0x3F,0xF8,0x01,0x00,0x01,0x00,
	0x01,0x00,0xFF,0xFE,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x05,0x00,0x02,0x00
};

char chen[] = { //辰
	0x00,0x00,0x3F,0xFC,0x20,0x00,0x20,0x00,0x2F,0xF8,0x20,0x00,0x20,0x00,0x3F,0xFC,
	0x24,0x80,0x24,0x88,0x24,0x50,0x24,0x20,0x44,0x10,0x45,0x08,0x86,0x06,0x04,0x00
};

char yi[] = { //一
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFE,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

char er[] = { //二
        0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFE,0x00,0x00,0x00,0x00,0x00,0x00
};

char san[] = { //三
        0x00,0x00,0x00,0x00,0x7F,0xFC,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xF8,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFE,0x00,0x00,0x00,0x00
};

char si[] = { //四
        0x00,0x00,0x00,0x00,0x7F,0xFC,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,
        0x48,0x44,0x48,0x3C,0x50,0x04,0x60,0x04,0x40,0x04,0x7F,0xFC,0x40,0x04,0x00,0x00
};

char wu[] = { //五
        0x00,0x00,0x7F,0xFC,0x02,0x00,0x02,0x00,0x02,0x00,0x02,0x00,0x3F,0xF0,0x04,0x10,
        0x04,0x10,0x04,0x10,0x04,0x10,0x08,0x10,0x08,0x10,0x08,0x10,0xFF,0xFE,0x00,0x00
};

char liu[] = { //六
        0x02,0x00,0x01,0x00,0x00,0x80,0x00,0x80,0x00,0x00,0xFF,0xFE,0x00,0x00,0x00,0x00,
        0x04,0x40,0x04,0x20,0x08,0x10,0x08,0x08,0x10,0x08,0x20,0x04,0x40,0x04,0x00,0x00
};

char qi[] = { //七
        0x02,0x00,0x02,0x00,0x02,0x00,0x02,0x00,0x02,0x00,0x02,0x3C,0x07,0xC0,0xFA,0x00,
        0x02,0x00,0x02,0x00,0x02,0x00,0x02,0x04,0x02,0x04,0x02,0x04,0x01,0xFC,0x00,0x00
};

char ba[] = { //八
        0x00,0x00,0x00,0x40,0x04,0x40,0x04,0x40,0x04,0x40,0x04,0x40,0x04,0x40,0x04,0x20,
        0x08,0x20,0x08,0x20,0x08,0x10,0x10,0x10,0x10,0x08,0x20,0x08,0x20,0x04,0x40,0x02
};

char jiu[] = { //九
        0x04,0x00,0x04,0x00,0x04,0x00,0x04,0x00,0x7F,0xE0,0x04,0x20,0x04,0x20,0x04,0x20,
        0x08,0x20,0x08,0x20,0x08,0x20,0x10,0x22,0x10,0x22,0x20,0x22,0x40,0x1E,0x80,0x00
};

char shi[] = { //十
        0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0xFF,0xFE,0x01,0x00,
        0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00
};

/*
        宋体二号 16*29
*/
int size_er[] = {16, 29};

char yi_erhao[] = { //一
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x1F,0x80,0x1F,0x80,
        0x03,0x80,0x03,0x80,0x03,0x80,0x03,0x80,0x03,0x80,0x03,0x80,0x03,0x80,0x03,0x80,
        0x03,0x80,0x03,0x80,0x03,0x80,0x03,0x80,0x03,0x80,0x03,0x80,0x03,0x80,0x07,0xC0,
        0x1F,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

char er_erhao[] = { //二
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0xE0,0x1C,0xF0,0x38,0x38,
        0x70,0x3C,0x78,0x3C,0x78,0x3C,0x38,0x3C,0x00,0x38,0x00,0x78,0x00,0x70,0x00,0xE0,
        0x01,0xC0,0x03,0x80,0x07,0x00,0x0E,0x00,0x1C,0x0C,0x38,0x1C,0x70,0x1C,0x7F,0xF8,
        0x7F,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

char san_erhao[] = { //三
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0xE0,0x3C,0xF0,0x38,0x70,
        0x78,0x78,0x78,0x38,0x38,0x38,0x00,0x78,0x00,0x70,0x01,0xE0,0x07,0xC0,0x01,0xF0,
        0x00,0x78,0x00,0x38,0x00,0x3C,0x30,0x3C,0x78,0x3C,0x78,0x38,0x78,0x38,0x3C,0xF0,
        0x1F,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

char si_erhao[] = { //四
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0x00,0xF0,0x01,0xF0,
        0x01,0xF0,0x03,0xF0,0x07,0xF0,0x06,0xF0,0x0E,0xF0,0x1C,0xF0,0x18,0xF0,0x30,0xF0,
        0x70,0xF0,0x60,0xF0,0xFF,0xFE,0x00,0xF0,0x00,0xF0,0x00,0xF0,0x00,0xF0,0x00,0xF0,
        0x07,0xFC,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

char wu_erhao[] = { //五
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xF8,0x3F,0xF8,0x38,0x00,
        0x38,0x00,0x38,0x00,0x38,0x00,0x30,0x00,0x3F,0xE0,0x3F,0xF0,0x38,0x78,0x30,0x38,
        0x00,0x3C,0x00,0x3C,0x00,0x3C,0x38,0x3C,0x78,0x3C,0x78,0x38,0x78,0x78,0x3C,0xF0,
        0x1F,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

char liu_erhao[] = { //六
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xF0,0x0F,0x78,0x1C,0x78,
        0x38,0x38,0x38,0x00,0x78,0x00,0x78,0x00,0x77,0xF0,0x7F,0xF8,0x7C,0x38,0x78,0x3C,
        0x78,0x1C,0x70,0x1C,0x70,0x1C,0x78,0x1C,0x78,0x1C,0x38,0x3C,0x3C,0x38,0x1E,0x70,
        0x0F,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

char qi_erhao[] = { //七
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xFC,0x3F,0xFC,0x78,0x18,
        0x70,0x30,0x60,0x70,0x00,0x60,0x00,0xE0,0x00,0xC0,0x01,0xC0,0x01,0xC0,0x03,0x80,
        0x03,0x80,0x03,0x80,0x07,0x80,0x07,0x80,0x07,0x80,0x07,0x80,0x07,0x80,0x07,0x80,
        0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

char ba_erhao[] = { //八
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0xE0,0x3C,0xF0,0x38,0x38,
        0x70,0x3C,0x70,0x1C,0x70,0x1C,0x78,0x38,0x3E,0x38,0x1F,0xF0,0x0F,0xE0,0x1F,0xF0,
        0x38,0xF8,0x70,0x78,0x70,0x3C,0x70,0x1C,0x70,0x1C,0x70,0x1C,0x78,0x38,0x3C,0xF0,
        0x1F,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

char jiu_erhao[] = { //九
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0xE0,0x3C,0xF0,0x38,0x78,
        0x70,0x38,0x70,0x3C,0x70,0x3C,0x70,0x3C,0x70,0x3C,0x70,0x3C,0x78,0x7C,0x3C,0xFC,
        0x1F,0xFC,0x07,0x3C,0x00,0x3C,0x00,0x38,0x00,0x78,0x38,0x70,0x38,0xF0,0x3D,0xE0,
        0x1F,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

char ling_erhao[] = { //零
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0xE0,0x1E,0xF0,0x1C,0x70,
        0x38,0x38,0x38,0x38,0x78,0x3C,0x78,0x3C,0x70,0x3C,0x70,0x3C,0x70,0x3C,0x70,0x3C,
        0x70,0x3C,0x70,0x3C,0x78,0x3C,0x78,0x3C,0x38,0x38,0x38,0x38,0x1C,0x70,0x1E,0xF0,
        0x0F,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

char point_erhao[] = { //小数点
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x00,0x7C,0x00,
        0x3C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

/*
        宋体一号 40*35
*/
int size_yi[2] = {40, 35};

char cai_yi[] = {
        0x00,0x00,0x00,0x00,0x00,0x00,0x1C,0x07,0x00,0x00,0x00,0x0F,0x07,0x80,0x00,0x00,
        0x0E,0x07,0x06,0x00,0x00,0x0E,0x07,0x1F,0x00,0x1F,0xFF,0xFF,0xFF,0x80,0x1C,0x0E,
        0x07,0x00,0x00,0x00,0xCE,0x07,0x00,0x00,0x00,0xFE,0x07,0x00,0x00,0x01,0xFC,0x30,
        0x00,0x00,0x01,0xE1,0xF0,0x1C,0x00,0x01,0xFF,0xFF,0xFE,0x00,0x03,0xC3,0xD8,0x3E,
        0x00,0x03,0xE3,0x9C,0x38,0x00,0x07,0x77,0x8C,0x70,0x00,0x0E,0x7F,0x0E,0xE0,0x00,
        0x0F,0x3F,0x07,0xC0,0x00,0x1F,0xBE,0x07,0xC0,0x00,0x3B,0xDC,0x0F,0xC0,0x00,0x21,
        0xFF,0xFF,0xF0,0x00,0x01,0xFF,0x00,0xFC,0x00,0x00,0xF0,0x00,0x3F,0xC0,0x01,0xE0,
        0x01,0xDF,0xC0,0x07,0xFF,0xFF,0xE7,0x00,0x0F,0x7F,0xFF,0xE0,0x00,0x3C,0x18,0xF6,
        0x00,0x00,0x00,0x3C,0xF3,0xC0,0x00,0x00,0x7C,0xF1,0xF0,0x00,0x00,0xF0,0xF0,0xF8,
        0x00,0x01,0xE0,0xF0,0x3C,0x00,0x03,0xCC,0xF0,0x1E,0x00,0x07,0x0F,0xF0,0x1E,0x00,
        0x1E,0x03,0xE0,0x0E,0x00,0x00,0x01,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

char yu_yi[] = {
        0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xC0,0x00,0x00,0x00,0x01,0xE0,0x00,0x00,0x00,
        0x00,0xF0,0x00,0x00,0x00,0x00,0xF0,0x00,0x00,0x02,0x00,0xF0,0x00,0x00,0x07,0x00,
        0x60,0x0E,0x00,0x07,0xFF,0xFF,0xFF,0x00,0x07,0x00,0x00,0x1F,0x00,0x0F,0x00,0x00,
        0x1C,0x00,0x1F,0x00,0x00,0x18,0x00,0x1E,0x00,0x00,0xF0,0x00,0x00,0x00,0x01,0xE0,
        0x00,0x01,0xFF,0xFF,0xF0,0x00,0x00,0x80,0xE0,0x00,0x00,0x00,0x00,0xE0,0x00,0x00,
        0x00,0x00,0xE0,0x00,0x00,0x00,0x00,0xE0,0x06,0x00,0x00,0x00,0xE0,0x0F,0x00,0x3F,
        0xFF,0xFF,0xFF,0x80,0x18,0x00,0xE0,0x00,0x00,0x00,0x00,0xE0,0x00,0x00,0x00,0x00,
        0xE0,0x00,0x00,0x00,0x00,0xE0,0x00,0x00,0x00,0x00,0xE0,0x00,0x00,0x00,0x00,0xE0,
        0x00,0x00,0x00,0x00,0xE0,0x00,0x00,0x00,0x00,0xE0,0x00,0x00,0x00,0x00,0xE0,0x00,
        0x00,0x00,0x3F,0xE0,0x00,0x00,0x00,0x0F,0xE0,0x00,0x00,0x00,0x03,0xC0,0x00,0x00,
        0x00,0x03,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

char chen_yi[] = {
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x0E,0x00,0x03,0x80,0x00,0x1E,0x00,0x03,0xFF,0xFF,0xFF,0x00,0x03,0x80,
        0x00,0x00,0x00,0x03,0x80,0x00,0x00,0x00,0x03,0x80,0x00,0x20,0x00,0x03,0x80,0x00,
        0x70,0x00,0x03,0x9F,0xFF,0xF8,0x00,0x03,0x8C,0x00,0x00,0x00,0x03,0x80,0x00,0x00,
        0x00,0x03,0x80,0x00,0x00,0x00,0x03,0x80,0x00,0x06,0x00,0x03,0x80,0x00,0x0F,0x00,
        0x03,0xFF,0xFF,0xFF,0x80,0x03,0xBF,0x70,0x00,0x00,0x03,0x8F,0x30,0x30,0x00,0x03,
        0x8F,0x38,0x78,0x00,0x03,0x8F,0x38,0xFC,0x00,0x03,0x8F,0x1D,0xF0,0x00,0x07,0x8F,
        0x1F,0xC0,0x00,0x07,0x0F,0x0F,0x00,0x00,0x07,0x0F,0x0F,0x00,0x00,0x07,0x0F,0x07,
        0x80,0x00,0x0E,0x0F,0x03,0xE0,0x00,0x0E,0x0F,0x1F,0xF0,0x00,0x1C,0x0F,0xF8,0xFE,
        0x00,0x1C,0x0F,0xF0,0x7F,0xC0,0x38,0x0F,0xC0,0x1F,0x00,0x30,0x07,0x80,0x06,0x00,
        0x60,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

char zhi_yi[] = { //智
        0x00,0x00,0x00,0x00,0x00,0x01,0xC0,0x00,0x00,0x00,0x01,0xE0,0x00,0x00,0x00,0x03,
        0xC0,0x80,0x00,0x00,0x03,0x81,0xCE,0x06,0x00,0x03,0xFF,0xEF,0xFF,0x00,0x07,0x3C,
        0x0E,0x0F,0x00,0x07,0x3C,0x0E,0x0F,0x00,0x0E,0x3C,0x0E,0x0F,0x00,0x1C,0x38,0x4E,
        0x0F,0x00,0x00,0x38,0xEE,0x0F,0x00,0x3F,0xFF,0xFE,0x0F,0x00,0x18,0x38,0x0E,0x0F,
        0x00,0x00,0x7C,0x0E,0x0F,0x00,0x00,0x7F,0x0F,0xFF,0x00,0x00,0xF7,0xCE,0x0F,0x00,
        0x00,0xE3,0xEE,0x0E,0x00,0x01,0xC1,0xEC,0x0C,0x00,0x03,0xF0,0xE0,0x70,0x00,0x0F,
        0x7F,0xFF,0xF8,0x00,0x3C,0x70,0x00,0xF0,0x00,0x30,0x70,0x00,0xF0,0x00,0x00,0x70,
        0x00,0xF0,0x00,0x00,0x70,0x00,0xF0,0x00,0x00,0x70,0x00,0xF0,0x00,0x00,0x7F,0xFF,
        0xF0,0x00,0x00,0x70,0x00,0xF0,0x00,0x00,0x70,0x00,0xF0,0x00,0x00,0x70,0x00,0xF0,
        0x00,0x00,0x70,0x00,0xF0,0x00,0x00,0x7F,0xFF,0xF0,0x00,0x00,0x70,0x00,0xF0,0x00,
        0x00,0x70,0x00,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
}; 

char neng_yi[] = { //能
        0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x00,0x00,0x00,0x00,0xF0,0x1E,0x00,0x00,0x00,
        0xF0,0x1F,0x00,0x00,0x01,0xE0,0x1E,0x18,0x00,0x03,0xCE,0x1E,0x3C,0x00,0x03,0x87,
        0x1E,0x7E,0x00,0x07,0x03,0x9F,0xF0,0x00,0x1E,0x03,0xDF,0xC2,0x00,0x3F,0xFF,0xFE,
        0x03,0x00,0x1F,0xF9,0xFE,0x03,0x00,0x1C,0x00,0xDE,0x03,0x00,0x00,0x00,0x1E,0x07,
        0x80,0x0C,0x07,0x0F,0xFF,0x80,0x0F,0xFF,0x8F,0xFF,0x80,0x0E,0x07,0x80,0x00,0x00,
        0x0E,0x07,0x00,0x00,0x00,0x0E,0x07,0x1C,0x00,0x00,0x0F,0xFF,0x1E,0x1C,0x00,0x0E,
        0x07,0x1C,0x1E,0x00,0x0E,0x07,0x1C,0x7E,0x00,0x0E,0x07,0x1C,0xF8,0x00,0x0E,0x07,
        0x1D,0xE0,0x00,0x0F,0xFF,0x1F,0x80,0x00,0x0E,0x07,0x1E,0x00,0x00,0x0E,0x07,0x1C,
        0x03,0x00,0x0E,0x07,0x1C,0x03,0x00,0x0E,0x07,0x1C,0x03,0x00,0x0E,0x07,0x1C,0x03,
        0x80,0x0E,0x07,0x1E,0x03,0x80,0x0E,0x7F,0x1F,0xFF,0xC0,0x0E,0x1F,0x0F,0xFF,0x80,
        0x0E,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
}; 

char jia_yi[] = { //家
        0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xC0,0x00,0x00,0x00,0x01,0xE0,0x00,0x00,0x00,
        0x00,0xF0,0x00,0x00,0x06,0x00,0xF0,0x00,0x00,0x06,0x00,0x60,0x07,0x00,0x07,0xFF,
        0xFF,0xFF,0x80,0x0E,0x00,0x00,0x0F,0x80,0x1E,0x00,0x00,0xCE,0x00,0x3E,0x00,0x01,
        0xFC,0x00,0x1F,0xFF,0xFF,0xF0,0x00,0x00,0x83,0xC0,0x00,0x00,0x00,0x07,0x80,0x20,
        0x00,0x00,0x0F,0x80,0x70,0x00,0x00,0x3F,0xC0,0xF8,0x00,0x00,0x79,0xE3,0xF0,0x00,
        0x01,0xE1,0xE7,0x80,0x00,0x07,0x83,0xFF,0x00,0x00,0x1E,0x07,0xFB,0x00,0x00,0x30,
        0x1F,0x3B,0x00,0x00,0x00,0x3C,0x7B,0x80,0x00,0x00,0xF8,0xFD,0x80,0x00,0x01,0xE1,
        0xFD,0xC0,0x00,0x07,0x83,0xFC,0xE0,0x00,0x3E,0x07,0x9C,0xF0,0x00,0x10,0x1F,0x1C,
        0x7C,0x00,0x00,0x3C,0x1C,0x3F,0x00,0x00,0xF8,0x3C,0x1F,0xC0,0x03,0xE0,0x3C,0x0F,
        0x00,0x0F,0x8F,0x7C,0x00,0x00,0x7C,0x07,0xF8,0x00,0x00,0x60,0x01,0xF0,0x00,0x00,
        0x00,0x00,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
}; 

char ju_yi[] = { //具
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0x00,0xC0,0x00,0x00,
        0x7F,0xFF,0xE0,0x00,0x00,0x70,0x01,0xE0,0x00,0x00,0x70,0x01,0xC0,0x00,0x00,0x70,
        0x01,0xC0,0x00,0x00,0x70,0x01,0xC0,0x00,0x00,0x7F,0xFF,0xC0,0x00,0x00,0x70,0x01,
        0xC0,0x00,0x00,0x70,0x01,0xC0,0x00,0x00,0x70,0x01,0xC0,0x00,0x00,0x70,0x01,0xC0,
        0x00,0x00,0x7F,0xFF,0xC0,0x00,0x00,0x70,0x01,0xC0,0x00,0x00,0x70,0x01,0xC0,0x00,
        0x00,0x70,0x01,0xC0,0x00,0x00,0x70,0x01,0xC0,0x00,0x00,0x7F,0xFF,0xC0,0x00,0x00,
        0x70,0x01,0xC0,0x00,0x00,0x70,0x01,0xC0,0x00,0x00,0x70,0x01,0xC6,0x00,0x00,0x70,
        0x01,0xCF,0x00,0x3F,0xFF,0xFF,0xFF,0x80,0x18,0x18,0x00,0x00,0x00,0x00,0x1C,0x06,
        0x00,0x00,0x00,0x3E,0x07,0xC0,0x00,0x00,0xFC,0x01,0xF0,0x00,0x01,0xF0,0x00,0xFC,
        0x00,0x03,0xE0,0x00,0x3E,0x00,0x0F,0x80,0x00,0x1E,0x00,0x1E,0x00,0x00,0x0F,0x00,
        0x78,0x00,0x00,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
}; 

char kong_yi[] = { //控
        0x00,0x00,0x00,0x00,0x00,0x03,0x80,0x00,0x00,0x00,0x03,0xE0,0x1C,0x00,0x00,0x03,
        0xC0,0x0F,0x00,0x00,0x03,0xC0,0x07,0x80,0x00,0x03,0xC1,0x87,0x80,0x00,0x03,0xC1,
        0x83,0x03,0x00,0x03,0xFB,0xFF,0xFF,0x80,0x7F,0xFF,0x80,0x07,0x80,0x33,0xC7,0x80,
        0x0E,0x00,0x03,0xCF,0x38,0x0C,0x00,0x03,0xC2,0x3D,0xEC,0x00,0x03,0xC0,0x7C,0x78,
        0x00,0x03,0xC0,0xF0,0x3E,0x00,0x03,0xDD,0xE0,0x1E,0x00,0x03,0xFB,0xC0,0x0F,0x00,
        0x03,0xF7,0x80,0x0F,0x00,0x0F,0xCE,0x00,0x1E,0x00,0x7F,0xCC,0x00,0x3C,0x00,0x7F,
        0xC3,0xFF,0xFE,0x00,0x7B,0xC1,0x8F,0x00,0x00,0x33,0xC0,0x0F,0x00,0x00,0x03,0xC0,
        0x0F,0x00,0x00,0x03,0xC0,0x0F,0x00,0x00,0x03,0xC0,0x0F,0x00,0x00,0x03,0xC0,0x0F,
        0x00,0x00,0x03,0xC0,0x0F,0x00,0x00,0x03,0xC0,0x0F,0x03,0x00,0x03,0xC0,0x0F,0x07,
        0x80,0x3B,0xDF,0xFF,0xFF,0xC0,0x3F,0xCE,0x00,0x00,0x00,0x0F,0x80,0x00,0x00,0x00,
        0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
}; 

char zhi2_yi[] = { //制
        0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x00,0x0E,0x00,0x00,0x3C,0x00,0x0F,0x80,0x00,
        0x38,0x00,0x0F,0x00,0x07,0x38,0x00,0x07,0x00,0x0F,0x38,0x00,0x07,0x00,0x0F,0x38,
        0xC3,0x87,0x00,0x0E,0x39,0xE3,0xC7,0x00,0x1F,0xFF,0xF3,0xC7,0x00,0x1C,0x38,0x03,
        0xC7,0x00,0x18,0x38,0x03,0xC7,0x00,0x38,0x38,0x33,0xC7,0x00,0x30,0x38,0x7B,0xC7,
        0x00,0x7F,0xFF,0xFF,0xC7,0x00,0x30,0x38,0x03,0xC7,0x00,0x00,0x38,0x03,0xC7,0x00,
        0x1C,0x38,0xF3,0xC7,0x00,0x1F,0xFF,0xF3,0xC7,0x00,0x1E,0x38,0xE3,0xC7,0x00,0x1E,
        0x38,0xE3,0xC7,0x00,0x1E,0x38,0xE3,0xC7,0x00,0x1E,0x38,0xE3,0xC7,0x00,0x1E,0x38,
        0xE3,0xC7,0x00,0x1E,0x38,0xE3,0xC7,0x00,0x1E,0x38,0xE3,0x87,0x00,0x1E,0x3F,0xE0,
        0x07,0x00,0x1E,0x3F,0xE0,0x07,0x00,0x1E,0x39,0xC0,0x07,0x00,0x18,0x39,0x80,0x07,
        0x00,0x00,0x38,0x01,0xFF,0x00,0x00,0x38,0x00,0xFF,0x00,0x00,0x38,0x00,0x1E,0x00,
        0x00,0x38,0x00,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
}; 

char xi_yi[] = { //系
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x78,0x00,0x00,0x00,0x07,0xFC,0x00,0x00,
        0x01,0xFF,0xFC,0x00,0x03,0xFF,0xFE,0x00,0x00,0x07,0xF8,0xF0,0x00,0x00,0x00,0x01,
        0xF0,0x00,0x00,0x00,0x03,0xC0,0x00,0x00,0x00,0x07,0x80,0xE0,0x00,0x00,0x1E,0x01,
        0xF0,0x00,0x00,0x3C,0x03,0xF0,0x00,0x01,0xFF,0xFF,0x80,0x00,0x01,0xFF,0xFF,0x00,
        0x00,0x00,0xFC,0x7C,0x00,0x00,0x00,0xC0,0xF0,0x00,0x00,0x00,0x03,0xE1,0xC0,0x00,
        0x00,0x0F,0x80,0xF0,0x00,0x00,0x3E,0x00,0x7C,0x00,0x01,0xF8,0x7F,0xFE,0x00,0x03,
        0xFF,0xFF,0xFE,0x00,0x03,0xFF,0x70,0x1E,0x00,0x01,0xC0,0x70,0x0E,0x00,0x00,0x1C,
        0x76,0x00,0x00,0x00,0x1E,0x77,0x80,0x00,0x00,0x3E,0x71,0xE0,0x00,0x00,0x7C,0x70,
        0xF8,0x00,0x00,0xF0,0x70,0x7E,0x00,0x01,0xE0,0x70,0x3F,0x00,0x07,0x80,0x70,0x1F,
        0x00,0x0F,0x0F,0xF0,0x0F,0x00,0x1C,0x07,0xF0,0x07,0x00,0x70,0x01,0xF0,0x07,0x00,
        0x00,0x00,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
}; 

char tong_yi[] = { //统
        0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x1C,0x00,0x00,0x00,0xF0,0x0F,0x00,0x00,0x01,
        0xF0,0x07,0x80,0x00,0x01,0xE0,0x07,0x86,0x00,0x03,0xC0,0x03,0x8F,0x00,0x03,0x87,
        0xFF,0xFF,0x80,0x07,0x8B,0x8F,0x00,0x00,0x07,0x1E,0x0F,0x80,0x00,0x0E,0x1F,0x1E,
        0x00,0x00,0x1C,0x3E,0x1C,0x00,0x00,0x3F,0xFC,0x38,0xF0,0x00,0x3F,0xF8,0x70,0x7C,
        0x00,0x3C,0xF0,0xE0,0x3E,0x00,0x00,0xE1,0xC0,0x3F,0x00,0x01,0xC3,0xFF,0xFF,0x00,
        0x03,0x83,0xFE,0xE7,0x00,0x07,0x01,0xFC,0xE3,0x00,0x0E,0x0E,0x3C,0xE0,0x00,0x3F,
        0xFE,0x3C,0xE0,0x00,0x3F,0xC0,0x3C,0xE0,0x00,0x1E,0x00,0x3C,0xE0,0x00,0x08,0x00,
        0x3C,0xE0,0x00,0x00,0x00,0x38,0xE0,0x00,0x00,0x3E,0x38,0xE0,0x00,0x03,0xF8,0x78,
        0xE3,0x80,0x3F,0xE0,0x78,0xE3,0x80,0x3F,0x00,0x70,0xE3,0x80,0x3C,0x00,0xE0,0xE3,
        0x80,0x18,0x01,0xE0,0xE3,0x80,0x00,0x07,0x80,0xFF,0xC0,0x00,0x1F,0x00,0xFF,0x80,
        0x00,0x3C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
}; 

/*
        宋体初号 56*56
*/
int size_chu[2] = {56, 56};

char cai_chu[] = { //蔡
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x1C,0x00,0x78,0x00,0x00,0x00,0x00,0x1F,0x80,0x7E,0x00,0x00,0x00,0x00,0x1F,0x00,
        0x3E,0x01,0x00,0x00,0x00,0x1E,0x00,0x3C,0x03,0x80,0x00,0x00,0x1E,0x00,0x3C,0x07,
        0xC0,0x0F,0xFF,0xFF,0xFF,0xFF,0xFF,0xE0,0x07,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0,0x03,
        0xC0,0x1E,0x00,0x3C,0x00,0x00,0x00,0x00,0x1E,0x00,0x3C,0x00,0x00,0x00,0x02,0x1E,
        0x00,0x3C,0x00,0x00,0x00,0x07,0x9E,0x00,0x3C,0x00,0x00,0x00,0x07,0xDE,0x00,0x38,
        0x00,0x00,0x00,0x07,0xF8,0x00,0x00,0x00,0x00,0x00,0x0F,0x80,0x06,0x00,0x06,0x00,
        0x00,0x0F,0x80,0x77,0x00,0x0F,0x00,0x00,0x1F,0xFF,0xFB,0xFF,0xFF,0x80,0x00,0x1F,
        0xFF,0xFF,0xFF,0xFF,0xC0,0x00,0x3E,0x01,0xFB,0x80,0x1F,0x80,0x00,0x3F,0x01,0xF1,
        0xC0,0x3E,0x00,0x00,0x7F,0x81,0xE1,0xC0,0x7C,0x00,0x00,0x7B,0xC3,0xE0,0xE0,0x78,
        0x00,0x00,0xF1,0xE3,0xC0,0xF0,0xF0,0x00,0x00,0xE1,0xF7,0xC0,0x78,0xE0,0x00,0x01,
        0xE0,0xF7,0x80,0x79,0xC0,0x00,0x03,0xF8,0xFF,0x00,0x3F,0xC0,0x00,0x07,0xBC,0x7F,
        0x00,0x1F,0x80,0x00,0x07,0x3E,0x1E,0x00,0x2F,0x80,0x00,0x0E,0x1E,0x3E,0x00,0x7F,
        0xC0,0x00,0x1C,0x1E,0x7F,0xFF,0xFF,0xE0,0x00,0x00,0x1E,0xFF,0xFF,0xFF,0xF8,0x00,
        0x00,0x1D,0xF3,0xC0,0x01,0xFE,0x00,0x00,0x03,0xE0,0x00,0x00,0x7F,0xC0,0x00,0x07,
        0xC0,0x00,0x01,0xBF,0xFC,0x00,0x0F,0x80,0x00,0x03,0xDF,0xFC,0x00,0x1E,0x00,0x00,
        0x07,0xE7,0xF0,0x00,0x7F,0xFF,0xFF,0xFF,0xF1,0xE0,0x00,0xF9,0xFF,0xFF,0xFF,0xE0,
        0x00,0x03,0xE0,0x00,0x1E,0x00,0x00,0x00,0x0F,0x80,0x30,0x1E,0x00,0x00,0x00,0x0C,
        0x00,0x7C,0x1E,0x3C,0x00,0x00,0x00,0x00,0xFE,0x1E,0x0F,0x80,0x00,0x00,0x01,0xFE,
        0x1E,0x07,0xE0,0x00,0x00,0x01,0xF0,0x1E,0x01,0xF0,0x00,0x00,0x03,0xE0,0x1E,0x00,
        0xFC,0x00,0x00,0x07,0xC0,0x1E,0x00,0x7E,0x00,0x00,0x1F,0x00,0x1E,0x00,0x3F,0x00,
        0x00,0x3E,0x1C,0x1E,0x00,0x1F,0x80,0x00,0x78,0x1F,0xFE,0x00,0x0F,0x80,0x01,0xF0,
        0x03,0xFE,0x00,0x0F,0x80,0x03,0xC0,0x01,0xFE,0x00,0x07,0x80,0x03,0x00,0x00,0x7C,
        0x00,0x03,0x00,0x00,0x00,0x00,0x78,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

char yu_chu[] = { //宇
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x7C,
        0x00,0x00,0x00,0x00,0x00,0x00,0x7E,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0x00,0x00,
        0x00,0x00,0x00,0x00,0x3F,0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0x00,0x00,0x00,0x00,
        0x70,0x00,0x1E,0x00,0x03,0x00,0x00,0x70,0x00,0x1E,0x00,0x07,0x80,0x00,0x7F,0xFF,
        0xFF,0xFF,0xFF,0xC0,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xE0,0x00,0xF0,0x00,0x00,0x00,
        0x07,0xF0,0x00,0xF0,0x00,0x00,0x00,0x0F,0x80,0x01,0xF0,0x00,0x00,0x00,0x0F,0x00,
        0x03,0xF0,0x00,0x00,0x00,0x1E,0x00,0x03,0xF0,0x00,0x00,0x00,0x9C,0x00,0x07,0xE0,
        0x00,0x00,0x01,0xF8,0x00,0x03,0xC0,0x00,0x00,0x03,0xF0,0x00,0x00,0x1F,0xFF,0xFF,
        0xFF,0xF0,0x00,0x00,0x1F,0xFF,0xFF,0xFF,0xF8,0x00,0x00,0x0E,0x00,0x3E,0x00,0x00,
        0x00,0x00,0x00,0x00,0x3E,0x00,0x00,0x00,0x00,0x00,0x00,0x3E,0x00,0x00,0x00,0x00,
        0x00,0x00,0x3E,0x00,0x00,0x00,0x00,0x00,0x00,0x3E,0x00,0x00,0x00,0x00,0x00,0x00,
        0x3E,0x00,0x00,0x00,0x00,0x00,0x00,0x3E,0x00,0x01,0x80,0x00,0x00,0x00,0x3E,0x00,
        0x03,0xC0,0x00,0x00,0x00,0x3E,0x00,0x07,0xE0,0x1F,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0,
        0x1F,0xFF,0xFF,0xFF,0xFF,0xFF,0xF8,0x0F,0x00,0x00,0x3E,0x00,0x00,0x00,0x00,0x00,
        0x00,0x3E,0x00,0x00,0x00,0x00,0x00,0x00,0x3E,0x00,0x00,0x00,0x00,0x00,0x00,0x3E,
        0x00,0x00,0x00,0x00,0x00,0x00,0x3E,0x00,0x00,0x00,0x00,0x00,0x00,0x3E,0x00,0x00,
        0x00,0x00,0x00,0x00,0x3E,0x00,0x00,0x00,0x00,0x00,0x00,0x3E,0x00,0x00,0x00,0x00,
        0x00,0x00,0x3E,0x00,0x00,0x00,0x00,0x00,0x00,0x3E,0x00,0x00,0x00,0x00,0x00,0x00,
        0x3E,0x00,0x00,0x00,0x00,0x00,0x00,0x3E,0x00,0x00,0x00,0x00,0x00,0x00,0x3E,0x00,
        0x00,0x00,0x00,0x00,0x40,0x7E,0x00,0x00,0x00,0x00,0x00,0xFF,0xFC,0x00,0x00,0x00,
        0x00,0x00,0x3F,0xFC,0x00,0x00,0x00,0x00,0x00,0x0F,0xFC,0x00,0x00,0x00,0x00,0x00,
        0x03,0xF8,0x00,0x00,0x00,0x00,0x00,0x01,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

char chen_chu[] = { //辰
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x00,0x00,0x38,0x00,0x00,0x00,0x07,
        0x80,0x00,0x3F,0xFF,0xFF,0xFF,0xFF,0xC0,0x00,0x3F,0xFF,0xFF,0xFF,0xFF,0xE0,0x00,
        0x3E,0x00,0x00,0x00,0x00,0x00,0x00,0x3E,0x00,0x00,0x00,0x00,0x00,0x00,0x3E,0x00,
        0x00,0x00,0x00,0x00,0x00,0x3E,0x00,0x00,0x00,0x00,0x00,0x00,0x3E,0x00,0x00,0x00,
        0x00,0x00,0x00,0x3E,0x00,0x00,0x00,0x70,0x00,0x00,0x3E,0x00,0x00,0x00,0xF8,0x00,
        0x00,0x3C,0x7F,0xFF,0xFF,0xFC,0x00,0x00,0x3C,0x3F,0xFF,0xFF,0xFE,0x00,0x00,0x3C,
        0x1E,0x00,0x00,0x00,0x00,0x00,0x3C,0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x00,0x00,
        0x00,0x00,0x00,0x00,0x3C,0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x00,0x00,0x00,0x00,
        0x00,0x00,0x3C,0x00,0x00,0x00,0x03,0x80,0x00,0x3C,0x00,0x00,0x00,0x07,0xC0,0x00,
        0x3D,0xFF,0xFF,0xFF,0xFF,0xE0,0x00,0x3D,0xFF,0xFF,0xFF,0xFF,0xF0,0x00,0x3C,0xFF,
        0x8E,0x00,0x00,0x00,0x00,0x3C,0x0F,0x8E,0x00,0x00,0x00,0x00,0x3C,0x0F,0x87,0x00,
        0x38,0x00,0x00,0x3C,0x0F,0x87,0x00,0x7C,0x00,0x00,0x3C,0x0F,0x87,0x80,0x7E,0x00,
        0x00,0x7C,0x0F,0x83,0x80,0xFF,0x00,0x00,0x7C,0x0F,0x83,0xC1,0xF8,0x00,0x00,0x7C,
        0x0F,0x83,0xC3,0xE0,0x00,0x00,0x78,0x0F,0x81,0xEF,0xC0,0x00,0x00,0x78,0x0F,0x81,
        0xFF,0x00,0x00,0x00,0x78,0x0F,0x80,0xFC,0x00,0x00,0x00,0x78,0x0F,0x80,0xF8,0x00,
        0x00,0x00,0xF0,0x0F,0x80,0x7C,0x00,0x00,0x00,0xF0,0x0F,0x80,0x3E,0x00,0x00,0x00,
        0xF0,0x0F,0x80,0x1F,0x00,0x00,0x01,0xE0,0x0F,0x80,0x1F,0xC0,0x00,0x01,0xE0,0x0F,
        0x80,0x7F,0xF0,0x00,0x03,0xC0,0x0F,0x83,0xE3,0xFC,0x00,0x03,0xC0,0x0F,0x8F,0xC1,
        0xFF,0x00,0x07,0x80,0x0F,0xFF,0x00,0xFF,0xF0,0x07,0x00,0x0F,0xFC,0x00,0x3F,0xFC,
        0x0F,0x00,0x1F,0xF8,0x00,0x1F,0xF0,0x0E,0x00,0x0F,0xE0,0x00,0x07,0xC0,0x1C,0x00,
        0x07,0xC0,0x00,0x01,0x80,0x38,0x00,0x07,0x80,0x00,0x00,0x00,0x30,0x00,0x02,0x00,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};