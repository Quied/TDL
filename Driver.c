#include "ntddk.h"
#include "wdf.h"

DRIVER_INITIALIZE DriverEntry;
EVT_WDF_DRIVER_DEVICE_ADD DriverEvtDeviceAdd;


NTSTATUS DriverENTRY(
	_In_ PDRIVER_OBJECT DriverObj,
	_In_ PUNICODE_STRING RegistryPath ) {

	NTSTATUS status = STATUS_SUCCESS;
	WDF_DRIVER_CONFIG config;

	// Print Information
	KdPrintEx((DPFLTR_IHVDRIVER_ID, DPFLTR_INFO_LEVEL, "Driver Entry"))

	WDF_DRIVER_CONFIG_INIT(&config, DriverEvtDeviceAdd);
	status = WdfDriverCreate(DriverObj, RegistryPath,
		WDF_NO_OBJECT_ATTRIBUTES, &config, WDF_NO_HANDLE);


	return status;
}

NTSTATUS DriverEvtDeviceAdd_Next(
	_In_ WDFDRIVER Driver,
	_Inout_ PWDFDEVICE_INIT DeviceInit ) {

	UNREFERENCED_PARAMETER(Driver);

	NTSTATUS status;

	WDFDEVICE hDevice;

	KdPrintEx((DPFLTR_IHVDRIVER_ID, DPFLTR_INFO_LEVEL, "EvtDeviceAdd"));
	
	status = WdfDeviceCreate(&DeviceInit, WDF_NO_OBJECT_ATTRIBUTES, &hDevice);


	return status;
}