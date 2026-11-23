# 📓 Cadernos ICPC e Maratona (`notebooks/`)

> **Status:** 🟢 Estrutura Pronta / ⏳ Aguardando Autoria _(Pós-IC — Evolução Ativa)_

Este diretório reúne **cadernos compactos de competição** (_Team Reference Documents / Notebook ICPC_), voltados para impressão em duas colunas durante provas da Maratona de Programação SBC e ICPC.

---

## 🎨 Padrão Editorial & Reuso

- **Foco Competitivo:** Implementações concisas em C++23 (~50 a 70 linhas por algoritmo), sem boilerplate OOP pesado, acompanhadas de checklists de redução e verificação de casos de borda.
- **Validação Cruzada:** Todos os templates compactos deverão ser testados contra os motores OOP de referência em [`../../implementations/`](../../implementations/).

---

## 📋 Catálogo Planejado (3 Cadernos)

| Arquivo Alvo                  | Escopo e Conteúdo                                                                                        |    Status    |
| :---------------------------- | :------------------------------------------------------------------------------------------------------- | :----------: |
| `icpc-flow-notebook.tex`      | **Caderno ICPC Completo de Fluxos em Redes:** 2 colunas com templates C++23 e receitas de modelagem.     | ⏳ Planejado |
| `icpc-maxflow-cheatsheet.tex` | **Caderno Compacto de Fluxo Máximo e Bipartidos:** `Dinic`, `HopcroftKarp`, König, Picard e Cotas.       | ⏳ Planejado |
| `icpc-mcf-cheatsheet.tex`     | **Caderno Compacto de Custo Mínimo:** `SSP-Dijkstra`, `KuhnMunkres`, Cotas Inferiores e Custos Convexos. | ⏳ Planejado |

---

## 🛠️ Como Compilar

```sh
make all
make clean
make distclean
```

Ou a partir da raiz do repositório / pasta [`latex/`](../README.md):

```sh
make notebooks
```
