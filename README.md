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
```

Initial Implementation plan:
- read URL from arguments (done)
- do regular expression for URL, PORT, PATH (done)
- wget index file based on URL PATH (done)
- read within anchor <a> and </a>
- display list

Future implementation plans:
- read config file with linux path and URL
- detect local linux path, read URL
