-- --------     << aula3exer2Evolucao4 >>     ------------
--
--                    SCRIPT DE MANIPULACAO (DML)
-- 
-- date Criacao ...........: 07/10/2019
-- Autor(es) ..............: Henrique Martins de Messias
--                           Max Henrique Barbosa
-- Banco de Dados .........: Oracle
-- Base de Dados(nome) ....: VRVR
-- 
-- date Ultima Alteracao ..: 14/10/2019
--   => Criacao das tabelas e ajustes na documentacao dos scritps
-- 
-- PROJETO => 01 Base de Dados
--         => 04 Tabelas
--         => 01 Visao 
--         => 03 Sequences
-- 
-- -----------------------------------------------------------------

Use aula3exer2Evolucao4;

 -- VISAO
DROP VIEW if exists HMM_V_HORARIOS;

 -- TABELAS
DROP TABLE if exists HMM_alocado;
DROP TABLE if exists HMM_PLANTONISTA;
DROP TABLE if exists HMM_ESPECIALIDADE;
DROP TABLE if exists HMM_SETOR;