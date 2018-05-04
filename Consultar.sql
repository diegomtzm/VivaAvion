--Diego Martinez
--Info completa de todos los vuelos reservados
SELECT v.* FROM Vuelo AS v, ReservacionVuelo AS rv
WHERE v.id_vuelo == rv.id_vuelo;

--Info completa de todos los clientes con vuelo reservado
SELECT c.* FROM Cliente AS c, ReservacionVuelo AS rv
WHERE c.id_cliente == rv.id_cliente;

--Info de los clientes en vuelo 'V0080'
SELECT c.* FROM Cliente AS c, ReservacionVuelo AS rv
WHERE rv.id_vuelo == "V0080"
	AND c.id_cliente == rv.id_cliente;

--Hector
--Info del vuelo del pasajero con el email 'goldensnicht@magic.com'
SELECT d.Origen, d.Destino, d.HoraAbordaje, d.HoraPartida
FROM VueloDep v
INNER JOIN Vuelo d ON v.id_vuelo == d.id_vuelo
WHERE v.id_cliente == (SELECT id_cliente FROM Cliente WHERE Email == 'goldensnicht@magic.com');
 
--Info del los clientes que se hospedan en Las Vegas
SELECT Nombre, Apellido_Paterno, Email
FROM Cliente
WHERE id_cliente IN (SELECT r.id_cliente
FROM Hotel h
INNER JOIN ReservacionHotel r ON h.id_hotel == r.id_hotel
WHERE Direccion LIKE '%Las Vegas%');
 
--Info de la cantidad de reservaciones por vuelo y el maximo de pasajeros
SELECT vd.id_vuelo, COUNT(vd.id_cliente) as Reservados, v.cantPasajeros
FROM VueloDep vd, Vuelo v 
WHERE vd.id_vuelo == v.id_vuelo
GROUP BY vd.id_vuelo;
 
--Roxana
-- Info del vuelo y que avion usa, ordenado por fecha
SELECT id_avion, v.id_vuelo, Fecha, HoraPartida, Origen, Destino, PuertaAbordaje
FROM AvionUsado a JOIN Vuelo v ON a.id_vuelo = v.id_vuelo
ORDER BY Fecha;
 
--información de cuantos boletos compro cada cliente
CREATE VIEW Boletos	
AS SELECT c.id_cliente, COUNT (c.id_cliente) AS cliente, COUNT (d.id_cliente) AS boletoDependiente
FROM ReservacionVuelo c JOIN VueloDep d ON c.id_cliente = d.id_cliente
GROUP BY c.id_cliente;
 
SELECT id_cliente, SUM (cliente + boletoDependiente) AS boletosComprados
FROM Boletos
GROUP BY id_cliente;
 
--Luis
--Info del hotel donde se hospedara el cliente 'BBT73'
SELECT *
FROM Hotel
WHERE id_hotel IN (SELECT id_hotel
               	FROM ReservacionHotel
               	WHERE id_cliente == 'BBT73');
 
--Info de los dependientes del id_cliente 'VD173'
SELECT nombreD, apellidoD_paterno, apellidoD_materno, edad, asistencia_personal, parentesco
FROM Dependientes
WHERE id_cliente == (SELECT id_cliente
                 	FROM Cliente
                 	WHERE id_cliente == 'VD173');
 
--Info de los dependientes que requieran asistencia personal
SELECT id_cliente, nombreD, apellidoD_paterno, apellidoD_materno
FROM Dependientes
WHERE asistencia_personal == true;
 
 
--Diego Valadez
--Info de los vuelos que usan el avion modelo 'ABoeing 777-300'
SELECT v.id_vuelo, v.Fecha, v.Origen, v.Destino, v.HoraPartida, v.Duracion, v.PuertaAbordaje, v.PrecioBase
FROM Avion a, AvionUsado au, Vuelo v
WHERE a.id_avion = au.id_avion AND au.id_vuelo = v.id_vuelo AND a.Modelo = 'ABoeing 777-300';
 
--Info de los vuelos que despegan de Cancun
SELECT *
FROM Vuelo
WHERE Origen = 'Cancun';
 
-- Cantidad de Dependientes de cada Cliente
SELECT id_cliente, COUNT (NombreD)
FROM Dependientes
GROUP BY id_cliente;
