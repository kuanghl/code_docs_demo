#ifndef __LL_DEV_H__
#define __LL_DEV_H__

/**
 * @file ll_dev.h
 * @brief This file contains interfaces for managing multiple devices.
 *
 * Detailed description of the ll_dev.h functionality goes here.
 *
 * @author kuanghl
 * @version V01.00.00
 * @date 2024-07-31
 *
 * Licensing information can be provided in a dedicated section or paragraph.
 * If you want to include a link to a license file, you can use the following format:
 * @see LICENSE.txt or the link to the license documentation
 *
 * Contact information for the author can be provided here as well:
 * Author: kuanghl
 * Email: hongliang.kuang@azurengine.com
 */

#include "ll_win.h"

//
// User events for MSI interrupts
//
#define RPP_USER_EVENT_NAME		"Global\\Rpp_User_IsrEvent_"

//
// Rpp Multiple Devices
//

/**
 * @brief Opens a Rpp device using hardware and software identifiers.
 *
 * This function attempts to open a Rpp device by specifying its hardware ID
 * (composed of a vendor ID and a device ID) and a software ID, which is the
 * system's enumeration of the device's ID. Successful opening of the device
 * provides a handle that can be used for subsequent operations.
 *
 * @param[in] vendor_id The vendor ID of the PCIe device, used to identify the manufacturer.
 * @param[in] device_id The device ID of the PCIe device, used to identify the specific device model.
 * @param[in] id The system-assigned unique ID for the enumeration of devices.
 *
 * @note Additional notes on usage, limitations, or requirements can be added here.
 *
 * @return If the operation is successful, the function returns a valid Rpp device handle.
 *         If the operation fails, the function returns NULL.
 *
 * @code
 * // Sample usage:
 * WORD vendorId = 0x1234; // Example vendor ID
 * WORD deviceId = 0x5678; // Example device ID
 * LONG deviceIdSys = 1;   // Example system enumeration ID
 *
 * HANDLE deviceHandle = RppOpenDevice(vendorId, deviceId, deviceIdSys);
 * if (deviceHandle != NULL) {
 *     // Successfully opened the Rpp device, proceed with operations using the handle.
 * } else {
 *     // Handle error, failed to open the Rpp device.
 * }
 * @endcode
 */
HANDLE RppOpenDevice(WORD vendor_id, WORD device_id, LONG id);

/**
 * @brief Opens a Rpp device using a software identifier and a device filename.
 *
 * This function attempts to open a Rpp device by specifying a software ID and
 * a filename associated with the device. The filename is used for callback purposes
 * within the driver. The function is used to obtain a device handle for further
 * communication with the Rpp device.
 *
 * @param[in] id The system-assigned unique ID for the enumeration of devices.
 * @param[in] filename The device filename used for callback operations in the driver.
 *
 * @note The current implementation does not support this function.
 *
 * @return Upon success, the function returns 0. If the operation fails, the function returns -1.
 *
 * @code
 * // Sample usage:
 * LONG deviceIdSys = 1;   // Example system enumeration ID
 * CHAR* deviceFileName = "rpp_device_file"; // Example filename
 *
 * int result = RppOpenDeviceFile(deviceIdSys, deviceFileName);
 * if (result == 0) {
 *     // Successfully opened the Rpp device file, proceed with further operations.
 * } else {
 *     // Handle error, failed to open the Rpp device file.
 * }
 * @endcode
 */
HANDLE RppOpenDeviceFile(LONG id, CHAR* filename);

/**
 * @brief Opens a specified number of Rpp devices or enumerates all Rpp devices in the system.
 *
 * This function can be used to open a specified number of Rpp devices by providing an array to store the device handles.
 * If the input parameter `hd` is NULL and `num` is 0, the function instead returns the total number of Rpp devices available in the system.
 *
 * @param[in,out] hd If not NULL, it points to an array where the function will store the handles of the opened Rpp devices.
 * @param[in] num The number of Rpp devices to open. If this is 0 and `hd` is NULL, the function returns the count of Rpp devices.
 *
 * @note If `hd` is not NULL and `num` is greater than 0, the caller must ensure that the array pointed to by `hd` is large enough to store `num` HANDLE entries.
 *
 * @return The function returns the number of Rpp devices successfully opened or, if called with `hd` NULL and `num` 0, the total number of Rpp devices in the system.
 *
 * @code
 * // Sample usage:
 * int numDevices = 0;                // To hold the number of Rpp devices
 * HANDLE* deviceHandles = NULL;      // Array to store device handles
 *
 * // First call to get the number of devices
 * numDevices = RppEnumAllDevices(NULL, 0);
 * if (numDevices > 0) {
 *     deviceHandles = new HANDLE[numDevices]; // Allocate memory for handles
 *     // Second call to open all devices
 *     int openedDevices = RppEnumAllDevices(deviceHandles, numDevices);
 *     if (openedDevices == numDevices) {
 *         // Successfully opened all Rpp devices
 *     } else {
 *         // Handle error, some devices could not be opened
 *     }
 *     delete[] deviceHandles; // Clean up allocated memory
 * }
 * @endcode
 */
int RppEnumAllDevices(HANDLE* hd, int num);

/**
 * @brief Closes an open Rpp device.
 *
 * This function is used to close a previously opened Rpp device, freeing any associated resources.
 *
 * @param[in] hObject The handle of the Rpp device to close. This handle is obtained when the device is opened.
 *
 * @note It is the responsibility of the caller to ensure that the device handle is valid before attempting to close it.
 *
 * @return Upon success, the function returns 0. If the operation fails, the function returns -1.
 *
 * @code
 * // Sample usage:
 * HANDLE deviceHandle; // Assume this is a valid handle to an open Rpp device.
 *
 * // Close the Rpp device
 * int result = RppCloseDevice(deviceHandle);
 * if (result == 0) {
 *     // Successfully closed the Rpp device
 * } else {
 *     // Handle error, failed to close the Rpp device
 * }
 * @endcode
 */
int RppCloseDevice(HANDLE hObject);

#endif // !__LL_DEV_H__
