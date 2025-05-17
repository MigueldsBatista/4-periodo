## Infraestrutura de Comunicação de Redes Móveis

### Evolução das Redes Móveis: 4G e 5G

As redes móveis evoluíram para fornecer maior velocidade, menor latência e suporte a novos tipos de aplicações. O mundo é dividido em **células**, onde cada dispositivo (UE - User Equipment) se conecta à **estação base** mais próxima.

---

## 4G LTE (Long Term Evolution)

### Como funciona:

* Baseado em **comutação de pacotes** (ao contrário do 3G, que usa comutação de circuitos em parte).
* Toda a comunicação é roteada via IP.

### Arquitetura e elementos principais:

* **UE (User Equipment)**: Dispositivo do usuário (smartphone, modem, etc.)
* **eNodeB**: Estação rádio-base que conecta o UE à rede
* **MME (Mobility Management Entity)**: Responsável por controle de mobilidade, autenticação e gerenciamento de sessões
* **HSS (Home Subscriber Server)**: Banco de dados central com informações de autenticação e localização dos usuários
* **Gateway (SGW e PGW)**: SGW roteia dados dentro da rede LTE; PGW conecta à Internet

---

## Estabelecimento de Conexão

### 1. Sincronização e Detecção da Célula

* O UE busca sinais de sincronização (PSS/SSS) da estação base
* Detecta a célula mais próxima e ajusta relógio e frequência

### 2. Associação com Estação Base

* UE envia uma requisição de conexão pelo canal **RACH (Random Access Channel)**
* Inclui identificação temporária
* eNodeB responde com alocação de recursos

### 3. Autenticação e Identidade

* UE envia identidade
* MME consulta o HSS para autenticar
* Sessão é estabelecida se a identidade for válida

### 4. Alocação de Endereço IP e Criação de Túneis

* O PGW aloca um endereço IP ao UE
* É criado um túnel GTP (GPRS Tunneling Protocol), identificado por um TEID, entre o UE e o PGW

### 5. Acesso à Internet

* Com o túnel criado, os dados podem fluir entre o UE e a internet

### 6. Transição para Estado Inativo/Ativo

* Quando o UE não está transmitindo, entra em modo inativo para poupar energia
* A **paginação** é usada pela rede para reativar o UE quando dados chegam

---

## Pilha de Protocolos LTE

* Baseada em IP

### Camadas intermediárias:

* **PDCP (Packet Data Convergence Protocol)**: Compressão de cabeçalho e criptografia
* **RLC (Radio Link Control)**: Correção de erros e reordenação
* **MAC (Medium Access Control)**: Acesso ao meio e agendamento
* **PHY (Física)**: Transmissão real dos bits via rádio
* **ARP**: Resolve IP para MAC dentro da rede local

---

## Vantagens do 4G em relação ao 3G

* * Velocidade maior (até 100 Mbps)
* * Suporte a vídeo em tempo real e jogos online
* * Latência reduzida
* * Mais estabilidade e melhor cobertura em áreas urbanas

---

## 5G – Quinta Geração

### O que muda:

* Muito mais velocidade (Gbps)
* Latência muito baixa (<1 ms)
* Suporte massivo a dispositivos (IoT)

### Principais Pontos:

* Separação de planos de controle e dados
* Conectividade confiável e sob demanda

### Benefícios para empresas:

* * Aumento de produtividade
* * Otimização de processos com automação
* * Sustentabilidade via uso eficiente de energia e recursos

### Benefícios para pessoas:

* * Baixo consumo de energia por dispositivo
* * Setor da saúde com suporte a cirurgias remotas e telemedicina

### Tecnologias 5G:

* **MIMO Massivo**: Várias antenas aumentam a capacidade e eficiência espectral
* **Beamforming**: Direcionamento do sinal para usuários específicos
* **Ondas Milimétricas**: Alta frequência, alta taxa de dados, curto alcance
* **Network Slicing**: Criação de redes virtuais otimizadas para diferentes serviços

### Limitações:

* Alcance menor, mais suscetível a obstáculos
* Infraestrutura cara (mais antenas pequenas)

---

## Gerenciamento da Mobilidade em Redes Móveis

### Conceito:

* **Mobilidade**: Capacidade do dispositivo manter conexão mesmo em movimento

### Tipos:

* **Desligamento em movimento**: UE sai do alcance e desconecta
* **Movimento dentro da mesma rede**:

  * **Handover**: Troca de estação base (mesma operadora)
* **Roaming**: Dispositivo muda de operadora (ex: Oi para Claro)

### Rede Nativa x Rede Visitada:

* Rede **nativa**: onde o dispositivo é registrado originalmente
* Rede **visitada**: rede externa (ou internacional)
* Ambas mantêm a sessão via comunicação entre seus elementos de controle

---

## Estratégias de Roteamento

* **Roteamento indireto**:

  * Os dados passam por um ponto central (ex: rede nativa)
  * * Fácil de gerenciar
  * * Maior latência

* **Roteamento direto**:

  * Dados fluem diretamente entre UE e PGW da rede visitada
  * * Menor latência
  * * Mais difícil de controlar

Esses mecanismos asseguram que usuários móveis mantenham conectividade com qualidade, mesmo mudando de localização ou rede.
