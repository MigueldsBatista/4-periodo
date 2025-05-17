# Seminário Redes - Camada de Enlace (Seções 6.1 & 6.2)

## 6. A Camada de Enlace e as LANs - Introdução

*   **Contexto:** Recapitulação do papel da camada de rede na comunicação entre hosts através de vários enlaces (com fio, sem fio) e comutadores de pacotes.
*   **Questões-chave abordadas:**
    *   Encapsulamento de datagramas da camada de rede em quadros da camada de enlace.
    *   Uso de diferentes protocolos da camada de enlace.
    *   Resolução de conflitos de transmissão em enlaces de difusão.
    *   Endereçamento da camada de enlace e sua relação com o endereçamento da camada de rede.
    *   Diferença entre switches e roteadores.
*   **Tipos de Canais da Camada de Enlace:**
    *   **Canais de Difusão:** Conectam múltiplos hosts (ex: LANs, redes de satélite). Requerem protocolos de Controle de Acesso ao Meio (MAC).
    *   **Enlaces Ponto-a-Ponto:** Conectam dois dispositivos (ex: roteador-para-roteador). Coordenação de acesso mais simples (ex: PPP).
*   **Visão Geral do Capítulo:**
    *   Terminologias da camada de enlace.
    *   Detecção e correção de erros.
    *   Redes de acesso múltiplo e LANs comutadas (incluindo Ethernet).
    *   LANs virtuais (VLANs) e redes de data center.

## 6.1 Introdução à Camada de Enlace

### 6.1.1 Serviços Fornecidos pela Camada de Enlace

*   **Enquadramento de Dados (Framing):**
    *   Encapsulamento de datagramas da camada de rede em quadros da camada de enlace.
    *   Os quadros consistem em um campo de dados (para o datagrama) e campos de cabeçalho.
    *   A estrutura do quadro é específica do protocolo.
*   **Acesso ao Enlace (Link Access):**
    *   Protocolos de Controle de Acesso ao Meio (MAC) definem regras para transmissão de quadros.
    *   Crucial para enlaces de difusão compartilhados (problema de acesso múltiplo).
    *   Mais simples ou inexistente para enlaces ponto-a-ponto.
*   **Entrega Confiável (Reliable Delivery):**
    *   Garante o transporte sem erros de datagramas através de um enlace, geralmente usando confirmações e retransmissões.
    *   Útil para enlaces com alta taxa de erro (ex: sem fio).
    *   Visa corrigir erros localmente, evitando retransmissões fim-a-fim.
    *   Pode ser uma sobrecarga desnecessária para enlaces com baixa taxa de erro (muitos protocolos com fio não o oferecem).
*   **Detecção e Correção de Erros (Error Detection and Correction):**
    *   Identifica e potencialmente corrige erros de bits em quadros transmitidos.
    *   Erros causados por atenuação de sinal e ruído eletromagnético.
    *   O transmissor adiciona bits de detecção de erro; o receptor realiza verificações.
    *   A detecção de erros na camada de enlace é frequentemente mais sofisticada e implementada em hardware do que nas camadas de transporte/rede.
    *   A correção de erros permite que o receptor identifique e corrija erros.

### 6.1.2 Onde a Camada de Enlace é Implementada?

*   **Controlador de Interface de Rede (NIC):** Tipicamente implementado em um adaptador de rede (chip de hardware).
*   **Funcionalidade:** Realiza serviços como enquadramento, acesso ao enlace e detecção de erros.
*   **Processo:**
    *   **Transmissor:** Encapsula datagramas em quadros, adiciona bits de detecção de erro e transmite.
    *   **Receptor:** Recebe quadros, extrai datagramas e realiza verificações de erro.
*   **Mistura Hardware/Software:**
    *   Principalmente hardware (na NIC).
    *   Algumas funções de alto nível (endereçamento, ativação do controlador, tratamento de interrupções) são baseadas em software, executando na CPU do host.

## 6.2 Técnicas de Detecção e Correção de Erros

### Introdução

*   **Objetivo:** Proteger dados (D) adicionando bits de Detecção e Correção de Erros (EDC).
*   **Processo:** Remetente transmite D+EDC. Receptor recebe D'+EDC' e tenta determinar se D' é igual a D.
*   **Limitações:** As técnicas podem detectar/corrigir erros *às vezes*, mas erros não detectados são possíveis.
*   **Compensação:** Técnicas mais sofisticadas oferecem melhor proteção, mas têm maior sobrecarga.
*   **Técnicas Comuns:** Verificações de paridade, somas de verificação, Verificações de Redundância Cíclica (CRC).

