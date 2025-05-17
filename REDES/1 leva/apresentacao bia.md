## Multiplexação por Divisão de Tempo (TDM) vs Multiplexação por Divisão de Frequência (FDM)

### O que são:

* **TDM (Time Division Multiplexing)**: Técnica onde vários sinais compartilham o mesmo canal físico, mas cada um transmite em tempos diferentes, em janelas de tempo específicas.
* **FDM (Frequency Division Multiplexing)**: Técnica onde diferentes sinais são transmitidos simultaneamente, mas em diferentes faixas de frequência no mesmo meio físico.

### Características:

* **TDM**:

  * Compartilhamento temporal
  * Sincronização é crucial
  * Utilizado em redes digitais
* **FDM**:

  * Compartilhamento espectral
  * Necessita de filtros e moduladores
  * Comum em transmissões analógicas (rádio, TV)

### Vantagens e Desvantagens:

* **TDM**:

  * * Boa utilização em ambientes digitais
  * * Ineficiente se nem todos os slots forem usados
* **FDM**:

  * * Transmissão simultânea
  * * Suscetível a interferência entre faixas

---

## Acesso Múltiplo por Divisão de Código (CDMA)

### O que é:
* Técnica onde múltiplos usuários compartilham o mesmo canal usando códigos ortogonais diferentes para separar as transmissões.

### Vantagens e Desvantagens:

* * Alta eficiência espectral
* * Imunidade a interferências
* * Requer sincronização precisa
* * Complexidade de codificação e decodificação

---

## Protocolos de Acesso Aleatório

### O que são:
* Protocolos onde os dispositivos competem pelo meio de transmissão sem coordenação central.

### Características:

* Descentralizados
* Simples
* Sujeitos a colisões

### Vantagens e Desvantagens:

* * Baixa complexidade
* * Boa para redes com tráfego esporádico
* * Colisões podem reduzir desempenho

### Tipos:

* **ALOHA**:
  * Transmite sempre que quiser
  * Alta taxa de colisões
  
* **Slotted ALOHA**:
  * Transmissões ocorrem em slots temporais sincronizados
  * Menor colisão que ALOHA puro
* **Carrier Sense Multiple Access (CSMA)**:
  * O dispositivo escuta antes de transmitir
  * Reduz colisões
* **CSMA com Detecção de Colisão (CSMA/CD)**:
  * Usado no Ethernet tradicional
  * Dispositivo interrompe transmissão ao detectar colisão

### Topologias:

* **Sem mestre (descentralizado)**: Todos os dispositivos têm igual prioridade
* **Circular (token ring)**: Acesso regulado por passagem de um token

---

## Protocolos de Revezamento

### O que são:
* Protocolos que coordenam o acesso ao meio através de alguma forma de permissão

### Tipos:

* **Polling (seleção)**: Um mestre consulta os dispositivos sequencialmente
* **Passagem de permissão (token)**: Um token circula entre os dispositivos autorizando a transmissão

### Características:

* Ordenado
* Menor colisão

### Vantagens e Desvantagens:

* * Menor colisão
* * Previsível
* * Overhead de controle
* * Pode haver atraso se token se perder ou polling for lento

---

## DOCSIS (Data Over Cable Service Interface Specification)

### O que é:

* Padrão de enlace para transmissão de dados sobre redes de TV a cabo

### Componentes:

* **Cable Modem (CM)**: Na casa do usuário
* **CMTS (Cable Modem Termination System)**: Na operadora, gerencia modems
* **Cabeamento coaxial/fibra**: Meio físico

### Downstream x Upstream:

* **Downstream**: CMTS para modem (broadcast)
* **Upstream**: Modem para CMTS (concorrência)

### Problemas de Colisão:

* Uso de:

  1. Divisão de frequência
  2. Divisão de tempo
  3. Requisições aleatórias com retentativas controladas

---

## Endereçamento na Camada de Enlace e ARP

### O que é:

* Endereçamento entre dispositivos de uma mesma rede local

### Características:

* Usa **endereços MAC** (Media Access Control) físicos
* Envia **frames** com origem e destino MAC

### ARP (Address Resolution Protocol):

* Mapeia IPs para MACs
* Envia **broadcast** para descobrir MAC
* Resposta é **unicast**
* Se o destino está fora da subrede, envia ao roteador (gateway)

### Tabela ARP:

* Cache local dos mapeamentos IP-MAC

### Vulnerabilidades:

* **ARP Spoofing**: Um atacante se faz passar por outro dispositivo
* **Interceptação de tráfego** e man-in-the-middle

---

## Ethernet

### O que é:

* Tecnologia de rede para LANs
* Primeira LAN de alta velocidade amplamente usada

### Evolução:

* Antes: Coaxial e Hubs (colisões comuns)
* Hoje: Switches (comutação, elimina colisões)

### Hub vs Switch:

* **Hub**: Repassa tudo para todos (colisões)
* **Switch**: Repassa apenas para o destino

### Quadro Ethernet:

* **Preâmbulo**: Sincronização
* **Endereços MAC**: Origem/destino
* **Tipo de dados**
* **CRC**: Verificação de erros

### Serviço:

* Não orientado à conexão
* Não confiável
* Não há reconhecimento de recebimento

---

## VLAN (Virtual Local Area Network)

### O que é:

* Rede lógica sobre rede física
* Divide a LAN em domínios de broadcast distintos

### Como funciona:

* Switches gerenciáveis com suporte a VLAN
* Cada porta pertence a uma VLAN

### Vantagens:

* * Organização
* * Segurança
* * Redução de broadcast
* * Melhora performance

### Identificação:

* VLANs possuem IDs
* Frames podem ser "tagged" (IEEE 802.1Q)

### Tipos de portas:

* **Access port**: Associa a uma única VLAN
* **Trunk port**: Carrega múltiplas VLANs com tags


## Onde ainda pode haver colisões:
Redes sem fio (onde é difícil detectar colisões diretamente)

Cenários de acesso múltiplo sem coordenação central

Sistemas como DOCSIS (no upstream) também tratam colisões por meio de requisições aleatórias e retentativas