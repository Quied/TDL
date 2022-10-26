#pragma once

#include <ntifs.h>

NTSTATUS DriverEntry(PDRIVER_OBJECT pDriveObj,
	PUNICODE_STRING pRegistKey);

NTSTATUS UnloadDriver(PDRIVER_OBJECT pDriverOvb);