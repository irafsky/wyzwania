# @title  Zmiana nazw plików

from glob import glob
from os import rename

pattern = "test/*"  #@param {type:"string"}
files = glob(pattern)

for file in files:
    name, ext = file.split('.')
    new_name = name + '.py'
    rename(file, new_name)
    print(file, '->', new_name)
print("Koniec")

x = 1; y = 2