.POSIX:
.SILENT:

MAKEFLAGS += --no-print-directory -s

# ----------------------------------------------------------------
# Makefile: Network Flow Implementations
# ----------------------------------------------------------------

CXX             = c++
CXXFLAGS        = -std=c++23 -fsyntax-only -Wall -Wextra
STRESS_CXXFLAGS = -std=c++23 -O2 -Wall -Wextra -Wpedantic
STRESS_BIN      = tests/min_cost_stress.out

.PHONY: default help all check impl test stress-test verify format format-cpp format-md clean clear

default: help
all: check

### ================================
### HELP & DOCUMENTATION
### ================================
help:
	_e=$$'\e'; \
	cmd() { printf "    $${_e}[36mmake %-20s$${_e}[0m %s\n" "$$1" "$$2"; }; \
	sec() { printf "\n  $${_e}[1;33m%s$${_e}[0m\n" "$$1"; }; \
	printf "\n  $${_e}[1;37mNetwork Flow — Módulo de Implementações em C++23$${_e}[0m\n"; \
	printf "  ============================================================\n"; \
	sec "Fluxos Batch & Validação:"; \
	cmd "verify"              "Executa checagem de sintaxe dos headers E todos os testes de problemas"; \
	cmd "check"               "Verifica a sintaxe C++23 de todos os headers (FlowNetwork e CostNetwork)"; \
	cmd "impl"                "Sinônimo para check (valida sintaxe C++23 dos headers)"; \
	cmd "test"                "Executa os problemas de Fluxo Máximo e Fluxo de Custo Mínimo"; \
	cmd "stress-test"         "Compila e executa a suíte de estresse de Custo Mínimo"; \
	sec "Qualidade & Formatação:"; \
	cmd "format"              "Formata códigos C++ (clang-format) e documentação (prettier)"; \
	sec "Limpeza:"; \
	cmd "clean"               "Remove binários compilados das subpastas de problemas"; \
	echo ""

verify: check test
	printf "\n$${_e}[1;32m==> Todas as implementações e problemas foram validados com sucesso!$${_e}[0m\n\n"

format: format-cpp format-md
	printf "%s\n" "Formatação completa de Implementações concluída!"

format-cpp:
	printf "%s\n" "Formatando todos os códigos C++ (.hpp e .cpp) em Implementações com clang-format..."
	find . -type f \( -name "*.hpp" -o -name "*.cpp" \) -not -path "*/.*/*" -exec clang-format -i {} +

format-md:
	if command -v prettier > "/dev/null" 2>&1; then \
		printf "%s\n" "Formatando documentação Markdown de Implementações com prettier..."; \
		prettier --write "**/*.md" > "/dev/null" 2>&1 || true; \
	fi

check:
	printf "%s\n" "Verificando sintaxe dos headers (flow-network)..."
	for f in flow-network/*.hpp; do \
		$(CXX) $(CXXFLAGS) "$$f" || exit 1; \
	done
	printf "%s\n" "Verificando sintaxe dos headers (cost-network)..."
	for f in cost-network/*.hpp; do \
		$(CXX) $(CXXFLAGS) "$$f" || exit 1; \
	done
	printf "%s\n" "Todos os headers compilaram perfeitamente!"

impl: check

test:
	printf "%s\n" "Executando testes dos problemas de Fluxo Máximo..."
	for dir in problems/max-flow/*/; do \
		case "$$dir" in *template*|*Template*) continue ;; esac; \
		if [ -f "$${dir}Makefile" ]; then \
			printf "%s\n" "-> Testando $$dir"; \
			(cd "$$dir" && $(MAKE) all > "/dev/null") || exit 1; \
		fi \
	done
	printf "%s\n" "Executando testes dos problemas de Fluxo de Custo Mínimo..."
	for dir in problems/min-cost-flow/*/; do \
		case "$$dir" in *template*|*Template*) continue ;; esac; \
		if [ -f "$${dir}Makefile" ]; then \
			printf "%s\n" "-> Testando $$dir"; \
			(cd "$$dir" && $(MAKE) all > "/dev/null") || exit 1; \
		fi \
	done
	$(MAKE) stress-test
	printf "%s\n" "Todos os problemas foram executados com sucesso!"

stress-test:
	printf "%s\n" "Compilando e executando suíte de estresse (cost-network)..."
	$(CXX) $(STRESS_CXXFLAGS) tests/min_cost_stress.cpp -o "$(STRESS_BIN)"
	"./$(STRESS_BIN)"

clean:
	rm -f "$(STRESS_BIN)"
	for dir in problems/max-flow/*/ problems/min-cost-flow/*/; do \
		if [ -f "$${dir}Makefile" ]; then \
			(cd "$$dir" && $(MAKE) clean); \
		fi \
	done

clear: clean
