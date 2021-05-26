import random

text =''
for i in range(10000):
    n = bin(random.randint(0,255))[2:]
    n = '0'*(8-len(n)) + n
    text += n 

text = text.strip('\n')

f = open('byteStream.txt', 'w')
f.write(text)
f.close()
    
