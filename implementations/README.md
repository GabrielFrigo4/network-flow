# 💻 Implementações e Códigos

Biblioteca de algoritmos de fluxo em redes implementados em C++. O projeto está organizado em duas famílias distintas de algoritmos, cada uma com sua interface base polimórfica:

- **[`flow-network/`](./flow-network/)** — Algoritmos de **Fluxo Máximo** (interface [`FlowNetwork`](./flow-network/FlowNetwork.hpp))
- **[`cost-network/`](./cost-network/)** — Algoritmos de **Fluxo de Custo Mínimo** (interface [`CostNetwork`](./cost-network/CostNetwork.hpp))

## ⚡ Algoritmos de Fluxo Máximo e Emparelhamento Bipartido (`FlowNetwork`)

| Algoritmo             | Header                                                              | Complexidade                       | Descrição                                                      |
| :-------------------- | :------------------------------------------------------------------ | :--------------------------------- | :------------------------------------------------------------- |
| Ford-Fulkerson        | [`FordFulkerson.hpp`](./flow-network/FordFulkerson.hpp)             | $\mathcal{O}(\|A\| \cdot \|f^*\|)$ | Método genérico com DFS (pseudopolinomial).                    |
| Edmonds-Karp          | [`EdmondsKarp.hpp`](./flow-network/EdmondsKarp.hpp)                 | $\mathcal{O}(V \cdot E^2)$         | Caminhos mais curtos via BFS.                                  |
| Dinic                 | [`Dinic.hpp`](./flow-network/Dinic.hpp)                             | $\mathcal{O}(V^2 \cdot E)$         | Digrafo de níveis + fluxo bloqueador via DFS.                  |
| MPM                   | [`MPM.hpp`](./flow-network/MPM.hpp)                                 | $\mathcal{O}(V^3)$                 | Fluxo bloqueador por potenciais de vazão em vértices.          |
| Push-Relabel FIFO     | [`PushRelabel.hpp`](./flow-network/PushRelabel.hpp)                 | $\mathcal{O}(V^3)$                 | Pré-fluxo com fila FIFO.                                       |
| Push-Relabel Improved | [`PushRelabelImproved.hpp`](./flow-network/PushRelabelImproved.hpp) | $\mathcal{O}(V^2 \sqrt{E})$        | Push-Relabel com seleção por maior altura e Gap Heuristic.     |
| Kuhn                  | [`Kuhn.hpp`](./flow-network/Kuhn.hpp)                               | $\mathcal{O}(V \cdot E)$           | Emparelhamento bipartido máximo dedicado via caminhos DFS.     |
| Hopcroft-Karp         | [`HopcroftKarp.hpp`](./flow-network/HopcroftKarp.hpp)               | $\mathcal{O}(E \sqrt{V})$          | Emparelhamento bipartido máximo em fases multi-origem BFS+DFS. |

## 🧮 Algoritmos de Custo Mínimo e Atribuição (`CostNetwork`)

| Algoritmo                      | Header                                                                            | Complexidade                                       | Descrição                                                                |
| :----------------------------- | :-------------------------------------------------------------------------------- | :------------------------------------------------- | :----------------------------------------------------------------------- |
| Cycle Canceling                | [`CycleCanceling.hpp`](./cost-network/CycleCanceling.hpp)                         | $\mathcal{O}(\|V\| \cdot \|A\|^2 \cdot C \cdot W)$ | Cancelamento iterativo de ciclos de custo negativo.                      |
| Successive Shortest (SPFA)     | [`SuccessiveShortest.hpp`](./cost-network/SuccessiveShortest.hpp)                 | $\mathcal{O}(\|V\| \cdot \|A\| \cdot F)$           | Caminhos mais curtos via SPFA com aumentações sucessivas.                |
| Successive Shortest (Dijkstra) | [`SuccessiveShortestDijkstra.hpp`](./cost-network/SuccessiveShortestDijkstra.hpp) | $\mathcal{O}(F \cdot \|A\| \log \|V\|)$            | Caminhos mais curtos via Dijkstra com Potenciais Nodais ($\pi$).         |
| Network Simplex                | [`NetworkSimplex.hpp`](./cost-network/NetworkSimplex.hpp)                         | Polinomial amortizado                              | Árvore geradora enraizada com pivoteamento por blocos.                   |
| Kuhn-Munkres (Húngaro)         | [`KuhnMunkres.hpp`](./cost-network/KuhnMunkres.hpp)                               | $\mathcal{O}(V^3)$                                 | Algoritmo Húngaro primal-dual dedicado para atribuição bipartida mínima. |

## 📐 Arquitetura

### FlowNetwork

