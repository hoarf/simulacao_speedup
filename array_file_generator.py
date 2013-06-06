import random

f = open('array.txt', 'w')

for i in xrange(0,9999999):
    f.write(str(random.randint(0, 99)))

f.close