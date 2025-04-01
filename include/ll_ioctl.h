#ifndef __LL_IOCTL_H__
#define __LL_IOCTL_H__

/**
 * @file ll_ioctl.h
 * @brief This file contains ioctl (input/output control) interfaces for user-space to call into the driver.
 *
 * Detailed description of the purpose and usage of the ioctl interfaces provided in this file.
 * This typically includes information about the device operations that can be controlled via these interfaces.
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


/**
 * @brief Cdev IOCTL codes
 */
#define RPP_IOCTL_START					    CTL_CODE(FILE_DEVICE_RPP, 0x900, METHOD_BUFFERED, FILE_ANY_ACCESS)      /**< start cdev IOCTL */
#define RPP_IOCTL_GETPARAM				    CTL_CODE(FILE_DEVICE_RPP, 0x901, METHOD_BUFFERED, FILE_ANY_ACCESS)      /**< get some information from the card */
#define RPP_IOCTL_BAR_MAP  				    CTL_CODE(FILE_DEVICE_RPP, 0x902, METHOD_BUFFERED, FILE_ANY_ACCESS)      /**< Bar map into User state */
#define RPP_IOCTL_BAR_UNMAP  			    CTL_CODE(FILE_DEVICE_RPP, 0x903, METHOD_BUFFERED, FILE_ANY_ACCESS)	    /**< Bar unmap User state */
#define RPP_IOCTL_KERNEL_MEM_ALLOC		    CTL_CODE(FILE_DEVICE_RPP, 0x904, METHOD_BUFFERED, FILE_ANY_ACCESS)		/**< Kernel memory use in PCIE DMA alloc(others memory alloc need to realize) */
#define RPP_IOCTL_KERNEL_MEM_FREE		    CTL_CODE(FILE_DEVICE_RPP, 0x905, METHOD_BUFFERED, FILE_ANY_ACCESS)		/**< Kernel memory use in PCIE DMA free(others memory free need to realize) */
#define RPP_IOCTL_KERNEL_MEM_MAP		    CTL_CODE(FILE_DEVICE_RPP, 0x906, METHOD_BUFFERED, FILE_ANY_ACCESS)		/**< Kernel memory map into User state */
#define RPP_IOCTL_KERNEL_MEM_UNMAP		    CTL_CODE(FILE_DEVICE_RPP, 0x907, METHOD_BUFFERED, FILE_ANY_ACCESS)		/**< Kernel memory unmap User state */
#define RPP_IOCTL_USER_MEM_MAP			    CTL_CODE(FILE_DEVICE_RPP, 0x908, METHOD_BUFFERED, FILE_ANY_ACCESS)		/**< User memory map into Kernel state */
#define RPP_IOCTL_USER_MEM_UNMAP		    CTL_CODE(FILE_DEVICE_RPP, 0x909, METHOD_BUFFERED, FILE_ANY_ACCESS)		/**< User memory unmap Kernel state */
#define RPP_IOCTL_USER_EVENTS_REGISTER	    CTL_CODE(FILE_DEVICE_RPP, 0x90a, METHOD_BUFFERED, FILE_ANY_ACCESS)		/**< User EventRegister for Kernel state */
#define RPP_IOCTL_USER_EVENTS_UNREGISTER    CTL_CODE(FILE_DEVICE_RPP, 0x90b, METHOD_BUFFERED, FILE_ANY_ACCESS)		/**< User EventUnregister for Kernel state */	
#define RPP_IOCTL_XFER_TO_DEV               CTL_CODE(FILE_DEVICE_RPP, 0x90c, METHOD_BUFFERED, FILE_ANY_ACCESS)      /**< Copy data from shared memory to device */
#define RPP_IOCTL_XFER_FROM_DEV             CTL_CODE(FILE_DEVICE_RPP, 0x90d, METHOD_BUFFERED, FILE_ANY_ACCESS)	    /**< Copy data from device to shared memory */
#define RPP_IOCTL_GETINTERRUPTINFO          CTL_CODE(FILE_DEVICE_RPP, 0x90e, METHOD_BUFFERED, FILE_ANY_ACCESS)	    /**< Get Interrupt info */
#define RPP_IOCTL_MAP_AND_XFER_TO_DEV       CTL_CODE(FILE_DEVICE_RPP, 0x90f, METHOD_BUFFERED, FILE_ANY_ACCESS)	    /**< User memory map and copy data to device */
#define RPP_IOCTL_MAP_AND_XFER_FROM_DEV     CTL_CODE(FILE_DEVICE_RPP, 0x910, METHOD_BUFFERED, FILE_ANY_ACCESS)	    /**< User memory map and copy data from device */
#define RPP_IOCTL_USER_MEM_GET_SGLIST       CTL_CODE(FILE_DEVICE_RPP, 0x911, METHOD_BUFFERED, FILE_ANY_ACCESS)	    /**< User mapped memory get sglist */
#define RPP_IOCTL_USER_MEM_MAP_SGLIST       CTL_CODE(FILE_DEVICE_RPP, 0x912, METHOD_BUFFERED, FILE_ANY_ACCESS)	    /**< User non-mapped memory map sglist */
#define RPP_IOCTL_USER_MEM_UNMAP_SGLIST     CTL_CODE(FILE_DEVICE_RPP, 0x913, METHOD_BUFFERED, FILE_ANY_ACCESS)	    /**< User non-mapped memory unmap sglist */
#define RPP_IOCTL_SETPARAM                  CTL_CODE(FILE_DEVICE_RPP, 0x914, METHOD_BUFFERED, FILE_ANY_ACCESS)	    /**< set some information for the card  */
#define RPP_IOCTL_PREPARE_DEVICE            CTL_CODE(FILE_DEVICE_RPP, 0x915, METHOD_BUFFERED, FILE_ANY_ACCESS)	    /**< Init prepare device to available status */
#define RPP_IOCTL_RELEASE_DEVICE            CTL_CODE(FILE_DEVICE_RPP, 0x916, METHOD_BUFFERED, FILE_ANY_ACCESS)	    /**< Exit release device to low power status  */
#define RPP_IOCTL_DIRECT_DMA_READ           CTL_CODE(FILE_DEVICE_RPP, 0x917, METHOD_OUT_DIRECT, FILE_ANY_ACCESS)	/**< PCIe DMA direct read with single channel */
#define RPP_IOCTL_DIRECT_DMA_WRITE          CTL_CODE(FILE_DEVICE_RPP, 0x918, METHOD_OUT_DIRECT, FILE_ANY_ACCESS)	/**< PCIe DMA direct write single channel */
#define RPP_IOCTL_END                       CTL_CODE(FILE_DEVICE_RPP, 0x919, METHOD_BUFFERED, FILE_ANY_ACCESS)      /**< end cdev IOCTL */

/**
 * @def Commonbuffer 0
 * @def Memory 1
 * @def ContiguousMemory 2
 * @def Pool 3
 * @def ContiguousMemorySpecifyCache 4
 */
#define KERNEL_MEMTYPE_COMMONBUFFER				0
#define KERNEL_MEMTYPE_MEMORY					1
#define KERNEL_MEMTYPE_CONTIGUOUSMEMORY			2	//maxsize <= 1GB
#define KERNEL_MEMTYPE_POOL						3
#define KERNEL_MEMTYPE_CONTIGUOUSSPACIFYCACHE	4	//maxsize <= 512MB

/**
 * @enum RPP_PARAMS_ENUM
 * The params.
 */
