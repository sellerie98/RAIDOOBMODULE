//****************************************************************************
//**                                                                        **
//**            (C)Copyright 1993-2017 Supermicro Computer, Inc.            **
//**                                                                        **
//****************************************************************************
//  File History
//
//  Rev. 1.05
//    Bug Fix:  Add SmcAOCPeiSetNVMeMode.
//    Reason:   
//    Auditor:  Isaac Hsu
//    Date:     Jan/20/2017
//
//  Rev. 1.04
//    Bug Fix:  Fix that On/Off Onboard LAN Device malfunction when modify
//              IIO bifurcation for Uplink.
//    Reason:   
//    Auditor:  Isaac Hsu
//    Date:     Jan/11/2017
//
//  Rev. 1.03
//    Bug Fix:  1. Remove JPTG1 support.
//              2. When disables Onboard LAN device, disables LAN Phy by
//                 asserting GPP_C8.
//    Reason:   
//    Auditor:  Isaac Hsu
//    Date:     Jan/03/2017
//
//  Rev. 1.02
//    Bug Fix:  Add JPTG1 support.
//    Reason:   
//    Auditor:  Isaac Hsu
//    Date:     Dec/27/2016
//
//  Rev. 1.01
//    Bug Fix:  Support AOC NVMe.
//    Reason:   
//    Auditor:  Isaac Hsu
//    Date:     Dec/16/2016
//
//  Rev. 1.00
//    Bug Fix:  Initialize revision
//    Reason:   Clone from Sample folder.
//    Auditor:  Isaac Hsu
//    Date:     Nov/18/2016
//
//****************************************************************************
//****************************************************************************
//<AMI_FHDR_START>
//----------------------------------------------------------------------------
//
// Name:		ProjectPeiDriver.c
//
// Description:
//  This file implement function of PROJECTDRIVER_PROTOCOL
//
//----------------------------------------------------------------------------
//<AMI_FHDR_END>
#include <token.h>
#include <Library/PeiServicesTablePointerLib.h>
#include <Library/DebugLib.h>
#include <Library/GpioLib.h>
#include "X11SPMPeiDriver.h"
#include "SmcCspLibBmc.h"
#include <AmiPeiLib.h>
#include <Ppi/ReadOnlyVariable2.h>
#include <PEI.h>
#include "Setup.h"
#if SmcAOC_SUPPORT
#include "../Module/SmcAOC/SmcAOCPei.h"
EFI_GUID gSmcAOCPeiProtocolGuid = EFI_SMC_AOC_PEI_PROTOCOL_GUID;
#endif


/*-----------------12/23/2014 3:06PM----------------
 * Coding for every platform
 * --------------------------------------------------*/
//HSX_PER_LANE_EPARAM_LINK_INFO  X11SPMPerLanesEparamTable[] = {
//};
//UINT32 X11SPMPerLanesEparamTableSize = sizeof (X11SPMPerLanesEparamTable);

//<AMI_PHDR_START>
//----------------------------------------------------------------------------
//
// Procedure   :  PeiProjectCheckAdjustVID
//
// Description :  Send out the Project Adjust VID
//
// Parameters:  **PeiServices - Pointer to the PEI services table
//              PROJECT_PEI_DRIVER_PROTOCOL *This - Pointer to an instance of the SUPERM_PEI_DRIVER_PROTOCOL
//
// Returns     :  Project Adjust VID
//
//----------------------------------------------------------------------------
//<AMI_PHDR_START>
UINT8 EFIAPI PeiProjectCheckAdjustVID(
    IN	EFI_PEI_SERVICES	**PeiServices,
    IN	PROJECT_PEI_DRIVER_PROTOCOL	*This
)
{
    DEBUG((EFI_D_INFO, "PeiProjectCheckAdjustVID.\n"));

    return 0;
}

//<AMI_PHDR_START>
//----------------------------------------------------------------------------
//
// Procedure   :  PeiProjectGetBID
//
// Description :  Send out the Project BID
//
// Parameters:  **PeiServices - Pointer to the PEI services table
//              PROJECT_PEI_DRIVER_PROTOCOL *This - Pointer to an instance of the SUPERM_PEI_DRIVER_PROTOCOL
//
// Returns     :  Project BID
//
//----------------------------------------------------------------------------
//<AMI_PHDR_START>
UINT8 EFIAPI PeiProjectGetBID(
    IN	EFI_PEI_SERVICES	**PeiServices,
    IN	PROJECT_PEI_DRIVER_PROTOCOL	*This
)
{
    DEBUG((EFI_D_INFO, "PeiProjectGetBID.\n"));

    return 0x00;
}

