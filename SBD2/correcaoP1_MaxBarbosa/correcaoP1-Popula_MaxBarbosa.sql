-- --------                 << maxbarbosa  >>             ------------
--
--                    SCRIPT DE POPULA (DML)
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

USE maxbarbosa;

INSERT INTO CARACTERISTICA (tipoCaracteristica, dsCaracteristica) VALUES ('caracInteresse', 'leitura'),
                                                                         ('caracInteresse', 'videogames'),
                                                                         ('caracPessoa', 'calmo'),
                                                                         ('caracPessoa', 'ciume' );

INSERT INTO PESSOA (pNome, uNome, apelido, sexo, dtNascimento) VALUES ('Edna', 'Lucio', 'nkory', 'F', '1998-10-05'),
                                                                      ('Max', 'Henrique', 'lobo', 'M', '1998-02-27'),
                                                                      ('Sarah', 'Barreto', 'salu', 'F', '2000-11-04'),
                                                                      ('Ronildo', 'Feitoza', 'desumilde', 'M', '1997-05-05');

INSERT INTO email (email, idPessoa) VALUES ('nkoryyue@gmail.com', 0),
                                           ('maxhb.df@gmail.com', 1),
                                           ('thesarahbarreto@gmail.com', 2),
                                           ('ronildodocarmo@gmail.com', 3);

INSERT INTO relaciona (idPessoa, idPessoaRelacionada) VALUES (1, 0), (1, 2), (1, 3), (3, 2);

INSERT INTO tem (idPessoa, idCAracteristica) VALUES (0, 2),
                                                    (1, 1),
                                                    (2, 1),
                                                    (3, 2);
