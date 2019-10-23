-- --------               << aula1exer2 >>              ------------ --
--                                                                   --
--                    SCRIPT DE CRIACAO (DDL)                        --
--                                                                   --
-- Data Criacao ..........: 21/08/2019                               --
-- Autor(es) .............: Max Henrique Barbosa                     --
-- Banco de Dados ........: MySQL                                    --
-- Base de Dados(nome) ...: aula1exer2                               --
--                                                                   --
-- Data Ultima Alteracao ..: 21/08/2019                              --
--    + Criacao da base de dados                                     --
--                                                                   --
-- PROJETO => 1 Base de Dados                                        --
--         => 9 Tabelas                                              --
--                                                                   --
-- ----------------------------------------------------------------- --

CREATE DATABASE IF NOT EXISTS aula1exer2;

USE aula1exer2;

CREATE TABLE PESSOA (
    cpf BIGINT(11) NOT NULL,
    nome VARCHAR(50) NOT NULL,
    senha VARCHAR(20) NOT NULL,
CONSTRAINT PESSOA_PK PRIMARY KEY (cpf)
) ENGINE=InnoDB;

CREATE TABLE GERENTE (
    email VARCHAR(50) NOT NULL,
	formacao VARCHAR(50) NOT NULL,
    cpf BIGINT(11) NOT NULL,
CONSTRAINT GERENTE_PK PRIMARY KEY (cpf),
CONSTRAINT GERENTE_PESSOA_fk FOREIGN KEY (cpf)
	REFERENCES PESSOA (cpf)
) ENGINE=InnoDB;

CREATE TABLE EMPREGADO (
    matricula INT NOT NULL,
    cpf BIGINT(11) NOT NULL UNIQUE,
    numero INT NOT NULL,
    logradouro VARCHAR(50) NOT NULL,
    bairro VARCHAR(50) NOT NULL,
    cidade VARCHAR(50) NOT NULL,
    uf VARCHAR(2) NOT NULL,
    cep INT(8) NOT NULL,
CONSTRAINT EMPREGADO_PK PRIMARY KEY (matricula),
CONSTRAINT EMPREGADO_PESSOA_FK FOREIGN KEY (cpf)
	REFERENCES PESSOA (cpf)
) ENGINE=InnoDB;

CREATE TABLE telefone (
    matricula INT NOT NULL,
    telefone BIGINT(14) NOT NULL,
CONSTRAINT telefone_EMPREGADO_FK FOREIGN KEY (matricula)
	REFERENCES EMPREGADO (matricula)
) ENGINE=InnoDB;

CREATE TABLE VENDA (
	precoTotal DECIMAL(10,2) NOT NULL,
	dataVenda TIMESTAMP NOT NULL,
    codVenda INT NOT NULL,
    quantidade INT NOT NULL,
CONSTRAINT VENDA_PK PRIMARY KEY (codVenda)
) ENGINE=InnoDB;

CREATE TABLE faz (
    matricula INT NOT NULL,
    codVenda INT NOT NULL,
CONSTRAINT faz_PK PRIMARY KEY (matricula, codVenda),
CONSTRAINT faz_EMPREGADO_FK FOREIGN KEY (matricula)
	REFERENCES EMPREGADO (matricula),
CONSTRAINT faz_VENDA_FK FOREIGN KEY (codVenda)
	REFERENCES VENDA (codVenda)
) ENGINE=InnoDB;

CREATE TABLE AREA (
    idArea INT NOT NULL AUTO_INCREMENT,
    nomeArea VARCHAR(50) NOT NULL,
    cpf BIGINT(11) NOT NULL,
CONSTRAINT AREA_PK PRIMARY KEY (idArea),
CONSTRAINT AREA_GERENTE_FK FOREIGN KEY (cpf)
	REFERENCES GERENTE (cpf)
) ENGINE=InnoDB AUTO_INCREMENT = 1;

CREATE TABLE PRODUTO (
    codigo INT NOT NULL,
    idArea INT NOT NULL,
    nomeProduto VARCHAR(50) NOT NULL,
CONSTRAINT PRODUTO_PK PRIMARY KEY (codigo),
CONSTRAINT PRODUTO_AREA_FK FOREIGN KEY (idArea)
	REFERENCES AREA (idArea)
) ENGINE=InnoDB;

CREATE TABLE inclui (
	codVenda INT NOT NULL,
    codProduto INT NOT NULL,
CONSTRAINT inclui_PK PRIMARY KEY (codVenda, codProduto),
CONSTRAINT inclui_VENDA_FK FOREIGN KEY (codVenda)
	REFERENCES VENDA (codVenda),
CONSTRAINT inclui_PRODUTO_FK FOREIGN KEY (codProduto)
	REFERENCES PRODUTO (codigo)
) ENGINE=InnoDB;