//**********************************************************************
//**********************************************************************
//**                                                                  **
//**        (C)Copyright 1985-2016, American Megatrends, Inc.         **
//**                                                                  **
//**                       All Rights Reserved.                       **
//**                                                                  **
//**      5555 Oakbrook Parkway, Suite 200, Norcross, GA 30093        **
//**                                                                  **
//**                       Phone: (770)-246-8600                      **
//**                                                                  **
//**********************************************************************
//**********************************************************************

/** @file  PeiReportStatusConOut.c
  Defines Status code function to display Progress and Error in ConOut Devices.
**/

#include <Token.h>
#include <Library/DebugLib.h>
#include <SmcPeiReportStatusConOut.h>
#include <Library/IoLib.h>
#include <Library\BaseMemoryLib.h>
#include <Setup.h>
#include <AMIVfr.h>
#include <Ppi\ReadOnlyVariable2.h>
#define	AMITSESETUP_GUID	\
	{ 0xc811fa38, 0x42c8, 0x4579, 0xa9, 0xbb, 0x60, 0xe9, 0x4e, 0xdd, 0xfb, 0x34 }
EFI_STATUS 
EFIAPI
TextOutNotifyCallBack (
    IN EFI_PEI_SERVICES             **PeiServices,
    IN EFI_PEI_NOTIFY_DESCRIPTOR    *NotifyDescriptor,
    IN VOID                         *Ppi
);
EFI_PEI_NOTIFY_DESCRIPTOR mTextOutPpiNotifyDescs = {
    EFI_PEI_PPI_DESCRIPTOR_NOTIFY_CALLBACK | EFI_PEI_PPI_DESCRIPTOR_TERMINATE_LIST,
    &gAmiPeiTextOutPpiGuid,
    TextOutNotifyCallBack
};


EFI_STATUS 
EFIAPI
TextOutNotifyCallBack (
    IN EFI_PEI_SERVICES             **PeiServices,
    IN EFI_PEI_NOTIFY_DESCRIPTOR    *NotifyDescriptor,
    IN VOID                         *Ppi
)
{
    AMI_PEI_TEXT_OUT                *pTextOut;
    pTextOut = Ppi;
    
    pTextOut->SetCursorPosition(pTextOut, 7, 8);
    pTextOut->SetAttribute(pTextOut,0x01, 0x0, FALSE);
    pTextOut->WriteString(pTextOut, 0, " #####                                                    ");
    
    pTextOut->SetCursorPosition(pTextOut, 7, 9);
    pTextOut->SetAttribute(pTextOut, 0x01, 0x00, FALSE);
    pTextOut->WriteString(pTextOut, 0, "#     # #    # #####  ###### #####  #    # #  ####  ##### ");

    pTextOut->SetCursorPosition(pTextOut, 7, 10);
    pTextOut->SetAttribute(pTextOut, 0x01, 0x00, FALSE);
    pTextOut->WriteString(pTextOut, 0, "#       #    # #    # #      #    # ##  ## # #    # #    #");

    pTextOut->SetCursorPosition(pTextOut, 7, 11);
    pTextOut->SetAttribute(pTextOut, 0x01, 0x00, FALSE);
    pTextOut->WriteString(pTextOut, 0, " #####  #    # #    # #####  #    # # ## # # #      #    #");


    pTextOut->SetCursorPosition(pTextOut, 7, 12);
    pTextOut->SetAttribute(pTextOut, 0x01, 0x00, FALSE);
    pTextOut->WriteString(pTextOut, 0, "      # #    # #####  #      #####  #    # # #      ##### ");


    pTextOut->SetCursorPosition(pTextOut, 7, 13);
    pTextOut->SetAttribute(pTextOut, 0x01, 0x00, FALSE);
    pTextOut->WriteString(pTextOut, 0, "#     # #    # #      #      #   #  #    # # #    # #   # ");


    pTextOut->SetCursorPosition(pTextOut, 7, 14);
    pTextOut->SetAttribute(pTextOut, 0x01, 0x00, FALSE);
    pTextOut->WriteString(pTextOut, 0, " #####   ####  #      ###### #    # #    # #  ####  #    #");


    pTextOut->SetCursorPosition(pTextOut, 65, 9);
    pTextOut->SetAttribute(pTextOut, 0x04, 0x00, FALSE);
    pTextOut->WriteString(pTextOut, 0, "   ####  ");


    pTextOut->SetCursorPosition(pTextOut,65, 10);
    pTextOut->SetAttribute(pTextOut, 0x04, 0x00, FALSE);
    pTextOut->WriteString(pTextOut, 0, "  ###### ");


    pTextOut->SetCursorPosition(pTextOut, 65, 11);
    pTextOut->SetAttribute(pTextOut, 0x04, 0x00, FALSE);
    pTextOut->WriteString(pTextOut, 0, " ########");

    pTextOut->SetCursorPosition(pTextOut,65, 12);
    pTextOut->SetAttribute(pTextOut, 0x04, 0x00, FALSE);
    pTextOut->WriteString(pTextOut, 0, " ########");


    pTextOut->SetCursorPosition(pTextOut, 65, 13);
    pTextOut->SetAttribute(pTextOut, 0x04, 0x00, FALSE);
    pTextOut->WriteString(pTextOut, 0, "  ###### ");


    pTextOut->SetCursorPosition(pTextOut, 65, 14);
    pTextOut->SetAttribute(pTextOut, 0x04, 0x00, FALSE);
    pTextOut->WriteString(pTextOut, 0, "   ####  ");
    return EFI_SUCCESS;
}

