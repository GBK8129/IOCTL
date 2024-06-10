cmd_/home/hp/Desktop/IOCTL/Module.symvers := sed 's/\.ko$$/\.o/' /home/hp/Desktop/IOCTL/modules.order | scripts/mod/modpost -m -a  -o /home/hp/Desktop/IOCTL/Module.symvers -e -i Module.symvers   -T -
