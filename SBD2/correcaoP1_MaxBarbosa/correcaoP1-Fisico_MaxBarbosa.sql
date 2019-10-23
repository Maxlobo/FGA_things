-- --------                 << maxbarbosa  >>             ------------
--
--                    SCRIPT DE CRIACAO (DDL)
--
-- Data Criacao ...........: 17/10/2019
-- Autor(es) ..............: Max Henrique Barbosa
-- Banco de Dados .........: MySQL
-- Banco de Dados(nome) ...: maxbarbosa
--
-- Data Ultima Alteracao ..: 17/10/2019
--   => Criacao de nova base de dados e criacao das tabelas
--
-- PROJETO => 01 Base de Dados
--         => 05 Tabelas
--         => 02 Usuarios
--         => 01 Visao
--
-- -----------------------------------------------------------------

CREATE DATABASE IF NOT EXISTS  maxbarbosa;

use maxbarbosa;
/* correcaoP1-Logico_MaxBarbosa: */

CREATE TABLE if not exists PESSOA (
    idPessoa INT AUTO_INCREMENT,
    pNome VARCHAR(30) NOT NULL,
    uNome VARCHAR(30) NOT NULL,
    apelido VARCHAR(30),
    sexo ENUM ('M', 'F') NOT NULL,
    dtNascimento DATE NOT NULL,

CONSTRAINT PESSOA_PK PRIMARY KEY (idPessoa)
)ENGINE = InnoDB AUTO_INCREMENT = 0;

CREATE TABLE if not exists CARACTERISTICA (
    idCaracteristica INT AUTO_INCREMENT,
    tipoCaracteristica ENUM ('caracInteresse', 'caracPessoa') NOT NULL,
    dsCaracteristica VARCHAR(30) NOT NULL,

CONSTRAINT CARACTERISTICA_PK PRIMARY KEY (idCaracteristica)
)ENGINE = InnoDB AUTO_INCREMENT = 0;

CREATE TABLE if not exists email (
    email VARCHAR(30) NOT NULL,
    idPessoa INT NOT NULL,

CONSTRAINT email_PK PRIMARY KEY (email)
)ENGINE = InnoDB;

CREATE TABLE if not exists relaciona (
    idPessoa INT,
    idPessoaRelacionada INT,

    CONSTRAINT relaciona_PESSOA_FK FOREIGN KEY (idPessoa) REFERENCES PESSOA (idPessoa)
    ON DELETE RESTRICT
    ON UPDATE RESTRICT,

    CONSTRAINT relacionada_PESSOA_FK FOREIGN KEY (idPessoaRelacionada) REFERENCES PESSOA (idPessoa)
    ON DELETE RESTRICT
    ON UPDATE RESTRICT
)ENGINE = InnoDB;

CREATE TABLE if not exists tem (
    idPessoa INT,
    idCaracteristica INT,

    CONSTRAINT tem_PESSOA_FK FOREIGN KEY (idPessoa) REFERENCES PESSOA (idPessoa)
    ON DELETE RESTRICT
    ON UPDATE RESTRICT,

    CONSTRAINT tem_CARACTERISTICA_FK FOREIGN KEY (idCaracteristica) REFERENCES CARACTERISTICA (idCaracteristica)
    ON DELETE RESTRICT
    ON UPDATE RESTRICT
)ENGINE = InnoDB;