typedef enum {
	/* get params */
	RPP_GETPARAM_BUSID = 1,
	RPP_GETPARAM_BARTYPE = 2,
	RPP_GETPARAM_VDEV_MEMINFO = 3,
	RPP_GETPARAM_BARSIZE = 4,
	RPP_GETPARAM_BLCONFIG = 5,
	RPP_GETPARAM_PWR_MODE = 6,
	RPP_GETPARAM_WORK_MODE = 7,
	RPP_GETPARAM_IDLEDET_MODE = 8,

	/* set params */
	RPP_SETPARAM_PWR_MODE = (1 << 16),
	RPP_SETPARAM_WORK_MODE = (2 << 16),
	RPP_SETPARAM_IDLEDET_MODE = (3 << 16),
	RPP_SETPARAM_OTHER_MODE = 0x7fff0000,
} RPP_PARAMS_ENUM;

#define RPP_SETPARAMS_MASK      0xFFFF0000

/**
 * @brief work mode
 */	
#define WORKMODE_DFS_BIT    0	/**< Bit position of DFS mode, use 1 bit */
#define WORKMODE_VE_BIT     1	/**< Bit Position of VE mode, use 1 bit */
#define WORKMODE_BOOST_BIT	2	/**< Bit Position of BOOST mode, use 1 bit */
#define WORKMODE_PERF_BIT	3	/**< Bit Position of Performance mode, use 4 bits */

#define RPP_WORKMODE_DFS_DISABLE			(0x0 << WORKMODE_DFS_BIT)	
#define RPP_WORKMODE_DFS_ENABLE				(0x1 << WORKMODE_DFS_BIT)
#define RPP_WORKMODE_VE_DISABLE				(0x0 << WORKMODE_VE_BIT)
#define RPP_WORKMODE_VE_ENABLE				(0x1 << WORKMODE_VE_BIT)
#define RPP_WORKMODE_BOOST_DISABLE			(0x0 << WORKMODE_BOOST_BIT)
#define RPP_WORKMODE_BOOST_ENABLE			(0x1 << WORKMODE_BOOST_BIT)
#define RPP_WORKMODE_MODE0					(0x1 << WORKMODE_PERF_BIT)
#define RPP_WORKMODE_MODE1					(0x2 << WORKMODE_PERF_BIT)
#define RPP_WORKMODE_MODE2					(0x3 << WORKMODE_PERF_BIT)
#define RPP_WORKMODE_MODE3					(0x4 << WORKMODE_PERF_BIT)
#define	RPP_WORKMODE_MODE4					(0x5 << WORKMODE_PERF_BIT)
#define RPP_WORKMODE_MODE5					(0x6 << WORKMODE_PERF_BIT)
#define RPP_WORKMODE_MODE6					(0x7 << WORKMODE_PERF_BIT)
#define RPP_WORKMODE_MODE7					(0x8 << WORKMODE_PERF_BIT)
#define RPP_WORKMODE_MODE8					(0x9 << WORKMODE_PERF_BIT)
#define RPP_WORKMODE_MODE9					(0xa << WORKMODE_PERF_BIT)
#define RPP_WORKMODE_MODE10					(0xb << WORKMODE_PERF_BIT)

#define RPP_PWRMODE_STOP_IDLEDET		0
#define RPP_PWRMODE_RESUME_IDLEDET		1

/**
 * dynamic frequency scaling, 0:disable, 1:boost_dfs enable, 2, low_freq_dfs enable
 * boost_dfs: the dynamic frequency is 1000/800/666/500/400/333/285/250/222/200 MHz
 * low_freq_dfs: the dynamic frequency is 800/400/233/200/160/133/114/100/88.8/80 MHz 
 */
#define    RPP_DFS_MODE_DISABLE     0
#define    RPP_DFS_MODE_BOOST       1
#define    RPP_DFS_MODE_LOW_FREQ    2

 /**
  * power mode
  */
typedef enum {
	RPP_PWRMODE_WORKING = 0x0,
	RPP_PWRMODE_LOW_POWER = 0x1,
} rpp_pwrmode_e;

/*
* The Mode Of Transfer
*/
#define SINGLE_BLOCK_MODE 1
#define MULTI_BLOCK_MODE  2

/*
* Bar number
*/
#define RPP_BAR_NUM 6

//
// Cdev ioctl request function
//

/**
 * @brief Setup a Rpp device.
 *
 * This function sets up the specified Rpp device for operation by sending
 * the necessary input data to the driver and receiving the output data.
 *
 * @param[in] hObject The handle of the Rpp device.
 * @param[in] indata  The input buffer that will be sent to the driver.
 * @param[in] insize  The length of the input buffer.
 * @param[out] outdata The output buffer that will be received from the driver.
 * @param[in] outsize The length of the output buffer.
 *
 * @note No support information provided.
 *
 * @return Upon success, the ioctl process in the driver returns 0. On failure, it returns a non-zero value.
 *
 * @code
 * // Sample usage:
 * int result = RppStart(hDevice, inputBuffer, inputSize, outputBuffer, outputSize);
 * if (result == 0) {
 *     // Device setup succeeded
 * } else {
 *     // Handle error
 * }
 * @endcode
 */
int RppStart(HANDLE hObject, LPVOID indata, DWORD insize, LPVOID outdata, DWORD outsize);						/* RPP IOCTL Callback Start For IoctlCode */

/**
 * @brief To get Rpp device information as lists: busid/ve info/bar type/bar size/boot config/device state.
 *
 * @param[in] hObject The handle of Rpp device.
 * @param[in] indata  The input buffer (struct rpp_param_info) will be sent to the driver. Need to set the param of struct rpp_param_info to get special information.
 * @param[in] insize  The input buffer length.
 * @param[out] outdata The output buffer (struct rpp_param_info) will be received from the driver, and we will get the data in the value space of struct rpp_param_info.
 * @param[in] outsize The output buffer length.
 *
 * @note
 *
 * @see struct rpp_param_info
 *
 * @return If the ioctl I/O process is successful in the driver, it will return 0; otherwise, it will return a non-zero value.
 *
 * @code
 * // Sample usage
 * int result = RppGetParameter(hObject, input_data, input_size, output_data, output_size);
 * if (result == 0) {
 *     // Success
 * } else {
 *     // Error handling
 * }
 * @endcode
 */
int RppGetParameter(HANDLE hObject, LPVOID indata, DWORD insize, LPVOID outdata, DWORD outsize);				/* RPP Get Device Parmeter In Driver */

/**
 * @brief Map the BAR space of a Rpp device into user space.
 *
 * This function maps the Base Address Register (BAR) space of a Rpp device
 * from kernel space to user space, allowing the user application to access
 * the device's memory directly.
 *
 * @param[in] hObject The handle of the Rpp device.
 * @param[in] indata  The input buffer of type \c struct CdevBarInfo, which will be sent to the driver.
 *                    The \c index field within this structure should be set to specify the BAR space to map.
 * @param[in] insize  The length of the input buffer.
 * @param[out] outdata The output buffer of type \c struct CdevBarInfo, which will be received from the driver.
 *                     This structure will contain the mapped BAR information usable in user space.
 * @param[in] outsize The length of the output buffer.
 *
 * @note The \c index value should be between 0 and 2, inclusive.
 *
 * @see struct CdevBarInfo
 *
 * @return Upon success, the ioctl process in the driver returns 0. On failure, it returns a non-zero value.
 *
 * @code
 * // Sample usage:
 * struct CdevBarInfo barInfo;
 * // ... (Initialize barInfo and set the index)
 * int result = RppBarMap(hDevice, &barInfo, sizeof(barInfo), &barInfo, sizeof(barInfo));
 * if (result == 0) {
 *     // BAR space mapped successfully
 * } else {
 *     // Handle error
 * }
 * @endcode
 */
int RppBarMap(HANDLE hObject, LPVOID indata, DWORD insize, LPVOID outdata, DWORD outsize);					    /* Device Bar Space From Kernel State Map Into User State */

