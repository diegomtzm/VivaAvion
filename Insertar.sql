-- Cliente (id_cliente, Nombre, Apellido_Paterno, Apellido_Materno, Email, Telefono, Asistencia_Personal, Edad)
INSERT INTO Cliente (Nombre, Apellido_Paterno, Apellido_Materno, Email, Telefono, Asistencia_Personal, Edad) VALUES ('Harry', 'Potter', 'Evans', 'goldensnicht@magic.com', '413-497-0167', 'No', '29');
INSERT INTO Cliente (Nombre, Apellido_Paterno, Apellido_Materno, Email, Telefono, Asistencia_Personal, Edad) VALUES ('Anakin', 'Skywalker', 'Vader', 'darthvader@galaxy.com', '327-255-1977', 'No', '45');
INSERT INTO Cliente (Nombre, Apellido_Paterno, Apellido_Materno, Email, Telefono, Asistencia_Personal, Edad) VALUES ('Sheldon', 'Lee', 'Cooper', 'spock.moonpie@darkmatter.com', '410-100-1001', 'Si', '38');
INSERT INTO Cliente (Nombre, Apellido_Paterno, Apellido_Materno, Email, Telefono, Asistencia_Personal, Edad) VALUES ('Serena', 'Van Der', 'Woodsen', 'xoxo@fashion.com', '212-453-4233','Si', '21' );
INSERT INTO Cliente (Nombre, Apellido_Paterno, Apellido_Materno, Email, Telefono, Asistencia_Personal, Edad) VALUES ('Damon', 'Salvatore', 'Somerhalder', 'mysticfalls@blood.com', '171-186-1841', 'No', '25');

-- Insert Dependientes (id_clienteD, nombreD, apellidoD_paterno, apellidoD_materno, edad, asistencia_personal, parentesco)

INSERT INTO Dependientes VALUES (3, 'Mary', 'Cooper', 'Metcalf', '55', 'Si', 'Madre'); --Sheldon
INSERT INTO Dependientes VALUES (1, 'Ronald', 'Bilius', 'Weasly', '30', 'Si', 'Amigo'); --Harry
INSERT INTO Dependientes VALUES (5, 'Stefan', 'Salvatore', 'Wesley', '17', 'No', 'Hermano'); -- Damon
INSERT INTO Dependientes VALUES (2, 'Luke ', 'Skywalker', 'Amidala', '19', 'Si', 'Hijo'); -- Darth vader
INSERT INTO Dependientes VALUES (4, 'Lily', 'Van Der', 'Woodsen', '52', 'Si', 'Madre'); --Serena
INSERT INTO Dependientes VALUES (4, 'Eric', 'Van Der', 'Woodsen', '17', 'Si', 'Hermano'); --Serena

--Avion (id_avion, Modelo, cant_Asientos) - https://www.ana.co.jp/es/mx/domestic/departure/inflight/seatmap/detail.html?c=code
INSERT INTO Avion VALUES('773', 'ABoeing 777-300', 514);
INSERT INTO Avion VALUES('32N', 'Airbus A320 200 V2', 150);
INSERT INTO Avion VALUES('76P', 'Boeing B767 300', 270);
INSERT INTO Avion VALUES('78P', 'Boeing B787-8', 335);
INSERT INTO Avion VALUES('CR7', 'Bombardier CRJ-700', 70);

--Insert Vuelo (id_vuelo, Fecha, HoraPartida, HoraAbordaje, Origen, Destino, Duracion, cantPasajeros, Piloto, PuertaAbordaje, precioBase)
INSERT INTO Vuelo VALUES ('V0079', '26-05-2018', '08:55', '09:00', 'Monterrey', 'Las Vegas', '1 hora, 15 min', '150', 'Miguel Medina', 'Terminal C', 9880);
INSERT INTO Vuelo VALUES ('V0080', '24-04-2018', '15:50', '16:00', 'CD. de Mexico', 'Pto. Escondido','3 horas, 10 min','60','Fernando Cantu', 'Terminal A', 5474);
INSERT INTO Vuelo VALUES ('V0081', '22-07-2018', '11:20', '11:30', 'Cancun', 'Queretaro', '2 horas, 15 min', '125', 'Mario Gonzalez', 'Terminal D', 1998);
INSERT INTO Vuelo VALUES ('V0082', '17-06-2018', '15:55', '16:05', 'Guadalajara', 'Los Angeles','1 hora, 20 min', '20','Gilberto Ortuño', 'Terminal B', 2278);
INSERT INTO Vuelo VALUES ('V0083', '21-07-2018', '19:20', '19:25', 'CD. Mexico', 'Los Cabos', '1 hora','150', 'Juan Mendez', 'Terminal C', 2139);

