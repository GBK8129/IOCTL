cmd_/home/hp/Desktop/IOCTL/modules.order := {   echo /home/hp/Desktop/IOCTL/IOCTL.ko; :; } | awk '!x[$$0]++' - > /home/hp/Desktop/IOCTL/modules.order
