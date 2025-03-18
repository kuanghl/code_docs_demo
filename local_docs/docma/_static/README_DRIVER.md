### Rpp Driver For Windows.

#### About.

Rpp windows driver interfaces Introduce.

Support Windows 10 higher(includes Windows 10).

#### Features.

- Supported PCIe basical options in kernel space.
    - PCIe bar mapping and read/write.
    - PCIe configure space read/write.
    - PCIe DMA direct mode transfer and descriptors component block transfer.
    - 16 MSI interrupt process.
    - Power mode settings and Work mode settings by ioctl.
- Support bar map into user space.
- Support MSI interrupt send to user space by event.
- Support user space memory PCIe DMA transaction by ioctl.
- Support scather gather list get from kernel.
- Support device information get from kernel.
- Support set device work mode and power mode.
- Support memory zero copy between kernel space and user space.

#### Quickstart.

Refer to driver unit test code.

#### Doxygen.


