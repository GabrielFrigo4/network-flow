# 📋 TO-DO Geral: Problemas de Fluxos em Redes

Documento de acompanhamento da pesquisa **"Problemas de Fluxos em Redes: Teoria, Algoritmos e Implementações"**, iniciada como Iniciação Científica na UFABC (orientação da Profa. Dra. Cristiane Maria Sato, condução de Gabriel Frigo) e continuada na forma do livro monográfico ([`latex/book.tex`](./latex/book.tex)) e da biblioteca C++23 em [`implementations/`](./implementations/).

> [!IMPORTANT]
> **Ciclo de Vida do Repositório:**
>
> - 🔒 **Iniciação Científica UFABC (`proposal.tex`, `report.tex`, `ic.tex`, `monolith.tex`, `poster.tex`, `latex/sections/`, `latex/tables/`, `latex/figures/`):** **Finalizada e congelada.** Texto, tabelas, figuras e pôster permanecem preservados como registro histórico entregue no Edital 01/2025 PIC/PIBIC. Apenas correções de código nos 9 motores originais da IC continuam sincronizadas automaticamente nos apêndices (`01` a `11`) e no `monolith.tex` via `make sync-code`.
> - 🟢 **Livro Monográfico (`latex/book.tex`), Famílias Editoriais Vivas (`latex/cards/`, `latex/minibooks/`, `latex/notebooks/`, `latex/slides/`), Biblioteca C++23 e Benchmarks Pós-IC (`make bench-book`):** **Em evolução contínua**, concentrando novos algoritmos, modelagens combinatórias, materiais derivados e validações em juízes online.

---

## 🧭 Sumário de Navegação

