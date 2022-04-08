#!/bin/python3

file = open('Flux_Results.txt', 'r')
Lines = file.readlines()
foo = 'hii'
for line in Lines:
    line = line.replace("Flux1", "Flux1[i]")
    line = line.replace("Flux2", "Flux2[i]")
    line = line.replace("Flux3", "Flux3[i]")
    line = line.replace("rho", "rho[i]")
    line = line.replace("Ve", "Ve[i]")
    line = line.replace("a_s", "a_s[i]")
    print(line)
