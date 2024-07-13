## LEVEL0

To begin with, we need to connect to the virtual machine using *SSH*.\
-> `ssh level0@{VM_ip} -p 4242`\
Next, we log-in with the password *level0*.

From here, we can start the project. Let's see what files we have to work with and from now on, we'll check what files are available in each level.\
-> `ls -la` or `la`\
As we can see, we only have an executable, *level0* and if we try to run it,\
-> `./level0`\
The program quit with a segmentation fault.\
So, we need to decompile the executable to look for a breach that we can exploit. For that, we'll be using *Ghidra*.

> **Ghidra** is an open source decompiler that helps getting the source code in Assembly and C from a binary file.

To import the binary file in *Ghidra*, we need to transfer it first.\
-> `scp -P 4242 level0@{VM_ip}:level0 .`\
Now, we open the file in *Ghidra* and we'll decompile it to get it's source code and find an exploitable breach.

In *Ghidra*, we can see that there's a check if the argument is equal to *"0x1a7"* to execute */bin/sh* with a set GID and UID. *(cf. source.c)*\
If we convert this value to decimal, we get *423*. Then, we run the binary file with the result.\
-> `./level0 423`

And we get a Shell prompt after the execution. From there, we check the informations about the newly set IDs.\
-> `id`\
As we can see, the UID is currently set to the user *level1*. So, we just have to open the content from the .pass file.\
-> `cd ..`\
-> `cat level1/.pass`

And we get our flag to access to level1.\
-> `su level1`