Todos os algoritmos de fluxo máximo herdam da classe base abstrata [`FlowNetwork`](./flow-network/FlowNetwork.hpp), que provê:

- Representação topológica via lista de adjacências com arcos em pares (direto + reverso)
- Métodos `get_residual_capacity()` e `push_flow()` com truque XOR (`id ^ 1`) para acessar arcos reversos em $\mathcal{O}(1)$
- Padrões Factory Method (`make`) e Prototype (`clone`)
- Interface pública `compute_max_flow(source, sink)`, `get_edges()`, `get_adjacency()`

### CostNetwork

Todos os algoritmos de custo mínimo herdam da classe base abstrata [`CostNetwork`](./cost-network/CostNetwork.hpp), que estende o modelo de `FlowNetwork` com:

- `Edge` ampliado com campo `cost` (custo unitário por unidade de fluxo)
- Método `add_edge(from, to, capacity, cost)` que cria automaticamente o arco reverso com custo negativo
- Interface pública `compute_min_cost_max_flow(source, sink)` que retorna o custo total mínimo
- Mesmos padrões Factory Method (`make`) e Prototype (`clone`)

## 🎯 Como Usar

### Fluxo Máximo

```cpp
#include "flow-network/Dinic.hpp"

using FlowSolver = Dinic;

int main() {
    auto fn = FlowSolver::create(num_nodes);
    fn->add_edge(from, to, capacity);
    Long max_flow = fn->compute_max_flow(source, sink);
}
```

### Fluxo de Custo Mínimo

```cpp
#include "cost-network/NetworkSimplex.hpp"

using CostSolver = NetworkSimplex;

int main() {
    auto cn = CostSolver::create(num_nodes);
    cn->add_edge(from, to, capacity, cost);
    Long min_cost = cn->compute_min_cost_max_flow(source, sink);
}
```

> [!TIP]
> Confira os códigos completos e estruturados nos nossos templates ([Fluxo Máximo](./problems/max-flow/template/main.cpp) e [Fluxo de Custo Mínimo](./problems/min-cost-flow/template/main.cpp)) para iniciar rapidamente a resolução de novos problemas.

## 🔗 Problemas Resolvidos

Todos os problemas estão na pasta [`problems/`](./problems/) e utilizam a arquitetura unificada com todos os algoritmos disponíveis:

### ⚡ Problemas de Fluxo Máximo

