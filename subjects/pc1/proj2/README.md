Autor: Pedro Guerra - PC1 2º semestre
Matrícula: 211057600011

# Sobre o Projeto

Este projeto é um cracker de hashes sha256 baseado em busca binaria.
O programa utiliza uma lista de pares de senhas e hashes pre-computada (rainbow table)
ordenada alfabeticamente pelos hashes para buscar as senhas que coincidam com os hashes desejados.
A saida do programa é um arquivo com os pares de usuarios/senhas que foram quebrados.

# Compilacao

Para compilar o projeto, execute:

```txt
make
```

Para limpar os arquivos e excluir o programa, execute:

```txt
make clean
```

# Como usar

O programa recebe 3 parametros da linhas de comando: 
 - um arquivo de entrada com os usuarios e hashes a serem quebrados
 - um arquivo de pares de senhas/hashes pre-computados e em ordem alfabetica
 - um arquivo para onde a saida deve ser salva

```txt
./<nome_executavel> <caminho_arquivo_criptografado><caminho_arquivo_pre_computado> <relatorio_quebra>
```

Os nomes de usuarios do arquivo de entrada e as senhas do arquivo pre-computado
devem ter um tamanho de, no maximo, 32 caracteres. 

O arquivo de hashes deve conter em cada linha um nome de usuario e a hash da senha do usuario 
separados por um espaço.

```txt
usuario1 <hash sha256 da senha do usuario1>
usuario2 <hash sha256 da senha do usuario2>
[...]
```

O arquivo de senhas pre-computadas deve conter em cada linha uma senha e o hash dela separados
por um espaço.
As linhas devem ser ordenadas por ordem alfabetica dos hashes.

```txt
senha1 <hash sha256 da senha1>
senha2 <hash sha256 da senha2>
[...]
```

O formato do arquivo de saida e, um par por linha dos nomes dos usuarios que tiveram a senha quebrada junto
de suas respectivas senhas, na ordem em que foram quebradas.

```txt
usuario1 senha1
usuario2 senha2
[...]
```


# Exemplos

Este projeto acompanha um pequeno conjunto de exemplos no diretorio `example`

• Arquivo criptografado:

```
robertofontes 8d969eef6ecad3c29a3a629280e686cf0c3f5d5a86aff3ca12020c923adc6c92
danielsaad ff7e0624efbfe4c006a29afcd7dd6f189535f5191259c321a31d5472f175f370
marcosvieira 4ccb3e2159a977232f2456b2292f062a54231311de25a1a8f5cd82f67b44a984
jeffersonrodriguespereiranetojr_ b9f195c5cc7ef6afadbfbc42892ad47d3b24c6bc94bb510c4564a90a14e8b799
migueldiaz e3770d9b3dc125004370aaa9b5c19e6c809131a50fd19cd47b60571d5ebba631
joaoaraujo d58d736c7a967fb5f307951932734f8b0594725faa5011dbb66a8c538e635fb6
robertjunior 4ccb3e2159a977232f2456b2292f062a54231311de25a1a8f5cd82f67b44a984
alberto 7499aced43869b27f505701e4edc737f0cc346add1240d4ba86fbfa251e0fc35
ricardonog 889886697c3e5b01b266d657fb3c32df3b39717355f3fddcdaff47b8147c8caf
michaeldouglas e4eead5f933af8c75a39135da4874756ade6689ddc22847446c5bc750dfa8246
ashketchum e63947f77959547625baab1d668a0fb7515940dbc3891de66d5a7b31f7375e16
```

• Arquivo pre-computado:

```
jordan 136c67657614311f32238751044a0a3c0294f2a521e573afa8e496992d3786ba
1234567890123456789012345678901  3b7184c0ceaf76a9607a31e4e1f87fb292375a16330c633f090bfd6cd8b7fa83
qwerty 65e84be33532fb784c48129675f9eff3a682b27168c0ea744b2cf58ee02337c5
chocolate 7499aced43869b27f505701e4edc737f0cc346add1240d4ba86fbfa251e0fc35
123456 8d969eef6ecad3c29a3a629280e686cf0c3f5d5a86aff3ca12020c923adc6c92
swordfish b9f195c5cc7ef6afadbfbc42892ad47d3b24c6bc94bb510c4564a90a14e8b799
cocacola c46d87f1fb4a5df6df841030ffe300e8271af74b62f2545c6c1759d18932675d
flamengo d58d736c7a967fb5f307951932734f8b0594725faa5011dbb66a8c538e635fb6
senhabemlongade32bytes1231231231 e3770d9b3dc125004370aaa9b5c19e6c809131a50fd19cd47b60571d5ebba631
pokemonisbadass e63947f77959547625baab1d668a0fb7515940dbc3891de66d5a7b31f7375e16
```

• Saída:

```
robertofontes 123456
jeffersonrodriguespereiranetojr_ swordfish
migueldiaz senhabemlongade32bytes1231231231
joaoaraujo flamengo
alberto chocolate
ashketchum pokemonisbadass
```