/**
 * @brief Unmaps the BAR space of a Rpp device from user space.
 *
 * This function is used to unmap the Base Address Register (BAR) space of a Rpp
 * device that was previously mapped into user space, allowing the system to
 * free resources associated with that mapping.
 *
 * @param[in] hObject The handle of the Rpp device.
 * @param[in] indata  The input buffer of type \c struct CdevBarInfo, which will be sent to the driver.
 *                    It should be configured to specify the BAR to be unmapped.
 * @param[in] insize  The size of the input buffer in bytes.
 * @param[out] outdata The output buffer of type \c struct CdevBarInfo, which may receive additional information from the driver.
 * @param[in] outsize The size of the output buffer in bytes.
 *
 * @note Ensure that the BAR space is no longer needed before calling this function.
 *
 * @see struct CdevBarInfo
 *
 * @return Upon successful completion of the ioctl process in the driver, the function returns 0.
 *         On failure, it returns a non-zero error code.
 *
 * @code
 * // Sample usage:
 * struct CdevBarInfo barInfo;
 * // ... (Prepare barInfo for the unmap operation)
 * int result = RppBarUnmap(hDevice, &barInfo, sizeof(barInfo), &barInfo, sizeof(barInfo));
 * if (result == 0) {
 *     // BAR space unmapped successfully
 * } else {
 *     // Handle error
 * }
 * @endcode
 */
int RppBarUnmap(HANDLE hObject, LPVOID indata, DWORD insize, LPVOID outdata, DWORD outsize);				    /* Device Bar Space Unmap User State */

/**
 * @brief Allocates kernel memory space for user-mode access.
 *
 * This function allocates memory in the kernel space that can be accessed by
 * user-mode applications. It is a critical operation that must be paired with
 * proper memory deallocation to prevent system instability.
 *
 * @param[in] hObject The handle of the Rpp device.
 * @param[in] indata  The input buffer of type \c struct CdevMemInfo, sent to the driver to configure the type and size of the kernel memory to be allocated.
 * @param[in] insize  The length of the input buffer in bytes.
 * @param[out] outdata The output buffer of type \c struct CdevMemInfo, received from the driver, containing the allocated kernel memory address and other information about the allocated space.
 * @param[in] outsize The length of the output buffer in bytes.
 *
 * @attention This is a risky operation. It is mandatory to free the allocated memory upon process exit. Failure to do so may result in a system crash (blue screen).
 *
 * @see struct CdevMemInfo
 *
 * @return On success, the ioctl process in the driver returns 0. On failure, a non-zero error code is returned.
 *
 * @code
 * // Sample usage:
 * struct CdevMemInfo memInfo;
 * // ... (Initialize memInfo with desired memory allocation parameters)
 * int result = RppKernelMemoryAlloc(hDevice, &memInfo, sizeof(memInfo), &memInfo, sizeof(memInfo));
 * if (result == 0) {
 *     // Kernel memory allocated successfully
 *     // Use the allocated memory pointed by memInfo.address
 * } else {
 *     // Handle allocation failure
 * }
 * @endcode
 */
int RppKernelMemoryAlloc(HANDLE hObject, LPVOID indata, DWORD insize, LPVOID outdata, DWORD outsize);			/* Alloc Memory In Kernel State */

/**
 * @brief Frees allocated kernel memory space.
 *
 * This function is used to release previously allocated kernel memory that is
 * accessible to the user-mode application. It is important to call this function
 * to avoid memory leaks and maintain system stability.
 *
 * @param[in] hObject The handle of the Rpp device.
 * @param[in] indata  The input buffer of type \c struct CdevMemInfo, which is sent to the driver. It should contain the necessary information to identify the memory space to be freed.
 * @param[in] insize  The size of the input buffer in bytes.
 * @param[out] outdata The output buffer of type \c struct CdevMemInfo, which may be used to receive confirmation or additional information from the driver about the freed memory.
 * @param[in] outsize The size of the output buffer in bytes.
 *
 * @note Ensure that the memory being freed is no longer in use before calling this function.
 *
 * @see struct CdevMemInfo
 *
 * @return On success, the ioctl process in the driver returns 0. On failure, a non-zero error code is returned.
 *
 * @code
 * // Sample usage:
 * struct CdevMemInfo memInfo;
 * // ... (Prepare memInfo with the information needed to free the memory)
 * int result = RppKernelMemoryFree(hDevice, &memInfo, sizeof(memInfo), NULL, 0);
 * if (result == 0) {
 *     // Kernel memory freed successfully
 * } else {
 *     // Handle memory free failure
 * }
 * @endcode
 */
int RppKernelMemoryFree(HANDLE hObject, LPVOID indata, DWORD insize, LPVOID outdata, DWORD outsize);			/* Free The Memory Of Kernel State */

/**
 * @brief Maps allocated kernel memory space into user space.
 *
 * This function maps the allocated kernel memory into the user space, allowing
 * user-mode applications to access the memory directly. It is a critical operation
 * that should be followed by proper unmapping to prevent system instability.
 *
 * @param[in] hObject The handle of the Rpp device.
 * @param[in] indata  The input buffer of type \c struct CdevMemInfo, which contains the configuration data of the kernel memory to be mapped.
 * @param[in] insize  The length of the input buffer in bytes.
 * @param[out] outdata The output buffer of type \c struct CdevMemInfo, which receives the stored mapping information from the driver.
 * @param[in] outsize The length of the output buffer in bytes.
 *
 * @attention This operation is risky and requires the memory to be unmapped upon process exit to avoid causing a system crash (blue screen).
 *
 * @see struct CdevMemInfo
 *
 * @return On success, the ioctl process in the driver returns 0. On failure, a non-zero error code is returned.
 *
 * @code
 * // Sample usage:
 * struct CdevMemInfo memInfo;
 * // ... (Initialize memInfo with the details of the kernel memory to be mapped)
 * int result = RppKernelMemoryMap(hDevice, &memInfo, sizeof(memInfo), &memInfo, sizeof(memInfo));
 * if (result == 0) {
 *     // Kernel memory mapped successfully
 *     // Use the mapped memory in user space
 * } else {
 *     // Handle mapping failure
 * }
 * @endcode
 */
int RppKernelMemoryMap(HANDLE hObject, LPVOID indata, DWORD insize, LPVOID outdata, DWORD outsize);				/* The Kernel Memory Map Into User State */

/**
 * @brief Unmaps kernel memory space from user space.
 *
 * This function is responsible for unmapping kernel memory that has been previously mapped into user space. It is a critical operation to ensure that all resources are properly released.
 *
 * @param[in] hObject The handle of the Rpp device.
 * @param[in] indata  The input buffer of type \c struct CdevMemInfo, which contains the mapping information of the kernel memory to be unmapped.
 * @param[in] insize  The size of the input buffer in bytes.
 * @param[out] outdata The output buffer of type \c struct CdevMemInfo, which may receive additional information from the driver after the unmapping process.
 * @param[in] outsize The size of the output buffer in bytes.
 *
 * @note It is the caller's responsibility to ensure that the memory is no longer needed before unmapping.
 *
 * @see struct CdevMemInfo
 *
 * @return On success, the ioctl process in the driver returns 0. On failure, a non-zero error code is returned.
 *
 * @code
 * // Sample usage:
 * struct CdevMemInfo memInfo;
 * // ... (Prepare memInfo with the mapping information to be unmapped)
 * int result = RppKernelMemoryUnmap(hDevice, &memInfo, sizeof(memInfo), NULL, 0);
 * if (result == 0) {
 *     // Kernel memory unmapped successfully
 * } else {
 *     // Handle unmapping failure
 * }
 * @endcode
 */
