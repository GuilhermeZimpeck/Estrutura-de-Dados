## FREE CELL

FreeCell é um jogo de cartas simples e single player, jogado com um baralho padrão de 52 cartas. O objetivo do jogo
é mover todas as cartas para as quatro pilhas de fundação e construir cada naipe do Ás ao Rei. Ao jogar, e possivel usar
quatro células vazias para armazenar cartas enquanto tenta ganhar.
##
## REGRAS
As regras do FreeCell são simples, mas exigem estratégia e planejamento para vencer o jogo.
- Organize as cartas em ordem decrescente e cores alternadas, usando o comando "move".
```
prompt> move 0 1
```
Nesse exemplo o jogardor moveria uma carta da coluna 0 para a coluna 1 (lemprando que as colunas vão de 0 a 7). 
- Mova cartas para as células livres quando necessário, usando o comando "free".
```
prompt> free 0 0
```
Nesse exemplo o jogardor moveria uma carta da coluna 0 para a celula livre 0 (lemprando que as celulas livres de 0 a 3). 
- Mova cartas das celulas livres para o tabuleiro, usando o comando "back".
```
prompt> back 0 0
```
Nesse exemplo o jogardor moveria uma carta da celula livre 0 para a coluna 0 (lemprando que as colunas vão de 0 a 7).
- Mova cartas do tabuleiro para as pilhas de fundação, usando o comando "stack".
```
prompt> stack 0 0
```
Nesse exemplo o jogardor moveria uma carta da coluna 0 para a fundação 0 (lemprando que as fundações vão de 0 a 3).
##
O jogo termina após todas as fundações estarem completas, ou caso o jogardor digite o comando "sair", oque faz o programa 
encerrar.
```
prompt> sair
```
