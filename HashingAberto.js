// Template para um tipo genérico
class HashNode {
    constructor(key, value) {
      this.key = key;
      this.value = value;
    }
  }
  
  // Template para um tipo genérico
  class HashMap {
    constructor() {
      this.capacity = 20;  // Capacidade inicial do array
      this.size = 0;       // Tamanho atual do mapa
      this.arr = new Array(this.capacity);  // Array que armazenará os elementos do mapa
  
      // Inicializa todos os elementos do array como NULL
      for (let i = 0; i < this.capacity; i++) {
        this.arr[i] = null;
      }
  
      // Nó fictício com valor e chave -1
      this.dummy = new HashNode(-1, -1);
    }
  
    // Isso implementa uma função hash para encontrar o índice de uma chave
    hashCode(key) {
      return key % this.capacity;
    }
  
    // Função para adicionar um par chave-valor
    insertNode(key, value) {
      const temp = new HashNode(key, value);
  
      // Aplica a função hash para encontrar o índice da chave dada
      let hashIndex = this.hashCode(key);
  
      // Encontra o próximo espaço livre
      while (
        this.arr[hashIndex] !== null &&
        this.arr[hashIndex].key !== key &&
        this.arr[hashIndex].key !== -1
      ) {
        hashIndex++;
        hashIndex %= this.capacity;
      }
  
      // Se um novo nó deve ser inserido, aumenta o tamanho atual
      if (
        this.arr[hashIndex] === null ||
        this.arr[hashIndex].key === -1
      ) {
        this.size++;
      }
      this.arr[hashIndex] = temp;
    }
  
    // Função para excluir um par chave-valor
    deleteNode(key) {
      // Aplica a função hash para encontrar o índice da chave dada
      let hashIndex = this.hashCode(key);
  
      // Encontrando o nó com a chave dada
      while (this.arr[hashIndex] !== null) {
        // Se o nó for encontrado
        if (this.arr[hashIndex].key === key) {
          const temp = this.arr[hashIndex];
  
          // Insere um nó fictício aqui para uso posterior
          this.arr[hashIndex] = this.dummy;
  
          // Reduz o tamanho
          this.size--;
          return temp.value;
        }
        hashIndex++;
        hashIndex %= this.capacity;
      }
  
      // Se não encontrado, retorna null
      return null;
    }
  
    // Função para procurar o valor para uma dada chave
    get(key) {
      // Aplica a função hash para encontrar o índice da chave dada
      let hashIndex = this.hashCode(key);
      let counter = 0;
  
      // Encontrando o nó com a chave dada
      while (this.arr[hashIndex] !== null) {
        if (counter++ > this.capacity) {
          // Para evitar um loop infinito
          return 0;
        }
  
        // Se o nó for encontrado, retorna seu valor
        if (this.arr[hashIndex].key === key) {
          return this.arr[hashIndex].value;
        }
        hashIndex++;
        hashIndex %= this.capacity;
      }
  
      // Se não encontrado, retorna 0
      return 0;
    }
  
    // Retorna o tamanho atual
    sizeofMap() {
      return this.size;
    }
  
    // Retorna verdadeiro se o tamanho for 0
    isEmpty() {
      return this.size === 0;
    }
  
    // Função para exibir os pares chave-valor armazenados
    display() {
      for (let i = 0; i < this.capacity; i++) {
        if (this.arr[i] !== null && this.arr[i].key !== -1) {
          console.log(`chave = ${this.arr[i].key} valor = ${this.arr[i].value}`);
        }
      }
    }
  }
  
  // Método de teste para a classe do mapa
  const h = new HashMap();
  h.insertNode(1, 1);
  h.insertNode(2, 2);
  h.insertNode(2, 3);
  h.display();
  console.log(h.sizeofMap());
  console.log(h.deleteNode(2));
  console.log(h.sizeofMap());
  console.log(h.isEmpty());
  console.log(h.get(2));
  