int RppKernelMemoryUnmap(HANDLE hObject, LPVOID indata, DWORD insize, LPVOID outdata, DWORD outsize);			/* The Kernel Memory Unmap User State */

/**
 * @brief Maps user memory space into kernel space.
 *
 * This function maps the user memory into the kernel space, allowing the kernel
 * to access user memory directly. It is an advanced and potentially risky operation
 * that requires careful management to prevent system instability.
 *
 * @param[in] hObject The handle of the Rpp device.
 * @param[in] indata  The input buffer of type \c struct CdevMemInfo, which contains the configuration for the user memory to be mapped into kernel space.
 * @param[in] insize  The size of the input buffer in bytes.
 * @param[out] outdata The output buffer of type \c struct CdevMemInfo, where the kernel may store mapping information, such as the kernel virtual address corresponding to the user memory.
 * @param[in] outsize The size of the output buffer in bytes.
 *
 * @attention This is a risky operation that must be paired with proper unmapping upon process exit. Failure to unmap the memory can lead to a system crash (blue screen).
 *
 * @see struct CdevMemInfo
 *
 * @return On success, the ioctl process in the driver returns 0. On failure, a non-zero error code is returned.
 *
 * @code
 * // Sample usage:
 * struct CdevMemInfo memInfo;
 * // ... (Initialize memInfo with the user memory mapping details)
 * int result = RppUserMemoryMap(hDevice, &memInfo, sizeof(memInfo), &memInfo, sizeof(memInfo));
 * if (result == 0) {
 *     // User memory mapped into kernel space successfully
 *     // Use the memory in kernel space
 * } else {
 *     // Handle mapping failure
 * }
 * @endcode
 */
int RppUserMemoryMap(HANDLE hObject, LPVOID indata, DWORD insize, LPVOID outdata, DWORD outsize);				/* User Memory Map Into Kernel State */

/**
 * @brief Unmaps user memory space from kernel space.
 *
 * This function is used to unmap user memory that has been mapped into kernel space, ensuring that the kernel no longer has direct access to the user memory.
 *
 * @param[in] hObject The handle of the Rpp device.
 * @param[in] indata  The input buffer of type \c struct CdevMemInfo, containing the mapping information of the user memory to be unmapped.
 * @param[in] insize  The size of the input buffer in bytes.
 * @param[out] outdata The output buffer of type \c struct CdevMemInfo, which may store additional information after the unmapping process. It can be NULL if no output is expected.
 * @param[in] outsize The size of the output buffer in bytes. This can be 0 if no output is expected.
 *
 * @note It is crucial to unmap the memory to avoid resource leaks and ensure the stability of the system.
 *
 * @see struct CdevMemInfo
 *
 * @return On success, the ioctl process in the driver returns 0. On failure, a non-zero error code is returned.
 *
 * @code
 * // Sample usage:
 * struct CdevMemInfo memInfo;
 * // ... (Prepare memInfo with the necessary information for unmapping)
 * int result = RppUserMemoryUnmap(hDevice, &memInfo, sizeof(memInfo), NULL, 0);
 * if (result == 0) {
 *     // User memory unmapped successfully
 * } else {
 *     // Handle unmapping failure
 * }
 * @endcode
 */
int RppUserMemoryUnmap(HANDLE hObject, LPVOID indata, DWORD insize, LPVOID outdata, DWORD outsize);				/* User Memory Unmap Kernel State */

/**
 * @brief Registers an event handle with the driver.
 *
 * This function allows an application to register an event handle with the Rpp device driver. This is useful for receiving notifications about specific events.
 *
 * @param[in] hObject The handle of the Rpp device.
 * @param[in] indata  The input buffer of type \c struct CdevEventRequest, which is sent to the driver to configure the registration of an event index.
 * @param[in] insize  The size of the input buffer in bytes.
 * @param[out] outdata The output buffer of type \c struct CdevEventRequest, which may be used to receive confirmation or additional information from the driver after the registration process.
 * @param[in] outsize The size of the output buffer in bytes.
 *
 * @note The maximum event index that can be registered is 15.
 *
 * @see struct CdevEventRequest
 *
 * @return On success, the ioctl process in the driver returns 0. On failure, a non-zero error code is returned.
 *
 * @code
 * // Sample usage:
 * struct CdevEventRequest eventRequest;
 * // ... (Initialize eventRequest with the desired event index and other necessary information)
 * int result = RppUserEventRegister(hDevice, &eventRequest, sizeof(eventRequest), NULL, 0);
 * if (result == 0) {
 *     // Event registration successful
 * } else {
 *     // Handle registration failure
 * }
 * @endcode
 */
int RppUserEventRegister(HANDLE hObject, LPVOID indata, DWORD insize, LPVOID outdata, DWORD outsize);		    /* User Events Register For IRO Send To User */

/**
 * @brief Unregisters an event handle from the driver.
 *
 * This function is used to unregister a previously registered event handle with the Rpp device driver, stopping the event notifications.
 *
 * @param[in] hObject The handle of the Rpp device.
 * @param[in] indata  The input buffer of type \c struct CdevEventRequest, which contains the configuration for the event index to be unregistered.
 * @param[in] insize  The size of the input buffer in bytes.
 * @param[out] outdata The output buffer of type \c struct CdevEventRequest, which may store additional information after the unregistration process. It can be NULL if no output is expected.
 * @param[in] outsize The size of the output buffer in bytes.
 *
 * @note The maximum event index that can be unregistered is 15. Ensure that the event handle is no longer needed before calling this function.
 *
 * @see struct CdevEventRequest
 *
 * @return On success, the ioctl process in the driver returns 0. On failure, a non-zero error code is returned.
 *
 * @code
 * // Sample usage:
 * struct CdevEventRequest eventRequest;
 * // ... (Initialize eventRequest with the event index to be unregistered)
 * int result = RppUserEventUnregister(hDevice, &eventRequest, sizeof(eventRequest), NULL, 0);
 * if (result == 0) {
 *     // Event unregistration successful
 * } else {
 *     // Handle unregistration failure
 * }
 * @endcode
 */
int RppUserEventUnregister(HANDLE hObject, LPVOID indata, DWORD insize, LPVOID outdata, DWORD outsize);			/* User Events Unregister */

/**
 * @brief Performs a DMA transfer to write mapped memory to the Rpp device.
 *
 * This function initiates a DMA transfer over PCIe to write data from a memory area mapped into user space to the Rpp device. It is used for efficient data transfer between host memory and device memory.
 *
 * @param[in] hObject The handle of the Rpp device.
 * @param[in] indata The input buffer of type \c struct CdevDmaRequest, which contains the configuration for the DMA transaction to be executed by the driver.
 * @param[in] insize The size of the input buffer in bytes, which should be sufficient to hold the \c struct CdevDmaRequest.
 * @param[out] outdata The output buffer, which may contain status or result information after the DMA transaction. If no output is expected, this can be NULL.
 * @param[in] outsize The size of the output buffer in bytes. If no output is expected, this should be 0.
 *
 * @note The specific requirements for the input and output buffers are determined by the driver and the DMA transaction details.
 *
 * @see struct CdevDmaRequest
 *
 * @return On success, the ioctl process in the driver returns 0. On failure, a non-zero error code is returned.
 *
 * @code
 * // Sample usage:
 * struct CdevDmaRequest dmaRequest;
 * // ... (Initialize dmaRequest with the necessary information for the DMA transfer)
 * int result = RppXferToDev(hDevice, &dmaRequest, sizeof(dmaRequest), NULL, 0);
 * if (result == 0) {
 *     // DMA transfer to device successful
 * } else {
 *     // Handle transfer failure
 * }
 * @endcode
 */
