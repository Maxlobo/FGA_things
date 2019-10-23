-- --------            << aula3exer2Evolucao4 >>        ------------ --
--                                                                   --
--                    SCRIPT CONTROLE (DDL/DCL)                      --
--                                                                   --
-- Data Criacao ..........: 27/09/2019                               --
-- Autor(es) .............: Daniel Maike Mendes Gonçalves            --
--                          Max Henrique Barbosa                     --
-- Banco de Dados ........: MySQL                                    --
-- Base de Dados(nome) ...: aula3exer1Evolucao2                      --
--                                                                   --
-- Data Ultima Alteracao ..: 02/10/2019                              --
--    + Criando usuários admin, usuario e gestor                     --
--                                                                   --
-- PROJETO => 1 Base de Dados                                        --
--         => 3 Tabelas                                              --
--                                                                   --
-- ----------------------------------------------------------------- --

Use aula3exer2Evolucao4;

-- administrador: possui todos os privilégios sobre essa base de dados somente, pois será o DBA para administrar essa base de dados;

CREATE USER 'administrador'@'localhost' IDENTIFIED BY 'adm123';
GRANT ALL PRIVILEGES ON aula3exer2Evolucao4.* TO 'administrador'@'localhost';

-- usuario: possui todos os privilégios de consulta de dados sobre a base de dados desse projeto somente;

CREATE USER 'usuario'@'localhost' IDENTIFIED BY 'user123';
GRANT SELECT ON aula3exer2Evolucao4.* TO 'usuario'@'localhost';

-- gestor: possui os privilégios de consultar os dados de todas as tabelas dessa base de dados, mas também pode cadastrar e alterar dados do plantonista e do setor do hospital.
CREATE USER 'gestor'@'localhost' IDENTIFIED BY 'gestor123';
GRANT SELECT ON aula3exer2Evolucao4;.* TO 'gestor'@'localhost';
GRANT INSERT ON aula3exer2Evolucao4.PLANTONISTA TO 'gestor'@'localhost';
GRANT INSERT ON aula3exer2Evolucao4.SETOR TO 'gestor'@'localhost';
GRANT UPDATE ON aula3exer2Evolucao4.PLANTONISTA TO 'gestor'@'localhost';
GRANT UPDATE ON aula3exer2Evolucao4.SETOR TO 'gestor'@'localhost';