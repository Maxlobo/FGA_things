-- --------     << aaula3exer2Evolucao4 >>     ------------
--
--                    SCRIPT DE CRIACAO (DDL)
-- 
-- date Criacao ...........: 07/10/2019
-- Autor(es) ..............: Henrique Martins de Messias
--                           Max Henrique Barbosa
-- Banco de Dados .........: Oracle
-- Base de Dados(nome) ....: VRVR
-- 
-- date Ultima Alteracao ..: 08/10/2019
--   => Criacao das tabelas e ajustes na documentacao dos scritps
--
-- PROJETO => 01 Base de Dados
--         => 04 Tabelas
--         => 01 Visao 
--         => 03 Sequences
-- 
-- -----------------------------------------------------------------

CREATE DATABASE IF NOT EXISTS aula3exer2Evolucao4;

 USE aula3exer2Evolucao4;

 -- TABELAS
CREATE TABLE IF NOT EXISTS HMM_SETOR (
    idSetor int NOT NULL AUTO_INCREMENT,
    nomeSetor VARCHAR(30) NOT NULL,
    CONSTRAINT HMM_SETOR_PK PRIMARY KEY(idSetor)
)ENGINE = InnoDB DEFAULT CHARSET = UTF8 AUTO_INCREMENT = 0;

CREATE TABLE IF NOT EXISTS HMM_ESPECIALIDADE (
    idEspecialidade int (3) NOT NULL AUTO_INCREMENT,
    tipoEspecialidade VARCHAR(50) NOT NULL,
    CONSTRAINT HMM_ESPECIALIDADE_PK PRIMARY KEY(idEspecialidade)
)ENGINE = InnoDB DEFAULT CHARSET = UTF8 AUTO_INCREMENT = 0;

CREATE TABLE IF NOT EXISTS HMM_PLANTONISTA (
    matricula LONG INT(8) NOT NULL,
    nome VARCHAR(40) NOT NULL,
    sexo CHAR (1),
    idEspecialidade INT(3),
    CONSTRAINT HMM_PLANTONISTA_HMM_ESPECIALIDADE_FK FOREIGN KEY(idEspecialidade) REFERENCES HMM_ESPECIALIDADE(idEspecialidade),
    CONSTRAINT HMM_PLANTONISTA_PK PRIMARY KEY(matricula)
)ENGINE = InnoDB DEFAULT CHARSET = UTF8;

CREATE TABLE IF NOT EXISTS HMM_alocado (
    idSetor LONG INT(4) NOT NULL,
    matricula LONG INT(8) NOT NULL,
    datahora TIMESTAMP NOT NULL,
    CONSTRAINT HMM_alocado_HMM_SETOR_FK FOREIGN KEY(idSetor) REFERENCES HMM_SETOR(idSetor),
    CONSTRAINT HMM_alocado_HMM_PLANTONISTA_FK FOREIGN KEY(matricula) REFERENCES HMM_PLANTONISTA(matricula),
    CONSTRAINT HMM_alocado_UK UNIQUE (matricula, datahora)
)ENGINE = InnoDB DEFAULT CHARSET = UTF8;