/**
    Print PEI phase status code check point and description string.

    @param PeiServices - Pointer to the PEI Core data Structure
    @param Value - EFI status code Value
    @param CodeType - EFI status code type
    @param Instance - The enumeration of a hardware or software entity within
                    the system. A system may contain multiple entities that
                    match a class/subclass pairing. The instance differentiates
                    between them. An instance of 0 indicates that instance
                    information is unavailable, not meaningful, or not relevant.
                    Valid instance numbers start with 1.
    @param CallerId - This optional parameter may be used to identify the caller.
                           This parameter allows the status code driver to apply different
                           rules to different callers.
    @param Data - This optional parameter may be used to pass additional data.

    @return EFI_STATUS

**/

EFI_STATUS
EFIAPI
PeiReportStatusConOutWorker (
    IN CONST  EFI_PEI_SERVICES        **PeiServices,
    IN EFI_STATUS_CODE_TYPE           CodeType,
    IN EFI_STATUS_CODE_VALUE          Value,
    IN UINT32                         Instance,
    IN CONST EFI_GUID                 *CallerId,
    IN CONST EFI_STATUS_CODE_DATA     *ErrorData OPTIONAL 
)
{
    EFI_STATUS              Status;
    UINTN                   CheckPointCode;
    CHAR8                   *ProgressCodeString=NULL;
    CHAR8                   *ErrorCodeString=NULL;
    CHAR8                   *PossibleCauseString=NULL;
    CHAR8                   *PossibleSolutionString=NULL;
    CHAR8                   CheckPointString[5];
    CHAR8                   ErrorString[13];
    CHAR8                   TextString[160];
    AMI_PEI_TEXT_OUT        *TextOutPpi;
    
    // Handle only the Progress Code and Error Code type Status 
    if(((CodeType & EFI_STATUS_CODE_TYPE_MASK) != EFI_PROGRESS_CODE) &&  ((CodeType & EFI_STATUS_CODE_TYPE_MASK) != EFI_ERROR_CODE) ) {
        return EFI_SUCCESS;
    }
    
    // Locate the Consplitter Conout Textout Or TextOut PPI
    Status = (*PeiServices)->LocatePpi(
                        PeiServices,
#if ConsoleOutConsplitter_SUPPORT 
                        &gAmiPeiConsplitterTextOutPpiGuid,
#else                         
                        &gAmiPeiTextOutPpiGuid,
#endif                        
                        0,
                        NULL,
                        &TextOutPpi);
                        
    if (EFI_ERROR(Status)) { 
        return Status;
    }
    
    // Check if the type is Progress Code
    if((CodeType & EFI_STATUS_CODE_TYPE_MASK) == EFI_PROGRESS_CODE ) {

        // Get the CheckPoint value for the EFI Progress Code
        CheckPointCode= GetAmiProgressCodeCheckPoint (Value);
        if(CheckPointCode == 0) {
            // If no CheckPoint found return it
            return EFI_SUCCESS;
        }
         
        // Get the Progress code String for the 
        ProgressCodeString= GetAmiProgressCodeString (Value);
        
        TextOutPpi->SetAttribute (TextOutPpi, POST_MSG_FOREGROUND, POST_MSG_BACKGROUND,DISPLAY_BLINK);
        
        SetMem (TextString, 60, ' ');
        TextString[60] = 0;
        TextOutPpi->SetCursorPosition (TextOutPpi, 00, 24);
        TextOutPpi->WriteString (TextOutPpi, PANEL_DISPLAY, TextString);
        if(ProgressCodeString != NULL) {
           // Write String to ConOut Device 
           AsciiSPrint (TextString, 160, "%a", ProgressCodeString);
           TextOutPpi->SetCursorPosition (TextOutPpi, 00, 24);
           TextOutPpi->WriteString (TextOutPpi, PANEL_DISPLAY, TextString);
        }
        
        TextOutPpi->SetCursorPosition (TextOutPpi, 78, 24);       
        AsciiSPrint (CheckPointString, 5, "%2x", CheckPointCode);
        TextOutPpi->WriteString (TextOutPpi, PANEL_DISPLAY, CheckPointString);
        // Set the Original Attribute 
        TextOutPpi->SetAttribute (TextOutPpi, POST_MSG_FOREGROUND, POST_MSG_BACKGROUND,DISPLAY_BLINK);        
    } else if( (CodeType & EFI_STATUS_CODE_TYPE_MASK) == EFI_ERROR_CODE) {
        // Get the Check Point value for the EFI Error Code
        CheckPointCode= GetAmiErrorCodeCheckPoint (Value);
        if(CheckPointCode == 0) {
            // If no CheckPoint found return it
            return EFI_SUCCESS;
        }
        
        // Get the Error Code String for the 
        Status= GetAmiErrorCodeString (Value, &ErrorCodeString,&PossibleCauseString,&PossibleSolutionString );
        AsciiSPrint (CheckPointString, 5, "0x%X", CheckPointCode);

        // Set the Attribute based on the Error Type
        if ( (CodeType & EFI_STATUS_CODE_SEVERITY_MASK) == EFI_ERROR_MINOR) {
            TextOutPpi->SetAttribute (TextOutPpi, MINOR_ERROR_FOREGROUND, MINOR_ERROR_BACKGROUND, DISPLAY_BLINK);
        } else { 
            TextOutPpi->SetAttribute (TextOutPpi, MAJOR_ERROR_FOREGROUND, MAJOR_ERROR_BACKGROUND, DISPLAY_BLINK);
        }

        // Add the Error String along with CheckPoint Value
        if(!EFI_ERROR(Status) && ErrorCodeString != NULL) {
            AsciiSPrint (TextString, 160, "%a : %a \n \r", CheckPointString, ErrorCodeString);
        }
        //Write the String to Conout device
        TextOutPpi->WriteString (TextOutPpi, PANEL_DISPLAY, TextString);
        
        if(ErrorData != NULL) { 
            // Display the Error Code Data
            AsciiSPrint (ErrorString, 13,  "%x %x %x %x ", ((*(UINT32*)(ErrorData + 1)) >> 24) & 0xFF, 
                    ((*(UINT32*)(ErrorData + 1)) >> 16) & 0xFF, ((*(UINT32*)(ErrorData + 1)) >> 8) & 0xFF, 
                    (*(UINT32*)(ErrorData + 1)) & 0xFF);
        
            TextOutPpi->WriteString(TextOutPpi, PANEL_DISPLAY, ErrorString);
        }
        
        //Display the Possible Cause String if available
        if(!EFI_ERROR(Status) && PossibleCauseString != NULL) {
            AsciiSPrint (TextString, 160, "%a \n \r", PossibleCauseString);
            TextOutPpi->WriteString (TextOutPpi, PANEL_DISPLAY, TextString);
        }
        
        //Display the Possible Solution String if available
        if(!EFI_ERROR(Status) && PossibleSolutionString != NULL) {
            AsciiSPrint (TextString, 160, "%a \n \r", PossibleSolutionString);
            TextOutPpi->WriteString (TextOutPpi, PANEL_DISPLAY, TextString);
        }
        
        // Set the Original Attribute
        TextOutPpi->SetAttribute (TextOutPpi, POST_MSG_FOREGROUND, POST_MSG_BACKGROUND,DISPLAY_BLINK);
        
    }
    return EFI_SUCCESS;
}

