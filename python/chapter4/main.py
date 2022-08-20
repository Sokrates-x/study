#!/bin/python3

# test env
print("Hello, World!");

# just like the std::set
vec = [1, 2, 3, 4, 5, 6];
print(vec[0]);
print(vec[1:3]);
print(vec[0:6]);
print(vec[:]);
# len
print(len(vec));
# change val
vec[5] += 1;
print(vec[:]);

# add list
vec += vec;
print(vec[:]);

# del element
del vec[5];
del vec[10];
print(vec[:]);

del vec[5:10];
print(vec[:]);

# use in loop
for i in vec:
    print(i, end=' ');
print();

# in the list?
print(1 in vec);
print(6 in vec);
print(6 not in vec);

# assign all
val0, val1, val2, val3, val4 = vec;
print(val3);

# find ?
print(vec.index(5));

# append
vec.append(6);
# insert 
vec.insert(0, 0);
# remove
vec.remove(0);
vec.remove(6);

# sort
vec.sort(reverse = True);
vec.sort();

print(vec[:]);

# sort for ASCII
strvec = [ 'A', 'a', 'Z', 'z' ];
strvec.sort();
# treat as lower
strvec.sort(key = str.lower);

print(strvec);

# str as a list
string = 'Hello, World!';
print(string[1]);
print('a' in string);
print('o' in string);
print("Len of " + string + " = " + str(len(string)));

# tuple
tpl = ('hello', 1, 'world', 3.14);
print(tpl);
print(tpl[0]);
# assign elements is not allowed
# tpl[1] = 2;

# type info
print(type(tpl));
print(type(('hello')));
print(type(('hello',)));

# type cast from list to tuple
tpl = tuple(vec);
print(tpl);
vec = list(tpl);
print(vec);

# copy & deepcopy
import copy
cvec = vec.copy();
cvec[0] = 100;
print (cvec);
print (vec);

vec2d = [vec, vec];
cvec2d = copy.copy(vec2d);
cvec2d = copy.deepcopy(vec2d);
cvec2d[0][0] = 100;
print(vec2d);

# none list val can NOT pass by ref ?
def appendName(name):
    name = "Xie " + name;

name = "Dong"
appendName(name);
print(name);

# excise
spam = ['apples', 'bananas', 'tofu', 'cats'];
def printPlus(listName) :
    for item in listName[0 : len(listName) - 1] :
        print(item, end = ', ');
    print('add', end = ' ');
    print(listName[len(listName) - 1]);
printPlus(spam);
