# Curso de controle de versão com GIT

Objetivo: controlar todos os passos da criação de um projeto.

Estrutura:

- Repositório:
  - Estações
- Estágios:
  - Working directory: `git add`
  - Staging area: `git commit`
  - Git directory

# Configuracao Básica

Os comandos a seguir são para configurar o nome e email do espaco global de trabalho do git:

```bash
git config --global user.name "Nome Usuario"
git config --global user.email "user@email"
```

# Comandos Básicos

Criando o primeiro repositório. Basta digitar:

```bash
git init
```

dentro da pasta que você quer controlar o código. Este comando vai criar uma pasta `.git`dentro do diretório corrente.

Para verificar a situação (status) atual da sua estação de trabalho (repositório) digite:

```bash
git status
```

Este comando vai mostrar se existem modificações para adicionar ao controle do git. Ele vai dizer se tem algo para ser "comitado" (para fazer) no nosso repositório.

Então precisamos criar ou modificar arquivos e usa o comando `git add` para realizar uma atualização.

> Sempre que realizmos um `git add`, estamos passando os arquivos do `Working directory` para o `Stagin area`.

Despois que criamos um repositório e adicionamos alguns arquivos, o comando `git status` vai mostrar que podemos adicionar estes para começar o controle de versão:

```bash
git add arquivo.ext
git add *.ext # todos os arquivos .ext
git . # todos os arquivos
```

Depois de adicionar os arquivos poderemos fazer os commits, isto é, agora vamos fazer uma confirmar as mudanças no seu projeto. Neste caso, digamos que se tenha adicionado toda a base do projeto (todos os arquivos iniciais do projeto), o próximo passo é tirar ele da `Staging area`e mandá-lo para `Git directory`, fazemos isso com `git commit`. Fazemos assim (para identificar o commit):

```bash
git commit -m "Commit inicial"
git commit -m "Arquivos base do projeto"
git commit -m "Base do projeto criada"
```

Uma boa prática é usar essa mensagem para informar o estágio do projeto, ou do que se trata, ou o que foi feito, nesta data. Depois do commit, o `git status` vai mostrar que não existe nenhuma uma alteração pendende de salvamento, `directory clean`.

Com isso aprendemos, em resumo,  como é o funcionamento do fluxo básico de arquivos no controle de versão (dentro de um repositório do git):

- Adicionando ou editando arquivos: **Working directory**
- Quando usa o comando `git add`:  Passando os arquivos para **Stage area** (estágio intermediário)
- Quando usa o `git commit`, você está dizendo terminei o meu trabalho pode gravar tudo isso que eu fiz até agora: Enviando os arquivos para o **Git directory**.

Se você cria um arquivo e não faz o commit, toda vez que você consultar o status do projeto, ele vai informar que existe esse arquivo para fazer o commit. Se você deseja que um arquivo não seja controlado (monitorado) pelo **git** podemos fazer o seguinte:

- crie um arquivo `.gitignore` dentro do diretório de trabalho (e fora da pasta **.git**)
- coloque o nomes dos arquivos/diretórios, em cada linha. por exemplo:
  - .gitignore (pra ignorar o próprio arquivo .gitignore)
  - arquivo_ignorado.txt
  - temp/

Agora o **git status** não mostrar mais esse arquivos na hora de fazer o commit. O git simplesmente ignora os arquivos listados no arquivo **.gitignore**.

Resumo dos três stágios no controle de versão:

- Começou a trabalhar no projeto, edita todos os arquivos, fez todas as alterações
- vai no gitbash e verificar o **status** e faz um **add** (em todos, ou so na extensão, ou so no arquivo que alterou)
- dá um **comit**
- e o **status** mostrará que não há nenhuma modificação a ser realizada.

>Passos básicos:
>
>1. modifica os arquivos para obter a solução desejada
>2. **git add .**
>3. **git status**
>4. **git commit -m "Conteudo inicial adicionado nos arquivos"**
>5. **git status**
>
>OBS: O add e commit pode ser realizados juntos com:
>
>- **git commit -a -m "Linhas adicionadas no readme"**

# Visualizar alterações de forma mais detalhada

O **git status** vai mostrar os arquivos que foram alterados e que podem ser comitados para o repositório do git. Mas e se quisermos saber quais alterações foram feitas dentro desse arquivo, o que podemos fazer? Para fazer esta consulta, para ver as diferenças no arquivo que ainda não foi comitado, podemos usa o comando `git diff`:

```bash
git diff
```

ele vai mostar em <span style='color:red'>vermelho</span> o que foi removido e em <span style='color:green'>verde</span> o que foi adicionado, normalmente, isto ocorre no final do arquivo. Se fizermos um `git add .` e depois um `git diff`, não serão reportadas diferenças, pois o arquivo na **stage area** e o arquivo local não diferem, são os mesmos. Para mostrar as diferenças entre os arquivos que tem na `stage area` e os arquivos na nuvem, pois ainda não foi feito o commit, podemos fazer `git diff --staged`. Se for feito um commit, não vamos encontrar mais diferenças usando esse comando.

O `git log`, mostra todos os commits que foram feitos no repositório, teremos um histórico das modificações. Este comando vai mostrar uma lista de modificações e as respectivas chaves, que podem ser usadas se você quiser voltar para uma versão específica. Cada item terá: a mensagem, o nome de quem modificou com e email, e o horário da modificação.

O comando `git log -p` vai mostar as modificações em ordem cronológica e também as alterações que foram realizadas. Usamos [ENTER] para percorrer as linhas ou pressionar a tecla `q` para finalizar. Para limitar o número de commites podemos dizer quantas entradas que queremos trazer:

```bash
git log -p -1
```

para mostrar apenas o último commit.

A melhor forma de visualizar os relatórios é através da interface gráfica do git: `gitk`.



Próximo: aula 4

https://www.youtube.com/watch?v=dRV13jZqhU0&list=PLInBAd9OZCzzHBJjLFZzRl6DgUmOeG3H0&index=4





