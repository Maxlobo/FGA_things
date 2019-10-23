-- --------               << aula1exer2 >>              ------------ --
--                                                                   --
--                   SCRIPT DE POPULACAO (DDL)                       --
--                                                                   --
-- Data Criacao ..........: 21/08/2019                               --
-- Autor(es) .............: Max Henrique Barbosa                     --
-- Banco de Dados ........: MySQL                                    --
-- Base de Dados(nome) ...: aula1exer2                               --
--                                                                   --
-- Data Ultima Alteracao ..: 21/08/2019                              --
--    + Deleta a as tabelas da base de dados                         --
--                                                                   --
-- PROJETO => 1 Base de Dados                                        --
--         => 9 Tabelas                                              --
--                                                                   --
-- ----------------------------------------------------------------- --

USE aula1exer2;

INSERT INTO PESSOA VALUES
	(09976933321, 'Pedro Barbosa', 'pd01ba23'),
    (09831231211, 'Joana Almeida', 'mstopra21'),
    (43137123211, 'João Pinto', 'rqsdd12'),
    (67390120932, 'Giovanna Queiroz', 'amora97'),
    (43127381232, 'Ivan Santos', 'klab32'),
    (71152813231, 'Joaquim Oliveira', 'oliver123');

INSERT INTO GERENTE VALUES
	('pedro@gmail.com', 'superior', 09976933321),
    ('almeida@gmail.com', 'superior', 09831231211),
    ('joaoli@gmail.com', 'superior', 43137123211);

INSERT INTO EMPREGADO VALUES
	(265321, 67390120932, 43, 'Rua Algusto Ribeiro', 'Setor Norte', 'Gama', 'DF', 72300000),
    (296232, 43127381232, 24, 'QR 210 conj 04 ', 'Norte', 'Ceilândia', 'DF', 31241200),
    (332172, 71152813231, 25, 'QNJ', 'Sul', 'Taguatinga', 'DF', 89132122);

INSERT INTO telefone VALUES
	(265321, 5561999961224),
    (296232, 5561997162322),
    (332172, 5561997368221);

INSERT INTO VENDA VALUES
	(470.00, '2019-08-01 10:00:09', 112, 1),
    (350.00, '2019-08-01 10:00:09', 113, 1),
    (200.00, '2019-08-01 10:00:09', 114, 1);
    
INSERT INTO faz VALUES
	(265321, 112),
    (296232, 113),
    (332172, 114);

INSERT INTO AREA VALUES
	(1, 'Esportes', 09976933321),
    (2, 'Informática', 09831231211),
    (3, 'Jogos', 43137123211);

INSERT INTO PRODUTO VALUES
	(3243, 1, 'luva de box 15 oz'),
    (2342, 2, 'mause xtz 3'),
    (2232, 3, 'fifa 19');

INSERT INTO inclui VALUES
	(112, 3243),
    (113, 2342),
    (114, 2232);