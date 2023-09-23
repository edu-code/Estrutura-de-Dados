// Implementação de Filas usando Apontadores

// - Há uma célula cabeça para facilitar a implementação das
// operações Enfileira e Desenfileira quando a fila está vazia.
// - Quando a fila está vazia, os apontadores Frente e Trás
// apontam para a célula cabeça.
// - Para enfileirar um novo item, basta criar uma célula nova,
// ligá-la após a célula que contém xn e colocar nela o novo item.
// - Para desenfileirar o item x1, basta desligar a célula
// cabeça da lista e a célula que contém x1 passa a ser a célula cabeça.

// - A fila é implementada por meio de células
// - Cada célula contém um item da fila e um apontador para outra célula.
// - A estrutura TipoFila contém um apontador para a frente
// da fila (célula cabeça) e um apontador para a parte de trás da fila.