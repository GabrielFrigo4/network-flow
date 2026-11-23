# 📘 Mini-Books Monotemáticos (`minibooks/`)

> **Status:** 🟢 Estrutura Pronta / ⏳ Aguardando Autoria _(Pós-IC — Evolução Ativa)_

Este diretório abriga **mini-books monotemáticos** (volumes curtos e autocontidos de 15 a 30 páginas), extraídos e aprofundados por tema específico para leitura rápida e distribuição independente do livro completo ([`../book.tex`](../book.tex)).

---

## 🎨 Padrão Editorial & Reuso

- **Design System Compartilhado:** Todos os mini-books importam estilos, ambientes (`definicao`, `teorema`, `demonstracao`) e TikZ de [`../common/header.tex`](../common/header.tex), citações de [`../common/references.bib`](../common/references.bib) e figuras de [`../diagrams/`](../diagrams/) via `TEXINPUTS="..:" BIBINPUTS="..:"`.
- **Autossuficiência:** Cada volume contém capa limpa, prefácio focado no tema, demonstrações completas e exemplos trabalhados passo a passo.

---

## 📋 Catálogo Planejado (6 Mini-Books)

| Arquivo Alvo                    | Título Provisório e Conteúdo                                                                                |    Status    |
| :------------------------------ | :---------------------------------------------------------------------------------------------------------- | :----------: |
| `max-flow-essentials.tex`       | **Guia Essencial de Fluxo Máximo:** Dualidade MFMC, Edmonds-Karp, Dinic, MPM e Push-Relabel com Gap.        | ⏳ Planejado |
| `bipartite-optimization.tex`    | **Otimização em Grafos Bipartidos:** Teoremas de König, Gallai e Hall, Kuhn, Hopcroft-Karp e Kuhn-Munkres.  | ⏳ Planejado |
| `modeling-handbook.tex`         | **Manual da Arte da Modelagem em Fluxos:** Vertex Splitting, Menger, Picard, Cotas Inferiores e Dilworth.   | ⏳ Planejado |
| `min-cost-and-simplex.tex`      | **Fluxo de Custo Mínimo e Network Simplex:** Dualidade, Ciclos Negativos, SSP-Dijkstra e Network Simplex.   | ⏳ Planejado |
| `strongly-polynomial-flows.tex` | **Algoritmos Fortemente Polinomiais em Redes:** Dinic, MPM, Karp, MMCC, Cancel-and-Tighten e `__int128`.    | ⏳ Planejado |
| `graph-cuts-segmentation.tex`   | **Visão Computacional com Corte Mínimo:** Modelagem Boykov-Jolly, grade 2D e arquitetura com `PushRelabel`. | ⏳ Planejado |

---

## 🛠️ Como Compilar

```sh
make all
make clean
make distclean
```

Ou a partir da raiz do repositório / pasta [`latex/`](../README.md):

```sh
make minibooks
```
