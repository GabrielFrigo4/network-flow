# 🃏 Cards de Referência Rápida (`cards/`)

> **Status:** 🟢 Estrutura Pronta / ⏳ Aguardando Autoria _(Pós-IC — Evolução Ativa)_

Este diretório concentra **cards de referência rápida** (_cheat sheets_ visuais de 1 página em formato paisagem/A4 ou A5) para consulta imediata de teoremas, invariantes, complexidades e receitas de redução em Fluxos em Redes.

---

## 🎨 Padrão Editorial & Reuso

- **Design System Compartilhado:** Todos os cards reutilizam a paleta semântica, macros matemáticas e biblioteca TikZ de [`../common/header.tex`](../common/header.tex) e os diagramas vetoriais de [`../diagrams/`](../diagrams/) via `TEXINPUTS="..:"`.
- **Formato:** 1 página densa por tópico, zero floreios textuais, prioridade total para fórmulas-chave, invariantes de algoritmo e diagramas esquemáticos.

---

## 📋 Catálogo Planejado (9 Cards)

| Arquivo Alvo                    | Escopo e Conteúdo                                                                                           |    Status    |
| :------------------------------ | :---------------------------------------------------------------------------------------------------------- | :----------: |
| `max-flow-cheatsheet.tex`       | Quadro comparativo dos 8 motores `FlowNetwork` (complexidades, invariantes e critérios de escolha prática). | ⏳ Planejado |
| `min-cost-cheatsheet.tex`       | Quadro comparativo dos 7 motores `CostNetwork` (ciclos negativos, $\varepsilon$-otimalidade, SSP, Simplex). | ⏳ Planejado |
| `bipartite-dualities.tex`       | As Quatro Dualidades (König, Gallai, Hall) e reconstrução de conjuntos a partir do grafo residual.          | ⏳ Planejado |
| `modeling-patterns-maxflow.tex` | Receituário visual de modelagem em Fluxo Máximo (Vertex Splitting, Corte Mínimo, Redução de Picard).        | ⏳ Planejado |
| `modeling-patterns-mcf.tex`     | Receituário visual de modelagem em Custo Mínimo (Cotas Inferiores $l \le f \le c$, Custos Convexos, MCMF).  | ⏳ Planejado |
| `dag-dilworth-card.tex`         | Cobertura Mínima de Caminhos em DAGs, grafo bipartido dividido $B(D)$ e Teorema de Dilworth.                | ⏳ Planejado |
| `network-simplex-pivoting.tex`  | Mecânica visual do Network Simplex (`T/L/U`, `parent`/`depth`/`thread`, ciclo fundamental e pricing).       | ⏳ Planejado |
| `strongly-polynomial-mcf.tex`   | Síntese visual de Karp, dualidade $\varepsilon$-ótima, MMCC e Cancel-and-Tighten.                           | ⏳ Planejado |
| `graph-cuts-vision.tex`         | Card visual de Segmentação Interativa de Imagens via Corte Mínimo (N-links, T-links e função de energia).   | ⏳ Planejado |

---

## 🛠️ Como Compilar

```sh
make all
make clean
make distclean
```

Ou a partir da raiz do repositório / pasta [`latex/`](../README.md):

```sh
make cards
```
