-- --------                 << maxbarbosa  >>             ------------
--
--                    SCRIPT DE CONTROLE (DDL)
--
-- Data Criacao ...........: 17/10/2019
-- Autor(es) ..............: Max Henrique Barbosa
-- Banco de Dados .........: MySQL
-- Banco de Dados(nome) ...: maxbarbosa
-- 
-- Data Ultima Alteracao ..: 17/10/2019
--   => adiciona dois usuarios e concede permissoes
--
-- PROJETO => 01 Base de Dados
--         => 03 Tabelas
--         => 02 Sequencias
--         => 02 Usuarios
--         => 01 Visao
--
-- -----------------------------------------------------------------

USE maxbarbosa;

CREATE USER 'ADMIN' IDENTIFIED BY 'senha1';
GRANT ALL PRIVILEGES ON maxbarbosa.* TO 'ADMIN';

CREATE USER 'PESSOA' IDENTIFIED BY 'senha2';
GRANT SELECT ON maxbarbosa.* TO  'PESSOA';