int RppXferToDev(HANDLE hObject, LPVOID indata, DWORD insize, LPVOID outdata, DWORD outsize);				    /* PCIe DMA Transfer Write To Device */

/**
 * @brief Reads data from the Rpp device using a PCIe DMA transfer from the mapped memory.
 *
 * This function configures and initiates a DMA transfer over PCIe to read data from the Rpp device into a memory area mapped into user space.
 *
 * @param[in] hObject The handle of the Rpp device.
 * @param[in] indata The input buffer of type \c struct CdevDmaRequest, sent to the driver to specify the DMA transaction parameters.
 * @param[in] insize The size of the input buffer in bytes, which should be sufficient to contain the \c struct CdevDmaRequest.
 * @param[out] outdata The output buffer, which may contain status or result information after the DMA transaction. If no output is expected, this can be NULL.
 * @param[in] outsize The size of the output buffer in bytes. If no output is expected, this should be 0.
 *
 * @note The function assumes that the transfer buffer is properly mapped and prepared for DMA transfers. The caller is responsible for ensuring the buffer is large enough to hold the expected data.
 *
 * @see struct CdevDmaRequest
 *
 * @return On success, the ioctl process in the driver returns 0. On failure, a non-zero error code is returned to indicate the nature of the error.
 *
 * @code
 * // Sample usage:
 * struct CdevDmaRequest dmaRequest;
 * // ... (Initialize dmaRequest with the necessary information for the DMA transfer)
 * // Assume 'mappedBuffer' is a pointer to the mapped memory where data will be read.
 * int result = RppXferFromDev(hDevice, &dmaRequest, sizeof(dmaRequest), NULL, 0);
 * if (result == 0) {
 *     // DMA transfer from device successful
 * } else {
 *     // Handle transfer failure
 * }
 * @endcode
 */
int RppXferFromDev(HANDLE hObject, LPVOID indata, DWORD insize, LPVOID outdata, DWORD outsize);					/* PCIe DMA Transfer Read From Device */

/**
 * @brief Retrieves interrupt information from the driver's FIFO.
 *
 * This function is used to scheduler and obtain interrupt information from the driver's FIFO, which is triggered by an MSI interrupt event.
 *
 * @param[in] hObject The handle of the Rpp device.
 * @param[in] indata NULL, as this function does not require an input buffer.
 * @param[in] insize 0, as this function does not require an input buffer.
 * @param[out] outdata The output buffer of type \c struct rpp_int_info, where the interrupt information retrieved from the driver will be stored.
 * @param[in] outsize The size of the output buffer in bytes, which should be sufficient to hold the interrupt information.
 *
 * @note This function utilizes the MSI interrupt event to trigger the retrieval of interrupt information.
 *
 * @see struct rpp_int_info
 *
 * @return On success, the ioctl process in the driver returns 0. On failure, a non-zero error code is returned.
 *
 * @code
 * // Sample usage:
 * struct rpp_int_info intInfo;
 * int result = RppGetInterruptInfo(hDevice, NULL, 0, &intInfo, sizeof(intInfo));
 * if (result == 0) {
 *     // Successfully retrieved interrupt information
 * } else {
 *     // Handle error in retrieving interrupt information
 * }
 * @endcode
 */
int RppGetInterruptInfo(HANDLE hObject, LPVOID indata, DWORD insize, LPVOID outdata, DWORD outsize);			/* Get Interrupt Information From Schedule Fifo */

/**
 * @brief Maps user space memory to the PCIe bus and performs a DMA transfer to write to the Rpp device.
 *
 * This function sets up a DMA transaction to transfer data from user space memory to the Rpp device via the PCIe bus. It is responsible for both mapping the memory and executing the DMA write operation.
 *
 * @param[in] hObject The handle of the Rpp device.
 * @param[in] indata The input buffer of type \c struct CdevDmaRequest, which contains the configuration for the DMA transaction to be executed by the driver.
 * @param[in] insize The size of the input buffer in bytes, which should be sufficient to contain the \c struct CdevDmaRequest.
 * @param[out] outdata Not used for this function. If provided, it should be NULL.
 * @param[in] outsize Not used for this function. Should be 0.
 *
 * @note The function assumes that the necessary memory has been allocated and is ready for DMA transfer. Any necessary synchronization or error checking should be handled before calling this function.
 *
 * @see struct CdevDmaRequest
 *
 * @return On success, the ioctl process in the driver returns 0. On failure, a non-zero error code is returned.
 *
 * @code
 * // Sample usage:
 * struct CdevDmaRequest dmaRequest;
 * // ... (Initialize dmaRequest with the necessary information for the DMA transfer)
 * // Assume 'mappedMemory' is a pointer to the user space memory to be transferred.
 * int result = RppMemoryMapAndXferToDev(hDevice, &dmaRequest, sizeof(dmaRequest), NULL, 0);
 * if (result == 0) {
 *     // DMA transfer to device successful
 * } else {
 *     // Handle transfer failure
 * }
 * @endcode
 */
int RppMemoryMapAndXferToDev(HANDLE hObject, LPVOID indata, DWORD insize, LPVOID outdata, DWORD outsize);		/* Map User Space Memory To PCIe Bus And PCIe DMA Transfer Write To Device */

/**
 * @brief Maps user space memory to the PCIe bus and performs a DMA transfer to read from the Rpp device.
 *
 * This function is responsible for setting up a DMA transaction to transfer data from the Rpp device to user space memory via the PCIe bus. It includes mapping the memory for DMA access and initiating the read operation.
 *
 * @param[in] hObject The handle of the Rpp device.
 * @param[in] indata The input buffer of type \c struct CdevDmaRequest, which contains the configuration for the DMA transaction to be executed by the driver.
 * @param[in] insize The size of the input buffer in bytes, which should be sufficient to contain the \c struct CdevDmaRequest.
 * @param[out] outdata Not used for this function. If provided, it should be NULL.
 * @param[in] outsize Not used for this function. Should be 0.
 *
 * @note The caller must ensure that the transfer buffer is properly allocated for DMA and the size is appropriate for the expected data transfer.
 *
 * @see struct CdevDmaRequest
 *
 * @return On success, the ioctl process in the driver returns 0. On failure, a non-zero error code is returned.
 *
 * @code
 * // Sample usage:
 * struct CdevDmaRequest dmaRequest;
 * // ... (Initialize dmaRequest with the necessary information for the DMA transfer)
 * // Assume 'mappedBuffer' is a pointer to the user space memory where data will be stored after DMA read.
 * int result = RppMemoryMapAndXferFromDev(hDevice, &dmaRequest, sizeof(dmaRequest), NULL, 0);
 * if (result == 0) {
 *     // DMA transfer from device to user space memory successful
 * } else {
 *     // Handle transfer failure
 * }
 * @endcode
 */
int RppMemoryMapAndXferFromDev(HANDLE hObject, LPVOID indata, DWORD insize, LPVOID outdata, DWORD outsize);		/* Map User Space Memory To PCIe Bus And PCIe DMA Transfer Read From Device */

