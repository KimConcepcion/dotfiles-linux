#	Script to print system information in better format:
#!/bin/bash

echo "Information about system:"
echo "------------------------------------------------------------"
printf 'kernel-name:	   '; uname -s
printf 'nodename:	   '; uname -n
printf 'kernel-release:	   '; uname -r
printf 'kernel-version:    '; uname -v
printf 'machine:	   '; arch
printf 'processor:	   '; uname -p
printf 'hardware-platform: '; uname -i
printf 'operating-system:  '; uname -o
echo "------------------------------------------------------------"
