## LEVEL1

In this level, we can notice from the source code that the main function make a call to *gets()* with a buffer of size 76 bytes. We can also see that there's a *run()* function that is not called. It looks like that this level is a *ret2win*.

> A **Ret2win** is a binary file where there is a hidden function that needs to be called but is not in the main.

Thus, we can use a buffer overflow exploit to make a call to *run()* and get access to the next level.

> A **Buffer Overflow Exploit**, takes advantage of the code overflowing in an unitended part of the memory to override some data and replace it.

To do so, we'll need to make a payload to inject the address of *run()* in the memory. To get the address of that function, we'll disassemble the binary.\
-> `objdump -d level1`\
Here, we can see that the function's address is *08048444*.Next, we'll fill the 76 bytes with any random characters and insert in this address in the next 4 bytes.

We just need to put all this content in our payload.\
-> `python -c 'print"A"*76 + "\x44\x84\x04\x08"' > /tmp/payload`\
And then, use this on the binary,\
-> `cat /tmp/payload - | ./level1`\
Finally, we have access to a shell where we can get the flag for the next level.\
-> `cd ..`\
-> `cat level2/.pass`