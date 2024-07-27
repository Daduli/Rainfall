## LEVEL0

To begin with, we need to connect to the virtual machine using *SSH*.\
-> `ssh level0@{VM_ip} -p 4242`\
Next, we log-in with the password *level0*.

From here, we can start the project. Let's see what files we have to work with and from now on, we'll check what files are available in each level.\
-> `ls -la` or `la`
```
.bash_logout  .bashrc  level0  .profile
```
As we can see, we only have an executable, *level0* and if we try to run it,\
-> `./level0`
```
Segmentation fault (core dumped)
```
The program quit with a segmentation fault.\
So, we need to decompile the executable to look for a breach that we can exploit. For that, we have multiple options:
* *Ghidra*
* *Decompiler Explorer*

Throughout this project, we'll be using both. But for this level, let's stick with *Ghidra*.

> **Ghidra** is an open source decompiler that helps getting the source code in Assembly and C from a binary file.

To import the binary file in *Ghidra*, we need to transfer it locally. Open another terminal:\
-> `scp -P 4242 level0@{VM_ip}:level0 .`
```
level0                                  100%  730KB   6.5MB/s   00:00
```
Now, we open the file in *Ghidra* to decompile it. From there, we can understand what the code is doing and find a breach in it.

In *Ghidra*, we can see that there's a check if the argument is equal to *"0x1a7"* to execute */bin/sh* with a set GID and UID. *(line 14)*\
If we convert this value to decimal, we get *423*. Then, we run the binary with the passcode.\
-> `./level0 423`
```
$
```

It seems that we get a Shell prompt after the execution. From there, we check the informations about the newly set IDs.\
-> `whoami`
```
level1
```
As we can see, we have the permissions of the user *level1*. So, we just have to open the content from the .pass file.\
-> `cd ..`\
-> `cat level1/.pass`

And we get our flag to access to level1.\
-> `su level1`

***LEVEL HACKED!***