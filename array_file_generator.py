import random

f = open('array.txt', 'w')

for i in xrange(0,50):
    f.write(str(random.randint(0, 99)) + ' ')
    #f.write(str(i) + ' ')

f.write('\n')

f.close
