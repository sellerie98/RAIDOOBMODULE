//****************************************************************************
//****************************************************************************
//**            (C)Copyright 1993-2018 Supermicro Computer, Inc.            **
//****************************************************************************
//****************************************************************************
//  File History
//
//  Rev. 1.00
//    Bug Fix:  Initial revision.
//    Reason:
//    Auditor:  Durant Lin
//    Date:     Sep/28/2018
//
//****************************************************************************
#ifndef _H_SMC_LSI_RAID_OOB_GLOBAL_TABLE_H_
#define _H_SMC_LSI_RAID_OOB_GLOBAL_TABLE_H_

extern SMC_RAID_VAR_HASH**			LsiVarHashTableName;
extern SMC_RAID_VAR_HASH**			LsiVarHashTableVarId;
extern BOOLEAN						mDetailedDebugMessage;

extern SMC_LSI_INSIDE_DOWN_FUNC		mSmcLsiInsideDownFunc[];
extern SMC_LSI_INSIDE_LOAD_FUNC		mSmcLsiInsideLoadFunc[];
extern SMC_LSI_INSIDE_CHANGE_FUNC	mSmcLsiInsideChangeFunc[];

extern SMC_RAID_SIZE_TYPE_MAP	SmcRaidSizeTypeMap[];
extern SMC_RAID_CMD_SPECIE_MAP	SpecieMap[];
extern SMC_RAID_CMD_JBOD_MAP	JbodMap[];

extern RAID_CMD_PROCESSING_MAP		RaidCmdProcessMapTable_B_3108[];
extern RAID_CMD_PROCESSING_MAP 		RaidCmdProcessClearMapTable_B_3108[];

extern RAID_CMD_PROCESSING_MAP		RaidCmdProcessMapTable_D_3108[];
extern RAID_CMD_PROCESSING_MAP 		RaidCmdProcessMapTable_D_3108_RaidRef[];
extern RAID_CMD_PROCESSING_MAP 		RaidCmdProcessClearMapTable_D_3108[];

extern SMCLSI_RAIDCMDFUNCTION_MAP	SmcLsiRaidFunctionMapBuildRaidTable[];
extern SMCLSI_RAIDCMDFUNCTION_MAP	SmcLsiRaidFunctionMapDeleteRaidTable[];
extern SMCLSI_RAIDCMDFUNCTION_MAP	SmcLsiRaidFunctionMapOtherRaidTable[];

#define D_3108_RAIDREF_RAIDDRIVE_NAME	0x0
#define D_3108_RAIDREF_OPERATION		0x1
#define D_3108_RAIDREF_GO				0x2
#define D_3108_RAIDREF_GO_QID			0x15C

extern RAID_CMD_PROCESSING_MAP		RaidCmdProcessMapTable_MakeJbod[];
extern RAID_CMD_PROCESSING_MAP		RaidCmdProcessMapTable_UnConfigJbod[];

extern RAID_CMD_PROCESSING_MAP		RaidCmdProcessMapTable_B_Span_3108_First[];
extern RAID_CMD_PROCESSING_MAP		RaidCmdProcessMapTable_B_Span_3108_Second[];
extern RAID_CMD_PROCESSING_MAP		RaidCmdProcessMapTable_B_Span_3108_Third[];
extern RAID_CMD_PROCESSING_MAP		RaidCmdProcessMapTable_B_Span_3108_Forth[];
extern RAID_CMD_PROCESSING_MAP		RaidCmdProcessMapTable_B_Span_3108_Fifth[];

#endif