/**
    This function is the entry point for this PEI.
    This installs the CallBack function for the ReportStatusCode 

    @param FileHandle Pointer to image file handle.
    @param PeiServices Pointer to the PEI Core data Structure

    @retval EFI_SUCCESS Successful driver initialization

**/
EFI_STATUS
EFIAPI
SmcInitializePeiReportStatusCode (
  IN EFI_PEI_FILE_HANDLE     FileHandle,
  IN CONST EFI_PEI_SERVICES  **PeiServices )
{

    EFI_STATUS                              Status;
    EFI_PEI_RSC_HANDLER_PPI                 *RscHandlerPpi; 
    EFI_PEI_READ_ONLY_VARIABLE2_PPI         *ReadOnlyVariable2;
    SETUP_DATA	                            SetupData;
    UINTN	                            VariableSize;
    AMITSESETUP				    AmiTseSetupData;
    EFI_GUID				    AmiTseSetupGuid = AMITSESETUP_GUID;
    EFI_GUID                                gEfiSetupGuid = SETUP_GUID;
    // Locate Handler for Registering the ConOut Status Code 
    Status = (*PeiServices)->LocatePpi (
                            PeiServices,
                            &gEfiPeiRscHandlerPpiGuid,
                            0,
                            NULL,
                            (VOID **) &RscHandlerPpi 
                            );

    if (!EFI_ERROR (Status)) {
        Status = RscHandlerPpi->Register (PeiReportStatusConOutWorker);
    }

    Status = (*PeiServices)->LocatePpi (
                PeiServices,
                &gEfiPeiReadOnlyVariable2PpiGuid,
                0,
                NULL,
                (VOID **)&ReadOnlyVariable2);
    if (EFI_ERROR (Status)) {
      return Status;
    }
    
    VariableSize = sizeof(SETUP_DATA);      
    Status = ReadOnlyVariable2->GetVariable(
      				 ReadOnlyVariable2,
      				 L"Setup",
      				 &gEfiSetupGuid,
      				 NULL,
      				 &VariableSize,  
      				 &SetupData
      				 );
    if (EFI_ERROR (Status)) {
      return Status;
    }
    VariableSize = sizeof (AMITSESETUP);
    Status = ReadOnlyVariable2->GetVariable (
		        ReadOnlyVariable2,
    			L"AMITSESetup",
    			&AmiTseSetupGuid,
    			NULL,
    			&VariableSize,
    			&AmiTseSetupData
    		  );
     if (EFI_ERROR (Status) || !(AmiTseSetupData.AMISilentBoot)) {
        return Status;	  
     }
     
     Status = (*PeiServices)->NotifyPpi(PeiServices, &mTextOutPpiNotifyDescs);
     ASSERT_EFI_ERROR(Status);    
    return EFI_SUCCESS;
}

//**********************************************************************
//**********************************************************************
//**                                                                  **
//**        (C)Copyright 1985-2016, American Megatrends, Inc.         **
//**                                                                  **
//**                       All Rights Reserved.                       **
//**                                                                  **
//**      5555 Oakbrook Parkway, Suite 200, Norcross, GA 30093        **
//**                                                                  **
//**                       Phone: (770)-246-8600                      **
//**                                                                  **
//**********************************************************************
//**********************************************************************