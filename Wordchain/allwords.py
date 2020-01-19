import string
alpha = string.ascii_lowercase
combs = [val1+val2+val3+val4 for val1 in alpha for val2 in alpha for val3 in alpha for val4 in alpha]
print(combs)