-- Hotel (id_hotel, Direccion, cant_habitaciones)
INSERT INTO Hotel (Nombre, Direccion, cant_Habitaciones, precioPorNoche) VALUES ('Plaza Hotel', '1 S Main St, Las Vegas, NV 89101', 2, 5); --plaza hotel y casino
INSERT INTO Hotel (Nombre, Direccion, cant_Habitaciones, precioPorNoche) VALUES ('Casa Losodeli', 'Prolongacion 2a. norte s/n, esquina Carretera Costera, 71980 Puerto Escondido, Oax.', 1, 15); --Casa Losodeli 
INSERT INTO Hotel (Nombre, Direccion, cant_Habitaciones, precioPorNoche) VALUES ('Meson de Carolina', 'Av Reforma Ote 36, Centro, 76000 Santiago de Queretaro, Qro.', 2, 11); -- Meson de Carolina qtro
INSERT INTO Hotel (Nombre, Direccion, cant_Habitaciones, precioPorNoche) VALUES ('Crowne Plaza', '5985 W Century Blvd, Los Angeles, CA 90045, EE. UU.', 2, 12); -- Crowne Plaza Los Angeles Airport LA
INSERT INTO Hotel (Nombre, Direccion, cant_Habitaciones, precioPorNoche) VALUES ('Bahia Hotel & Beah House', 'Av. El Pescador, s/n, El Medano, 23453 Cabo San Lucas, B.C.S.', 3, 8); --Bahia Hotel & Beach House Los cabos

--ReservacionVuelo (id_vuelo, id_cliente)
INSERT INTO ReservacionVuelo VALUES('V0080','HP8764'); 
INSERT INTO ReservacionVuelo VALUES('V0083','GG10021');
INSERT INTO ReservacionVuelo VALUES('V0082','SW1138');
INSERT INTO ReservacionVuelo VALUES('V0079','VD173'); 
INSERT INTO ReservacionVuelo VALUES('V0081','BBT73'); 

--VueloDep (id_cliente, nombreD, id_vuelo)
INSERT INTO VueloDep VALUES('BBT73','Mary', 'V0081');
INSERT INTO VueloDep VALUES('VD172','Damon', 'V0079');
INSERT INTO VueloDep VALUES('SW1138','Luke', 'V0082');
INSERT INTO VueloDep VALUES('GG10021','Lily', 'V0083');
INSERT INTO VueloDep VALUES('GG10021','Eric', 'V0083');
INSERT INTO VueloDep VALUES('HP8764','Ronald', 'V0080');


--AvionUsado(id_vuelo, id_avion)
INSERT INTO AvionUsado VALUES('V0079','773');
INSERT INTO AvionUsado VALUES('V0080','32N');
INSERT INTO AvionUsado VALUES('V0081','76P');
INSERT INTO AvionUsado VALUES('V0082','CR7');
INSERT INTO AvionUsado VALUES('V0083','78P');

-- ReservacionHotel (id_cliente, id_hotel)
INSERT INTO ReservacionHotel VALUES('GG10021','H381');
INSERT INTO ReservacionHotel VALUES('HP8764','H855');
INSERT INTO ReservacionHotel VALUES('SW1138','H410');
INSERT INTO ReservacionHotel VALUES('VD173', 'H520');
INSERT INTO ReservacionHotel VALUES('BBT73','H769');