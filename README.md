# ml_shellexec

ml_shellexec is a module for [Multi Theft Auto: San Andreas] [1] that allows executing commands on Linux servers, and return the output of those commands as a string. This module enables just one serverside function:

```lua
string shellexec(string command)
```

The function will return the output of the executed command as a string, or false if anything went wrong.

> The module is based on ml_system, originally developed by x86 <sebasdevelopment@gmx.com>. Original module allowed executing commands but it returned a boolean value indicating if the command was succesfully executed or not. This version allows checking the output of the executed command instead.

### Compiling the module

To compile the module under a 32 bit Debian 6:
```sh
$ apt-get install libreadline5-dev libncurses5-dev
$ cd lib/lua51/
$ make linux
$ make install
$ cd ../..
$ make
```

Alternatively, you can download the precompiled binary file from http://git.pablophg.net/ml_shellexec/downloads/

### Installing the module

Place ml_shellexec.so compiled in the previous step on *mods/deathmatch/modules* on your existing MTA:SA installation. Then open *mods/deathmatch/mtaserver.conf* and add the following line:
```xml
<module src="ml_shellexec.so"/>
```

### Using the module

An example script:

```lua
function getServerDate()
    return shellexec('date')
end

local date = getServerDate()
outputChatBox('Server date is: '..date)
```

That will show something like: *Server date is: Mon Nov 10 06:16:11 UTC 2014* on the chat. Of course, it is nothing really useful to just get the date, as you could just use MTA's functions for that; but this module allows doing other interesting things like downloading files using *wget*, list directories, modify resources, connect to a Redis database, and more. What to use the module for is up to you.

[1]:https://code.google.com/p/mtasa-blue/