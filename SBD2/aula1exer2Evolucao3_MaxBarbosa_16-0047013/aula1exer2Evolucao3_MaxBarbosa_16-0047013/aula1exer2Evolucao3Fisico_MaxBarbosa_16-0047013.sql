/*
-- --------            << aula1exer2Evolucao3 >>        ------------ --
--                                                                   --
--                    SCRIPT DE CRIACAO (DDL)                        --
--                                                                   --
-- Data Criacao ..........: 26/08/2019                               --
-- Autor(es) .............: Max Henrique Barbosa                     --
-- Banco de Dados ........: MySQL                                    --
-- Base de Dados(nome) ...: aula1exer2Evolucao3                      --
--                                                                   --
-- Data Ultima Alteracao ..: 26/08/2019                              --
--    + Criacao da base de dados                                     --
--    + Criacao das tabelas                                          --
--                                                                   --
-- PROJETO => 1 Base de Dados                                        --
--         => 8 Tabelas                                              --
--                                                                   --
-- ----------------------------------------------------------------- --
*/

CREATE DATABASE IF NOT EXISTS aula1exer2Evolucao3;

USE aula1exer2Evolucao3;

CREATE TABLE PESSOA (
    nome VARCHAR(200) NOT NULL,
    cpf BIGINT NOT NULL,
    senha VARCHAR(20) NOT NULL,
    CONSTRAINT PESSOA_PK PRIMARY KEY (cpf)
) ENGINE = InnoDB DEFAULT CHARSET = UTF8;

CREATE TABLE EMPREGADO (
    matricula BIGINT NOT NULL,
    rua VARCHAR(40) NOT NULL,
    numero VARCHAR(20) NOT NULL,
    cpf BIGINT NOT NULL,
    CONSTRAINT EMPREGADO_PK PRIMARY KEY (matricula),
    CONSTRAINT EMPREGADO_UC UNIQUE (cpf),
    CONSTRAINT EMPREGADO_PESSOA_FK FOREIGN KEY (cpf) REFERENCES PESSOA (cpf) ON DELETE RESTRICT ON UPDATE RESTRICT
) ENGINE = InnoDB DEFAULT CHARSET = UTF8;

CREATE TABLE GERENTE (
    formacaoEscolar VARCHAR(20) NOT NULL,
    email VARCHAR(40) NOT NULL,
    cpf BIGINT NOT NULL,
    CONSTRAINT GERENTE_UC UNIQUE (cpf),
    CONSTRAINT GERENTE_PESSOA_FK FOREIGN KEY (cpf) REFERENCES PESSOA (cpf) ON DELETE RESTRICT ON UPDATE RESTRICT
) ENGINE = InnoDB DEFAULT CHARSET = UTF8;

CREATE TABLE AREA (
    idArea INT NOT NULL,
    nome VARCHAR(50) NOT NULL,
    cpf BIGINT NOT NULL,
    CONSTRAINT AREA_PK PRIMARY KEY (idArea),
    CONSTRAINT AREA_GERENTE_FK FOREIGN KEY (cpf) REFERENCES GERENTE (cpf) ON DELETE RESTRICT ON UPDATE RESTRICT
) ENGINE = InnoDB DEFAULT CHARSET = UTF8;

CREATE TABLE PRODUTO (
    precoUnitario FLOAT NOT NULL,
    codigo BIGINT NOT NULL,
    nome VARCHAR(50) NOT NULL,
    idArea INT NOT NULL,
    CONSTRAINT PRODUTO_PK PRIMARY KEY (codigo),
    CONSTRAINT PRODUTO_AREA_FK FOREIGN KEY (idArea) REFERENCES AREA (idArea) ON DELETE RESTRICT ON UPDATE RESTRICT
) ENGINE = InnoDB DEFAULT CHARSET = UTF8;

CREATE TABLE VENDA (
    idVenda INT NOT NULL,
    dtVenda DATE NOT NULL,
    matricula BIGINT NOT NULL,
    CONSTRAINT VENDA_PK PRIMARY KEY (idVenda),
    CONSTRAINT VENDA_EMPREGADO_FK FOREIGN KEY (matricula) REFERENCES EMPREGADO (matricula) ON DELETE RESTRICT ON UPDATE RESTRICT
) ENGINE = InnoDB DEFAULT CHARSET = UTF8;

CREATE TABLE telefone (
    matricula BIGINT NOT NULL,
    telefone BIGINT NOT NULL,
    CONSTRAINT telefone_EMPREGADO_FK FOREIGN KEY (matricula) REFERENCES EMPREGADO (matricula) ON DELETE RESTRICT ON UPDATE RESTRICT
) ENGINE = InnoDB DEFAULT CHARSET = UTF8;

CREATE TABLE possui (
    idVenda INT NOT NULL,
    codigo BIGINT NOT NULL,
    quantidade INT NOT NULL,
    CONSTRAINT possui_VENDA_FK FOREIGN KEY (idVenda) REFERENCES VENDA (idVenda) ON DELETE RESTRICT ON UPDATE RESTRICT,
    CONSTRAINT possui_PRODUTO_FK FOREIGN KEY (codigo) REFERENCES PRODUTO (codigo) ON DELETE RESTRICT ON UPDATE RESTRICT
) ENGINE = InnoDB DEFAULT CHARSET = UTF8;