### 6.2.1 Verificações de Paridade (Parity Checks)

*   **Bit de Paridade Única:**
    *   Adiciona um bit para tornar o número total de 1s par (paridade par) ou ímpar (paridade ímpar).
    *   O receptor conta os 1s; uma contagem incorreta (para o esquema escolhido) indica um número ímpar de erros de bit.
    *   Falha em detectar um número par de erros de bit.
    *   Menos eficaz para erros em rajada.
*   **Paridade Bidimensional (Two-Dimensional Parity):**
    *   Bits de dados organizados em linhas e colunas; paridade calculada para cada linha e coluna.
    *   Pode detectar e corrigir erros de bit único identificando a linha e coluna com o erro.
    *   Pode detectar (mas não corrigir) qualquer combinação de dois erros.
*   **Técnicas FEC (Forward Error Correction):**
    *   Permitem que o receptor detecte e corrija erros sem retransmissão.
    *   Reduz retransmissões e permite correção imediata.
    *   Benéfico para aplicações em tempo real ou enlaces com longos atrasos de propagação.

### 6.2.2 Métodos de Soma de Verificação (Checksum Methods)

*   **Como Funcionam:**
    *   Os bits de dados são tratados como uma sequência de inteiros de k bits.
    *   Esses inteiros são somados, e o resultado (ou seu complemento) forma os bits de detecção de erro.
*   **Soma de Verificação da Internet (Internet Checksum):**
    *   Usada por TCP, UDP e IP.
    *   Bytes de dados tratados como inteiros de 16 bits, somados. O complemento de 1 dessa soma é o checksum.
    *   O receptor calcula o complemento de 1 da soma dos dados recebidos (incluindo o checksum); se o resultado for tudo zeros, nenhum erro é detectado (geralmente).
*   **Características:**
    *   Sobrecarga de pacote relativamente baixa.
    *   Oferece proteção um pouco mais fraca em comparação com o CRC.
*   **Fundamentação de Uso:**
    *   **Camada de Transporte (Checksum):** Implementada em software (SO); precisa ser simples e rápida.
    *   **Camada de Enlace (CRC):** Implementada em hardware dedicado (adaptadores); pode lidar com operações mais complexas.

### 6.2.3 Verificação de Redundância Cíclica (CRC)

*   **O que é CRC:**
    *   Técnica poderosa de detecção de erros baseada em aritmética polinomial (módulo 2).
    *   Strings de bits são tratadas como polinômios com coeficientes 0/1.
*   **Representação Polinomial:**
    *   Adição/Subtração é equivalente a XOR bit a bit (sem vai-um/empresta-um).
*   **Funcionamento:**
    *   **Definições:**
        *   `D`: Dados originais (d bits).
        *   `G`: Polinômio gerador (r+1 bits, predefinido, público).
        *   `R`: Bits de redundância/CRC (r bits).
    *   **Remetente (Sender):**
        1.  Escolhe `G` (MSB é 1).
        2.  Calcula `R` tal que `(D * 2^r) XOR R` seja exatamente divisível por `G`.
        3.  Transmite `D` anexado com `R`.
    *   **Receptor (Receiver):**
        1.  Recebe `d+r` bits.
        2.  Divide os bits recebidos por `G`.
        3.  Se o resto for 0: nenhum erro detectado.
        4.  Se o resto for não-zero: erro detectado.
*   **Como Calcular R (Bits de Verificação):**
    *   `R = (D * 2^r) mod G` (onde `D * 2^r` é D deslocado à esquerda por r bits).
    *   Exemplo fornecido: D=101110, G=1001 -> r=3, R=011. Transmitido: 101110011.
*   **Propriedades dos Padrões CRC (ex: CRC-32):**
    *   **Capacidade de Detecção:**
        *   Detecta todos os erros em rajada de comprimento `<= r` (na verdade, o documento diz `<= r+1 bits` para o gerador G de comprimento r+1, o que significa erros em rajada até o comprimento r).
        *   Detecta erros em rajada mais longos que `r` bits com alta probabilidade (ex: `1 - 0.5^r`).
        *   Detecta qualquer número ímpar de erros de bit.