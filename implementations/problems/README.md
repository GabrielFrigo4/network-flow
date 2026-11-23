# 🧩 Resolução de Problemas (Competitive Programming)

Bem-vindo ao diretório de **Problemas**! Aqui encontram-se as aplicações práticas das nossas implementações de Fluxos em Redes para resolver problemas clássicos de _Competitive Programming_ (Maratonas de Programação e Juízes Online).

Este diretório serve como validação empírica da corretude e da eficiência da nossa biblioteca de grafos. A pasta está dividida em duas grandes categorias:

- 🌊 **[`max-flow/`](./max-flow/)**: Problemas modelados sobre a classe base [`FlowNetwork`](../flow-network/FlowNetwork.hpp) (motor padrão: `PushRelabelImproved` / `Dinic`).
- 🧮 **[`min-cost-flow/`](./min-cost-flow/)**: Problemas modelados sobre a classe base [`CostNetwork`](../cost-network/CostNetwork.hpp) (motor padrão: `NetworkSimplex`).

---

## 📋 Catálogo Geral e Mapeamento 1:1 com o TO-DO

| Problema                                                                 | Juiz Online                                                                                                     | Categoria                                 | Tópicos de Modelagem Aplicados (1:1 com o TO-DO)                                                                                                                                                                                |
| :----------------------------------------------------------------------- | :-------------------------------------------------------------------------------------------------------------- | :---------------------------------------- | :------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| 🌊 **[Download Speed](./max-flow/download-speed/)**                      | [CSES 1694](https://cses.fi/problemset/task/1694)                                                               | [Fluxo Máximo](./max-flow/)               | • Grafo Residual e Arestas Reversas<br>• Caminhos de Aumento (Augmenting Paths)<br>• Saturação e $st$-Fluxo Máximo Canônico                                                                                                     |
| 🤝 **[School Dance](./max-flow/school-dance/)**                          | [CSES 1696](https://cses.fi/problemset/task/1696)                                                               | [Fluxo Máximo](./max-flow/)               | • Grafo Bipartido<br>• Super-fonte ($s$) e Super-sumidouro ($t$)<br>• Múltiplas Fontes e Sumidouros<br>• Capacidades Unitárias ($c=1$)                                                                                          |
| 🛣️ **[Distinct Routes](./max-flow/distinct-routes/)**                    | [CSES 1711](https://cses.fi/problemset/task/1711)                                                               | [Fluxo Máximo](./max-flow/)               | • Caminhos Disjuntos por Arestas (Edge-Disjoint)<br>• Capacidades Unitárias ($c=1$)<br>• Decomposição de Fluxo (Path Recovery)                                                                                                  |
| ✂️ **[Police Chase](./max-flow/police-chase/)**                          | [CSES 1695](https://cses.fi/problemset/task/1695)                                                               | [Fluxo Máximo](./max-flow/)               | • Corte Mínimo (Algoritmo / Teorema Max-Flow Min-Cut)<br>• Arestas Bidirecionais vs. Direcionadas<br>• Capacidades Unitárias ($c=1$)                                                                                            |
| 🌐 **[Time Travel](./max-flow/time-travel/)**                            | [Beecrowd 2082](https://judge.beecrowd.com/en/problems/view/2082)                                               | [Fluxo Máximo](./max-flow/)               | • Corte Mínimo Global<br>• Arestas Bidirecionais vs. Direcionadas<br>• Clonagem de Rede (`clone()`)                                                                                                                             |
| 🪙 **[Coin Grid](./max-flow/coin-grid/)**                                | [CSES 1709](https://cses.fi/problemset/task/1709)                                                               | [Fluxo Máximo](./max-flow/)               | • Grafo Bipartido<br>• Super-fonte ($s$) e Super-sumidouro ($t$)<br>• Cobertura de Vértices Mínima (MVC / König)<br>• Complementaridade de Conjuntos ($\lvert V \rvert - MVC$)                                                  |
| 🔄 **[Edição de Rede (Fluxo Máximo)](./max-flow/network-editing/)**      | [CF Gym 106679E](https://codeforces.com/gym/106679/problem/E) ([Gym 106679](https://codeforces.com/gym/106679)) | [Fluxo Máximo](./max-flow/)               | • Redução para Emparelhamento Bipartido Máximo ($\mathcal{O}(M \sqrt{M})$)<br>• Remoção Gulosa de Identidades ($k \times 0$)<br>• Fórmula Fechada: $2(M - k) - F$                                                               |
| ⚡ **[Fast Maximum Flow](./max-flow/fast-maximum-flow/)**                | [SPOJ FASTFLOW](https://www.spoj.com/problems/FASTFLOW/)                                                        | [Fluxo Máximo](./max-flow/)               | • Fluxo Máximo em Grafo Não-Direcionado Ponderado<br>• Arcos Bidirecionais Simétricos com `PushRelabelImproved`                                                                                                                 |
| 🏆 **[Petya and Graph](./max-flow/petya-and-graph/)**                    | [CF 1082G](https://codeforces.com/problemset/problem/1082/G)                                                    | [Fluxo Máximo](./max-flow/)               | • Fechamento de Peso Máximo (Redução de Picard)<br>• Subgrafo Induzido de Peso Máximo via Corte Mínimo $s$-$t$                                                                                                                  |
| 🔢 **[Array and Operations](./max-flow/array-and-operations/)**          | [CF 498C](https://codeforces.com/problemset/problem/498/C)                                                      | [Fluxo Máximo](./max-flow/)               | • Decomposição Ortogonal por Fatores Primos<br>• Expansão Unitária de $b$-Emparelhamento Bipartido (`HopcroftKarp`)                                                                                                             |
| 🔁 **[Maximum Flow](./max-flow/maximum-flow/)**                          | [CF 843E](https://codeforces.com/problemset/problem/843/E)                                                      | [Fluxo Máximo](./max-flow/)               | • Corte Mínimo para Saturação Mínima de Arcos Ativos<br>• Circulação Viável com Cotas Inferiores ($l \le f \le c$)                                                                                                              |
| 📋 **[Task Assignment](./min-cost-flow/task-assignment/)**               | [CSES 2129](https://cses.fi/problemset/task/2129)                                                               | [Fluxo de Custo Mínimo](./min-cost-flow/) | • Grafo Bipartido com Custos (Assignment Problem)<br>• Super-fonte ($s$) e Super-sumidouro ($t$)<br>• Múltiplas Fontes e Sumidouros<br>• Custos Reduzidos (Reduced Costs)<br>• Transformação Min Cost Max Flow                  |
| 📦 **[Parcel Delivery](./min-cost-flow/parcel-delivery/)**               | [CSES 2121](https://cses.fi/problemset/task/2121)                                                               | [Fluxo de Custo Mínimo](./min-cost-flow/) | • Min Cost Flow com Demanda Fixa ($k$ parcelas)<br>• Super-fonte ($s$) para Limitação de Demanda<br>• Grafo Residual com Custos<br>• Custos Reduzidos (Reduced Costs)                                                           |
| 🚀 **[Distinct Routes II](./min-cost-flow/distinct-routes-ii/)**         | [CSES 2130](https://cses.fi/problemset/task/2130)                                                               | [Fluxo de Custo Mínimo](./min-cost-flow/) | • $k$ Caminhos Disjuntos de Custo Mínimo (Min-Cost $k$-Disjoint Paths)<br>• Capacidades Unitárias ($c=1$)<br>• Decomposição de Fluxo (Path Recovery)<br>• Custos Reduzidos (Reduced Costs)<br>• Transformação Min Cost Max Flow |
| 🔄 **[Edição de Rede (Custo Mínimo)](./min-cost-flow/network-editing/)** | [CF Gym 106679E](https://codeforces.com/gym/106679/problem/E) ([Gym 106679](https://codeforces.com/gym/106679)) | [Fluxo de Custo Mínimo](./min-cost-flow/) | • Emparelhamento Bipartido com Custos (Min Cost Flow)<br>• Super-fonte ($s$) e Super-sumidouro ($t$)<br>• Nó Intermediário Dummy (2-Hop Substitution)<br>• Resolução com `NetworkSimplex`                                       |
| 🎨 **[Red-Blue Graph](./min-cost-flow/red-blue-graph/)**                 | [CF 1288F](https://codeforces.com/problemset/problem/1288/F)                                                    | [Fluxo de Custo Mínimo](./min-cost-flow/) | • Circulação de Custo Mínimo com Cotas Inferiores ($l \le f \le c$)<br>• Balanço de Grau em Bipartido via `super_source` / `super_sink` (`SuccessiveShortestDijkstra`)                                                          |

---

## ⚡ Detalhamento das Modelagens: Fluxo Máximo (`FlowNetwork`)

### 1. 🌊 Download Speed (CSES 1694)

- **Pasta:** [`max-flow/download-speed/`](./max-flow/download-speed/)
- **Problema:** Encontrar a taxa máxima de transmissão de dados entre o servidor $1$ e o servidor $n$.
- **Modelagem:** Aplicação direta do modelo canônico de $st$-fluxo máximo em digrafos direcionados com capacidades arbitrárias.
- **Extração de Resultado:** O valor retornado por `compute_max_flow(0, n - 1)` corresponde exatamente ao fluxo máximo saturado na rede.

### 2. 🤝 School Dance (CSES 1696)

- **Pasta:** [`max-flow/school-dance/`](./max-flow/school-dance/)
- **Problema:** Formar o maior número de pares de dança entre meninos e meninas a partir de pares potenciais.
- **Modelagem:** Grafo Bipartido $G = (L \cup R, E)$ com Super-Fonte $s$ conectada a todos os meninos ($s \to u$, cap $1$) e Super-Sumidouro $t$ conectado a todas as meninas ($v \to t$, cap $1$). Pares potenciais recebem arestas direcionadas $u \to v$ com capacidade $1$.
- **Extração de Resultado:** Pares combinados são identificados iterando sobre as arestas $(u, v)$ que possuem $f(u, v) = 1$.

### 3. 🛣️ Distinct Routes (CSES 1711)

- **Pasta:** [`max-flow/distinct-routes/`](./max-flow/distinct-routes/)
- **Problema:** Encontrar o número máximo de rotas disjuntas em arestas entre a sala $1$ e a sala $n$, listando cada caminho.
- **Modelagem:** Todas as conexões recebem capacidade $c(u, v) = 1$. O valor do fluxo máximo indica o número de caminhos aresta-disjuntos.
- **Extração de Resultado (Path Recovery):** A partir do nó fonte, realiza-se uma travessia seguindo arcos com $f > 0$ e marcando as arestas utilizadas (`used_edge`) até atingir o sumidouro, decompondo o fluxo total em caminhos simples.

### 4. ✂️ Police Chase (CSES 1695)

- **Pasta:** [`max-flow/police-chase/`](./max-flow/police-chase/)
- **Problema:** Encontrar o número mínimo de ruas a serem bloqueadas para impedir a fuga entre a cidade $1$ e a cidade $n$, identificando quais ruas bloquear.
- **Modelagem:** Grafo não-direcionado com capacidades unitárias, modelado adicionando arcos bidirecionais simétricos `add_edge(u, v, 1, 1)`.
- **Extração de Resultado (Min Cut):** Realiza-se uma BFS/DFS a partir da fonte no grafo residual para encontrar o conjunto $S$ de vértices alcançáveis ($c_f(u, v) > 0$). As arestas do corte mínimo são os arcos originais que saem de $S$ e chegam em $T = V \setminus S$.

### 5. 🌐 Time Travel (Beecrowd 2082)

- **Pasta:** [`max-flow/time-travel/`](./max-flow/time-travel/)
- **Problema:** Determinar o custo do corte mínimo global em uma rede não-direcionada ponderada.
- **Modelagem:** Matriz de capacidades simétricas. Para encontrar o corte global sem fixar o sumidouro, fixa-se $s = 0$ e itera-se o sumidouro $t$ por todos os outros vértices $1 \dots n-1$, utilizando o método `clone()` para isolar cada execução de fluxo.
- **Extração de Resultado:** O corte global é $\min_{t \in \{1 \dots n-1\}} \text{max\_flow}(0, t)$.

### 6. 🪙 Coin Grid (CSES 1709)

- **Pasta:** [`max-flow/coin-grid/`](./max-flow/coin-grid/)
- **Problema:** Esvaziar um grid $n \times n$ com o menor número de operações, onde cada operação remove todas as moedas de uma linha ou de uma coluna.
- **Modelagem:** Redução para Cobertura de Vértices Mínima (MVC) em Grafo Bipartido (Linhas $\leftrightarrow$ Colunas). Pelo **Teorema de König**, $\lvert MVC \rvert = \lvert \text{Matching Máximo} \rvert = \text{Max Flow}$.
- **Extração de Resultado:** No grafo residual após o fluxo máximo, seja $Z$ o conjunto de vértices alcançáveis pela fonte. Pelo Teorema de König:
    - A linha $i$ pertence ao MVC se **não** for alcançável pela fonte ($i \notin Z$).
    - A coluna $j$ pertence ao MVC se **for** alcançável pela fonte ($j \in Z$).

### 7. 🔄 Edição de Rede via Matching Bipartido (CF Gym 106679E / Maratona SBC 2026)

- **Pasta:** [`max-flow/network-editing/`](./max-flow/network-editing/)
- **Link do Problema:** [Codeforces Gym 106679 - Problema E (Edição de Rede)](https://codeforces.com/gym/106679/problem/E) ([Contest Gym 106679](https://codeforces.com/gym/106679))
- **Problema:** Determinar o número mínimo de intervenções para transformar $M_1$ arestas na topologia desejada de $M_2$ arestas.
- **Redução para Fluxo Máximo:**
    - Remove as $k$ arestas idênticas (custo $0$).
    - Modela um emparelhamento bipartido máximo entre as arestas restantes que compartilham um vértice (custo $1$).
    - As arestas que sobrarem sem emparelhamento custarão $2$ cada.
    - **Fórmula Fechada:** $\text{Custo} = 2 \times (M - k) - F$, onde $F$ é o fluxo máximo de emparelhamento computed por `PushRelabelImproved` ou `Dinic`.
    - Complexidade: $\mathcal{O}(M \sqrt{M})$.

### 8. ⚡ Fast Maximum Flow (SPOJ FASTFLOW)

- **Pasta:** [`max-flow/fast-maximum-flow/`](./max-flow/fast-maximum-flow/)
- **Link do Problema:** [SPOJ FASTFLOW](https://www.spoj.com/problems/FASTFLOW/)
- **Problema:** Calcular o fluxo máximo entre o vértice $1$ e o vértice $N$ em um grafo não-direcionado com até $5.000$ vértices, $30.000$ arestas e capacidades elevadas.
- **Modelagem:** Descartam-se auto-laços (`u == v`) e cada aresta não-direcionada é convertida em um par de arcos direcionados simétricos `add_edge(u - 1, v - 1, cap)` e `add_edge(v - 1, u - 1, cap)` sob o motor [`PushRelabelImproved`](../flow-network/PushRelabelImproved.hpp).
- **Extração de Resultado:** O valor retornado diretamente por `compute_max_flow(0, num_nodes - 1)` fornece o fluxo máximo da rede.

### 9. 🏆 Petya and Graph (Codeforces 1082G)

- **Pasta:** [`max-flow/petya-and-graph/`](./max-flow/petya-and-graph/)
- **Link do Problema:** [Codeforces 1082G - Petya and Graph](https://codeforces.com/problemset/problem/1082/G)
- **Problema:** Dado um grafo com custos $a_i$ nos vértices e pesos $w_j$ nas arestas, escolher um subconjunto de vértices que maximize a soma dos pesos das arestas induzidas menos a soma dos custos dos vértices selecionados.
- **Modelagem (Fechamento de Peso Máximo / Redução de Picard):** Cada vértice $i$ conecta-se ao sumidouro (`add_edge(i, sink, vertex_cost)`) e cada aresta $j = (u, v, w)$ origina um nó auxiliar ligado da fonte (`add_edge(source, edge_node, weight)`) com dependências infinitas para ambas as extremidades (`add_edge(edge_node, u, INF)` e `add_edge(edge_node, v, INF)`), resolvido com [`MPM`](../flow-network/MPM.hpp).
- **Extração de Resultado:** Subtraindo o corte mínimo da soma total dos pesos das arestas, obtém-se `total_edge_weight - fn->compute_max_flow(source, sink)`.

### 10. 🔢 Array and Operations (Codeforces 498C)

- **Pasta:** [`max-flow/array-and-operations/`](./max-flow/array-and-operations/)
- **Link do Problema:** [Codeforces 498C - Array and Operations](https://codeforces.com/problemset/problem/498/C)
- **Problema:** Dado um vetor de inteiros $(a_1, \dots, a_n)$ e $m$ pares bons $(i_k, j_k)$ de paridades opostas, maximizar o número de divisões simultâneas de um par bom por algum divisor comum $d > 1$.
- **Modelagem (Decomposição Ortogonal por Fatores Primos e Expansão Unitária):** Fatora-se cada $a_i$ em primos, criando um vértice unitário para cada ocorrência de primo $p$ em $a_i$; posições ímpares recebem arco da fonte e pares ligam-se ao sumidouro com capacidade $1$, adicionando arcos unitários entre cópias de mesmo primo $p$ pertencentes aos pares bons $(u, v)$, resolvido com [`HopcroftKarp`](../flow-network/HopcroftKarp.hpp).
- **Extração de Resultado:** `fn->compute_max_flow(source, sink)` retorna o número máximo de operações divisórias por fatores primos.

### 11. 🔁 Maximum Flow (Codeforces 843E)

- **Pasta:** [`max-flow/maximum-flow/`](./max-flow/maximum-flow/)
- **Link do Problema:** [Codeforces 843E - Maximum Flow](https://codeforces.com/problemset/problem/843/E)
- **Problema:** Dado um grafo direcionado com arcos marcados como ativos (`flag = 1`) ou inativos (`flag = 0`), atribuir fluxos e capacidades compatíveis minimizando o número de arcos saturados em um corte mínimo $s$-$t$.
- **Modelagem em Duas Etapas (Corte Mínimo + Circulação com Cotas Inferiores):**
    - Em `cut_net`, atribui-se capacidade $\infty$ a `flag == 0` e capacidade $1$ direta mais $\infty$ reversa a `flag == 1`, recuperando a partição alcançável `in_s` de `source` após [`Dinic`](../flow-network/Dinic.hpp).
    - Em `circ_net`, impõe-se cota inferior $l = 1$ a cada arco com `flag == 1` via nós `super_source` / `super_sink` e arco de retorno `(sink, source)` de capacidade $\infty$.
- **Extração de Resultado:** Arcos com `flag == 0` recebem `0 1`; arcos com `flag == 1` recebem `flow = 1 + circ_edges[circ_edge_id[i]].flow`, com `cap = flow` se cruzam o corte mínimo (`in_s[u] && !in_s[v]`) ou `flow + 1` caso contrário.

---

## 🧮 Detalhamento das Modelagens: Fluxo de Custo Mínimo (`CostNetwork`)

### 12. 📋 Task Assignment (CSES 2129)

- **Pasta:** [`min-cost-flow/task-assignment/`](./min-cost-flow/task-assignment/)
- **Problema:** Atribuir $n$ tarefas a $n$ funcionários de forma bijetiva minimizando o custo total da matriz $C_{n \times n}$.
- **Modelagem:** Grafo Bipartido com Super-Fonte $s \to i$ (cap $1$, custo $0$), tarefas $n+j \to t$ (cap $1$, custo $0$), e arestas funcionário-tarefa $i \to n+j$ (cap $1$, custo $C_{ij}$).
- **Extração de Resultado:** `compute_min_cost_max_flow(source, sink)` encontra a atribuição ótima. As tarefas associadas a cada funcionário são recuperadas pelas arestas $i \to n+j$ com $f = 1$.

### 13. 📦 Parcel Delivery (CSES 2121)

- **Pasta:** [`min-cost-flow/parcel-delivery/`](./min-cost-flow/parcel-delivery/)
- **Problema:** Transportar exatamente $k$ encomendas da cidade $1$ para a cidade $n$ com capacidade e custo por rota, minimizando o custo total.
- **Modelagem:** Cria-se uma Super-Fonte $0$ conectada à cidade real $1$ com capacidade restrita a $k$ e custo $0$ (`add_edge(0, 1, k, 0)`). As rotas entre cidades recebem suas capacidades e custos unitários originais.
- **Extração de Resultado:** Se `get_total_flow(0) < k`, a rede não suporta o volume exigido (imprime `-1`). Caso contrário, o custo mínimo ótimo é o valor retornado.

### 14. 🚀 Distinct Routes II (CSES 2130)

- **Pasta:** [`min-cost-flow/distinct-routes-ii/`](./min-cost-flow/distinct-routes-ii/)
- **Problema:** Encontrar $k$ caminhos disjuntos por arcos entre a sala $1$ e a sala $n$ de forma que a soma total dos comprimentos dos caminhos seja mínima.
- **Modelagem:** Super-fonte conectada à sala $1$ com capacidade $k$ e custo $0$. Cada conexão original entre salas recebe capacidade $1$ e custo $1$.
- **Extração de Resultado:** `compute_min_cost_max_flow` empurra $k$ unidades de fluxo pelo caminho mais barato. A reconstrução dos $k$ caminhos é realizada via decomposição de fluxo no residual com rastreamento de arestas visitadas.

### 15. 🔄 Edição de Rede via Custo Mínimo (CF Gym 106679E / Maratona SBC 2026)

- **Pasta:** [`min-cost-flow/network-editing/`](./min-cost-flow/network-editing/)
- **Link do Problema:** [Codeforces Gym 106679 - Problema E (Edição de Rede)](https://codeforces.com/gym/106679/problem/E) ([Contest Gym 106679](https://codeforces.com/gym/106679))
- **Problema:** Determinar o número mínimo de intervenções para transformar a topologia de conexões.
- **Modelagem com Min Cost Flow:**
    - Se $M_1 \neq M_2$, retorna `-1`.
    - Constrói rede bipartida com super-fonte e super-sumidouro.
    - Arestas idênticas têm custo 0, arestas com 1 ponta comum têm custo 1, e um nó `Dummy` intermediário conecta todas as conexões iniciais e finais com custo $1 + 1 = 2$.
    - Resolução direta com o algoritmo [`NetworkSimplex`](../cost-network/NetworkSimplex.hpp).

### 16. 🎨 Red-Blue Graph (Codeforces 1288F)

- **Pasta:** [`min-cost-flow/red-blue-graph/`](./min-cost-flow/red-blue-graph/)
- **Link do Problema:** [Codeforces 1288F - Red-Blue Graph](https://codeforces.com/problemset/problem/1288/F)
- **Problema:** Colorir arestas de um grafo bipartido com vermelho (`R`, custo $r$), azul (`B`, custo $b$) ou incolor (`U`, custo $0$) respeitando restrições de predominância de cor por vértice e minimizando o custo total.
- **Modelagem (Circulação de Custo Mínimo com Cotas Inferiores):** Cada aresta $(u, v)$ cria um arco $u \to n_1 + v$ (cap. $1$, custo `r_cost`) e um arco oposto $n_1 + v \to u$ (cap. $1$, custo `b_cost`). Vértices `R` e `B` recebem arcos incidentes a `source`/`sink` com cota inferior $l = 1$ via `add_bounded_edge` (acumulando balanços em `balance`), vértices `U` recebem $l = 0$, insere-se arco de retorno `(sink, source)` com cap. `INF` e custo `0`, e compensa-se `balance` via `super_source` e `super_sink` com [`SuccessiveShortestDijkstra`](../cost-network/SuccessiveShortestDijkstra.hpp).
- **Extração de Resultado:** Confere-se viabilidade verificando se o fluxo nos arcos de demanda iguala `required_flow` (caso contrário imprime `-1`). Quando viável, imprime `total_cost` e a coloração `'R'`, `'B'` ou `'U'` conforme `edges[red_edge_id[i]].flow > 0` ou `edges[blue_edge_id[i]].flow > 0`.

---

## 🚀 Templates de Início Rápido

- 🌊 **Template de Fluxo Máximo:** [`max-flow/template/main.cpp`](./max-flow/template/main.cpp)
- 🧮 **Template de Fluxo de Custo Mínimo:** [`min-cost-flow/template/main.cpp`](./min-cost-flow/template/main.cpp)

---

## 🛠️ Workflow de Desenvolvimento e Submissão (`make clip`)

Cada pasta de problema possui um arquivo `Makefile` com suporte a execução local e empacotamento automático para juízes online através do [`bundle.py`](../bundle.py):

| Comando                      | Descrição                                                                                                                                                                 |
| :--------------------------- | :------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| **`make`** ou **`make run`** | Compila a solução local em C++23 com otimização `-O2` e executa usando o arquivo `input.txt`.                                                                             |
| **`make clip`**              | Executa o bundler automático embutindo todos os headers locais da biblioteca e copia o código unificado final para o **Clipboard** (`wl-copy`) pronto para colar no juiz. |
| **`make bundle`**            | Gera o código C++ unificado e autocontido exibindo-o na saída padrão (terminal).                                                                                          |
| **`make clean`**             | Remove os arquivos binários locais compilados.                                                                                                                            |
