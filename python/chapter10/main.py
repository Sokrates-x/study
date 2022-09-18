#!/bin/python3

import os, traceback

# log exception msg and continue
try:
    raise Exception('Error: test error.');
except Exception as err:
    errFile = open('errMsg.log', 'w');
    errFile.write(traceback.format_exc());
    errFile.close();
    print('Error Catched.');

a = 1;
b = 0;
try:
    assert b != 0, 'Divided number must not be zero.';
except AssertionError as err:
    print(str(err) + ' Please Enter a NONE ZERO number:') 
    b = input();
c = a/int(b);
print(c);

# logging
import logging
logging.basicConfig(filename = 'errLog.log',level = logging.DEBUG, format = ' %(asctime)s - %(levelname)s - %(message)s');
# disable logging
#logging.disable(logging.DEBUG);
logging.debug('Start of program');
def factorial(n):
    logging.debug('Calculate the factorial of ' + str(n));
    if n == 0:
        return 1;
    return n*(factorial(n -1));

print(factorial(5));
logging.debug('End of program');


