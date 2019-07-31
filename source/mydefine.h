#ifndef __MYDEFINE_H__
#define __MYDEFINE_H__

//**************************************************************
#define	_UART_ENABLE				ENABLE	//1: enable;	0: disable
#define _LED_FLASH_ENABLE			ENABLE//LED闪烁功能的预编译是都使能位,//可选:ENABLE,DISABLE
#define _LVD_LVDEN	 	 			DISABLE//可选:ENABLE,DISABLE
#define _UART_DEBUG					ENABLE  //(_UART_ENABLE && ENABLE) for debug msg


/* TIME */
#define C_TIME_100MS				50//50*2MS=100MS
#define C_TIME_1S					10//10*100MS=1S
#define C_TIME_05S					5	// 100MS*5=500MS
#define C_TIME_3S					30	// 100MS*30=3S
#define C_TIME_5S					50	// 100MS*100=10S
#define C_TIME_10S					100	// 100MS*100=10S
//#define C_TIME_10S					10	// 100MS*10=1S

#define C_LED_FLASH_OFF				0
#define C_LED_FLASH_ON				1
#define C_LED_FLASH_CNT				6	//=2 LED浜伃涓�娆? =4 LED浜伃2娆? =6 LED浜伃3娆?浠ユ绫绘帹.
#define C_LED_FLASH_IMP				12	//浣撹剛娴嬭瘯瀹屾垚鍚庝綋閲嶅拰浣撹剛浜ゆ浛闂儊3娆?
#define C_LED_FLASH_DELAY			30  //100MS*30=3S

//WORK MODE
#define TASK_STARTUP				0
#define TASK_LOWBATTERY				1
#define TASK_SCALES					2
#define TASK_SLEEP					3
#define TASK_WEIGHT_AUTOON			4


//DISPLAY MODE
#define DISPLAY_POWERON				0
#define DISPLAY_LOWBATTERY				1//浣庣數
#define DISPLAY_NOLOAD				2//绌鸿浇 褰撳墠閲嶉噺灏忎簬鏈�灏忕О閲嶉噸閲忥紝鏄剧ず0.0,10s鍚庡叧鏈?
#define DISPLAY_LOADUP				3//瀹屾垚涓�娆＄О閲?
#define DISPLAY_LOADFIX				4//瀹屾垚涓�娆＄ū閲嶆脯閲忓悗閲嶉噺绌╁畾娌掓湁瑙ｉ帠
#define DISPLAY_LOADDOWN			5//涓嬬Г鍕曚綔
#define DISPLAY_OVERLOAD			6//瓒呴噸
#define DISPLAY_IMPEDANCEING		7
#define DISPLAY_IMPEDANCE_FINISH	8//娴嬭瘯闃绘姉
#define DISPLAY_CAL					9//鏍″噯
#define DISPLAY_CALPASS				10//鏍″噯鎴愬姛.
#define DISPLAY_CALFAIL				11
#define DISPLAY_ALLOFF				12//鍏抽棴鎵�鏈夋樉绀篖ED
#define DISPLAY_PCT				13//鍏抽棴鎵�鏈夋樉绀篖ED

#define DISPLAY_MAX					14


//闃绘姉娴嬭瘯閿欒
//闃绘姉 - 闃绘姉鍊?鍠綅ohm. 鑻ョ偤(0xffff-鐒″緟娓樆鎶楅尟瑾?/(0xFFF1-鎺ヨЦ鐣板父閷)/(0xFFF2-闃绘姉瓒呭嚭绡勫湇)
#define IMPEDANCE_ERR_NOTEST					0xFFFF//(0xffff-鐒″緟娓樆鎶楅尟瑾?
#define IMPEDANCE_ERR_ABNORMAL					0xFFF1//(0xFFF1-鎺ヨЦ鐣板父閷)
#define IMPEDANCE_ERR_OUTRANGE					0xFFF2//(0xFFF2-闃绘姉瓒呭嚭绡勫湇)


#define C_TIMEING_CYCLE2MS 			5
#define C_TIMEING_TIMEOUT 			2

#define CMD_HEARD						0xFD
#define DATA_BUF_LEN				11

//命令的各个组成所在位置 position
#define POS_HEARD						0//0xFD//heard:0xFD 包头：FD，表示手机发给秤的数据
#define POS_CMDTYPE						1//cmd type:=34 标定命令; =35 关机命令； =36 显示低电LO命令； =37 表示为有效用户组信息； =38 表示秤进入抱婴
#define POS_UNIT						2//unit:单位转换字节	=00:KG ; =01:LB; =02 ST; =03 jin -->由于LED没有ST单位，只有=0x01显示KG，其他值显示LB
#define POS_USER						3//user: 00~09:P0~P9
#define POS_CHECKSUM					10//checksum:8.BYTE2-BYTE7 的异或校验和。= (DATA_BUF_LEN - 1)


#endif //__MYDEFINE_H__
