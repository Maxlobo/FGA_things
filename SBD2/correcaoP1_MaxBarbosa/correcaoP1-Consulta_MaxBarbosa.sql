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

USE maxbarbosa

CREATE INDEX CARACTERISTICAS_IDX ON PESSOA (pNome);


CREATE VIEW V_CARACTERISTICAS_PESSOA (apelido, nome, caracteristica) AS
	SELECT p.apelido, p.pNome, c.dsCaracteristica
	FROM PESSOA p
	INNER JOIN tem t ON t.idPessoa = p.idPessoa
	INNER JOIN CARACTERISTICA c ON c.idCaracteristica = t.idCaracateristica;