Autor: Pedro Guerra - PC1 2º semestre
Matrícula: 211057600011

# Sobre o Projeto

Este projeto e um interpretador toy assembly similar a arquitetura MIPS.
O interpretador possui 32 registradores RN de 32-bits, aceita ate 100000 instrucoes e ate 100 linhas de codigo e suporta o seguinte conjunto de instrucoes:

```
• MOV RX INTEIRO: atribui a RX o valor do INTEIRO
• MOV RX RY: atribui a RX o valor de RY.
• ADD RX RY RZ: soma os valores de RY e RZ e armazena o resultado em RX.
• SUB RX RY RZ: subtrai RZ de RY e armazena o resultado em RX.
• MUL RX RY RZ: multiplica RY por RZ e armazena o resultado em RX.
• DIV RX RY RZ: divide RY por RZ e armazena o resultado em RX. A divisão é inteira,
isto é, a parte fracionária é desprezada.
• MOD RX RY RZ: toma o resultado de RY mod RZ e armazena o resultado em RX. O
resultado RX da operação de mod é sempre 0 ≤ RX < RZ.
• BEQ RX RY ENDERECO: o fluxo do programa é direcionado para a instrução que ocupa
a linha de número ENDERECO caso RX seja igual a RY.
• BLT RX RY ENDERECO: o fluxo do programa é direcionado para a instrução que ocupa
a linha de número ENDERECO caso RX seja menor que RY.
• JMP ENDERECO: o fluxo do programa é direcionado para a instrução que ocupa a
linha de número ENDERECO.
• LOAD RX RY: carrega o conteúdo de memoria[RY] para o registrador RX.
• STORE RX RY: carrega o conteúdo de RX para memoria[RY].
• PRINT RX: imprime uma linha na tela com o o valor de RX.
```

# Compilacao

Para compilar o projeto, execute:

```
make
```

Para limpar os arquivos e excluir o programa, execute:

```
make clean
```

# Como usar

Quando utilizar o programa, envie na primeira linha o numero de instrucoes que devem ser interpretadas, e nas linhas seguintes, envie as instrucoes, uma por linha. Um exemplo de input e:

```txt
3               // numero de linhas do assembly
MOV R0 100
PRINT R0
EXIT
```

# Exemplos

• Entrada:

```
5
MOV R0 1
MOV R1 1
ADD R0 R1 R1
PRINT R0
EXIT
```

• Saída:

```
2
```

• Entrada:
```
16
MOV R0 1
MOV R1 1
MOV R2 2
MOV R3 2
MOV R4 10
MOV R5 1
PRINT R0
PRINT R1
BEQ R3 R4 15
ADD R2 R1 R0
PRINT R2
MOV R0 R1
MOV R1 R2
ADD R3 R3 R5
JMP 8
EXIT
```

• Saída:

```
1
1
2
3
5
8
13
21
34
55
```