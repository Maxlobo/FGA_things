/*
-- --------            << aula1exer2Evolucao3 >>        ------------ --
--                                                                   --
--                    SCRIPT POPULA (DML)                            --
--                                                                   --
-- Data Criacao ..........: 26/08/2019                               --
-- Autor(es) .............: Max Henrique Barbosa                     --
-- Banco de Dados ........: MySQL                                    --
-- Base de Dados(nome) ...: aula1exer2Evolucao3                      --
--                                                                   --
-- Data Ultima Alteracao ..: 26/08/2019                              --
--    + Populando todas as tabelas com 3 tuplas                      --
--                                                                   --
-- PROJETO => 1 Base de Dados                                        --
--         => 8 Tabelas                                              --
--                                                                   --
-- ----------------------------------------------------------------- --
*/

USE aula1exer2Evolucao3;

INSERT PESSOA (cpf, nome, senha) VALUES (12156849257, 'Artur Pinto', '5das1gd6as51'),
										(33549871540, 'Marco Lima', '5vfsa51fv'),
										(98156826652, 'Neymar Junior', 'vfs5d56fa'),
										(43215466666, 'Everton Cebolinha', 'ff1fsd4'),
										(42343243245, 'Fernando Silva', 'b1vc1b5'),
										(53542354554, 'Thiago Silva', 'q5we4eq2');
                                        
INSERT GERENTE (cpf, formacaoEscolar, email) VALUES (12156849257, 'Superior', 'arturarp@gmail.com'),
													(33549871540, 'Superior', 'marcolima@gmail.com'),
													(98156826652, 'Superior', 'neneyp@gmail.com');

INSERT EMPREGADO (cpf, matricula, rua, numero) VALUES (43215466666, 15898, 'CSB 03 LOTE 05', 'APT 1404'),
													  (42343243245, 51662, 'CSB 09 LOTE 02', 'APT 701'),
													  (53542354554, 354435, 'CSB 10 LOTE 06', 'APT 502');

INSERT telefone (matricula, telefone) VALUES (354435, 61996745588),
											 (51662, 61995356522),
											 (15898, 61998565655);

INSERT AREA (idArea, nome, cpf) VALUES (434, 'Eletrodomesticos', 98156826652),
									   (543, 'Informatica', 33549871540),
									   (42314, 'Moveis', 12156849257);

INSERT PRODUTO (codigo, precoUnitario, nome, idArea) VALUES (5433, 1200.00, 'Rack com Painel para TV', 42314),
															(47465, 5200.00, 'Notebook Avell i7', 543),
															(53545, 2200.00, 'Geladeira', 434);

INSERT VENDA (matricula, idVenda, dtVenda) VALUES (15898, 541345, '2019-06-14'),
												  (51662, 678478, '2019-06-15'),
												  (354435, 099876, '2019-06-16');

INSERT possui (codigo, idVenda, quantidade) VALUES (53545, 099876, 2),
												   (47465, 678478, 3),
												   (5433, 541345, 1);