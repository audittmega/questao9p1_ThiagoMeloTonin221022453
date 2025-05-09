# Sistema de Verificação Modular

Este programa implementa um sistema de segurança baseado em verificação modular, utilizando conceitos avançados de matemática discreta.

## Funcionalidades

O programa realiza as seguintes operações:
1. Verifica se G e n são coprimos usando o Algoritmo de Euclides
2. Calcula o inverso modular de G em Zn
3. Realiza divisão modular H⊘G em Zn
4. Verifica coprimalidade entre a e n1
5. Aplica o Teorema de Fermat (se n1 for primo) ou o Teorema de Euler
6. Calcula exponenciação modular eficiente

## Como Usar

1. Compile o programa:
```bash
gcc questao9.c -o questao9.exe
```

2. Execute o programa:
```bash
questao9.exe
```

3. Siga as instruções na tela para inserir:
   - Valores de H, G e n (separados por espaço)
   - Valores de x e n1 (separados por espaço)

## Exemplo de Uso

Entrada:
```
H = 38, G = 79, n = 252
x = 5, n1 = 7
```

O programa mostrará cada etapa do processo de forma detalhada.

## Requisitos

- Compilador C (gcc)
- Sistema operacional Windows/Linux/MacOS

## Autor

Thiago Melo Tonin

## Disciplina

Matemática Discreta 2 