/**
 * @brief Retrieves the scatter-gather list for the mapped memory.
 *
 * This function is used to obtain the scatter-gather list from the driver, which contains the mappings of logical addresses to physical addresses on the PCIe bus for the mapped memory blocks.
 *
 * @param[in] hObject The handle of the Rpp device.
 * @param[in] indata The input buffer of type \c struct CdevSGList, which is sent to the driver to configure or specify the scatter-gather operation.
 * @param[in] insize The size of the input buffer in bytes, which should be sufficient to contain the necessary information for the scatter-gather list request.
 * @param[out] outdata The output buffer of type \c struct CdevSGList, where the driver will store the retrieved scatter-gather list information.
 * @param[in] outsize The size of the output buffer in bytes, which should be large enough to hold the returned scatter-gather list.
 *
 * @note The exact structure and use of the input buffer may depend on the specific driver implementation and the requirements for scatter-gather list retrieval.
 *
 * @see struct CdevSGList
 *
 * @return On success, the ioctl process in the driver returns 0. On failure, a non-zero error code is returned.
 *
 * @code
 * // Sample usage:
 * struct CdevSGList sgListRequest; // Assume this is properly initialized.
 * struct CdevSGList sgListResult;
 * DWORD resultSize = sizeof(sgListResult);
 *
 * // Request the scatter-gather list from the driver.
 * int result = RppMemoryGetSGList(hDevice, &sgListRequest, sizeof(sgListRequest), &sgListResult, resultSize);
 * if (result == 0) {
 *     // Successfully retrieved the scatter-gather list.
 *     // sgListResult now contains the list of physical addresses.
 * } else {
 *     // Handle error in retrieving the scatter-gather list.
 * }
 * @endcode
 */
int RppMemoryGetSGList(HANDLE hObject, LPVOID indata, DWORD insize, LPVOID outdata, DWORD outsize);				/* Get Mapped User Space Memory PCIe Bus Physical Address List */

/**
 * @brief Maps user space memory to the PCIe bus and retrieves the scatter-gather list.
 *
 * This function maps user space memory to the PCIe bus and gets the scatter-gather list, which includes the physical address mappings for the memory blocks on the PCIe bus.
 *
 * @param[in] hObject The handle of the Rpp device.
 * @param[in] indata The input buffer of type \c struct CdevSGList, which is sent to the driver to define the scatter-gather list configuration, including logical addresses and lengths.
 * @param[in] insize The size of the input buffer in bytes, which should be sufficient to contain the input structure.
 * @param[out] outdata The output buffer of type \c struct CdevSGList, where the driver will store the retrieved scatter-gather list containing the physical address mappings.
 * @param[in] outsize The size of the output buffer in bytes, which should be large enough to hold the returned scatter-gather list information.
 *
 * @note The function assumes that the input buffer is properly initialized with the required information for mapping and list retrieval.
 *
 * @see struct CdevSGList
 *
 * @return On success, the ioctl process in the driver returns 0. On failure, a non-zero error code is returned.
 *
 * @code
 * // Sample usage:
 * struct CdevSGList sgList;
 * DWORD inSize = sizeof(sgList); // Size of the input structure
 * DWORD outSize = sizeof(sgList); // Size of the output structure
 *
 * // Map the user space memory and get the scatter-gather list.
 * int result = RppMemoryMapSGList(hDevice, &sgList, inSize, &sgList, outSize);
 * if (result == 0) {
 *     // Successfully mapped memory and retrieved the scatter-gather list.
 * } else {
 *     // Handle error in mapping memory or retrieving the scatter-gather list.
 * }
 * @endcode
 */
int RppMemoryMapSGList(HANDLE hObject, LPVOID indata, DWORD insize, LPVOID outdata, DWORD outsize);				/* Map User Space Memory To PCIe Bus And Get Physical Address List */

/**
 * @brief Unmaps user space memory and frees the scatter-gather list.
 *
 * This function is used to unmap user space memory from the PCIe bus and frees any associated scatter-gather list resources.
 *
 * @param[in] hObject The handle of the Rpp device.
 * @param[in] indata The input buffer of type \c struct CdevSGList, which includes the configuration for the scatter-gather list to be freed. It contains logical addresses, lengths, and other necessary information.
 * @param[in] insize The size of the input buffer in bytes, which should be sufficient to contain the input structure.
 * @param[out] outdata Not used for this function. If provided, it should be NULL.
 * @param[in] outsize Not used for this function. Should be 0.
 *
 * @note The function should be called after the memory is no longer needed to ensure that resources are properly released.
 *
 * @see struct CdevSGList
 *
 * @return On success, the ioctl process in the driver returns 0. On failure, a non-zero error code is returned.
 *
 * @code
 * // Sample usage:
 * struct CdevSGList sgList; // Assume this is properly initialized with the information to be freed.
 * DWORD inSize = sizeof(sgList); // Size of the input structure
 *
 * // Unmap the user space memory and free the scatter-gather list.
 * int result = RppMemoryUnmapSGList(hDevice, &sgList, inSize, NULL, 0);
 * if (result == 0) {
 *     // Successfully unmapped memory and freed the scatter-gather list.
 * } else {
 *     // Handle error in unmapping memory or freeing the scatter-gather list.
 * }
 * @endcode
 */
int RppMemoryUnmapSGList(HANDLE hObject, LPVOID indata, DWORD insize, LPVOID outdata, DWORD outsize);			/* Unmap User Space Memory To PCIe Bus And Free Physical Address List */

/**
 * @brief Sets the Rpp device work mode and power mode.
 *
 * This function sends configuration parameters to the Rpp device driver to set the device's work mode (such as DFS - Dynamic Frequency Scaling, VE - Vector Engine, Boost mode or Performance mode) and power mode.
 *
 * @param[in] hObject The handle of the Rpp device.
 * @param[in] indata The input buffer of type \c struct rpp_param_info, which contains the configuration parameters for setting the specific mode. This buffer is sent to the driver.
 * @param[in] insize The size of the input buffer in bytes.
 * @param[out] outdata Not used for this function. If provided, it should be NULL.
 * @param[in] outsize Not used for this function. Should be 0.
 *
 * @note The exact configuration parameters and their effects may depend on the Rpp device and driver implementation.
 *
 * @see struct rpp_param_info
 *
 * @return On success, the ioctl process in the driver returns 0. On failure, a non-zero error code is returned.
 *
 * @code
 * // Sample usage:
 * struct rpp_param_info paramInfo;
 * // ... (Initialize paramInfo with the desired work and power mode settings)
 * DWORD inSize = sizeof(paramInfo);
 *
 * // Set the Rpp device mode.
 * int result = RppSetParameter(hDevice, &paramInfo, inSize, NULL, 0);
 * if (result == 0) {
 *     // Successfully set the Rpp device mode.
 * } else {
 *     // Handle error in setting the Rpp device mode.
 * }
 * @endcode
 */
int RppSetParameter(HANDLE hObject, LPVOID indata, DWORD insize, LPVOID outdata, DWORD outsize);				/* Set Rpp device mode(Power/Work) */

/**
 * @brief Device initialization before preparing to use the device.
 * 
 * This function will restore the device from low-power mode to working mode, and the implementation of the recovery process depends on the low-power support characteristics of the board and host.
 * 
 * @param[in] hObject The handle of the Rpp device.
 * @param[in] indata The input buffer no used, set to NULL.
 * @param[in] insize The size of the input buffer in bytes, it will be zero.
 * @param[out] outdata The output buffer no used, set to NULL.
 * @param[in] outsize The size of the output buffer in bytes, it will be zero.
 * 
 * @note This processing may depend on the Rpp device and driver implementation.
 *
 * @see None
 * 
 * @return On success, the ioctl process in the driver returns 0. On failure, a non-zero error code is returned.
 * 
 * @code
 * // Sample usage:
 *
 * // Rpp device preparation.
 * int result = RppPrepareDevice(hDevice, NULL, 0, NULL, 0);
 * if (result == 0) {
 *     // Successfully make the device ready.
 * } else {
 *     // Handle error in making the device ready.
 * }
 * @endcode
 */
int RppPrepareDevice(HANDLE hObject, LPVOID indata, DWORD insize, LPVOID outdata, DWORD outsize);