- [📖 Bloco I: Roadmap Ativo do Livro (book.tex) & Expansões](#-bloco-i-roadmap-ativo-do-livro-booktex--expansões)
    - [Arquitetura Editorial do Livro (`book.tex`)](#-arquitetura-editorial-do-livro-booktex)
    - [Roadmap Editorial e Estrutural do Livro (`book.tex`)](#-roadmap-editorial-e-estrutural-do-livro-booktex)
    - [Novos Artefatos Editoriais Vivos (Pós-IC)](#-novos-artefatos-editoriais-vivos-pós-ic)
    - [Expansões Algorítmicas Concluídas (Pós-IC)](#-expansões-algorítmicas-concluídas-pós-ic)
- [⚡ Bloco II: Motores de Fluxo em C++23](#-bloco-ii-motores-de-fluxo-em-c23)
    - [Algoritmos de Fluxo Máximo](#-algoritmos-de-fluxo-máximo)
    - [Algoritmos de Fluxo de Custo Mínimo](#-algoritmos-de-fluxo-de-custo-mínimo)
- [🎯 Bloco III: Modelagem, Reduções e Problemas](#-bloco-iii-modelagem-reduções-e-problemas)
    - [Mecânicas e Técnicas de Redução](#-mecânicas-e-técnicas-de-redução)
    - [Aplicação Prática: Segmentação de Imagens](#-aplicação-prática-segmentação-de-imagens)
    - [Validação em Juízes Online: Problemas Resolvidos](#-validação-em-juízes-online-problemas-resolvidos)
    - [Problemas Complementares Avançados (Concluídos Pós-IC)](#-problemas-complementares-avançados-concluídos-pós-ic)
    - [Backlog de Modelagens e Problemas (Livro Maratona)](#-backlog-de-modelagens-e-problemas-livro-maratona)
- [📚 Bloco IV: Teoria e Rigor Matemático](#-bloco-iv-teoria-e-rigor-matemático)
    - [Axiomas e Leis Fundamentais](#-axiomas-e-leis-fundamentais)
    - [Teoremas de Conectividade e Estrutura](#-teoremas-de-conectividade-e-estrutura)
    - [Teoria em Grafos Bipartidos](#-teoria-em-grafos-bipartidos)
    - [Teoremas de Fluxo de Custo Mínimo](#-teoremas-de-fluxo-de-custo-mínimo)
    - [Network Simplex: Estruturas e Mecânicas](#-network-simplex-estruturas-e-mecânicas)
    - [Teoremas de Modelagens Avançadas (Cap. 12)](#-teoremas-de-modelagens-avançadas-cap-12)
- [📊 Bloco V: Validação Experimental e Histórico Institucional](#-bloco-v-validação-experimental-e-histórico-institucional)
    - [Infraestrutura e Automação de Benchmarks](#-infraestrutura-e-automação-de-benchmarks)
    - [Instâncias e Geradores Sintéticos](#-instâncias-e-geradores-sintéticos)
    - [Baterias Experimentais e Análise de Desempenho](#-baterias-experimentais-e-análise-de-desempenho)
    - [Histórico Institucional: Iniciação Científica UFABC (🔒 Finalizado)](#-histórico-institucional-iniciação-científica-ufabc--finalizado)

---

# 📖 Bloco I: Roadmap Ativo do Livro (`book.tex`) & Expansões

## 📚 Arquitetura Editorial do Livro (`book.tex`)

Monografia independente em LaTeX ([`latex/book.tex`](./latex/book.tex)), estruturada em **5 Partes e 14 Capítulos** com 15 motores algorítmicos C++23, modelagens combinatórias genéricas, aplicação em visão computacional e suíte experimental dedicada (`latex/book/tables/`, `latex/book/figures/`):

| Parte / Eixo Editorial                                         | Capítulos                                             | Escopo Consolidado                                                                                                           |
| :------------------------------------------------------------- | :---------------------------------------------------- | :--------------------------------------------------------------------------------------------------------------------------- |
| **Parte I:** Teoria Estrutural e Algoritmos de Fluxo Máximo    | `01_fundamentals` a `04_preflow_push` (Caps. 1–4)     | Definições formais, Dualidade MFMC e Integralidade, Caminhos Aumentantes (FF, EK, Dinic, MPM) e Push-Relabel (FIFO e Gap).   |
| **Parte II:** Otimização em Grafos Bipartidos e Conectividade  | `05_bipartite_graphs` a `06_connectivity` (5–6)       | Emparelhamento, König, Gallai, Hall, Kuhn, Hopcroft-Karp, Menger, Vertex Splitting e Decomposição Linear.                    |
| **Parte III:** Fluxo de Custo Mínimo e Otimização Primal-Dual  | `07_min_cost_theory` a `11_min_cost_synthesis` (7–11) | Teoria MCF, Métodos Primais (Klein, MMCC, Cancel-and-Tighten), Métodos Duais (SSP, Kuhn-Munkres), Network Simplex e Síntese. |
| **Parte IV:** Modelagem, Reduções e Aplicações Práticas        | `12_advanced_modeling` a `13_segmentation` (12–13)    | Fechamento de Peso Máximo, Cotas Inferiores, $b$-Emparelhamentos, DAGs/Dilworth, Custos Convexos e Segmentação de Imagens.   |
| **Parte V:** Validação Experimental e Engenharia de Desempenho | `14_benchmarks` (Cap. 14) + Apêndices `00`–`18`       | Protocolo com 80 instâncias DIMACS + 18 bipartidas, tabelas, gráficos Pós-IC e listagens C++23 sincronizadas.                |

---

## 🧭 Roadmap Editorial e Estrutural do Livro (`book.tex`)

- [x] **Reorganização Arquitetural em 5 Partes:** Deslocar a _Segmentação Interativa de Imagens_ para a Parte IV (**Modelagem, Reduções e Aplicações Práticas**, Cap. 13) antes dos Benchmarks (Parte V, Cap. 14), preservando a continuidade teórica direta entre Conectividade (Cap. 6) e Fluxo de Custo Mínimo (Cap. 7).
- [x] **Particionamento Didático dos Algoritmos de Custo Mínimo:** Dividir o antigo Cap. 9 em **Métodos Primais de Cancelamento de Ciclos** (Cap. 8: Klein $\to$ MMCC $\to$ Cancel-and-Tighten) e **Métodos Duais e Primal-Duais: Caminhos de Custo Mínimo** (Cap. 9: SSP-SPFA, SSP-Dijkstra e Kuhn-Munkres).
- [x] **Formalização Genérica de Modelagens Avançadas (Cap. 12):** Redigir [`12_advanced_modeling.tex`](./latex/book/chapters/12_advanced_modeling.tex) cobrindo Fechamento de Peso Máximo (Picard), Circulação e Fluxos com Cotas Inferiores ($l \le f \le c$), $b$-Emparelhamentos e Decomposição Ortogonal, Cobertura Mínima de Caminhos em DAGs / Teorema de Dilworth e Custos Convexos por Partes.
- [ ] **Implementar e Validar Código para as Modelagens já Formalizadas no Livro (`LaTeX: ✅ | Código: ⏳`):**
    - Cobertura Mínima de Caminhos em DAG (Disjunta / Transitiva) — validar em POJ 2060 / UVa 1184.
    - Teorema de Dilworth e Anticadeia Máxima em Posets — validar em POJ 1548 / SPOJ _MDOLLS_.
    - Fluxo Máximo e Mínimo $s$-$t$ com Cotas Inferiores — validar em LOJ 116 / LOJ 117.
    - Custos Convexos por Partes em MCF — validar em [CF 863F](https://codeforces.com/problemset/problem/863/F).
- [ ] **Apêndice de Templates Compactos para Maratona (ICPC):** Criar apêndice no livro e integrar com os cadernos em [`latex/notebooks/`](./latex/notebooks/) usando versões enxutas (~60 linhas) de `Dinic` e `MCMF-Dijkstra` para caderno de competição (_Notebook ICPC_), validadas automaticamente contra os motores OOP de [`flow-network/`](./implementations/flow-network/) e [`cost-network/`](./implementations/cost-network/).
- [ ] **Expansão de Modelagens de Fronteira (Nível 3):** Formalizar no Cap. 12 e validar em código Redes Expandidas no Tempo, Corte Mínimo Global (Stoer-Wagner) / Árvore de Gomory-Hu, Dualidade Planar ($s$-$t$ Corte Mínimo $\iff$ Caminho Dual), Subgrafo de Densidade Máxima (Goldberg, 1984) e Otimização Paramétrica / Dualidade Linear de MCF.

---

## 🎨 Novos Artefatos Editoriais Vivos (Pós-IC)

Além do livro principal, novas frentes editoriais mantêm evolução contínua sem alterar os documentos congelados da IC:

### Famílias Estruturadas no Repositório

| Família Editorial              | Pasta                                    | Estrutura & Makefile | Artefatos `.tex` | Escopo e Descrição                                                                                           |
| :----------------------------- | :--------------------------------------- | :------------------: | :--------------: | :----------------------------------------------------------------------------------------------------------- |
| **Cards de Referência Rápida** | [`latex/cards/`](./latex/cards/)         |          ✅          |   ⏳ Planejado   | 9 _cheat sheets_ de 1 página para consulta rápida de teoremas, invariantes, complexidades e reduções.        |
| **Mini-Books Monotemáticos**   | [`latex/minibooks/`](./latex/minibooks/) |          ✅          |   ⏳ Planejado   | 6 volumes curtos (15–30 páginas) dedicados a temas isolados para leitura independente.                       |
| **Cadernos ICPC e Maratona**   | [`latex/notebooks/`](./latex/notebooks/) |          ✅          |   ⏳ Planejado   | 3 cadernos em 2 colunas com templates C++23 (~60 linhas) e checklists de modelagem para prova.               |
| **Apresentações Beamer**       | [`latex/slides/`](./latex/slides/)       |          ✅          |   ⏳ Planejado   | 4 decks de slides reutilizando diretamente os diagramas vetoriais de [`latex/diagrams/`](./latex/diagrams/). |

### Catálogo Completo Planejado por Família

- **🃏 Cards (`latex/cards/README.md`) — 9 artefatos (`⏳ Planejado`):**
    1. `max-flow-cheatsheet.tex` — Quadro comparativo dos 8 motores `FlowNetwork`.
    2. `min-cost-cheatsheet.tex` — Quadro comparativo dos 7 motores `CostNetwork`.
    3. `bipartite-dualities.tex` — As Quatro Dualidades (König, Gallai, Hall) e reconstrução residual.
    4. `modeling-patterns-maxflow.tex` — Receituário visual em Fluxo Máximo (Vertex Splitting, Corte Mínimo, Picard).
    5. `modeling-patterns-mcf.tex` — Receituário visual em Custo Mínimo (Cotas Inferiores, Custos Convexos, MCMF).
    6. `dag-dilworth-card.tex` — Cobertura Mínima de Caminhos em DAGs, Bipartido Dividido $B(D)$ e Dilworth.
    7. `network-simplex-pivoting.tex` — Mecânica visual do Network Simplex (`T/L/U`, `thread`, ciclo fundamental).
    8. `strongly-polynomial-mcf.tex` — Síntese visual de Karp, $\varepsilon$-otimalidade, MMCC e Cancel-and-Tighten.
    9. `graph-cuts-vision.tex` — Card visual de Segmentação Interativa de Imagens via Corte Mínimo (N-links e T-links).
- **📘 Mini-Books (`latex/minibooks/README.md`) — 6 volumes (`⏳ Planejado`):**
    1. `max-flow-essentials.tex` — _Guia Essencial de Fluxo Máximo_.
    2. `bipartite-optimization.tex` — _Otimização em Grafos Bipartidos_.
    3. `modeling-handbook.tex` — _Manual da Arte da Modelagem em Fluxos_.
    4. `min-cost-and-simplex.tex` — _Fluxo de Custo Mínimo e Network Simplex_.
    5. `strongly-polynomial-flows.tex` — _Algoritmos Fortemente Polinomiais em Redes_.
    6. `graph-cuts-segmentation.tex` — _Visão Computacional com Corte Mínimo_.
- **📓 Cadernos ICPC (`latex/notebooks/README.md`) — 3 cadernos (`⏳ Planejado`):**
    1. `icpc-flow-notebook.tex` — _Caderno ICPC Completo de Fluxos em Redes_ (2 colunas).
    2. `icpc-maxflow-cheatsheet.tex` — _Caderno Compacto de Fluxo Máximo e Bipartidos_.
    3. `icpc-mcf-cheatsheet.tex` — _Caderno Compacto de Custo Mínimo_.
- **📽️ Apresentações Beamer (`latex/slides/README.md`) — 4 decks (`⏳ Planejado`):**
    1. `intro-max-flow.tex` — _Introdução a Fluxo Máximo e Corte Mínimo_.
    2. `maratona-flow-modeling.tex` — _Oficina de Modelagem de Fluxos para Maratona (ICPC)_.
    3. `min-cost-network-simplex.tex` — _Fluxo de Custo Mínimo, Dualidade e Network Simplex_.
    4. `graph-cuts-vision-talk.tex` — _Segmentação de Imagens com Corte Mínimo em C++23_.

### 💡 Ideias Bônus para Expansão Futura (Backlog Aberto)

- [ ] **Listas de Exercícios Comentadas (`latex/workbooks/`):** Cadernos temáticos com enunciados originais, roteiro de redução guiado, gabarito matemático e dicas progressivas por nível.
- [ ] **Galeria Standalone de Diagramas TikZ (`latex/diagrams/` $\to$ SVG/PDF):** Compilação isolada dos diagramas TikZ em figuras vetoriais independentes para reuso direto em READMEs, blog técnico e slides.
- [ ] **Notas Técnicas / Artigos Curtos (`latex/articles/`):** Textos executivos de 8–12 páginas para divulgação técnica ou portfólio sem alterar o relatório congelado da IC.

---

## 🚀 Expansões Algorítmicas Concluídas (Pós-IC)

Desenvolvimento algorítmico e pesquisa teórica concluídos na fase Pós-IC e integrados exclusivamente ao livro monográfico ([`latex/book.tex`](./latex/book.tex)), mantendo os artefatos institucionais da Iniciação Científica congelados no escopo original entregue.

| Algoritmo / Componente                                                                           | Referência Teórica                    |                  Complexidade                   | LaTeX (Livro) | Implementação | Foco e Descrição Técnica                                                                                         |
| :----------------------------------------------------------------------------------------------- | :------------------------------------ | :---------------------------------------------: | :-----------: | :-----------: | :--------------------------------------------------------------------------------------------------------------- |
| [**Kuhn**](./implementations/flow-network/Kuhn.hpp)                                              | Kuhn (1955)                           |        $\mathcal{O}(\|V\| \cdot \|E\|)$         |      ✅       |      ✅       | Emparelhamento bipartido clássico via busca em profundidade (DFS) de caminhos alternantes.                       |
| [**Hopcroft-Karp**](./implementations/flow-network/HopcroftKarp.hpp)                             | Hopcroft e Karp (1973)                |        $\mathcal{O}(\|E\| \sqrt{\|V\|})$        |      ✅       |      ✅       | Emparelhamento máximo bipartido não ponderado (fases de BFS global e DFS bloqueadora).                           |
| [**Algoritmo Húngaro (Kuhn-Munkres)**](./implementations/cost-network/KuhnMunkres.hpp)           | Kuhn (1955), Munkres (1957)           |             $\mathcal{O}(\|V\|^3)$              |      ✅       |      ✅       | Atribuição de custo mínimo (emparelhamento com pesos) via potenciais duais e folgas complementares.              |
| [**MPM (Malhotra, Kumar, Maheshwari)**](./implementations/flow-network/MPM.hpp)                  | Malhotra et al. (1978)                |             $\mathcal{O}(\|V\|^3)$              |      ✅       |      ✅       | Fluxo bloqueador via potenciais nodais de passagem em digrafos densos.                                           |
| [**Minimum-Mean Cycle Canceling**](./implementations/cost-network/MinimumMeanCycleCanceling.hpp) | Goldberg & Tarjan (1989); Karp (1978) | $\mathcal{O}(\|V\|^2 \cdot \|A\|^3 \log \|V\|)$ |      ✅       |      ✅       | Cancelamento iterativo de ciclos de custo médio mínimo via programação dinâmica de Karp (fortemente polinomial). |
| [**Cancel-and-Tighten**](./implementations/cost-network/CancelAndTighten.hpp)                    | Goldberg & Tarjan (1989)              | $\mathcal{O}(\|V\|^2 \cdot \|A\|^2 \log \|V\|)$ |      ✅       |      ✅       | Escalonamento $\varepsilon$-ótimo combinando cancelamento de ciclos admissíveis e aperto de potenciais nodais.   |
| [**Harness de Benchmark Bipartido**](./experiments/drivers/bipartite_runner.cpp)                 | Suíte Comparativa Dedicada            |               Benchmark Empírico                |      ✅       |      ✅       | Avaliação empírica: reduções genéricas via `FlowNetwork`/`CostNetwork` vs. algoritmos dedicados bipartidos.      |

- [x] **Kuhn:** Implementar algoritmo de Kuhn em C++23 ([`Kuhn.hpp`](./implementations/flow-network/Kuhn.hpp)) herdando de [`FlowNetwork`](./implementations/flow-network/FlowNetwork.hpp) para emparelhamento bipartido via caminhos alternantes em $\mathcal{O}(\|V\| \cdot \|E\|)$.
- [x] **Hopcroft-Karp:** Implementar motor dedicado de emparelhamento bipartido máximo em C++23 ([`HopcroftKarp.hpp`](./implementations/flow-network/HopcroftKarp.hpp)) herdando de [`FlowNetwork`](./implementations/flow-network/FlowNetwork.hpp) com complexidade $\mathcal{O}(\|E\| \sqrt{\|V\|})$.
- [x] **Algoritmo Húngaro (Kuhn-Munkres):** Implementar algoritmo Húngaro em C++23 ([`KuhnMunkres.hpp`](./implementations/cost-network/KuhnMunkres.hpp)) herdando de [`CostNetwork`](./implementations/cost-network/CostNetwork.hpp) para problema de atribuição de custo mínimo em $\mathcal{O}(\|V\|^3)$.
- [x] **MPM (Malhotra, Kumar, Maheshwari):** Implementar classe `MPM` ([`MPM.hpp`](./implementations/flow-network/MPM.hpp)) herdando de [`FlowNetwork`](./implementations/flow-network/FlowNetwork.hpp) com fluxo bloqueador em $\mathcal{O}(\|V\|^3)$ e validar nas 40 instâncias DIMACS.
- [x] **Minimum-Mean Cycle Canceling:** Implementar algoritmo fortemente polinomial de Goldberg-Tarjan em C++23 ([`MinimumMeanCycleCanceling.hpp`](./implementations/cost-network/MinimumMeanCycleCanceling.hpp)) herdando de [`CostNetwork`](./implementations/cost-network/CostNetwork.hpp) com detecção de ciclos via Karp em $\mathcal{O}(\|V\|^2 \cdot \|A\|^3 \log \|V\|)$.
- [x] **Cancel-and-Tighten:** Implementar motor fortemente polinomial de Goldberg-Tarjan em C++23 ([`CancelAndTighten.hpp`](./implementations/cost-network/CancelAndTighten.hpp)) herdando de [`CostNetwork`](./implementations/cost-network/CostNetwork.hpp) com cancelamento de ciclos admissíveis e aperto de potenciais em $\mathcal{O}(\|V\|^2 \cdot \|A\|^2 \log \|V\|)$.
- [x] **Benchmark Bipartido e Separação IC vs. Livro:** Separar os artefatos experimentais da IC (`latex/tables/`, `latex/figures/`, `make bench-ic`) dos artefatos expandidos do Livro Pós-IC (`latex/book/tables/`, `latex/book/figures/`, `make bench-book`).

---

# ⚡ Bloco II: Motores de Fluxo em C++23

## ⚡ Algoritmos de Fluxo Máximo

Progresso dos algoritmos de fluxo máximo implementados em C++ e documentados no [Livro](./latex/book.tex). O código-fonte de cada algoritmo pode ser encontrado no diretório de [Implementações](./implementations/README.md), onde cada algoritmo herda da classe base abstrata [`FlowNetwork`](./implementations/flow-network/FlowNetwork.hpp).

| Nome                                                                            | LaTeX | Implementação | Descrição                                                                                                                            |
| :------------------------------------------------------------------------------ | :---: | :-----------: | :----------------------------------------------------------------------------------------------------------------------------------- |
| [Ford-Fulkerson](./implementations/flow-network/FordFulkerson.hpp)              |  ✅   |      ✅       | Método iterativo genérico baseado em caminhos aumentantes (pseudopolinomial).                                                        |
| [Edmonds-Karp](./implementations/flow-network/EdmondsKarp.hpp)                  |  ✅   |      ✅       | Especialização do Ford-Fulkerson com BFS. Complexidade $\mathcal{O}(\|V\| \cdot \|E\|^2)$.                                           |
| [Dinic Algorithm](./implementations/flow-network/Dinic.hpp)                     |  ✅   |      ✅       | Digrafo de níveis + fluxo bloqueador via DFS. Complexidade $\mathcal{O}(\|V\|^2 \cdot \|E\|)$.                                       |
| [MPM (Malhotra, Kumar, Maheshwari)](./implementations/flow-network/MPM.hpp)     |  ✅   |      ✅       | Fluxo bloqueador via potenciais nodais de passagem em redes niveladas. Complexidade $\mathcal{O}(\|V\|^3)$ estrita (Pós-IC / Livro). |
| [Push Relabel FIFO](./implementations/flow-network/PushRelabel.hpp)             |  ✅   |      ✅       | Família de pré-fluxo com fila FIFO. Complexidade $\mathcal{O}(\|V\|^3)$.                                                             |
| [Push Relabel Improved](./implementations/flow-network/PushRelabelImproved.hpp) |  ✅   |      ✅       | Push-Relabel com Gap Heuristic para terminação acelerada via descarte de nós inalcançáveis.                                          |
| [Kuhn](./implementations/flow-network/Kuhn.hpp)                                 |  ✅   |      ✅       | Emparelhamento máximo bipartido via DFS de caminhos aumentantes em $\mathcal{O}(\|V\| \cdot \|E\|)$ (Pós-IC / Livro).                |
| [Hopcroft-Karp](./implementations/flow-network/HopcroftKarp.hpp)                |  ✅   |      ✅       | Emparelhamento máximo bipartido via fases de BFS e DFS disjunta em $\mathcal{O}(\|E\|\sqrt{\|V\|})$ (Pós-IC / Livro).                |

---

## 🧮 Algoritmos de Fluxo de Custo Mínimo

Progresso dos algoritmos de fluxo de custo mínimo documentados no [Livro](./latex/book.tex) e implementados no diretório [Implementações](./implementations/README.md), onde cada algoritmo herda da classe base abstrata [`CostNetwork`](./implementations/cost-network/CostNetwork.hpp).

| Nome                                                                                            | LaTeX | Implementação | Descrição                                                                                                                                                            |
| :---------------------------------------------------------------------------------------------- | :---: | :-----------: | :------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| [Cycle Canceling](./implementations/cost-network/CycleCanceling.hpp)                            |  ✅   |      ✅       | Baseia-se em encontrar fluxos viáveis e iterativamente cancelar ciclos de custo negativo no residual.                                                                |
| [Minimum-Mean Cycle Canceling](./implementations/cost-network/MinimumMeanCycleCanceling.hpp)    |  ✅   |      ✅       | Cancelamento fortemente polinomial de ciclos residuais de custo médio mínimo via Karp em $\mathcal{O}(\|V\|^2 \cdot \|A\|^3 \log \|V\|)$ (Pós-IC / Livro).           |
| [Cancel-and-Tighten](./implementations/cost-network/CancelAndTighten.hpp)                       |  ✅   |      ✅       | Escalonamento $\varepsilon$-ótimo com cancelamento de ciclos admissíveis e aperto de potenciais em $\mathcal{O}(\|V\|^2 \cdot \|A\|^2 \log \|V\|)$ (Pós-IC / Livro). |
| [Successive Shortest Path (SPFA)](./implementations/cost-network/SuccessiveShortest.hpp)        |  ✅   |      ✅       | Roteamento de fluxo por caminhos mais baratos via aumentações sucessivas com SPFA/Bellman-Ford.                                                                      |
| [Successive Shortest (Dijkstra)](./implementations/cost-network/SuccessiveShortestDijkstra.hpp) |  ✅   |      ✅       | Aumentações sucessivas utilizando Dijkstra com potenciais nodais ($\pi$) para manter $\bar{c} \ge 0$.                                                                |
| [Network Simplex](./implementations/cost-network/NetworkSimplex.hpp)                            |  ✅   |      ✅       | Algoritmo primal baseado em árvores geradoras com pivoteamento eficiente de bases.                                                                                   |
| [Kuhn-Munkres (Algoritmo Húngaro)](./implementations/cost-network/KuhnMunkres.hpp)              |  ✅   |      ✅       | Atribuição bipartida de custo mínimo via potenciais duais em $\mathcal{O}(\|V\|^3)$ (Pós-IC / Livro).                                                                |

---

# 🎯 Bloco III: Modelagem, Reduções e Problemas

## 🛠️ Mecânicas e Técnicas de Redução

Progresso dos conceitos, mecânicas e reduções de rede documentadas no [Livro](./latex/book.tex) e validadas nas soluções em C++.

### Estruturas e Mecânicas de Busca

| Nome                                   | LaTeX | Implementação | Descrição                                                                                    |
| :------------------------------------- | :---: | :-----------: | :------------------------------------------------------------------------------------------- |
| Grafo Residual e Arestas Reversas      |  ✅   |      ✅       | Estrutura fundamental que armazena a capacidade restante e permite o cancelamento de fluxos. |
| Caminhos de Aumento (Augmenting Paths) |  ✅   |      ✅       | Rota simples no grafo residual com capacidade residual estritamente positiva.                |
| Saturação                              |  ✅   |      ✅       | Estado de uma aresta onde o fluxo $f$ é exatamente igual à sua capacidade $c$.               |

### Transformações de Rede

| Nome                                      | LaTeX | Implementação | Descrição                                                                                       |
| :---------------------------------------- | :---: | :-----------: | :---------------------------------------------------------------------------------------------- |
| Super-fonte ($s$) e Super-sumidouro ($t$) |  ✅   |      ✅       | Criação de nós auxiliares para unificar múltiplos pontos de entrada ou saída em uma única rede. |
| Múltiplas Fontes e Sumidouros             |  ✅   |      ✅       | Redução sistemática de problemas multi-ponto para o modelo padrão $s-t$.                        |
| Grafo Bipartido                           |  ✅   |      ✅       | Estrutura de rede onde os vértices são divididos em dois conjuntos disjuntos e independentes.   |

### Restrições e Divisões

| Nome                                           | LaTeX | Implementação | Descrição                                                                                          |
| :--------------------------------------------- | :---: | :-----------: | :------------------------------------------------------------------------------------------------- |
| Capacidades Unitárias ($c=1$)                  |  ✅   |      ✅       | Caso especial de modelagem para problemas de contagem, caminhos disjuntos e emparelhamento.        |
| Caminhos Disjuntos por Arestas (Edge-Disjoint) |  ✅   |      ✅       | Modelagem de rotas que não compartilham conexões entre si.                                         |
| Vertex Splitting (Divisão de Vértices)         |  ✅   |      ✅       | Técnica de substituir um nó $v$ por uma aresta $(v_{in}, v_{out})$ para controlar o fluxo interno. |
| Capacidades em Vértices (Node Capacities)      |  ✅   |      ✅       | Uso de Vertex Splitting para limitar o volume de fluxo que atravessa um nó específico.             |
| Arestas Bidirecionais vs. Direcionadas         |  ✅   |      ✅       | Diferenciação técnica no tratamento de arcos simétricos no grafo residual.                         |

### Extração e Resultados

| Nome                                  | LaTeX | Implementação | Descrição                                                                                                                          |
| :------------------------------------ | :---: | :-----------: | :--------------------------------------------------------------------------------------------------------------------------------- |
| Corte Mínimo (Algoritmo)              |  ✅   |      ✅       | Identificação do conjunto de arestas saturadas que desconectam $s$ de $t$ via busca no residual.                                   |
| Decomposição de Fluxo (Path Recovery) |  ✅   |      ✅       | Algoritmo para extrair caminhos individuais e ciclos a partir do fluxo total.                                                      |
| Complementaridade de Conjuntos        |  ✅   |      ✅       | Relação entre tamanhos de conjuntos em grafos, como o cálculo de Conjunto Independente via $\|V\| - \|C\|$ (ou $\|V\| - \tau(G)$). |

### Conceitos e Mecânicas de Custo

| Nome                             | LaTeX | Implementação | Descrição                                                                                       |
| :------------------------------- | :---: | :-----------: | :---------------------------------------------------------------------------------------------- |
| Grafo Residual com Custos        |  ✅   |      ✅       | Extensão do grafo residual com custos nos arcos diretos e custos negativos nos arcos reversos.  |
| Ciclos de Custo Negativo         |  ✅   |      ✅       | Condição de otimalidade: um fluxo é de custo mínimo se e somente se não há ciclos negativos.    |
| Custos Reduzidos (Reduced Costs) |  ✅   |      ✅       | Técnica de usar potenciais nos nós ($\pi$) para garantir custos de arestas não-negativos.       |
| Transformação Min Cost Max Flow  |  ✅   |      ✅       | Adaptação do MCF para quando desejamos empurrar o _máximo de fluxo_ com o menor custo possível. |

### Modelagens Avançadas de Fluxo

| Técnica de Modelagem                                             | LaTeX (Cap. 12) | Implementação | Foco e Aplicação Prática                                                                                                 |
| :--------------------------------------------------------------- | :-------------: | :-----------: | :----------------------------------------------------------------------------------------------------------------------- |
| **Fechamento de Peso Máximo (Redução de Picard)**                |       ✅        |      ✅       | Seleção de projetos com dependências e subgrafo induzido de peso máximo via corte mínimo $s-t$ (CF 1082G).               |
| **Circulação com Demandas e Cotas Inferiores ($l \le f \le c$)** |       ✅        |      ✅       | Atendimento de demandas $b(v)$ e capacidades mínimas via compensação $s^* / t^*$ (CF 1288F e CF 843E).                   |
| **$b$-Emparelhamentos Capacitados e Decomposição Ortogonal**     |       ✅        |      ✅       | Multiplicidades nodais com expansão unitária e particionamento em atributos disjuntos / fatores primos (CF 498C).        |
| **Cobertura Mínima de Caminhos em DAG (Disjunta / Transitiva)**  |       ✅        |      ⏳       | Partição mínima de vértices de um DAG em caminhos via bipartido dividido $B(D)$ e `HopcroftKarp` (código pendente).      |
| **Teorema de Dilworth e Anticadeia Máxima em Posets**            |       ✅        |      ⏳       | Dualidade entre cadeias e anticadeias via König no fecho transitivo $B(D^*)$ (código pendente).                          |
| **Fluxo Máximo e Mínimo $s$-$t$ com Cotas Inferiores**           |       ✅        |      ⏳       | Viabilidade por arco de retorno $(t, s, \infty)$ acoplada à maximização/minimização residual (código dedicado pendente). |
| **Custos Convexos por Partes em MCF (_Convex Cost Flow_)**       |       ✅        |      ⏳       | Linearização por múltiplos arcos paralelos de custo marginal crescente (código pendente).                                |
| **Redes Expandidas no Tempo (_Time-Expanded Networks_)**         |       ⏳        |      ⏳       | Roteamento dinâmico multi-período por replicação temporal de camadas $V \times \{0, \dots, T\}$.                         |
| **Corte Mínimo Global (Stoer-Wagner) e Árvore de Gomory-Hu**     |       ⏳        |      ⏳       | Estrutura compacta de $\|V\| - 1$ cortes equivalentes para consultas par-a-par e corte global não-dirigido.              |
| **Dualidade Planar ($s$-$t$ Corte Mínimo $\iff$ Caminho Dual)**  |       ⏳        |      ⏳       | Redução do corte mínimo em grafos planares $s$-$t$ ao caminho mínimo de Dijkstra no digrafo dual.                        |
| **Subgrafo de Densidade Máxima (_Maximum Density Subgraph_)**    |       ⏳        |      ⏳       | Busca binária paramétrica acoplada ao corte mínimo $s$-$t$ (algoritmo de Goldberg, 1984).                                |

---

## 🖼️ Aplicação Prática: Segmentação de Imagens

Software e pipeline de visão computacional desenvolvido em C++23 que emprega corte mínimo $s-t$ para segmentação binária de imagens (primeiro plano vs. fundo), documentado no **Capítulo 13** do Livro ([`13_segmentation.tex`](./latex/book/chapters/13_segmentation.tex)) e implementado em [`applications/image-segmentation/`](./applications/image-segmentation/).

| Módulo / Componente                                                                        | LaTeX (Cap. 13) | Implementação | Descrição                                                                                                  |
| :----------------------------------------------------------------------------------------- | :-------------: | :-----------: | :--------------------------------------------------------------------------------------------------------- |
| [Segmentação de Imagens (Max Flow / Min Cut)](./applications/image-segmentation/README.md) |       ✅        |      ✅       | Software para separar foreground/background em fotografias utilizando modelagem de corte mínimo em grafos. |
| [Parser e Manipulador de Imagens PPM](./applications/image-segmentation/ppm.cpp)           |       ✅        |      ✅       | Leitor e escritor de imagens em formato Portable Pixmap (`.ppm`) sem dependências externas.                |
| [Parser de Sementes (_Seeds_)](./applications/image-segmentation/seeds.cpp)                |       ✅        |      ✅       | Mapeador de pistas interativas do usuário para nós de super-fonte ($s$) e super-sumidouro ($t$).           |
| [Pipeline Principal de Segmentação](./applications/image-segmentation/main.cpp)            |       ✅        |      ✅       | Construção da rede em grade 2D, resolução via `FlowNetwork` e escrita da máscara de saída.                 |

---

## 💻 Validação em Juízes Online: Problemas Resolvidos

A suíte de problemas clássicos implementada no repositório valida as reduções teóricas implementadas nos motores de fluxo. Cada problema possui código autocontido, testes e Makefile dedicado em [`implementations/problems/`](./implementations/problems/).

### ⚡ Problemas de Fluxo Máximo

| Problema            | Juiz Online                                                                       | Código Local                                                               | Técnica de Fluxo Empregada                                    |
| :------------------ | :-------------------------------------------------------------------------------- | :------------------------------------------------------------------------- | :------------------------------------------------------------ |
| **Download Speed**  | [CSES 1694](https://cses.fi/problemset/task/1694)                                 | [`main.cpp`](./implementations/problems/max-flow/download-speed/main.cpp)  | $s-t$ Fluxo Máximo sobre rede residual.                       |
| **Police Chase**    | [CSES 1695](https://cses.fi/problemset/task/1695)                                 | [`main.cpp`](./implementations/problems/max-flow/police-chase/main.cpp)    | Corte Mínimo $s-t$ (Max-Flow Min-Cut) em arcos bidirecionais. |
| **Time Travel**     | [Beecrowd 2082](https://judge.beecrowd.com/en/problems/view/2082)                 | [`main.cpp`](./implementations/problems/max-flow/time-travel/main.cpp)     | Corte Mínimo Global via fixação iterativa de fontes.          |
| **School Dance**    | [CSES 1696](https://cses.fi/problemset/task/1696)                                 | [`main.cpp`](./implementations/problems/max-flow/school-dance/main.cpp)    | Emparelhamento Máximo Bipartido via capacidades unitárias.    |
| **Coin Grid**       | [CSES 1709](https://cses.fi/problemset/task/1709)                                 | [`main.cpp`](./implementations/problems/max-flow/coin-grid/main.cpp)       | Cobertura Mínima de Vértices via Teorema de König.            |
| **Edição de Rede**  | [CF Gym 106679E](https://codeforces.com/gym/106679/problem/E) (Maratona SBC 2026) | [`main.cpp`](./implementations/problems/max-flow/network-editing/main.cpp) | Redução para Emparelhamento Bipartido Máximo com fórmula.     |
| **Distinct Routes** | [CSES 1711](https://cses.fi/problemset/task/1711)                                 | [`main.cpp`](./implementations/problems/max-flow/distinct-routes/main.cpp) | Caminhos disjuntos por arestas e decomposição de fluxo.       |

### 🧮 Problemas de Fluxo de Custo Mínimo

| Problema                 | Juiz Online                                                                       | Código Local                                                                       | Técnica de Fluxo Empregada                                 |
| :----------------------- | :-------------------------------------------------------------------------------- | :--------------------------------------------------------------------------------- | :--------------------------------------------------------- |
| **Parcel Delivery**      | [CSES 2121](https://cses.fi/problemset/task/2121)                                 | [`main.cpp`](./implementations/problems/min-cost-flow/parcel-delivery/main.cpp)    | Fluxo de Custo Mínimo com Demanda Exata $k$.               |
| **Task Assignment**      | [CSES 2129](https://cses.fi/problemset/task/2129)                                 | [`main.cpp`](./implementations/problems/min-cost-flow/task-assignment/main.cpp)    | Atribuição Bipartida de Custo Mínimo (Assignment Problem). |
| **Distinct Routes II**   | [CSES 2130](https://cses.fi/problemset/task/2130)                                 | [`main.cpp`](./implementations/problems/min-cost-flow/distinct-routes-ii/main.cpp) | Min-Cost $k$-Disjoint Paths e decomposição de caminhos.    |
| **Edição de Rede (MCF)** | [CF Gym 106679E](https://codeforces.com/gym/106679/problem/E) (Maratona SBC 2026) | [`main.cpp`](./implementations/problems/min-cost-flow/network-editing/main.cpp)    | Otimização de Custos com Min Cost Flow.                    |

---

## 📋 Problemas Complementares Avançados (Concluídos Pós-IC)

Problemas selecionados para validação avançada de técnicas específicas de modelagem de fluxo:

| Problema                                                                | Plataforma / ID                                                      | Código Local                                                                    | Técnica de Fluxo Alvo                                             |    Status    |
| :---------------------------------------------------------------------- | :------------------------------------------------------------------- | :------------------------------------------------------------------------------ | :---------------------------------------------------------------- | :----------: |
| [Fast Maximum Flow](https://www.spoj.com/problems/FASTFLOW/)            | [SPOJ FASTFLOW](https://www.spoj.com/problems/FASTFLOW/)             | [`main.cpp`](./implementations/problems/max-flow/fast-maximum-flow/main.cpp)    | Benchmark extremo de vazão em digrafos densos e esparsos.         | ✅ Resolvido |
| [Petya and Graph](https://codeforces.com/problemset/problem/1082/G)     | [Codeforces 1082G](https://codeforces.com/problemset/problem/1082/G) | [`main.cpp`](./implementations/problems/max-flow/petya-and-graph/main.cpp)      | Fechamento de Peso Máximo (Redução de Picard) via Min-Cut.        | ✅ Resolvido |
| [Array and Operations](https://codeforces.com/problemset/problem/498/C) | [Codeforces 498C](https://codeforces.com/problemset/problem/498/C)   | [`main.cpp`](./implementations/problems/max-flow/array-and-operations/main.cpp) | Decomposição ortogonal por fatores primos ($b$-emparelhamento).   | ✅ Resolvido |
| [Maximum Flow](https://codeforces.com/problemset/problem/843/E)         | [Codeforces 843E](https://codeforces.com/problemset/problem/843/E)   | [`main.cpp`](./implementations/problems/max-flow/maximum-flow/main.cpp)         | Corte mínimo + circulação com cotas inferiores ($l \le f \le c$). | ✅ Resolvido |
| [Red-Blue Graph](https://codeforces.com/contest/1288/problem/f)         | [Codeforces 1288F](https://codeforces.com/contest/1288/problem/f)    | [`main.cpp`](./implementations/problems/min-cost-flow/red-blue-graph/main.cpp)  | Circulação de custo mínimo com cotas inferiores em bipartidos.    | ✅ Resolvido |

---

## 🏆 Backlog de Modelagens e Problemas (Livro Maratona)

Roteiro priorizado de modelagens, teoremas construtivos e problemas clássicos de programação competitiva para o livro monográfico ([`latex/book.tex`](./latex/book.tex)), estruturado por faixa de dificuldade competitiva e alinhado 1:1 entre teoria LaTeX e código C++.

### 🥉 Nível 1: ICPC Regional e Nacional (Base Indispensável)

| Modelagem / Técnica Alvo                                             | Motor Principal                | Problemas de Validação (Juízes Online)                                                 | LaTeX (Livro) | Código Local |        Status         |
| :------------------------------------------------------------------- | :----------------------------- | :------------------------------------------------------------------------------------- | :-----------: | :----------: | :-------------------: |
| **Capacidades em Vértices (_Vertex Splitting_ $v_{in}\to v_{out}$)** | `Dinic`                        | [CSES 1711 (_Distinct Routes_)](https://cses.fi/problemset/task/1711), SPOJ _DISJPATH_ |      ✅       |      ✅      |     ✅ Concluído      |
| **Recuperação Explícita da Partição do Corte Mínimo $(S, T)$**       | `Dinic`                        | [CSES 1695 (_Police Chase_)](https://cses.fi/problemset/task/1695)                     |      ✅       |      ✅      |     ✅ Concluído      |
| **Atribuição Bipartida e Escalonamento Ponderado**                   | `KuhnMunkres` / `SSP-Dijkstra` | [CSES 2129 (_Task Assignment_)](https://cses.fi/problemset/task/2129)                  |      ✅       |      ✅      |     ✅ Concluído      |
| **Cobertura Mínima de Caminhos em DAG (Disjuntos e Transitivos)**    | `HopcroftKarp`                 | POJ 2060 (_Taxi Cab Scheme_), UVa 1184 (_Air Raid_)                                    |      ✅       |      ⏳      | ⏳ Implementar Código |
| **Teorema de Dilworth e Anticadeia Máxima em Posets**                | `HopcroftKarp` + König         | POJ 1548 (_Robots_), SPOJ _MDOLLS_ (_Nested Dolls_)                                    |      ✅       |      ⏳      | ⏳ Implementar Código |

### 🥈 Nível 2: ICPC Nacional, Codeforces Div.1 e CSES Avançado

| Modelagem / Técnica Alvo                                           | Motor Principal                   | Problemas de Validação (Juízes Online)                                                                                                   | LaTeX (Livro) | Código Local |        Status         |
| :----------------------------------------------------------------- | :-------------------------------- | :--------------------------------------------------------------------------------------------------------------------------------------- | :-----------: | :----------: | :-------------------: |
| **Fechamento de Peso Máximo (Redução de Picard / Projetos)**       | `Dinic` / `MPM`                   | [CF 1082G (_Petya and Graph_)](https://codeforces.com/problemset/problem/1082/G), SPOJ _PROFIT_                                          |      ✅       |      ✅      |     ✅ Concluído      |
| **Circulação Viável e MCF com Cotas Inferiores ($l \le f \le c$)** | `SSP-Dijkstra` / `Dinic`          | [CF 1288F (_Red-Blue Graph_)](https://codeforces.com/contest/1288/problem/f), [CF 843E](https://codeforces.com/problemset/problem/843/E) |      ✅       |      ✅      |     ✅ Concluído      |
| **$b$-Emparelhamentos e Decomposição por Fatores Primos**          | `HopcroftKarp`                    | [CF 498C (_Array and Operations_)](https://codeforces.com/problemset/problem/498/C)                                                      |      ✅       |      ✅      |     ✅ Concluído      |
| **Fluxo Máximo e Mínimo $s$-$t$ com Cotas Inferiores**             | `Dinic`                           | LOJ 116 (_Max Flow with Lower Bounds_), LOJ 117 (_Min Flow with Lower Bounds_)                                                           |      ✅       |      ⏳      | ⏳ Implementar Código |
| **MCF com Custos Convexos por Partes (Arcos Paralelos)**           | `SSP-Dijkstra` / `NetworkSimplex` | [CF 863F (_Almost Permutation_)](https://codeforces.com/problemset/problem/863/F)                                                        |      ✅       |      ⏳      | ⏳ Implementar Código |
| **Fluxo em Redes Expandidas no Tempo (_Time-Expanded_)**           | `Dinic`                           | SPOJ _EVACUATE_, UVa 10985 (_Rings'n'Ropes_)                                                                                             |      ⏳       |      ⏳      |     ⏳ Planejado      |

### 🥇 Nível 3: ICPC World Finals e Fronteira Teórica

| Modelagem / Técnica Alvo                                        | Motor Principal            | Problemas de Validação (Juízes Online)                                                    | LaTeX (Livro) | Código Local |    Status    |
| :-------------------------------------------------------------- | :------------------------- | :---------------------------------------------------------------------------------------- | :-----------: | :----------: | :----------: |
| **Corte Mínimo Global (Stoer-Wagner) e Árvore de Gomory-Hu**    | `Dinic` ($\|V\|-1$ cortes) | [CF 343E (_Pumping Stations_)](https://codeforces.com/problemset/problem/343/E), POJ 2914 |      ⏳       |      ⏳      | ⏳ Planejado |
| **Dualidade Planar ($s$-$t$ Corte Mínimo $\iff$ Caminho Dual)** | `Dijkstra` no Grafo Dual   | BZOJ 1001 (_Wolf Catching Rabbit_), ICPC NEERC _Grid Cut_                                 |      ⏳       |      ⏳      | ⏳ Planejado |
| **Subgrafo de Densidade Máxima (Goldberg, 1984)**               | `Dinic` + Busca Binária    | POJ 3155 (_Hard Life_)                                                                    |      ⏳       |      ⏳      | ⏳ Planejado |
| **Otimização Paramétrica e Dualidade Linear de MCF**            | `CancelAndTighten` / `SSP` | [CF 1307G (_Cow and Exercise_)](https://codeforces.com/problemset/problem/1307/G)         |      ⏳       |      ⏳      | ⏳ Planejado |

---

# 📚 Bloco IV: Teoria e Rigor Matemático

Progresso dos teoremas, axiomas e provas formais documentados no livro monográfico ([`latex/book.tex`](./latex/book.tex)).

## ⚖️ Axiomas e Leis Fundamentais

| Nome                        | LaTeX | Formalização | Descrição                                                                                                 |
| :-------------------------- | :---: | :----------: | :-------------------------------------------------------------------------------------------------------- |
| Conservação de Fluxo        |  ✅   |      ✅      | Axioma de conservação estrita de fluxo líquido em nós intermediários ($\sum f_{in} = \sum f_{out}$).      |
| Restrição de Capacidade     |  ✅   |      ✅      | Condição de admissibilidade do fluxo respeitando os limites dos arcos ($0 \le f(u,v) \le c(u,v)$).        |
| Dualidade de Ford-Fulkerson |  ✅   |      ✅      | Teorema fundamental que iguala o valor do Fluxo Máximo à capacidade do Corte Mínimo ($\|f^*\| = c(S,T)$). |

## 🎓 Teoremas de Conectividade e Estrutura

| Nome                             | LaTeX | Prova Formal | Descrição                                                                                                          |
| :------------------------------- | :---: | :----------: | :----------------------------------------------------------------------------------------------------------------- |
| Teorema da Decomposição de Fluxo |  ✅   |      ✅      | Prova formal de que qualquer fluxo estático pode ser particionado em fluxos ao longo de caminhos e ciclos simples. |
| Teorema da Integralidade         |  ✅   |      ✅      | Garantia de que capacidades inteiras geram fluxo máximo puramente inteiro.                                         |
| Teorema de Menger (Arestas)      |  ✅   |      ✅      | O número máximo de caminhos disjuntos por arestas é igual à cardinalidade do corte mínimo de arestas.              |
| Teorema de Menger (Vértices)     |  ✅   |      ✅      | O número máximo de caminhos internamente disjuntos por vértices é igual ao tamanho do corte mínimo de vértices.    |

## 🧩 Teoria em Grafos Bipartidos

| Nome                        | LaTeX | Prova Formal | Descrição                                                                                                                      |
| :-------------------------- | :---: | :----------: | :----------------------------------------------------------------------------------------------------------------------------- |
| Teorema de König            |  ✅   |      ✅      | Prova da igualdade entre o tamanho do Emparelhamento Máximo e a Cobertura de Vértices Mínima ($\nu(G) = \tau(G)$).             |
| Teorema de Hall (Condition) |  ✅   |      ✅      | Critério necessário e suficiente para a existência de um emparelhamento saturante em grafos bipartidos ($\|N(S)\| \ge \|S\|$). |

## 💸 Teoremas de Fluxo de Custo Mínimo

| Nome                                                  | LaTeX | Prova Formal | Descrição                                                                                                            |
| :---------------------------------------------------- | :---: | :----------: | :------------------------------------------------------------------------------------------------------------------- |
| Condição de Otimalidade (Ciclos Negativos)            |  ✅   |      ✅      | Prova formal de que um fluxo é de custo mínimo se e somente se o grafo residual não possui ciclos de custo negativo. |
| Equivalência dos Custos Reduzidos                     |  ✅   |      ✅      | Prova de que a ausência de ciclos residuais negativos equivale à existência de um vetor de potenciais nodais $\pi$.  |
| Complementaridade de Folgas (Complementary Slackness) |  ✅   |      ✅      | Teorema de dualidade linear garantindo que o fluxo ótimo ocorre quando custos reduzidos e fluxos estão alinhados.    |
| Matriz Totalmente Unimodular (TUM)                    |  ✅   |      ✅      | Matriz de incidência do digrafo, que garante que a base do Network Simplex seja puramente inteira.                   |

## 🌲 Network Simplex: Estruturas e Mecânicas

Todos os conceitos fundamentais do Network Simplex estão completamente formalizados no LaTeX e implementados no motor [`NetworkSimplex.hpp`](./implementations/cost-network/NetworkSimplex.hpp):

| Componente Estrutural / Mecânica                 | LaTeX | Implementação | Descrição                                                                                                    |
| :----------------------------------------------- | :---: | :-----------: | :----------------------------------------------------------------------------------------------------------- |
| Árvore Geradora Básica (Spanning Tree)           |  ✅   |      ✅       | Estrutura de árvore geradora que define uma solução básica viável primal no digrafo.                         |
| Potenciais Nodais ($\pi$)                        |  ✅   |      ✅       | Vetor de variáveis duais associado aos vértices, utilizado para o cômputo dos custos reduzidos $\bar{c}$.    |
| Arcos Básicos, Não-Básicos e Limitados           |  ✅   |      ✅       | Partição dos arcos da rede nas classes $T$ (árvore), $L$ (não-básicos livres) e $U$ (não-básicos saturados). |
| Regra de Pricing (Entering Arc)                  |  ✅   |      ✅       | Critério de seleção do arco com custo reduzido violador para entrar na base viável.                          |
| Ciclo Fundamental e Arco Limitante (Leaving Arc) |  ✅   |      ✅       | Identificação do ciclo único formado pela inserção do arco e do arco gargalo que deixa a base.               |
| Pivoteamento e Atualização da Árvore             |  ✅   |      ✅       | Atualização da árvore geradora, do fluxo residual e dos potenciais nodais duais em $\mathcal{O}(\|V\|)$.     |

## 🧩 Teoremas de Modelagens Avançadas (Cap. 12)

Provas formais integradas ao [`12_advanced_modeling.tex`](./latex/book/chapters/12_advanced_modeling.tex):

| Teorema / Resultado Formal                       | LaTeX | Prova Formal | Descrição                                                                                                                               |
| :----------------------------------------------- | :---: | :----------: | :-------------------------------------------------------------------------------------------------------------------------------------- |
| Redução de Picard (Fechamento de Peso Máximo)    |  ✅   |      ✅      | Bijeção entre cortes $s$-$t$ finitos e fechamentos em digrafos com identidade exata $p(U) = P^+ - \ccap(S, T)$.                         |
| Viabilidade e Otimalidade com Cotas Inferiores   |  ✅   |      ✅      | Saturação total da superfonte compensadora $s^*$ na rede residual $c - l$ e preservação linear de custos $\sum w(a)l(a) + \cost(f'^*)$. |
| Expansão Unitária e Decomposição Ortogonal       |  ✅   |      ✅      | Equivalência de $b$-emparelhamentos por replicação nodal e aditividade $\sum_k \nu_{b_k}(G_k)$ sobre atributos disjuntos.               |
| Cobertura Mínima em DAG e Teorema de Dilworth    |  ✅   |      ✅      | Igualdade $k^* = \|V\| - \nu(B(D))$ e dedução construtiva da igualdade cadeia-anticadeia via Teorema de König no fecho transitivo.      |
| Linearização Exata de Custos Convexos por Partes |  ✅   |      ✅      | Argumento de troca garantindo o preenchimento sequencial dos arcos paralelos em ordem não decrescente de inclinação marginal.           |

---

# 📊 Bloco V: Validação Experimental e Histórico Institucional

## 🛠️ Infraestrutura e Automação de Benchmarks

Infraestrutura completa de testes empíricos implementada em C++23 e Python para execução automatizada de benchmarks e coleta de métricas:

| Ferramenta / Componente               | Código-Fonte                                                       | Status | Descrição                                                                                            |
| :------------------------------------ | :----------------------------------------------------------------- | :----: | :--------------------------------------------------------------------------------------------------- |
| Parser DIMACS (Max Flow)              | [`dimacs_max.hpp`](./experiments/parsers/dimacs_max.hpp)           |   ✅   | Leitor em C++ otimizado para o formato padronizado DIMACS (`.max`).                                  |
| Parser DIMACS (Min Cost Flow)         | [`dimacs_min.hpp`](./experiments/parsers/dimacs_min.hpp)           |   ✅   | Leitor em C++ otimizado para o formato padronizado DIMACS (`.min`).                                  |
| Driver C++ de Medição (Max Flow)      | [`max_flow_runner.cpp`](./experiments/drivers/max_flow_runner.cpp) |   ✅   | Executável para rodar motores de fluxo máximo com `std::chrono::high_resolution_clock`.              |
| Driver C++ de Medição (Min Cost Flow) | [`min_cost_runner.cpp`](./experiments/drivers/min_cost_runner.cpp) |   ✅   | Executável para rodar motores de custo mínimo com medição de tempo e validação.                      |
| Script Orquestrador de Execuções      | [`run_benchmarks.py`](./experiments/.scripts/run_benchmarks.py)    |   ✅   | Automação em Python para varrer instâncias, aplicar timeouts e coletar médias e desvio padrão.       |
| Pipeline de Tabelas LaTeX             | [`generate_tables.py`](./experiments/.scripts/generate_tables.py)  |   ✅   | Script para processar CSVs de resultados e compilar tabelas LaTeX formatadas em `booktabs`.          |
| Pipeline de Gráficos e Figuras        | [`plot_charts.py`](./experiments/.scripts/plot_charts.py)          |   ✅   | Geração de curvas de complexidade assintótica empírica em escala log-log com `matplotlib`/`seaborn`. |

## 🏋️ Instâncias e Geradores Sintéticos

| Nome                                    | Código-Fonte                                                  | LaTeX | Implementação | Descrição                                                                                               |
| :-------------------------------------- | :------------------------------------------------------------ | :---: | :-----------: | :------------------------------------------------------------------------------------------------------ |
| Coleções DIMACS (Max Flow)              | [`fetch_dimacs.py`](./experiments/.scripts/fetch_dimacs.py)   |  ✅   |      ✅       | Download e organização de instâncias clássicas da literatura (Washington, RMF, Genrmf).                 |
| Coleções DIMACS (Min Cost Flow)         | [`fetch_dimacs.py`](./experiments/.scripts/fetch_dimacs.py)   |  ✅   |      ✅       | Download e organização de instâncias de referência de custo mínimo (Netgen, Grid).                      |
| Gerador: Grafos Aleatórios Esparsos     | [`random_graph.py`](./experiments/generators/random_graph.py) |  ✅   |      ✅       | Geração controlada de grafos com $\|A\| \approx 4\|V\|$ variando $\|V\|$ em escala logarítmica.         |
| Gerador: Grafos Aleatórios Densos       | [`random_graph.py`](./experiments/generators/random_graph.py) |  ✅   |      ✅       | Geração controlada de grafos com $\|A\| \approx \|V\|^2 / 10$ para testar limites de algoritmos densos. |
| Gerador: Redes em Grade (Grid 2D/3D)    | [`grid_graph.py`](./experiments/generators/grid_graph.py)     |  ✅   |      ✅       | Estrutura em grade simulando problemas de visão computacional / segmentação.                            |
| Gerador: Casos Patológicos de Pior Caso | [`worst_case.py`](./experiments/generators/worst_case.py)     |  ✅   |      ✅       | Redes desenhadas para induzir o pior caso de caminhos aumentantes (ex: Ford-Fulkerson exponencial).     |

## ⚡ Baterias Experimentais e Análise de Desempenho

| Bateria / Análise                      | LaTeX | Execução | Descrição                                                                                                      |
| :------------------------------------- | :---: | :------: | :------------------------------------------------------------------------------------------------------------- |
| Escalabilidade por Vértices ($\|V\|$)  |  ✅   |    ✅    | Comparação de tempo (EK vs. Dinic vs. Push-Relabel FIFO vs. Push-Relabel Improved) variando $\|V\|$.           |
| Escalabilidade por Arestas ($\|A\|$)   |  ✅   |    ✅    | Teste de sensibilidade variando a densidade do grafo com número fixo de vértices.                              |
| Avaliação da Gap Heuristic             |  ✅   |    ✅    | Comparação direta de tempo de execução e número de relabels entre Push-Relabel padrão e Improved.              |
| Corretude Cruzada de Fluxo Máximo      |  ✅   |    ✅    | Validação automática garantindo que todos os algoritmos encontram exatamente o mesmo valor $f^*$.              |
| Escalabilidade Esparsa vs. Densa (MCF) |  ✅   |    ✅    | Comparação entre Cycle Canceling, SSP (SPFA), SSP (Dijkstra + $\pi$) e Network Simplex.                        |
| Sensibilidade a Custos e Capacidades   |  ✅   |    ✅    | Avaliação de desempenho variando a magnitude dos custos ($C$) e capacidades ($U$).                             |
| Eficiência Prática do Network Simplex  |  ✅   |    ✅    | Contagem empírica do número de pivoteamentos e tempo por iteração frente aos métodos de caminhos.              |
| Corretude Cruzada de Custo Mínimo      |  ✅   |    ✅    | Validação automática garantindo que todas as soluções viáveis encontram exatamente o mesmo custo ótimo $z^*$.  |
| Seção de Resultados Experimentais      |  ✅   |    ✅    | Redação formal da metodologia experimental, especificações de hardware e discussão no livro e relatório da IC. |
| Tabelas Comparativas de Desempenho     |  ✅   |    ✅    | Tabelas formatadas em `booktabs` integradas aos documentos LaTeX.                                              |
| Gráficos de Desempenho e Curvas Log    |  ✅   |    ✅    | Figuras comparativas e curvas de escalabilidade geradas pelo pipeline e incluídas no LaTeX.                    |

---

## 🏛️ Histórico Institucional: Iniciação Científica UFABC (🔒 Finalizado)

Registro consolidado das entregas concluídas no âmbito do Edital 01/2025 PIC/PIBIC/UFABC sob orientação da Profa. Dra. Cristiane Maria Sato. **Os documentos abaixo encontram-se congelados** (apenas correções eventuais de código nos 9 motores originais da IC propagam para os apêndices `01..11` via `make sync-code`):

| Entrega Institucional                                 | Escopo / Arquivo                                                                                       | Status | Síntese do Entregável                                                                                                     |
| :---------------------------------------------------- | :----------------------------------------------------------------------------------------------------- | :----: | :------------------------------------------------------------------------------------------------------------------------ |
| **Proposta Inicial do Projeto**                       | [`latex/proposal.tex`](./latex/proposal.tex)                                                           | 🔒 ✅  | Plano de trabalho e cronograma submetidos ao edital de Iniciação Científica.                                              |
| **Relatório Final, Versão Limpa e Monólito Overleaf** | [`report.tex`](./latex/report.tex), [`ic.tex`](./latex/ic.tex), [`monolith.tex`](./latex/monolith.tex) | 🔒 ✅  | Revisão integral com a orientadora, 9 motores originais (5 Max-Flow + 4 MCF) e resultados de `make bench-ic`.             |
| **Benchmarks Congelados da IC (`--suite ic`)**        | `latex/tables/`, `latex/figures/`                                                                      | 🔒 ✅  | Bateria final executada na máquina de referência com validação cruzada e curvas log-log originais da IC.                  |
| **Pôster Científico do Simpósio de IC (90×120 cm)**   | [`latex/poster.tex`](./latex/poster.tex)                                                               | 🔒 ✅  | Editoração visual completa com síntese teórica, arquitetura C++23, galeria da segmentação de imagens e resultados DIMACS. |

---

> [!TIP]
> Para detalhes sobre convenções de código, diretrizes de engenharia e regras de estilo, consulte o [AGENTS.md](AGENTS.md) e o [PRINCIPLES.md](PRINCIPLES.md).
