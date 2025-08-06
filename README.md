
# 🧩 Labirinto com Backtracking em C

Este projeto implementa a resolução de um labirinto utilizando o algoritmo de **backtracking com estrutura de dados tipo pilha**, proposto na disciplina de **Estrutura de Dados** da UFPB.

## 🎯 Objetivo

A partir de uma posição inicial no labirinto, encontrar o caminho até o tesouro (`$`) usando backtracking e uma pilha para armazenar os caminhos a serem explorados.

## 🛠️ Estrutura

- `labirinto.c`: Código-fonte completo em linguagem C.
- O labirinto é representado por uma matriz de caracteres.
- A pilha armazena posições válidas a serem exploradas.

## 📦 Como compilar e executar

Requisitos: GCC instalado.

```bash
gcc labirinto.c -o labirinto
./labirinto
```

## 🧪 Exemplo de Labirinto

```text
#####
#   #
# # #
#*#$#
#####
```

- `#` = parede
- `' '` = caminho livre
- `*` = posição inicial do jogador
- `$` = tesouro (objetivo)

## ✅ Resultado esperado

Ao executar, o programa indicará se o tesouro foi encontrado e em qual posição. Caso contrário, dirá que não há caminho.

## 📅 Entrega

Data de entrega: **05/07/2025**  
Submeta o código no GitHub e poste o link do repositório no SIGAA.

---

Desenvolvido para a disciplina de **Estrutura de Dados**  
Professor: Gilberto Farias de Sousa Filho  
Universidade Federal da Paraíba – CIn
