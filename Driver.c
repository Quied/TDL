#include "Driver.h"
#include "message.h"

#pragma warning (disable : 4100)


NTSTATUS DriverEntry(PDRIVER_OBJECT pDriveObj, PUNICODE_STRING pRegistKey) {
	pDriveObj->DriverUnload = UnloadDriver;
	DbgPrintEx(0, 0, "message");

	DebugMessage("Driver Load");



	return STATUS_SUCCESS;
}



NTSTATUS UnloadDriver(PDRIVER_OBJECT pDriverOvb) {
	DebugMessage("Driver UnLoad");



	return STATUS_SUCCESS;
}
