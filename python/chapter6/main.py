#!/bin/python3

print(r"Hello\'sWorld");
print("Hello\'sWorld");
print("Hello'sWorld");
print('Hello\'sWorld');

# with '''***'''
print('''ll\nlll
    ldfaeaf
    sdfaw
    efasf''');

"""This
This
Emmm
"""
def function():
    """Emmm"""
    print('emmm...'); 

function();

string = "Hello, World!";
print(string[-1]);
print(string[7:]);
print('h'.upper() in string);
print('h'.lower() not in string);

print(string[0].isupper());
print(string[1].islower());
print(string.upper());
print(string.lower());

# pure digitals is not lower
numstr = '123';
print(not numstr.islower());
# digitals with lowers is lower 
numstr = '123a';
print(numstr.islower());

numstr = 'abc';
print(numstr.isalpha());
numstr = '123';
print(numstr.isdecimal());
numstr = 'abc123';
print(numstr.isalnum());
numstr = ' ';
numstr = '\t';
numstr = '\n';
print(numstr.isspace());
# title begin with upper
numstr = 'Abc';
# only one upper is needed for one word
numstr = 'A Bc';
# space is lower is upper
numstr = 'A B C';
print(numstr.istitle());
# it is also upper
print(numstr.isupper());
numstr = 'a b c';
print(numstr.islower());
numstr = 'a,b,c';
print(numstr.islower());
# , . is lower not upper
numstr = 'A,B,C';
print(not numstr.islower());

print(numstr.startswith('A'));
print(numstr.endswith('C'));

# join
jlist = ['a', 'b', 'c'];
jstr = ', '.join(jlist);

# split
slist = jstr.split(', ');
print(slist);

print('/' + "Alice".center(78, '*') + '/');
string = 'Alice';
print("Left Just:".ljust(20, ' '), end = '');
print(string.ljust(20, ' '));
print('Center Just:'.center(20, ' '), end = '');
print(string.center(20, ' '));
print('Right Just:'.rjust(20, ' '), end = '');
print(string.rjust(20, ' '));

content = { 'Entropy' : 7, 'Joint entropy and conditonal entropy' : 15,
    'Relative entropy and conditional entropy' : 18, 'Relations' : 19 };
def printContent(ct):
    print();
    print();
    print()
    print("Content".center(60));
    for k, v in ct.items():
        print(k, end = ''); 
        print(str(v).rjust(60 - len(k), '.'));

printContent(content);

# strip
string = ' A ';
print(string.strip());
print(string.lstrip());
print(string.rstrip());

string = 'ABCdfeaffABCCBA';
# strip util char not in Arg
print(string.strip('ACB'));


