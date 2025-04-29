# 🌌 SNES Orbital Trigonometry Demo

Este é um projeto de demonstração para Super Nintendo (SNES) que simula a órbita da lua ao redor da Terra usando funções trigonométricas (`sin` e `cos`).  
Inspirado no vídeo do GameDevBoss sobre órbitas no Mega Drive:  
🎥 [SGDK 2.10 - Minha contribuição mudou tudo! O que eu fiz??? (YouTube)](https://www.youtube.com/watch?v=EkLGyghS1Vc)

![Demonstração orbital](assets/orbital-demo.gif)

## ✨ Funcionalidades

- 🌕 Lua orbitando a Terra com movimento elíptico ajustável.
- 🎮 Cursor controlável via controle SNES que também orbita a Terra.
- 🛠️ Estrutura modular com `Earth`, `Moon`, `Cursor` e utilitários matemáticos.

## 🧮 Sistema Trigonométrico Customizado

Para simular o movimento orbital sem o uso de ponto flutuante (não suportado nativamente pelo SNES), o projeto utiliza uma **tabela de lookup** para `seno` de 0° a 90°, com valores inteiros de 0 a 1000 (representando 0.0 a 1.0). A partir disso, as funções `sin` e `cos` são construídas com base na simetria dos quadrantes:

### 🔢 Tabela de Seno (`all_angle[91]`)

| Ângulo | Valor Inteiro | Valor Aproximado |
| ------ | ------------- | ---------------- |
| 0°     | 0             | 0.0              |
| 30°    | 500           | 0.5              |
| 90°    | 1000          | 1.0              |

Essa tabela reduz o custo computacional e evita cálculos de ponto flutuante em tempo real.

### 🧠 Funções Trigonométricas

- `s16 sin(u16 angle)`  
  Calcula o seno com base na tabela, usando simetria dos quadrantes (0–359°).
- `s16 cos(u16 angle)`  
  Calcula o cosseno reutilizando o seno: `cos(x) = sin(x + 90°)`.
- `void TrigonometryOrbital_computePositionEx(...)`  
  Calcula a posição X/Y de um objeto orbitando outro com:

  - ângulo
  - distância
  - ponto de referência
  - escala nos eixos X e Y (achatamento para elipse)

- `void TrigonometryOrbital_computePosition(...)`  
  Calcula a posição X/Y de um objeto orbitando outro com:
  - ângulo
  - distância
  - ponto de referência

Essa abordagem permite criar órbitas **circulares ou elípticas** em tempo real com alta performance.

### ✨ Exemplo de uso da órbita:

```c
u16 cursor_x, cursor_y;
TrigonometryOrbital_computePosition(
  &cursor_x,
  &cursor_y,
  earth.x + 16,  // centro da Terra
  earth.y + 16,
  cursor.angle,
  40             // raio orbital
);
```

### 🔍 Escala Elíptica

Se quiser simular uma órbita achatada (como uma elipse), use a função `TrigonometryOrbital_computePositionEx` passando `x_scale` e `y_scale` com valores diferentes de 100.

```c
u16 moon_x, moon_y;
TrigonometryOrbital_computePositionEx(
  &moon_x,
  &moon_y,
  earth.x + 16,
  earth.y + 16,
  moon.angle,
  50,
  120, // x_scale
  80   // y_scale
);
```

## ⚙️ Requisitos

- [Docker](https://www.docker.com/)
- [Node.js](https://nodejs.org/) _(opcional — usado para facilitar a execução do build via script)_
- `pvsneslib` instalada em um diretório anterior ao `workdir` do projeto

## 📦 Instalação da `pvsneslib`

Antes de compilar o projeto, você precisa ter a biblioteca [`pvsneslib`](https://github.com/alekmaul/pvsneslib) instalada.  
Você pode baixá-la diretamente através da página de releases oficiais:

🔗 **[Download da pvsneslib (Releases)](https://github.com/alekmaul/pvsneslib/releases)**

> Após o download, descompacte a lib em um diretório anterior ao do seu projeto para que a estrutura fique assim:
>
> ```
> /seu-workspace/
> ├── pvsneslib/
> └── seu-projeto/
> ```

## 🚀 Como rodar

### Usando Node.js

Se você tiver o Node.js instalado, pode rodar:

```bash
npm run pvsneslib:build
```

### Usando apenas Docker

Se não tiver o Node.js instalado:

```bash
docker compose -f infra/compose.yaml up
```

## 📦 Estrutura do Projeto

```
├── infra/
│ ├── Dockerfile
│ └── compose.yaml           # Docker Compose para build automatizado
├── assets/
│ └── orbital-demo.png       # Imagem ilustrativa da simulação
├── res/
│ ├── gfx/
│ │ └── bg.png               # Imagem do Background
│ └── sprite/
│     └── spr_all.png        # Imagem com Todos os Sprites
├── src/
│ ├── core/
│ │ ├── background.h/.c        # Gerenciamento do background
│ │ ├── palette_sprite.h/.c    # Paletas de cor para sprites
│ │ └── storage_sprite.h/.c    # Carregamento e gerenciamento de sprites
│ ├── math/
│ │ └── trigonometry.h/.c      # Funções trigonométricas personalizadas
│ ├── main.c                   # Entrada principal do jogo
│ ├── earth.h/.c               # Lógica da Terra
│ ├── moon.h/.c                # Lógica da Lua
│ └── cursor.h/.c              # Lógica do cursor controlável
├── .env                       # Variáveis de Ambiente: Nome da ROM e Modo Debug
├── data.asm
├── hdr.asm
├── Makefile
├── README.md
└── trigonometry.sfc           # Demonstração
```

## 🙌 Créditos

- 🎮 **[pvsneslib](https://github.com/alekmaul/pvsneslib)** – Biblioteca base para desenvolvimento SNES em C.
- 🎥 **GameDevBoss** – Pela inspiração e explicação sobre órbitas no Mega Drive.  
  Vídeo: [SGDK 2.10 - Minha contribuição mudou tudo!](https://www.youtube.com/watch?v=EkLGyghS1Vc)

---

Sinta-se livre para estudar, modificar e expandir!

🛠️ Made with ❤️ e nostalgia.