//<AMI_PHDR_START>
//----------------------------------------------------------------------------
//
// Procedure   :  PeiProjectCheckBMCPresent
//
// Description :  Check BMC Present or not
//
// Parameters:  **PeiServices - Pointer to the PEI services table
//              PROJECT_PEI_DRIVER_PROTOCOL *This - Pointer to an instance of the SUPERM_PEI_DRIVER_PROTOCOL
//
// Returns     :  1: BMC Present  0: MBC not present
//
//----------------------------------------------------------------------------
//<AMI_PHDR_START>
UINT8 EFIAPI PeiProjectCheckBMCPresent(
    IN	EFI_PEI_SERVICES	**PeiServices,
    IN	PROJECT_PEI_DRIVER_PROTOCOL	*This
)
{
    UINT32	ReturnVal = 1;
	
    //ReturnVal = CheckBMCPresent();

    DEBUG ((EFI_D_INFO, "PeiProjectCheckBMCPresent Return = %x.\n", ReturnVal));
    return (UINT8)ReturnVal;
}

//<AMI_PHDR_START>
//----------------------------------------------------------------------------
//
// Procedure   :  PeiProjectSystemConfiguration
//
// Description :  Create Project own System Configurate Information
//
// Parameters:  **PeiServices - Pointer to the PEI services table
//              PROJECT_PEI_DRIVER_PROTOCOL *This - Pointer to an instance of the SUPERM_PEI_DRIVER_PROTOCOL
//				UINT8 *SystemConfigurationData - Pointer to SystemConfigurationData data structure address
//
// Returns     :  EFI_SUCCESS
//
//----------------------------------------------------------------------------
//<AMI_PHDR_START>
EFI_STATUS PeiProjectSystemConfiguration(
    IN	EFI_PEI_SERVICES	**PeiServices,
    IN	PROJECT_PEI_DRIVER_PROTOCOL	*This,
    OUT	UINT8	*SystemConfigurationData
)
{
    UINT8	i;

    DEBUG((EFI_D_INFO, "PeiProjectSystemConfiguration.\n"));

    for(i = 0; i < 10; i++)
        *(SystemConfigurationData + i) = 0x00;

    return EFI_SUCCESS;
}

//<AMI_PHDR_START>
//----------------------------------------------------------------------------
//
// Procedure   :  PeiProjectHardwareInfo
//
// Description :  Create Project own Hareware Information
//
// Parameters:  **PeiServices - Pointer to the PEI services table
//              PROJECT_PEI_DRIVER_PROTOCOL *This - Pointer to an instance of the SUPERM_PEI_DRIVER_PROTOCOL
//              UINT8 *HardWareInfoData - Pointer to HardWareInfoData data structure address
//              UINT8 *LanMacInfoData - Pointer to LanMacInfoData data structure address
//
//
// Returns     :  EFI_SUCCESS
//
//----------------------------------------------------------------------------
//<AMI_PHDR_START>
EFI_STATUS EFIAPI PeiProjectHardwareInfo(
    IN	EFI_PEI_SERVICES	**PeiServices,
    IN	PROJECT_PEI_DRIVER_PROTOCOL	*This,
    OUT	UINT8	*HardWareInfoData,
    OUT	UINT8	*LanMacInfoData
)
{
    DEBUG((EFI_D_INFO, "PeiProjectHardwareInfo.\n"));


    // HardWareInfoData parameter data is used by 0x20 command
    // IPMI 0x20 command data:
    // Byte 0   : motherboard SSID  (bit[0:8])
    // Byte 1   : motherboard SSID  (bit[16:24])
    // Byte 2   : hardware monitor chip number
    // Byte 3   : NumLan M
    // Byte 4-9 : LAN port M+1 MAC address

    *(HardWareInfoData + 0) = (SMC_SSID >> 16) & 0xFF;
    *(HardWareInfoData + 1) = (SMC_SSID >> 24) & 0xFF;
    *(HardWareInfoData + 2) = 0x01;
    *(HardWareInfoData + 3) = 0x01;

    // LanMacInfoData parameter data is used by 0x9E command
    // IPMI 0x9E command data:
    // Byte 0    : LAN number N  (exclude NumLan of 0x30 0x20 command)
    // Byte 1-6  : LAN port M MAC address
    // Byte 7-12 : LAN port M+1 MAC address

    *LanMacInfoData = 0x01;

    return EFI_SUCCESS;
}

