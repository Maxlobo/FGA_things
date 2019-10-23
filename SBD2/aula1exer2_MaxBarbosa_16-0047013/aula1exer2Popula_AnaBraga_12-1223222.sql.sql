-- --------               << aula1exer2 >>              ------------ --
--                                                                   --
--                    SCRIPT PARA POPULAR (DML)                      --
--                                                                   --
-- Data Criacao ..........: 19/08/2019                               --
-- Autor(es) .............: Max Henrique Barbosa                     --
-- Banco de Dados ........: MySQL                                    --
-- Base de Dados(nome) ...: aula1exer2                               --
--                                                                   --
-- Data Ultima Alteracao ..: 19/08/2019                              --
--    + Coloca dados nas tabelas                                     --
--                                                                   --
-- PROJETO => 1 Base de Dados                                        --
--         => 7 Tabelas                                              --
--                                                                   --
-- ----------------------------------------------------------------- --

USE aula1exer2;

INSERT INTO GERENTE(escolaridade, email, cpf) VALUES ('Fundamental', 'doug@gmail.com', 00000000001);
INSERT INTO GERENTE(escolaridade, email, cpf) VALUES ('Médio', 'matias@gmail.com', 00000000002);
INSERT INTO GERENTE(escolaridade, email, cpf) VALUES ('Superior', 'fabricio@gmail.com', 00000000003);

INSERT INTO TELEFONE(codTelefone, telefone) VALUES (01, 1111111);
INSERT INTO TELEFONE(codTelefone, telefone) VALUES (02, 2222222);
INSERT INTO TELEFONE(codTelefone, telefone) VALUES (03, 3333333);

INSERT INTO EMPREGADO(codTelefone, quadra, rua, numero, matricula, cpf) VALUES (01, 'QNL', 'C', 15, 11111111, 00000000091);
INSERT INTO EMPREGADO(codTelefone, quadra, rua, numero, matricula, cpf) VALUES (02, 'QNN', 'D', 20, 22222222, 00000000092);
INSERT INTO EMPREGADO(codTelefone, quadra, rua, numero, matricula, cpf) VALUES (03, 'QNM', 'E', 25, 23232323, 00000000093);

INSERT INTO PRODUTO(preco, codigo) VALUES (50.00, 0000011111);
INSERT INTO PRODUTO(preco, codigo) VALUES (750.00, 0000022222);
INSERT INTO PRODUTO(preco, codigo) VALUES (3000.00, 0000033333);

INSERT INTO FUNCIONARIO(nome, cpf, senha) VALUES ('Douglas', 00000000001, 0000000010);
INSERT INTO FUNCIONARIO(nome, cpf, senha) VALUES ('Geraldo', 0000000091, 0000000020);
INSERT INTO FUNCIONARIO(nome, cpf, senha) VALUES ('Manoel', 0000000092, 0000000030);
INSERT INTO FUNCIONARIO(nome, cpf, senha) VALUES ('Gustavo', 0000000093, 0000000040);
INSERT INTO FUNCIONARIO(nome, cpf, senha) VALUES ('Matias', 00000000002, 0000000050);
INSERT INTO FUNCIONARIO(nome, cpf, senha) VALUES ('Fabricio', 00000000003, 0000000060);

INSERT INTO vende(matricula, codigoProduto, dataVenda, quantidade) VALUES (11111111, 0000011111, '2019-01-01', 20);
INSERT INTO vende(matricula, codigoProduto, dataVenda, quantidade) VALUES (22222222, 0000022222, '2019-02-02', 10);
INSERT INTO vende(matricula, codigoProduto, dataVenda, quantidade) VALUES (33333333, 0000033333, '2019-03-03', 5);

INSERT INTO supervisiona(matricula, cpf ) VALUES (11111111, 00000000001);
INSERT INTO supervisiona(matricula, cpf ) VALUES (22222222, 00000000002);
INSERT INTO supervisiona(matricula, cpf ) VALUES (33333333, 00000000003);