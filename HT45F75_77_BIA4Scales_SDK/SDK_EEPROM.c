asm(" message' **************************************************** ' ");
asm(" message' *       2018 BY BEST HEALTH ELECTRONIC INC         * ' ");
asm(" message' *__________________________________________________* ' ");
asm(" message' *        SDK  NAME  : 	SDK_EEPROM.c	          * ' ");
asm(" message' *   Compiler   Ver. :      V3.52                   * ' ");
asm(" message' *   IDE3000    Ver. :      V7.96                   * ' ");
asm(" message' *   RELEASE    Ver. :      1.0.0                   * ' ");
asm(" message' *   RELEASE   DATA  :     2018/05/09               * ' ");
asm(" message' *__________________________________________________* ' ");
asm(" message' *    MCU / CFG Ver. :   BH66F2650 / 1.8            * ' ");
asm(" message' *                       BH66F2660 / 1.2            * ' ");
asm(" message' **************************************************** ' ");

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// ====================================================================================@
//                                  功能說明                                            @
// ====================================================================================@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
/*
1. 寫一個Byte數據
2. 讀一個Byte數據
*/

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// ====================================================================================@
//                                  封庫設置                                            @
// ====================================================================================@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// TODO
// 針對單 Bank 和多 bank 自動處理
#include "BH66F2660.h"
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// ====================================================================================@
//                                  依賴參數                                            @
// ====================================================================================@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// ====================================================================================@
//                                  對外參數                                            @
// ====================================================================================@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void Write_EEPROMByte(unsigned char addr, unsigned char WriteData); // 寫一個Byte數據
unsigned char Read_EEPROMByte(unsigned char addr);                  // 讀一個Byte數據

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// ====================================================================================@
//                                  源代碼                                             @
// ====================================================================================@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

/****************************************************
 Function: Write_EEPROM
 INPUT	: @addr 寫地址 @寫數據
 OUTPUT	: None
 NOTE	: none
 ***************************************************/
void Write_EEPROMByte(unsigned char addr, unsigned char WriteData)
{
	bit EMI_Protect;
	EMI_Protect = _emi;
	_emi = 0;
	_mp1h = 1;
	_mp1l = 0x40;
	_eea = addr;
	_eed = WriteData;
	//_WREN與_WR需在連續的兩個指令週期內完成
	asm("set [0x02].3");	// WREN
	asm("set [0x02].2");	// WR
	asm("sz  [0x02].2");	// WR
	asm("jmp $-1");
	_iar1 = 0; //disable WREN
	_emi = EMI_Protect;
}
/*****************************************************
 Function: Read_EEPROM
 INPUT	: @addr 讀地址
 OUTPUT	: @讀到的數據
 NOTE	: none
 ****************************************************/
unsigned char Read_EEPROMByte(unsigned char addr)
{
	_eea = addr;
	_mp1h = 1;
	_mp1l = 0x40;
	asm("set [0x02].1");	// RDEN
	asm("set [0x02].0");	// RD
	asm("sz  [0x02].0");	// RD
	asm("jmp $-1");
	_iar1 = 0;
	return _eed;
}