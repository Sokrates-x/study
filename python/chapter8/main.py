#!/bin/python3

import os

print(os.path.join('~', 'github'));

if not os.path.exists('./data'):
    os.makedirs('./data');

path = os.getcwd();

# split base and dir
file = os.path.split(path + '/main.py');

print(file[0]);

# use path's join
fullName = os.path.join(file[0], file[1]);
# use list's join
fullName = '/'.join(file);

print(fullName);
print(os.path.basename(fullName));
print(os.path.dirname(fullName));

# split all
fullSplit = fullName.split(os.path.sep);

for i in fullSplit:
    print(i);

# file size
print(os.path.getsize(fullName));

# get dir's file list 
print(os.listdir(path));

# is file is dir
print(not os.path.isdir(fullName));
print(os.path.isfile(fullName));


pyFile = open(fullName);
pyContent = pyFile.read();
#print(pyContent);

fullName = os.getcwd() + '/data/data.txt';
print(fullName);

# creat file
dataFile = open(fullName, 'w'); 
dataFile.write('Hello, world!\n');
dataFile.close();

# append file
dataFile = open(fullName, 'a');
dataFile.write('Hello, world!\n');
dataFile.close();

# read only open
dataFile = open(fullName);
dataContent = dataFile.read();
print(dataContent);
dataFile.close();

# shelve
# use shelve data
import shelve
shData = shelve.open('shData');
print(shData['grade']['Calculus']);
shData.close();

# import my own py model
import grade
print(grade.grades)


