#pragma once
#define holeInfoNum 128
#define zhangLaSeqNum 64
#define READ_OPC 1
#define WRITE_OPC 2
#define READ_WRITE_OPC 3

#define IDR_START1 1
#define IDR_START2 2
#define IDR_RANDOM 4
#define IDR_OTHER  8

#define IDW_START1 0X10
#define IDW_START2 0X20
#define IDW_RANDOM 0X40
#define IDW_OTHER  0X80




#include "stdlib.h"
#include "time.h"
#define HEART_BEAT  3
#define RECONNECT_SECOND  10

#define SINGLE_OPC_NUM ( 39 )

#define itemNum ( SINGLE_OPC_NUM * 2)

#define ParameterNum (2)

#define simulate_data 2

#define debugVersion  //lg

//#define debug_noMachine 1  


#include "comBase.h"

#include <windows.h>  
#include "psapi.h"  
#include"stdio.h"
#include <tlhelp32.h>
#include <stdlib.h>
#include <stdio.h>

#include <tchar.h>





