# Exercícios de Prática – Teoria da Computação (PDAs, Máquinas de Turing e Gramáticas)

## 🧠 AUTÔMATOS PUSHDOWN (PDA)

---

### 🔸 Exercício 1 – Linguagem palíndroma com símbolo central

Construa um PDA que reconhece a linguagem:

    L = { w c wᴿ | w ∈ {a,b}* }

Exemplos: `aca`, `bcb`, `abbcbba`

🛠️ Dica: empilhe `a` ou `b` até ler `c`; depois desempilhe e compare com o restante da entrada.

---

### 🔸 Exercício 2 – Igualdade entre dois símbolos

Construa um PDA que reconhece:

    L = { aⁿbⁿ | n ≥ 0 }

Agora modifique-o para reconhecer:

    L = { aⁿbᵐ | n = m ou n = 2m }

---

### 🔸 Exercício 3 – Sequência balanceada com sufixo livre

Projete um PDA para:

    L = { aⁿbⁿcᵐ | n, m ≥ 0 }

Ou seja, o número de `a`s deve ser igual ao número de `b`s, seguido por qualquer quantidade de `c`.

---

### 🔸 Exercício 4 – Falsos palíndromos (Desafio)

Construa um PDA para a linguagem:

    L = { x ∈ {a,b}* | x ≠ xᴿ }

Ou seja, todas as strings que **não** são palíndromos.

---

## 🔤 GRAMÁTICAS LIVRES DE CONTEXTO (GLC)

---

### 🔸 Exercício 5 – Linguagem com repetição

Construa uma gramática livre de contexto para a linguagem:

    L = { ww | w ∈ {a,b}+ }

Exemplos: `aa`, `abab`, `babaabaa`

---

### 🔸 Exercício 6 – Prefixos e sufixos

Projete uma GLC para a linguagem:

    L = { a^n b^m c^n d^m | n, m ≥ 1 }

---

### 🔸 Exercício 7 – Linguagem com dependências cruzadas

Construa uma GLC para:

    L = { a^n b^m c^m d^n | n, m ≥ 1 }

---

### 🔸 Exercício 8 – Linguagem de expressões balanceadas (Desafio)

Projete uma GLC para reconhecer expressões com parênteses, colchetes e chaves corretamente balanceados.

Exemplos válidos: `()`, `[{}]`, `({[]})`
Exemplos inválidos: `(]`, `[(])`, `{[}`

---

## ⚙️ MÁQUINAS DE TURING (MT)

---

### 🔸 Exercício 9 – Multiplicação unária

Construa uma MT que reconhece a linguagem:

    L = { 1ᵐ#1ⁿ#1ᵐⁿ | m, n ≥ 1 }

Exemplo: `11#111#111111` (2 × 3 = 6)

---

### 🔸 Exercício 10 – Verificação de paridade

Projete uma MT que aceita strings com número par de `1`s:

    L = { x ∈ {0,1}* | número de 1's em x é par }

---

### 🔸 Exercício 11 – Remoção de símbolos

Construa uma MT que remove todos os `b`s de uma string sobre {a,b}.

Entrada: `abbaab`  
Saída esperada: `aaa`

---

### 🔸 Exercício 12 – Reconhecimento de palíndromos (Desafio)

Projete uma MT que reconhece palíndromos sobre {a, b}.

🛠️ Dica: use marcações para apagar primeira e última letras e comparar, repetindo o processo até a fita esvaziar ou restar 1 símbolo.

---

### 📝 Recomendações para resolução:

1. Descreva informalmente a ideia de funcionamento.
2. Esboce os estados e transições principais.
3. (Opcional) Formalize com a notação de 7 tuplas (MT), 6 tuplas (PDA) ou regras de produção (GLC).
