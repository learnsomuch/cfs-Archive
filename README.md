# cfs (Cloud Filesystem)


## Setup
```
  # git clone https://github.com/learnsomuch/cfs.git
  # cd cfs
  # make 
  # make clean
  # ./cfs
  Usage: cfs <URL>
  <URL>		 Support http, https, port, path 
  If no arguments, print help
  
  
  Sample execution: 
  # ./cfs learnsomuch.com/demo
  ../
  test/
  README.md
```

Future implementation plans:
- read config file with linux path and URL
- detect local linux path, read URL
- Support switches (eg. ls, sync)
