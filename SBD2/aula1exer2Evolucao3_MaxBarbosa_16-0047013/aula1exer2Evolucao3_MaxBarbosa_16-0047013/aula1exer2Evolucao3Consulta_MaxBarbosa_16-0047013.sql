USE aula1exer2Evolucao3;

-- A
	SELECT * FROM VENDA WHERE matricula = 15898;
    
-- B
	SELECT * FROM PRODUTO AS P 
	JOIN possui AS Po ON Po.codigo = P.codigo
    WHERE Po.idVenda = 541345;
    
-- C
	SELECT * FROM EMPREGADO AS E
    JOIN PESSOA AS P ON P.cpf = E.cpf
    ORDER BY P.nome;

-- D
	SELECT * FROM PRODUTO AS P 
	JOIN possui AS Po ON P.codigo = Po.codigo;