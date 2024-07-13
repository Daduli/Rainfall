## LEVEL3

In this level, we can see from the decompiled code, that we won't be able to exploit a buffer overflow because of *fgets()*. But we can notice that we can perform a *format string attack* from *printf()*.

> A *Format String Attack* is an exploit that takes advantage from the vulnerability of the format string to access memory and read, write or execute harmful code.

We can also see that there's a condition that compares an unitialized variable with the value 64. We'll use this to write into the memory and set the variable to 64.\
First, we'll need to find the offset to know where we'll have to write.\
-> `./level3`\
-> `AAAA %p %p %p %p %p %p %p`\
We can notice that the offset is at the 4th argument.

Next, we'll need to find the address of the variable we want to write into.\
-> `objdump -d level3`\
If we look before the *cmp* instruction in *v()*, we can see that the address *0x804988c* is the one we want.

Now, we just need to create our payload with the informations we just collected, following the sample of *payload = address of the variable + value we want to write + address where we want to write it in*.\
-> `python -c 'print("\x8c\x98\x04\x08" + "A"*60 + "%4$n")' > /tmp/payload3`\
-> `cat /tmp/payload3 - | ./level3`

And there we go, we should have a Shell prompt and we can now get the flag for the next level!