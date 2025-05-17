## Redes Sem Fio: Fundamentos e Funcionamento

### 1. Introdução

Redes sem fio possibilitam a comunicação entre dispositivos sem a necessidade de cabos físicos, utilizando ondas eletromagnéticas como meio de transmissão. São amplamente utilizadas em ambientes domésticos, corporativos e públicos.

---

### 2. Elementos da Rede Sem Fio

* **Estação (STA)**: Dispositivo cliente, como notebooks, smartphones, etc.
* **Ponto de Acesso (AP)**: Coordena a comunicação entre as estações e conecta a rede sem fio à rede cabeada.
* **Meio de transmissão**: O ar, utilizado para propagação dos sinais de rádio.
* **Controlador de rede**: Em redes corporativas, gerencia múltiplos APs.

---

### 3. Tipos de Rede Sem Fio

1. **WPAN (Wireless Personal Area Network)**: Curta distância (ex: Bluetooth)
2. **WLAN (Wireless Local Area Network)**: Média distância, como Wi-Fi
3. **WMAN (Wireless Metropolitan Area Network)**: Cobre cidades (ex: WiMAX)
4. **WWAN (Wireless Wide Area Network)**: Longas distâncias, ex: redes celulares

---

### 4. Desafios Técnicos

* Interferência de outros dispositivos
* Segurança da transmissão
* Variação de sinal (desvanecimento)
* Limitações de banda

---

### 5. Características dos Enlaces e Redes Sem Fio

* **Atenuação**: Perda de potência com a distância
* **Interferência**: Sinais externos prejudicam a comunicação
* **Multivias**: Reflexões causam diferentes caminhos para o sinal
* **Maior taxa de erro**: Enlaces sem fio usam **CRC** e **retransmissão** para garantir confiabilidade
* **SNR (Signal-to-Noise Ratio)**: Quanto maior, melhor a qualidade do enlace
* **Modulação Adaptativa**: Ajuste dinâmico do esquema de modulação conforme a qualidade do sinal
* **Terminal Oculto**: Dispositivos fora do alcance um do outro colidem ao transmitir simultaneamente
* **Desvanecimento**: Flutuações rápidas na intensidade do sinal

---

### 6. CDMA (Code Division Multiple Access)

Permite que múltiplos dispositivos compartilhem o mesmo canal usando códigos únicos de espalhamento (chipping code).

#### Como funciona:

* Cada transmissor codifica seu sinal com um código exclusivo
* O receptor utiliza o mesmo código para extrair os dados desejados
* Vários sinais coexistem no mesmo canal sem interferência significativa

---

### 7. Controle de Acesso ao Meio – IEEE 802.11

* Dispositivos compartilham o mesmo canal (o ar)
* Utilizam o método **CSMA/CA (Carrier Sense Multiple Access with Collision Avoidance)**

#### Funcionamento:

* Escuta o canal antes de transmitir
* Se estiver ocupado, espera um tempo aleatório (backoff)
* Reduz as colisões, ao contrário do CSMA/CD usado em Ethernet

#### Confirmação e Recebimento

* Problema do **terminal oculto**
* Solução: RTS/CTS (Request to Send / Clear to Send)
* Processo:

  * STA1 envia RTS
  * AP responde CTS
  * Outras estações ouvem o CTS e evitam transmitir

---

### 8. Wi-Fi Essencial: Quadros e Conexão

#### Estrutura dos quadros Wi-Fi:

* Campos: preâmbulo, endereço de destino, endereço de origem, controle, dados, CRC

#### Conexão:

* **Associação**: STA solicita conexão com AP
* **Desassociação**: STA informa que está se desconectando

---

### 9. Mobilidade e Recursos Avançados

#### Mobilidade:

* Dispositivo muda de um AP para outro (handoff)
* Pode manter sessões ativas (ex: chamada de vídeo)

#### Segurança:

* **WEP**: Obsoleto, inseguro
* **WPA / WPA2 / WPA3**: Proporcionam autenticação e criptografia

#### Qualidade de Serviço (QoS):

* Prioriza tráfego sensível a latência (ex: chamadas vs. downloads)
* Mecanismos: IEEE 802.11e

Esses fundamentos são essenciais para compreender como redes sem fio operam, os desafios enfrentados e os mecanismos de controle utilizados para garantir comunicação eficiente e segura.
