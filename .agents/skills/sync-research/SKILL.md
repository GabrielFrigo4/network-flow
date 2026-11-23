---
name: sync-research
description: Runbook cognitivo para compilação, testes algorítmicos, sincronização de apêndices LaTeX e rigor terminológico no projeto Network Flow.
---

# 🔄 Sync Research Skill — Network Flow

Este runbook orienta o agente na validação de implementações C++, execução de testes, sincronização de código com apêndices LaTeX e manutenção do rigor terminológico da pesquisa **Network Flow**.

---

## ⚙️ Fluxo Canônico de Build e Sincronização

Execute os alvos do `Makefile` na raiz do repositório na ordem operacional abaixo:

```sh
make impl
make test
make sync-code
make book
make clean
```

- **`make impl`:** Valida a sintaxe C++23 de todos os headers em `implementations/`.
- **`make test`:** Executa as suítes de testes de algoritmos e aplicações.
- **`make sync-code`:** Sincroniza implementações C++ com as listagens LaTeX (`.scripts/sync_listings.py`) e reconstrói o monólito (`.scripts/build_monolith.py`).
- **`make book`:** Compila exclusivamente a monografia (`book.pdf`).
- **`make clean`:** Remove artefatos temporários de compilação em todos os submódulos.

---

## ✍️ Diretrizes Editoriais & Rigor Terminológico

Para regras gerais de redação científica (No-Fluff, Math-First, Teste do Leitor Não-Nativo, build isolado e sincronização de listagens), siga a skill global `latex-typesetting`. No projeto **Network Flow**, aplique as distinções estruturais e terminológicas específicas abaixo:

### 1. Escopo por Documento LaTeX

- **IC / Relatórios Institucionais 🔒 Congelado (`latex/sections/`, `latex/ic.tex`, `latex/report.tex`, `latex/monolith.tex`, `latex/proposal.tex`, `latex/poster.tex`):** Artefatos entregues à UFABC e congelados no escopo original (9 motores da IC). Proibido alterar texto, resultados, tabelas (`latex/tables/`), figuras (`latex/figures/`) ou pôster; apenas correções de código nos 9 headers originais da IC propagam automaticamente para `latex/appendices/01..11` e `monolith.tex` via `make sync-code`.
- **Livro / Monografia 🟢 Evolução Ativa (`latex/book/chapters/`, `latex/book.tex`, `latex/book/`):** Documento em evolução contínua (5 Partes, 14 Capítulos), sem limite de páginas; permite demonstrações completas, novas reduções combinatórias, intuições bem fundamentadas e exemplos passo a passo mantendo sobriedade acadêmica.

### 2. Precisão Terminológica Matemática (Fluxos em Redes)

Termos com definição formal rigorosa NUNCA devem ser usados como sinônimos casuais ou adornos estilísticos:

- **_Isomórfico_:** Proibido para código ou equivalência operacional de pivoteamentos.
- **_Topologia_:** Proibido para designar estrutura de digrafos ou redes de fluxo gerais.
- **_Canônico_:** Proibido para instâncias DIMACS ou decomposições arbitrárias de fluxo.
- **_Geométrico_:** Proibido para propriedades combinatórias de grafos ou programação linear fora de contexto espacial.
- **_Convergência_:** Proibido para encerramento finito de algoritmos combinatórios discretos exatos.
