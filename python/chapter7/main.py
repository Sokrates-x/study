#!/bin/python3

import re

phoneNumRegex = re.compile(r'\d{3}-\d{3}-\d{4}');

mo = phoneNumRegex.search('My phone num is 333-333-3333 or 555-555-5555');

subReg = re.compile(r'(\d{3})-(\d{3})-(\d{4})');

submo = subReg.search('My phone num is 333-333-3333 or 555-555-5555');

print(mo.group());
print(submo.group());
print(submo.group(1) + '.' + submo.group(2) + '.' + submo.group(3));

# with prefix
string = 'premise, prefer, precise';
strReg = re.compile(r'pre([a-z]{1}mise|[a-z]{1}ise)');
strmo = strReg.search(string);
print(strmo.group());
print(strmo.group(1));

# ? selectable sub match
strReg2 = re.compile(r'pre([a-z]{1})?ise');
strmo2 = strReg2.search(string);
print(strmo2.group());
print(strmo2.group(1));

# * 0 or more times match
strReg3 = re.compile(r'pre([a-z]{1})*ise');
strmo3 = strReg3.search(string);
print(strmo3.group());

# + 1 or more times matchs
strReg4 = re.compile(r'pre([a-z]{1})+ise');
strmo4 = strReg4.search(string);
print(strmo4.group());

# match policy
string = "HaHaHaHaHa";
strReg5 = re.compile(r'(Ha){3,5}');
strmo5 = strReg5.search(string);
print(strmo5.group());
strReg6 = re.compile(r'(Ha){3,5}?');
strmo6 = strReg6.search(string);
print(strmo6.group());

strReg7 = re.compile(r'Ha');
strmo7 = strReg7.findall(string);

print(strmo7);

