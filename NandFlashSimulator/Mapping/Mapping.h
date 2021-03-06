/*********************************************************
*     File Name : Mapping.h
*     YIN  @ 2016.12.15
*     Description  : Initial create
**********************************************************/
#ifndef _MAPPING_H_
#define _MAPPING_H_
/*********************************************************
*  Include
**********************************************************/
#include "NandFlash_sim.h"

#define NAND_OK   0
#define NAND_FAIL 1

#define  NAND_BLOCK_COUNT (MAX_NANDFLASH_CHIP_CNT * MAX_BLOCKS_PER_CHIP)  /* 32个chip ，每个chip 有 2个 plane ， 一个plane 有 1024 个block */
#define  PAGES_PER_CHIP   (MAX_BLOCKS_PER_CHIP * MAX_PAGES_PER_BLOCK)
#define  BLOCKS_PER_CHIP  (MAX_BLOCKS_PER_CHIP)

#define BB_OFFSET				0		/* 块内第1个page备用区的第1个字节是坏块标志 */
#define USED_OFFSET				1		/* 块内第1个page备用区的第2个字节是已用标志 */
#define LBN0_OFFSET				2		/* 块内第1个page备用区的第3个字节表示逻辑块号低8bit */
#define LBN1_OFFSET				3		/* 块内第1个page备用区的第4个字节表示逻辑块号高8bit */

#define CHECK_SPARE_SIZE		4		/* 实际使用的备用区大小,用于函数内部声明数据缓冲区大小 */

extern uint32_t Nand_Mapping_ReadID(uint32_t PageNo, uint8_t* pID);

extern uint32_t Nand_Mapping_ReadData(uint8_t* pDataBuffer, uint32_t PageNo, uint16_t AddrInPage, uint16_t ByteCount);
extern uint32_t Nand_Mapping_ReadSpare(uint8_t* pDataBuffer, uint32_t PageNo, uint16_t AddrInPage, uint16_t ByteCount);

extern uint32_t Nand_Mapping_WriteData(uint8_t* pDataBuffer, uint32_t PageNo, uint16_t AddrInPage, uint16_t ByteCount);
extern uint32_t Nand_Mapping_WriteSpare(uint8_t* pDataBuffer, uint32_t PageNo, uint16_t AddrInPage, uint16_t ByteCount);

extern uint32_t Nand_Mapping_EraseBlock(uint32_t PageNo);

extern uint8_t NAND_BuildLUT(void);
extern uint16_t LbnToPbn(uint32_t aLbn);

#endif