/**
 * @brief When the device is no longer in use, it should be released before shutting it down.
 * 
 * This function will cause the device to return from working mode to low-power mode if there are no applications continuing to use the device. The return of low-power processing depends on the low-power characteristics supported by the board and host.
 * 
 * @param[in] hObject The handle of the Rpp device.
 * @param[in] indata The input buffer no used, set to NULL.
 * @param[in] insize The size of the input buffer in bytes, it will be zero.
 * @param[out] outdata The output buffer no used, set to NULL.
 * @param[in] outsize The size of the output buffer in bytes, it will be zero.
 * 
 * @note This processing may depend on the Rpp device and driver implementation.
 *
 * @see None
 *
 * @return On success, the ioctl process in the driver returns 0. On failure, a non-zero error code is returned.
 *
 * @code
 * // Sample usage:
 *
 * // Rpp device release.
 * int result = RppReleaseDevice(hDevice, NULL, 0, NULL, 0);
 * if (result == 0) {
 *     // Successfully make the device idle.
 * } else {
 *     // Handle error in making the device idle.
 * }
 * @endcode
 */
int RppReleaseDevice(HANDLE hObject, LPVOID indata, DWORD insize, LPVOID outdata, DWORD outsize);

/**
 * @brief Reads data from the Rpp device using a PCIe DMA transfer from the host memory.
 *
 * This function configures and initiates a DMA transfer over PCIe to read data from the Rpp device into a memory area using single channel.
 *
 * @param[in] hObject The handle of the Rpp device.
 * @param[in] indata The input buffer of type \c struct CdevDmaRequest, sent to the driver to specify the DMA transaction parameters.
 * @param[in] insize The size of the input buffer in bytes, which should be sufficient to contain the \c struct CdevDmaRequest.
 * @param[out] outdata The output buffer, which wiil be stored DMA read data.
 * @param[in] outsize The size of the output buffer in bytes. 
 *
 * @note The function assumes that the transfer buffer is properly allocated and prepared for DMA transfers. The caller is responsible for ensuring the buffer is large enough to hold the expected data.
 *
 * @see struct CdevDmaRequest
 *
 * @return On success, the ioctl process in the driver returns 0. On failure, a non-zero error code is returned to indicate the nature of the error.
 *
 * @code
 * // Sample usage:
 * struct CdevDmaRequest dmaRequest;
 * // ... (Initialize dmaRequest with the necessary information for the DMA transfer)
 * // Assume 'buffer' is a pointer to the transfer memory where data will be read.
 * int result = RppDirectDMARead(hDevice, &dmaRequest, sizeof(dmaRequest), buffer, bufferSize);
 * if (result == 0) {
 *     // DMA transfer from device successful
 * } else {
 *     // Handle transfer failure
 * }
 * @endcode
 */
int RppDirectDMARead(HANDLE hObject, LPVOID indata, DWORD insize, LPVOID outdata, DWORD outsize);

/**
 * @brief Performs a DMA transfer to write host memory to the Rpp device.
 *
 * This function initiates a DMA transfer over PCIe to write data from a memory area allocated into user space to the Rpp device. It is used for efficient data transfer between host memory and device memory.
 *
 * @param[in] hObject The handle of the Rpp device.
 * @param[in] indata The input buffer of type \c struct CdevDmaRequest, which contains the configuration for the DMA transaction to be executed by the driver.
 * @param[in] insize The size of the input buffer in bytes, which should be sufficient to hold the \c struct CdevDmaRequest.
 * @param[out] outdata The output buffer, which will be store DMA write data.
 * @param[in] outsize The size of the output buffer in bytes.
 *
 * @note The specific requirements for the input and output buffers are determined by the driver and the DMA transaction details.
 *
 * @see struct CdevDmaRequest
 *
 * @return On success, the ioctl process in the driver returns 0. On failure, a non-zero error code is returned.
 *
 * @code
 * // Sample usage:
 * struct CdevDmaRequest dmaRequest;
 * // ... (Initialize dmaRequest with the necessary information for the DMA transfer)
 * // Assume 'buffer' is a pointer to the transfer memory where data will be write.
 * int result = RppDirectDMAWrite(hDevice, &dmaRequest, sizeof(dmaRequest), buffer, bufferSize);
 * if (result == 0) {
 *     // DMA transfer to device successful
 * } else {
 *     // Handle transfer failure
 * }
 * @endcode
 */
int RppDirectDMAWrite(HANDLE hObject, LPVOID indata, DWORD insize, LPVOID outdata, DWORD outsize);
	
/*
 * Defines a structure to encapsulate event request information for the Rpp device.
 * This structure is used to register and manage events with the Rpp device driver.
 */
struct CdevEventRequest {
    UINT32 pid;							/**< Process ID of the user application. */
    UINT8 index;						/**< Index of the event to register (0 to 15). */
    HANDLE event;						/**< Event handle to be registered. */
};

/*
 * Defines a structure to represent the BAR (Base Address Register) information for a device.
 * This structure is used to manage the mapping and properties of device memory regions.
 */
struct CdevBarInfo {
	UINT8 status;              /**< Status flag: bit 0 indicates whether the BAR is mapped (1) or unmapped (0). */
	UINT8 index;               /**< The index of the BAR to map (0 to 2). */
	UINT32 size;               /**< The size of the BAR region. */
	ULONG64 phy_addr;          /**< The physical address of the BAR region. */
	PVOID kernel_addr;         /**< The kernel virtual address corresponding to the BAR region. */
	PVOID user_addr;           /**< The user virtual address where the BAR is mapped. */
	PVOID mdl;                 /**< Memory Descriptor List (MDL) for the BAR, used for mapping between kernel and user space. */
};

/*
 * Defines a structure to hold parameter information for an RPP device.
 * This structure is used to set or get various configuration parameters
 * of the RPP device, with the specific parameter defined by an enumerator.
 */
struct rpp_param_info {
	UINT64 param;            /**< Parameter identifier, referring to values defined in RPP_PARAMS_ENUM. */
	UINT8 value[128];        /**< Buffer to hold the data for send or receive operations related to the parameter. */
};

/*
 * Defines a structure to hold idle parameter information for an RPP device.
 * This structure is used to set or get various configuration parameters
 * of the RPP device, with the specific parameter defined by an enumerator.
 */
struct rpp_idle_states {
	UINT32 enable;				/**< [In/Out] idle enable / idle state */
	UINT32 flag;				/**< [In/Out] force setting / d3coldsupport */
	UINT32 device_healthy;		/**< device available flags:
								  * bit0: PCIe Link reset is 0 but normal is 1
									   device PCIe Link Gen3--> Gen1 or Gen1 --> Gen3 workaround bug fix
								  * bit1: Mpu firmware load failed or not loaded is 0, loaded success is 1
								  * bit[2:31]: reserved */
	UINT32 driver_version;		/**< Driver version */
};

/*
 * The direction of DMA transfer.
 */
typedef enum {
	DMA_WRITE = 0,  /**< Write */
	DMA_READ        /**< Read */
} DMA_DIRC;

/*
 * Defines a structure for a PCIe DMA transfer test in kernel space.
 * This structure is used to encapsulate all the necessary information for a DMA transfer request.
 */
struct DmaRequestTest {
	UINT32 size;                      /**< Size of the data to be transferred in the DMA operation. */
	UINT32 offset;                    /**< Offset within the VE DMA buffer for the transfer. */
	PVOID host;                       /**< Host buffer address (virtual memory address), must be physically contiguous. */

	UINT64 device;                    /**< VE device buffer address (physical DDR address). */
	UINT8 chenel;                     /**< PCIe DMA channel select. */
	DMA_DIRC rw;                      /**< DMA transfer direction, read or write. */
};

/*
 * Defines a structure for a PCIe DMA transfer request in kernel space.
 * This structure encapsulates the parameters required for a DMA transfer operation.
 */
