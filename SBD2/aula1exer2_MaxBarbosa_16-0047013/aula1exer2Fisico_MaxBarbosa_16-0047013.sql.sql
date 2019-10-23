-- --------               << aula1exer2 >>              ------------ --
--                                                                   --
--                    SCRIPT DE CRIACAO (DDL)                        --
--                                                                   --
-- Data Criacao ..........: 19/08/2019                               --
-- Autor(es) .............: Max Henrique Barbosa                     --
-- Banco de Dados ........: MySQL                                    --
-- Base de Dados(nome) ...: aula1exer2                               --
--                                                                   --
-- Data Ultima Alteracao ..: 19/08/2019                              --
--    + Criacao da base de dados                                     --
--                                                                   --
-- PROJETO => 1 Base de Dados                                        --
--         => 7 Tabelas                                              --
--                                                                   --
-- ----------------------------------------------------------------- --

CREATE DATABASE if NOT EXISTS aula1exer2;
USE aula1exer2;

CREATE TABLE GERENTE (
    escolaridade VARCHAR(30),
    email VARCHAR(30) UNIQUE,
    cpf INT(11) UNIQUE,
	CONSTRAINT PK_GERENTE PRIMARY KEY (cpf)
);

CREATE TABLE TELEFONE (
    codTelefone INT(2) AUTO_INCREMENT,
    telefone INT(9),
    CONSTRAINT PK_TELEFONE PRIMARY KEY (codTelefone)
);

CREATE TABLE EMPREGADO (
    codTelefone INT(2),
    quadra VARCHAR(30),
    rua VARCHAR(30),
    numero INT(3),
    matricula INT(8) UNIQUE,
    cpf INT(11) UNIQUE,
	CONSTRAINT PK_EMPREGADO PRIMARY KEY (matricula, cpf),
    CONSTRAINT FK_EMPREGADO_TELEFONE FOREIGN KEY (codTelefone) REFERENCES TELEFONE (codTelefone)
);

CREATE TABLE PRODUTO (
    preco DECIMAL(7, 2),
    codigo INT(10),
    CONSTRAINT PK_PRODUTO PRIMARY KEY (codigo)
);

CREATE TABLE FUNCIONARIO (
    nome VARCHAR(30) NOT NULL,
    cpf INT(11) UNIQUE,
    senha INT(10) NOT NULL,
    CONSTRAINT PK_FUNCIONARIO PRIMARY KEY (cpf)
);

CREATE TABLE vende (
    matricula INT(8) NOT NULL,
    codigoProduto INT(10) NOT NULL,
    dataVenda DATE,
    quantidade INT(3),
    CONSTRAINT PK_vende PRIMARY KEY (matricula, codigoProduto)
);

CREATE TABLE supervisiona (
    matricula INT(8),
    cpf INT(11),
    CONSTRAINT PK_supervisiona PRIMARY KEY (matricula, cpf)
);