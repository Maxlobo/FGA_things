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
-- date Ultima Alteracao ..: 08/10/2019
--   => Criacao das tabelas e ajustes na documentacao dos scritps
--
-- PROJETO => 01 Base de Dados
--         => 04 Tabelas
--         => 01 Visao
--         => 03 Sequences
--
-- -----------------------------------------------------------------

Use aula3exer2Evolucao4;

-- View que mostra os horários ocupados por algum plantonista em cada setor
CREATE OR REPLACE VIEW HMM_V_HORARIOS (setor, datahora, plantonista) AS
  SELECT s.nomeSetor, a.datahora, p.nome
    FROM HMM_SETOR s JOIN HMM_alocado a
                       ON a.idSetor = s.idSetor
                     JOIN HMM_PLANTONISTA p
                       ON a.matricula = p.matricula
   ORDER BY s.nomeSetor, a.datahora, p.nome;



create index indice_horario on HMM_alocado(datahora);