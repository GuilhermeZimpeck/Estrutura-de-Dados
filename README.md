# Estrutura-de-Dados
turma da professora Myrna Cecilia Amorim <br>
Os códigos das minhas aulas, as listas, e as provas foram feitos usando a linguagem C e C++.
# Conteúdo Estudado
- Ordenação :

codigos do tipo "SORT", onde recebem a quantidade de elementos a serem lidos, realizam a leitura dos elementos do tipo inteiro, e os armazenam em um vetor de até 100 posiçôes. Após a leitura, as funções do tipo Sort ordenam o vetor em ordem crescente. O 'BubbleSort', 'SelectionSort' e o 'inserctionSort' são algoritimos da ordem O(n²), portanto constumam ter um desempenho maior com vetores menores. Entretanto, por outro lado, o 'MergeSort' e 'QuickSort' são de ordem O(nlog n), então funcionam melhor em vetores maiores, isso porque ambas funções utilizam a recursividade(chamar a função dentro da própria função), e o método de divisão e conquista(divide o vetor em vetores menores). 

- Listas Encadeadas:

Listas encadeadas são estruturas dinâmicas formadas por nós, nos quais cada nó armazena um dado e uma referência ou ponteiro para outro nó. São estudadas as listas simplesmente encadeadas, duplamente encadeadas e circulares, além das operações de inserção, remoção, busca e percorrimento. Também são analisadas suas vantagens e desvantagens em relação aos arrays, principalmente quanto ao uso de memória e ao custo das operações. Dentre os tipos de lista estão a Fila e a Pilha.

- Filas:

Filas são estruturas baseadas no princípio FIFO (First In, First Out), no qual o primeiro elemento inserido é o primeiro a ser removido. As principais operações são enqueue, responsável pela inserção, e dequeue, responsável pela remoção, além da consulta ao elemento que está na frente da fila. São estudadas implementações utilizando arrays e listas encadeadas, incluindo filas circulares e filas de prioridade

- Pilhas:

Pilhas são estruturas que seguem o princípio LIFO (Last In, First Out), no qual o último elemento inserido é o primeiro a ser removido. As principais operações são push, para inserir um elemento, pop, para remover, e top ou peek, para consultar o elemento no topo.

- Heaps

Heaps são árvores binárias especiais utilizadas principalmente para implementar filas de prioridade e algoritmos de ordenação. Existem principalmente os Min-Heaps, nos quais o menor elemento fica na raiz, e os Max-Heaps, nos quais o maior elemento fica na raiz. São estudadas operações como inserção, remoção, heapify e construção de um heap, além da relação entre heaps e o algoritmo Heap Sort. Essa estrutura é especialmente importante porque permite obter e remover rapidamente o elemento de maior ou menor prioridade.

- Árvores | Árvores Binárias de Busca | Árvores Balanceadas

Árvores são estruturas de dados hierárquicas, formadas por nós organizados em diferentes níveis. Seus principais conceitos incluem raiz, nós, folhas, pais, filhos, e altura. São estudadas principalmente as árvores binárias e seus diferentes métodos de percorrimento, como pré-ordem, em ordem (in-order), pós-ordem e por nível, que permitem visitar os elementos da árvore seguindo diferentes estratégias. As Árvores Binárias de Busca são árvores binárias que organizam seus elementos de maneira que os valores menores ficam à esquerda de um nó e os maiores ficam à direita. Isso permite realizar operações de busca, inserção e remoção de maneira eficiente quando a árvore está bem balanceada. Também são estudados conceitos como menor e maior elemento, antecessor e sucessor, além do problema das árvores desbalanceadas, que pode fazer com que determinadas operações deixem de apresentar o desempenho esperado. Árvores balanceadas são utilizadas para evitar que uma árvore de busca se torne excessivamente desbalanceada e passe a se comportar como uma lista encadeada. Um dos principais exemplos estudados são as árvores AVL, que utilizam rotações para manter a diferença de altura entre as subárvores dentro de determinados limites.