/*-----------------12/23/2014 3:06PM----------------
 * Coding for every platform
 * --------------------------------------------------*/
//<AMI_PHDR_START>
//----------------------------------------------------------------------------
//
// Procedure   :  PeiProjectSystemConfiguration
//
// Description :  Create Project own System Configurate Information
//
// Parameters:  **PeiServices - Pointer to the PEI services table
//              PROJECT_PEI_DRIVER_PROTOCOL *This - Pointer to an instance of the SUPERM_PEI_DRIVER_PROTOCOL
//              OUT UINT32 *SizeOfTable - Size of HSX_ALL_LANES_EPARAM_LINK_INFO
//              OUT UINT32 *per_lane_SizeOfTable - Size of HSX_PER_LANE_EPARAM_LINK_INFO
//              OUT HSX_ALL_LANES_EPARAM_LINK_INFO **ptr - Pointer to HSX_ALL_LANES_EPARAM_LINK_INFO data structure address
//              OUT HSX_PER_LANE_EPARAM_LINK_INFO  **per_lane_ptr - Pointer to HSX_PER_LANE_EPARAM_LINK_INFO data structure address
//
// Returns     :  EFI_SUCCESS
//
//----------------------------------------------------------------------------
//<AMI_PHDR_START>
UINT32 EFIAPI GetProjectEParam(
    IN	EFI_PEI_SERVICES	**PeiServices,
    IN	PROJECT_PEI_DRIVER_PROTOCOL	*This,
    OUT	UINT32	*SizeOfTable,
    OUT	ALL_LANES_EPARAM_LINK_INFO	**Ptr
)
{

	return TRUE;
}

//<AMI_PHDR_START>
//----------------------------------------------------------------------------
//
// Procedure   :  GetProjectPchData
//
// Description :  Get PCH data function in board level
//  PLATFORM_PCH_DATA[10] as below
//  UINT8   PchPciePortCfg1;   // PCIE Port Configuration Strap 1
//  UINT8   PchPciePortCfg2;   // PCIE Port Configuration Strap 2
//  UINT8   PchPciePortCfg3;   // PCIE Port Configuration Strap 3
//  UINT8   PchPciePortCfg4;   // PCIE Port Configuration Strap 4
//  UINT8   PchPciePortCfg5;   // PCIE Port Configuration Strap 5
//  UINT8   PchPcieSBDE;
//  UINT8   LomLanSupported;   // Indicates if PCH LAN on board is supported or not
//  UINT8   GbePciePortNum;    // Indicates the PCIe port qhen PCH LAN on board is connnected.
 // UINT8   GbeRegionInvalid;
 // BOOLEAN GbeEnabled;        // Indicates if the GBE is SS disabled
//
// Returns     :  EFI_SUCCESS
//
//----------------------------------------------------------------------------
//<AMI_PHDR_START>
EFI_STATUS EFIAPI GetProjectPchData(
    IN	EFI_PEI_SERVICES	**PeiServices,
    IN	PROJECT_PEI_DRIVER_PROTOCOL	*This,
    IN OUT	UINT8	PLATFORM_PCH_DATA[10]
)
{
    EFI_STATUS	Status = EFI_SUCCESS;
    DEBUG((EFI_D_INFO, "GetProjectPchData Start.\n"));
    PLATFORM_PCH_DATA[0] = 1;
    PLATFORM_PCH_DATA[1] = 1;
    PLATFORM_PCH_DATA[2] = 1;
    PLATFORM_PCH_DATA[3] = 1;
    PLATFORM_PCH_DATA[4] = 1;

    DEBUG((EFI_D_INFO, "GetProjectPchData End.\n"));
    return EFI_SUCCESS;
}