| Problema                                                          | Juiz                                                                              | Técnica / Redução de Modelagem                                |
| :---------------------------------------------------------------- | :-------------------------------------------------------------------------------- | :------------------------------------------------------------ |
| [Download Speed](./problems/max-flow/download-speed/)             | [CSES 1694](https://cses.fi/problemset/task/1694)                                 | $st$-Fluxo Máximo Canônico, Grafo Residual                    |
| [School Dance](./problems/max-flow/school-dance/)                 | [CSES 1696](https://cses.fi/problemset/task/1696)                                 | Grafo Bipartido, Super-fonte/Sumidouro, Capacidades Unitárias |
| [Distinct Routes](./problems/max-flow/distinct-routes/)           | [CSES 1711](https://cses.fi/problemset/task/1711)                                 | Caminhos Disjuntos por Arcos, Decomposição de Fluxo           |
| [Police Chase](./problems/max-flow/police-chase/)                 | [CSES 1695](https://cses.fi/problemset/task/1695)                                 | Corte Mínimo (Max-Flow Min-Cut), Arestas Bidirecionais        |
| [Time Travel](./problems/max-flow/time-travel/)                   | [Beecrowd 2082](https://judge.beecrowd.com/en/problems/view/2082)                 | Corte Mínimo Global, Arestas Bidirecionais                    |
| [Coin Grid](./problems/max-flow/coin-grid/)                       | [CSES 1709](https://cses.fi/problemset/task/1709)                                 | Grafo Bipartido, Cobertura Mínima (König), Complementaridade  |
| [Edição de Rede](./problems/max-flow/network-editing/)            | [CF Gym 106679E](https://codeforces.com/gym/106679/problem/E) (Maratona SBC 2026) | Redução para Emparelhamento Bipartido Máximo, Fórmula Fechada |
| [Fast Maximum Flow](./problems/max-flow/fast-maximum-flow/)       | [SPOJ FASTFLOW](https://www.spoj.com/problems/FASTFLOW/)                          | Fluxo Máximo em Grafo Não-Direcionado de Alta Capacidade      |
| [Petya and Graph](./problems/max-flow/petya-and-graph/)           | [CF 1082G](https://codeforces.com/problemset/problem/1082/G)                      | Fecho de Peso Máximo (Seleção de Projetos via Corte Mínimo)   |
| [Array and Operations](./problems/max-flow/array-and-operations/) | [CF 498C](https://codeforces.com/problemset/problem/498/C)                        | Emparelhamento Bipartido sobre Fatores Primos                 |
| [Maximum Flow](./problems/max-flow/maximum-flow/)                 | [CF 843E](https://codeforces.com/problemset/problem/843/E)                        | Corte Mínimo com Arestas Saturadas e Circulação com Limites   |

### 🧮 Problemas de Fluxo de Custo Mínimo

| Problema                                                           | Juiz                                                                              | Técnica / Redução de Modelagem                                       |
| :----------------------------------------------------------------- | :-------------------------------------------------------------------------------- | :------------------------------------------------------------------- |
| [Task Assignment](./problems/min-cost-flow/task-assignment/)       | [CSES 2129](https://cses.fi/problemset/task/2129)                                 | Grafo Bipartido com Custos (Assignment), Algoritmo Húngaro           |
| [Parcel Delivery](./problems/min-cost-flow/parcel-delivery/)       | [CSES 2121](https://cses.fi/problemset/task/2121)                                 | Min Cost Flow com Demanda $k$, Limitação via Super-fonte             |
| [Distinct Routes II](./problems/min-cost-flow/distinct-routes-ii/) | [CSES 2130](https://cses.fi/problemset/task/2130)                                 | Min Cost $k$-Disjoint Paths, Decomposição de Fluxo                   |
| [Edição de Rede](./problems/min-cost-flow/network-editing/)        | [CF Gym 106679E](https://codeforces.com/gym/106679/problem/E) (Maratona SBC 2026) | Transformação de Rede (Min Cost Flow & Matching de Fluxo Máximo)     |
| [Red-Blue Graph](./problems/min-cost-flow/red-blue-graph/)         | [CF 1288F](https://codeforces.com/problemset/problem/1288/F)                      | Circulação de Custo Mínimo com Limites Inferiores em Grafo Bipartido |

---

## 📦 Bundler para Submissões em Juízes Online (`bundle.py`)

Em plataformas de programação competitiva (_Codeforces_, _CSES_, _Beecrowd_, etc.), submissões multi-arquivo não são suportadas. Para manter a biblioteca 100% modular sem duplicação de código, o projeto inclui o script utilitário [`bundle.py`](./bundle.py).

### O que o `bundle.py` faz:

- **Resolução Recursiva:** Lê o arquivo `main.cpp` e embute recursivamente todas as classes e headers locais (`#include "..."`).
- **Limpeza de Guards:** Remove `#pragma once` e include guards (`#ifndef` / `#define` / `#endif`) redundantes dos headers inlined.
- **Deduplicação de Includes da STL:** Coleta todos os `#include <...>` da biblioteca padrão, remove duplicatas e os posiciona ordenados no topo do arquivo.
- **Normalização de Espaçamento:** Garante formatação limpa e sem acúmulo de linhas em branco residuais.

### Comandos nos Makefiles de Problemas:

Cada diretório de problema em [`problems/`](./problems/) possui um `Makefile` padronizado compatível com POSIX (`.POSIX:`):

| Comando             | Ação                                                                                                                        |
| :------------------ | :-------------------------------------------------------------------------------------------------------------------------- |
| `make` / `make all` | Compila a solução C++ e executa automaticamente com os dados de `input.txt`.                                                |
| `make run`          | Executa o binário compilado redirecionando `input.txt` para a entrada padrão (`stdin`).                                     |
| `make clip`         | Executa o `bundle.py` e copia o código autocontido diretamente para o **Clipboard** (`wl-copy`) pronto para Ctrl+V no juiz. |
| `make bundle`       | Imprime o código unificado completo na saída padrão (terminal).                                                             |
| `make clean`        | Remove os executáveis compilados.                                                                                           |

### 📋 Template Canônico de Makefile para Problemas:

```makefile
.POSIX:

CXX      = c++
EXT      = cpp
TARGET   = main
INPUT    = input.txt
SRC      = $(TARGET).$(EXT)
CXXFLAGS = -Wl,-z,stack-size=268435456 -std=c++23 -O2
EXE      = ./$(TARGET)
CLIP     = wl-copy
BUNDLE   = python3 ../../../bundle.py

.PHONY: all run clean clip bundle

all: $(EXE) run

$(EXE): $(SRC)
	$(CXX) $(CXXFLAGS) "$(SRC)" -o "$(EXE)"

run:
	"$(EXE)" < "$(INPUT)"

clean:
	rm -f "$(EXE)"

bundle:
	$(BUNDLE) "$(SRC)"

clip:
	$(BUNDLE) "$(SRC)" | $(CLIP)
```
