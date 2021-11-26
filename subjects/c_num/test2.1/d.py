#!/usr/bin/env python3

'''
Implementacao em python do
metodo iterativo de Gauss-Jacobi
questao 1 - item d - teste 2.1
Autor: Pedro Guerra
'''

# Acessar linha
def getl(mat, n):
    return [i for i in mat[n]]

# Acessar coluna
def getc(mat, n):
    return [i[n] for i in mat]

# x(k) inicial
xk = [
        [0],
        [0],
        [0],
        [0]
    ]

# H
H = [
        [0,0,-1/5,1/5],
        [0,0,-1/6,-1/6],
        [5/7,-6/7,0,-2/7],
        [0,0,0,0]
    ]

# u
u = [
        [129/5],
        [107/6],
        [118/7],
        [126/6]
    ]

# Resultado da multiplicacao
mul = []

# Resultado da soma
som = []

# Multiplicacao
def mult():
    for i in range(len(H)):
        mul.append([])

        for j in range(len(xk[0])):
            _mul = [x*y for x, y in zip(getl(H, i), getc(xk, j))]
            mul[i].append(sum(_mul))

# Soma
def soma():
    for i in range(len(H)):
        som.append([])

        for j in range(len(u[0])):
            _som = mul[i][j] + u[i][j]
            som[i].append(_som)

print("|k|                  xk")
for i in range(10):
     mult()
     soma()
     xk = som
     mul = []
     som = []
     print(f"|{i}| {xk}")