EFI_STATUS EFIAPI GetProjectPciEBifurcate(
    IN EFI_PEI_SERVICES **PeiServices,
    IN OUT	IIO_CONFIG	*SetupData
)
{
    EFI_STATUS	Status = EFI_SUCCESS;
    UINT8	DefaultIOU0[2], DefaultIOU1[2], DefaultIOU2[2];
#if ONBOARD_LAN_DISABLE_BY_SETUP_ITEM
    UINTN       VarSize;
    SETUP_DATA	Setup10GbE;
    EFI_GUID	SetupGuid = SETUP_GUID;
    EFI_PEI_READ_ONLY_VARIABLE2_PPI  *ReadOnlyVariable;
#endif
#if SmcAOC_SUPPORT
    PEI_SMC_AOC_PROTOCOL    *mSmcAOCPeiProtocol = NULL;
    SMC_SLOT_INFO           SLOT_Tbl[] = SLOT_INFO_Tbl;
#endif


    DEBUG((EFI_D_INFO, "PEI GetProjectPciEBifurcate Start.\n"));

    DefaultIOU0[0] = SetupData->ConfigIOU0[0];
    DefaultIOU1[0] = SetupData->ConfigIOU1[0];
    DefaultIOU2[0] = SetupData->ConfigIOU2[0];
    DefaultIOU0[1] = SetupData->ConfigIOU0[1];
    DefaultIOU1[1] = SetupData->ConfigIOU1[1];
    DefaultIOU2[1] = SetupData->ConfigIOU2[1];

    DEBUG((-1, "DefaultIOU = %x, %x, %x\n", DefaultIOU0[0], DefaultIOU1[0], DefaultIOU2[0]));
    DEBUG((-1, "DefaultIOU = %x, %x, %x\n", DefaultIOU0[1], DefaultIOU1[1], DefaultIOU2[1]));

    if(SetupData->ConfigIOU0[0] == 0xff){
    	SetupData->ConfigIOU0[0] = IIO_BIFURCATE_xxxxxx16;
        SetupData->SLOTIMP[1] = 1; // Slot 4
        SetupData->SLOTPSP[1] = 1;
    }
    if(SetupData->ConfigIOU1[0] == 0xff){
       	SetupData->ConfigIOU1[0] = IIO_BIFURCATE_xxxxxx16;
        SetupData->SLOTIMP[5] = 1; // Slot 6
        SetupData->SLOTPSP[5] = 5;
    }
    if(SetupData->ConfigIOU2[0] == 0xff){
       	SetupData->ConfigIOU2[0] = IIO_BIFURCATE_xxx8xxx8;
        SetupData->SLOTIMP[9] = 1;
        SetupData->SLOTPSP[9] = 9;
        SetupData->SLOTIMP[11] = 1; // Slot 7
        SetupData->SLOTPSP[11] = 11;
    }
    if(SetupData->ConfigIOU0[1] == 0xff){
       	SetupData->ConfigIOU0[1] = IIO_BIFURCATE_xxxxxx16;
       	SetupData->HidePEXPMenu[22] = 1;
    }
    if(SetupData->ConfigIOU1[1] == 0xff){
       	SetupData->ConfigIOU1[1] = IIO_BIFURCATE_xxxxxx16;
       	SetupData->HidePEXPMenu[26] = 1;
    }
    if(SetupData->ConfigIOU2[1] == 0xff){
       	SetupData->ConfigIOU2[1] = IIO_BIFURCATE_xxxxxx16;
       	SetupData->HidePEXPMenu[30] = 1;
    }
    if(SetupData->ConfigMCP0[0] == 0xff){
    	SetupData->ConfigMCP0[0] = IIO_BIFURCATE_xxxxxx16;
        SetupData->HidePEXPMenu[13] = 1;
    }
    if(SetupData->ConfigMCP1[0] == 0xff){
        SetupData->ConfigMCP1[0] = IIO_BIFURCATE_xxxxxx16;
        SetupData->HidePEXPMenu[17] = 1;
    }
    if(SetupData->ConfigMCP0[1] == 0xff){
        SetupData->ConfigMCP0[1] = IIO_BIFURCATE_xxxxxx16;
        SetupData->HidePEXPMenu[34] = 1;
    }
    if(SetupData->ConfigMCP1[1] == 0xff){
        SetupData->ConfigMCP1[1] = IIO_BIFURCATE_xxxxxx16;
        SetupData->HidePEXPMenu[38] = 1;
    }

#if SmcAOC_SUPPORT
    Status = (*PeiServices)->LocatePpi(PeiServices, &gSmcAOCPeiProtocolGuid, 0, NULL, &mSmcAOCPeiProtocol);
    DEBUG((-1, "LocatePpi mSmcAOCPeiProtocol = %r.\n", Status));
    if(!EFI_ERROR(Status)) {
        mSmcAOCPeiProtocol->SmcAOCPeiCardDetection(PeiServices, 0, 0, 0, SLOT_Tbl, sizeof(SLOT_Tbl)/sizeof(SMC_SLOT_INFO));
        mSmcAOCPeiProtocol->SmcAOCPeiBifurcation(SetupData, DefaultIOU0, DefaultIOU1, DefaultIOU2);
        mSmcAOCPeiProtocol->SmcAOCPeiSetNVMeMode(PeiServices, 0, 0, 0, SLOT_Tbl, sizeof(SLOT_Tbl)/sizeof(SMC_SLOT_INFO));
    }
#endif

#if ONBOARD_LAN_DISABLE_BY_SETUP_ITEM
    Status = (*PeiServices)->LocatePpi(PeiServices, &gEfiPeiReadOnlyVariable2PpiGuid, 0, NULL, &ReadOnlyVariable);
    if(!EFI_ERROR(Status)){
        VarSize = sizeof(SETUP_DATA);
        Status = ReadOnlyVariable->GetVariable(ReadOnlyVariable, L"Setup", &SetupGuid, NULL, &VarSize, &Setup10GbE);
        if(!EFI_ERROR(Status)) {
            if(Setup10GbE.SmcOnboardLan == 0) {
                SetupData->PciePortDisable[9] = 0;  // 10Gbe LAN map to CPU PCIe port 3A and 3B
                SetupData->PciePortDisable[10] = 0;
                GpioSetOutputValue((SMC_GPP_C+8), 1); // Disable Lan Phy
            }
        }
    }
#endif

    DEBUG((EFI_D_INFO, "PEI - GetProjectPciEBifurcate End.\n"));
    return EFI_SUCCESS;
}

