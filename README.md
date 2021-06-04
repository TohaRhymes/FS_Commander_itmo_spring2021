## NTFS file system reader
__System Software lab 1__

[REPORT](https://github.com/TohaRhymes/FS_Commander_itmo_spring2021/blob/master/%D0%A1%D0%9F%D0%9E_%D0%BB%D0%B0%D0%B11_%D0%A7%D0%B0%D0%BD%D0%B3%D0%B0%D0%BB%D0%B8%D0%B4%D0%B8_P33122.docx.pdf)

### Launch
To run program in list mode use `list` key.
To run it in shell mode use `commander` key and specify drive or device descriptor.

### ```list```-example
Input:
```
$ sudo ./SPO_file_system list
```
Output:
```
System partition:
        /dev/nvme0n1p6  63996690432   B 7.45 GiB                TYPE=swap       UUID=a1806d01-8e3e-4685-98d2-d564acbfed4a       
        /dev/nvme0n1p5  311997497344   B        36.32 GiB               TYPE=ext4       UUID=e4a0739e-bdd9-4d78-a344-2f067fafabd8       
        /dev/loop0      5152931840   B  614.27 MiB              TYPE=squashfs   
        /dev/loop1      921862144   B   109.89 MiB              TYPE=squashfs   
        /dev/loop2      831717376   B   99.14 MiB               TYPE=squashfs   
        /dev/loop3      1366228992   B  162.86 MiB              TYPE=squashfs   
        /dev/loop4      643497984   B   76.71 MiB               TYPE=squashfs   
        /dev/loop5      634880000   B   75.68 MiB               TYPE=squashfs   
        /dev/loop6      921894912   B   109.89 MiB              TYPE=squashfs   
        /dev/loop7      832241664   B   99.21 MiB               TYPE=squashfs   
        /dev/nvme0n1p1  2181038080   B  260.0 MiB               TYPE=vfat       UUID=DC90-8D6B  LABEL=SYSTEM    
```

### ```commander``` launch
```
 sudo ./SPO_file_system commander /dev/sda1
```
