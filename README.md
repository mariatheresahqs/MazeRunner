# MazeRunner

Trabalho prático da disciplina de Projeto e Análise de Algoritmos.

Vários estudantes de ciência da computação foram presos em um país cujo governo os considerava uma ameaça à sua manutenção no poder! O governo decidiu ainda fazer uns experimentos com objetivos desconhecidos, onde cada um dos prisioneiros era então retirado de sua cela e colocado em um labirinto, com uma ou mais chaves. O prisioneiro deve então tentar escapar deste labirinto. Obviamente ele não consegue atravessar as paredes, a não ser que seja uma porta e que ele tenha chaves sobrando em seu bolso. O objetivo é escapar do labirinto, mas não se sabe se importa o número de tentativas erradas e nem o número de chaves usadas. Se você voltar atrás em uma porta que você usou uma chave, pode pegar de volta a chave, já que o caminho não levou à saída do labirinto, e então poderá usá-la em outra porta de outro caminho possível do labirinto. Por sorte, o estudante de ciência da computação, prevenido, estava com seu notebook e com um drone. Com isso usou o drone para fotografar o labirinto por cima, e então bastava escrever um algoritmo para encontrar a saída mais rapidamente, tendo como entrada a foto tirada convertida para um arquivo texto.

Você deve portanto imaginar que você é o tal estudante e projetar um algoritmo com backtracking para encontrar uma saída do labirinto neste contexto, implementá-lo em C e documentá-lo, de acordo com as especificações abaixo.

Observe a figura:

<p align="center">
  <img src="https://github.com/mariatheresahqs/MazeRunner/blob/master/labirinto.png" width="250">
</p>


Esta tabela representa o espaço geográfico do labirinto, onde cada célula representa um quadrado de 1 metro quadrado. Temos neste espaço o estudante de ciência da computação, cuja posição inicial está representada por um quadrado verde (ou seja, o estudante está inicialmente nesta posição). O estudante deverá caminhar pelos vários quadrados (ou seja, várias posições) até chegar em uma das células da primeira linha da tabela (linha de cima).
Os quadrados azuis representam paredes, pelas quais o estudante obviamente não pode passar. O estudante só pode movimentar para cima, para baixo e para os lados. Ou seja, não pode se movimentar nas diagonais.

Você deverá escrever um programa na linguagem C que utilize um algoritmo projetado por você, que leia um arquivo com as informações do labirinto onde o estudante está, bem como sua exata posição inicial. Seu programa deverá então encontrar um caminho que leve o estudante de sua posição inicial até uma das células da primeira linha da tabela, mostrando na tela cada tentativa de movimento feita e qual o caminho encontrado.

Seu programa deverá obrigatoriamente usar backtracking. Uma função recursiva chamada movimenta_estudante deverá ser criada. Isso significa que primeiramente você deverá encontrar a posição inicial do estudante. Quando encontrar, deverá chamar esta função uma única vez, e a partir daí ela chamará ela mesma, até que o estudante chegue na primeira linha (linha zero). 