PROJECT_PEI_DRIVER_PROTOCOL PeiProjectInterface =
{
	PeiProjectCheckAdjustVID,
	NULL,
	NULL,
	PeiProjectHardwareInfo,
	PeiProjectCheckBMCPresent,
	NULL,
	GetProjectPchData,
	GetProjectPciEBifurcate,
	NULL,
	NULL
};

//<AMI_PHDR_START>
//----------------------------------------------------------------------------
//
// Procedure   : ProjectPeiDriverInit
//
// Description : Init Project at PEI phase
//
// Parameters:  FfsHeader   Pointer to the FFS file header
//              PeiServices Pointer to the PEI services table
//
// Returns     :  EFI_SUCCESS
//
//----------------------------------------------------------------------------
//<AMI_PHDR_START>
EFI_STATUS EFIAPI X11SPMPeiDriverInit(
    IN	EFI_FFS_FILE_HEADER	*FfsHeader,
    IN	EFI_PEI_SERVICES	**PeiServices
)
{
    EFI_PEI_PPI_DESCRIPTOR	*mPpiList = NULL;
    EFI_STATUS	Status;

    DEBUG((DEBUG_INFO, "ProjectPeiDriverInit.\n"));

    Status = (*PeiServices)->AllocatePool (PeiServices, sizeof (EFI_PEI_PPI_DESCRIPTOR), &mPpiList);
    ASSERT_PEI_ERROR (PeiServices, Status);

    mPpiList->Flags = EFI_PEI_PPI_DESCRIPTOR_PPI | EFI_PEI_PPI_DESCRIPTOR_TERMINATE_LIST;
    mPpiList->Guid = &gProjectOwnPeiProtocolGuid;
    mPpiList->Ppi = &PeiProjectInterface;

    Status = (**PeiServices).InstallPpi(PeiServices, mPpiList);
    if (EFI_ERROR(Status)){
        DEBUG((DEBUG_INFO, "ProjectPeiDriverInit fail.\n"));
        return Status;
    }

    DEBUG((DEBUG_INFO, "Exit ProjectPeiDriverInit.\n"));

    return EFI_SUCCESS;
}