struct DmaRequest {
	UINT32	size;						/**< Size of the data transfer request. */
	UINT32	offset;						/**< Offset within the VE DMA buffer for the transfer operation. */
	PVOID	host;						/**< Host buffer address (virtual memory address), must be physically contiguous. */

	UINT64	device;						/**< VE device buffer address (physical DDR address). */
};


/*
 * Defines a structure for a PCIe DMA transfer request.
 * This structure encapsulates all the necessary parameters for a DMA transfer operation.
 */
struct CdevDmaRequest {
	UINT8	mode;                       /**< Transfer mode: single or multi-block. */
	UINT32	size;						/**< Total size of the data transfer request. */
	UINT32	host_offset;				/**< Offset within the host DMA buffer. */
	PVOID	host_addr;					/**< Host buffer virtual address, must be physically contiguous.
											Case 0: If mem_type is Kernel memory, host_addr is the kernel address.
											Case 1: If mem_type is User memory, host_addr is the user address. */
	UINT64	mem_size;					/**< Total size of the host buffer. */
	UINT64	mdl;						/**< Memory Descriptor List (MDL) for the host buffer. */
	UINT32	dev_offset;					/**< Offset within the device DMA buffer. */
	UINT64	dev_addr;					/**< Device buffer address (physical DDR address). */
	UINT8	chan;						/**< PCIe DMA channel select. */
	//DMA_DIRC rw;						/* DMA transfer direction: Read or Write. This field is currently not used, but could be added if needed. */
};


/*
 * Defines a structure for memory information used in DMA transactions.
 * This structure is used to specify the properties of memory for kernel and user space,
 * including type, status, size, and addresses for mapping and MDL (Memory Descriptor List) usage.
 */
struct CdevMemInfo {
	UINT8 type;           /**< Memory type: kernel or user memory. */
	UINT8 status;         /**< Status flags:
							*  bit 0 - User allocated or free.
							*  bit 1 - Kernel allocated or free.
							*  bit 2 - Map or unmap operation. */
	UINT32 size;          /**< Size of the memory block. */
	PVOID virt_addr;      /**< Virtual address used to create an MDL. */
	UINT64 mdl;           /**< MDL value, used for memory mapping. */
	UINT64 phy_addr;      /**< Physical start address (currently not used). */

	PVOID user_addr;      /**< Start virtual address of the memory in user space (if applicable). */
	UINT8 user_memtype;   /**< User memory type (currently not used). */

	PVOID kernel_addr;    /**< Start virtual address of the memory in kernel space. */
	UINT8 kernel_memtype; /**< Kernel memory type. */

	// WDFCOMMONBUFFER common_buffer; /* For DMA contiguous physical address allocation (not used). */
	// WDFMEMORY memory; /* WDF memory object (not used). */
};

/*
 * Represents interrupt information for an RPP device.
 * This structure is used to store and manage interrupt vector and related information.
 */
struct rpp_int_info {
	UINT32 int_vector;  /**< Interrupt vector where[0:15] represents the interrupt source :
						 * 0 - Scheduler, 1 - Microprocessor Unit, [16-31] - Device index. */
	UINT32 int_info1;   /**< Additional interrupt information 1 (purpose should be documented). */
	UINT32 int_info2;   /**< Additional interrupt information 2 (purpose should be documented). */
	UINT32 int_info3;   /**< Additional interrupt information 3 (purpose should be documented). */
	UINT32 int_desc[8]; /**< Array of 8 interrupt descriptors, each providing further details about the interrupt. */
	struct timespec64 {
		LONGLONG tv_sec;	/**< seconds */
		LONG tv_nsec;		/**< nanoseconds */
	} isr_kts;
};

/* 
 * Define a structure to obtain configuration information of the board.
 */
typedef struct ee_control_header_struct_t {
	UINT16 magic_number;
	UINT16 size;
	UINT16 version;		// 3
	UINT16 board_info;  // 0x0000 - dudi, 0x0001 - v4, 0x0002 - M3, 0x0003 - M5, 0x0004 - A4, 0x0005 - A8, 0x0006 - A9_V1, 0x0007 - A9_V2 (board version)

	/*
	 * @brief board basic configurations.
	 * 
	 * bit[3:0]:MaxNumDDR 1 or 4;
	 * bit[11:4]:ddrsize;//0001 - 1GB, 0010 - 2GB, 0100 - 4GB, 1000 - 8GB, 10000 - 16GB 10000 - 32GB 100000 - 64GB
	 * bit[15:12]:PCIeGen; // Gen2 or Gen3
	 * bit[19:16]:PCIe_lane; //0x1 – x1, 0x2 – x2, 0x4 - x4
	 * bit[23:20]:bar_size, 0 – normal, 1 – small bar
	 * bit[27:24]:wdt_en, 0 – disable, 1 – enable
	 * bit[31:28]:chip_version; // 0 - r8, 1 - r9
	 */
	UINT32 board_mn;

	/*
	 * @brief frequency setting parameters.
	 * 
	 * bit[11:0]:MaxRppFreq;// 600MHz, 800MHz, 1000MHz bit[31]:BoostModeCap; // =1: enable boost mode, =0: disable boost mode. Cannot set to '1' if MaxRppFreq<1GHz
	 * bit[23:12]:DefFreq; // 600MHz, 800MHz, 1000MHz --> max pll1 frequency for setworkmode
	 * bit[30:24]:BoostModeTriggerLimit; // When GPU loading reaches this limit,then trigger the boost // =0:no limit, =1: 15%, =2: 30%, =3: 45%, =4:60%, =5: 75%, =6: 90%, =7: 100%
	 * bit[31]: BoostModeCap; // =1: enable boost mode, =0: disable boost mode. Cannot set to '1' if MaxRppFreq<1GHz
	 */
	UINT32 freq;
	

	UINT32   sn[4];
	UINT32   date;

	/*
	 * @brief temperature line parameters.
	 * 
	 * bit[7:0]:The temperature that triggers the fan to turn on while waiting for sema;//97
	 * bit[15:8]:The temperature that triggers shutdown while waiting for sema; // 104
	 * bit[27:16]:ddr vendor; // 0: micron; 1: samsung;
	 * bit[31:28]: ddr protocol; // 0: lpddr4; 1; lpddr4x
	 */
	UINT32   main_boot_temp_monitor;

	UINT32   pci_device_id_vendor_id;
	UINT32   pci_subsystem_id_subsystem_vendor_id;
	UINT32   pci_class_code_revision_id;
	UINT32   resv[3];
} EE_CONTROL_HDR, * EE_CONTROL_HDR_PTR;


/*
 * Represents a physical memory element with its continuous physical address, length,
 * and a reserved field for future use or specific conditions.
 */
struct CdevPhysicalElement {
	UINT64 Address;            /**< The 64-bit physical address of the memory element. */
	UINT32 Length;             /**< The length of the physical element in bytes. */
	ULONG_PTR Reserved;        /**< Reserved for future use or specific conditions, should be set to zero. */
};


/*
 * Represents a scatter-gather list for DMA operations, describing non-contiguous memory areas.
 */
struct CdevSGList {
	PVOID host_addr;          /**< Host buffer virtual address, must be physically contiguous.
								 Depending on the memory type:
								 - If mem_type is Kernel memory, host_addr points to the kernel address.
								 - If mem_type is User memory, host_addr points to the user address. */
	UINT64 mem_size;          /**< Total size of the host buffer in bytes. */
	UINT64 mdl;               /**< Memory Descriptor List (MDL) for the host buffer, used for DMA operations. */

	ULONG NumberOfElements;    /**< The number of physical elements in the list. */
	struct CdevPhysicalElement* eles;  /**< Pointer to an array of physical elements, each describing a non-contiguous memory area. */
};

#endif // !__LL_IOCTL_H__
