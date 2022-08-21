#!/bin/python3

import os, shutil, re
os.chdir('./data');

fileList = os.listdir('.');

for i in fileList:
    if os.path.isfile(i) : 
        reg = re.compile(r'.*\.txt$');
        reg2 = re.compile(r'.*\.pdf$');
        reg3 = re.compile(r'.*\.jpg$');
        if reg.search(i) == None and reg2.search(i) == None and \
            reg3.search(i) == None:
            print('Unkown File type.'); 

# move copy
for i in fileList:
    if os.path.isfile(i) :
        reg = re.compile(r'.*\.txt$');
        if reg.search(i) != None:
            shutil.copy(i, './txt');
        reg = re.compile(r'.*\.pdf$');
        if reg.search(i) != None:
            shutil.copy(i, './pdf');
        if i.endswith('.jpg'):
            shutil.copy(i, './jpg');

# copy tree
if not os.path.exists('./backup') :
    os.makedirs('./backup');
"""
for i in fileList:
    if os.path.isdir(i) and os.path.basename(i) != 'backup':
       shutil.copytree(i, './backup/' + os.path.basename(i));
"""
# remove
# shutil.unlink(path)
# shutil.rmdir(path)
# shutil.rmtree(path)

# import send2trash

# walk the file tree
for cf, sf, f in os.walk('.'):
    print(cf);
    print(sf);
    print(f);

import zipfile
os.chdir('./backup');
cmp = zipfile.ZipFile('bkup.zip', 'w');
for f in os.listdir('.'):
    cmp.write(f, compress_type=zipfile.ZIP_DEFLATED);
print(cmp.namelist());
cmp.close();

# extract
cmp = zipfile.ZipFile('bkup.zip');
cmp.extractall();
cmp.close();


