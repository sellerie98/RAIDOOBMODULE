#ifndef _H_SMC_LSI_RAID_OOB_SETTING_
#define _H_SMC_LSI_RAID_OOB_SETTING_


extern	SMC_LSI_RAID_NANE			RaidName[];
extern 	SMC_LSI_RAID_FORM_HEADER	mSmcLsiRaidFormRefSearchTable[];
extern  SMC_RAID_ITEMS_HEADER		mSmcLsiItemsTable[];
extern	SMC_RAID_CHRECORD_HEADER	mSmcLsiChRecordsTable[];

extern	SMC_LSI_AFTER_DOWN_FUNC		mSmcLsiAfterDwonFuncTable[];
extern	SMC_LSI_AFTER_LOAD_FUNC		mSmcLsiAfterLoadFuncTable[];

extern 	SMC_RAID_CMD_RAIDTYPE_TO_VALUE_MAP	mSmcRaidTypeToValueMapTable[];

#endif
