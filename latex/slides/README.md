# 📽️ Apresentações Beamer (`slides/`)

> **Status:** 🟢 Estrutura Pronta / ⏳ Aguardando Autoria _(Pós-IC — Evolução Ativa)_

Este diretório concentra **apresentações didáticas em LaTeX Beamer** para seminários, aulas, oficinas de maratona e palestras técnicas, reaproveitando diretamente os diagramas vetoriais TikZ de [`../diagrams/`](../diagrams/).

---

## 🎨 Padrão Editorial & Reuso

- **Design System Compartilhado:** Uso direto dos estilos TikZ e paleta semântica de [`../common/header.tex`](../common/header.tex) (adaptados à proporção `16:9` do Beamer) e referências de [`../common/references.bib`](../common/references.bib) via `TEXINPUTS="..:" BIBINPUTS="..:"`.
- **Clean Cleanup:** O `Makefile` local já remove artefatos específicos do Beamer (`.nav`, `.snm`, `.vrb`) em `make clean`.

---

## 📋 Catálogo Planejado (4 Apresentações)

| Arquivo Alvo                   | Título e Escopo da Apresentação                                                                               |    Status    |
| :----------------------------- | :------------------------------------------------------------------------------------------------------------ | :----------: |
| `intro-max-flow.tex`           | **Introdução a Fluxo Máximo e Corte Mínimo:** Redes residuais, MFMC, Edmonds-Karp e Dinic passo a passo.      | ⏳ Planejado |
| `maratona-flow-modeling.tex`   | **Oficina de Modelagem de Fluxos para Maratona (ICPC):** König, Menger, Picard, Cotas Inferiores e Dilworth.  | ⏳ Planejado |
| `min-cost-network-simplex.tex` | **Fluxo de Custo Mínimo, Dualidade e Network Simplex:** Ciclos negativos, potenciais nodais e pivoteamento.   | ⏳ Planejado |
| `graph-cuts-vision-talk.tex`   | **Segmentação de Imagens com Corte Mínimo em C++23:** Modelagem energética em grade 2D e resultados práticos. | ⏳ Planejado |

---

## 🛠️ Como Compilar

```sh
make all
make clean
make distclean
```

Ou a partir da raiz do repositório / pasta [`latex/`](../README.md):

```sh
make slides
```
