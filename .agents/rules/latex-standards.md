---
description: Padrões de documentação LaTeX e integridade acadêmica para Network Flow.
globs: "latex/**/*.tex"
always_on: true
---

# Diretrizes de LaTeX & Documentação Acadêmica

1. **Congelamento dos Artefatos da IC (Regra Soberana):** Os documentos institucionais entregues na Iniciação Científica (`latex/proposal.tex`, `latex/report.tex`, `latex/ic.tex`, `latex/monolith.tex`, `latex/poster.tex`, `latex/sections/`, `latex/tables/` e `latex/figures/`) estão **finalizados e congelados**. É **proibido** editar manualmente seu texto, resultados, tabelas, figuras ou layout sem ordem explícita e nominal do usuário; a única mutação permitida é a regeneração automática via `make sync-code` em caso de bugfix nos 9 motores originais da IC (`appendices/01..11` e `monolith.tex`). Toda evolução contínua concentra-se exclusivamente em `latex/book.tex` e `latex/book/`.
2. **Compilação Idempotente:** Compilação gerenciada via `latexmk` através do `make latex` ou `make book`.
3. **Sincronização C++ ↔ Apêndices:** Nunca edite apêndices de código manualmente. Sempre altere os arquivos em `implementations/` e execute `make sync-code`.
4. **Estrutura Modular:** Capítulos isolados em `book/chapters/`, seções congeladas da IC em `sections/` e bibliografia BibTeX unificada em `common/references.bib`.
5. **Clean Code & Tipografia:** Evitar pacotes conflitantes e seguir os padrões tipográficos canônicos da UFABC e da classe `book`.
6. **Estilo Textual Estrito (`Linguagem.txt`) & O Teste do Leitor Não-Nativo:**
    - **Regra de Ouro:** Qualquer leitor não nativo na língua portuguesa (ou ferramenta de tradução acadêmica) deve ser capaz de ler o texto técnico diretamente sem se confundir. O conteúdo formal já é denso; o texto deve ser uma lente transparente para a matemática.
    - **IC / Relatórios (`ic.tex`, `report.tex`, `sections/`):** Linguagem não complexa, estritamente acadêmica, sem florear, pouco rebuscada, sem palavras extras ("vale ressaltar", "com o intuito de"), mais matemática e direta.
    - **Livro (`book.tex`, `book/chapters/`):** Mesma sobriedade de IC/Relatório (sem floreios, pouco rebuscada, direta e matemática), porém sem restrição de páginas para aprofundamento das demonstrações e intuições.
7. **Precisão Terminológica Matemática Estrita:** Evite utilizar termos de áreas aprofundadas da matemática (isomorfismo, topologia, canônico, geometria, convergência, invariante) como meros sinônimos estéticos ou figuras retóricas. Digrafos são estruturas combinatórias (não espaços topológicos); algoritmos exatos discretos encerram/terminam (não convergem numericamente); e decomposições de fluxo não são únicas (não são canônicas).
