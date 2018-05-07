-- Cliente table - Cliente (id_cliente, Nombre, Apellido_Paterno, Apellido_Materno, Email, Telefono, Asistencia_Personal, Edad)
DROP TABLE IF EXISTS VueloDep;
DROP TABLE IF EXISTS ReservacionHotel;
DROP TABLE IF EXISTS AvionUsado;
DROP TABLE IF EXISTS ReservacionVuelo;
DROP TABLE IF EXISTS Vuelo;
DROP TABLE IF EXISTS Hotel;
DROP TABLE IF EXISTS Avion;
DROP TABLE IF EXISTS Dependientes;
DROP TABLE IF EXISTS Cliente;

DROP TABLE IF EXISTS Cliente;
CREATE TABLE Cliente(
   	id_cliente VARCHAR(10),
   	Nombre VARCHAR(20),
   	Apellido_Paterno VARCHAR(20),
   	Apellido_Materno VARCHAR(20),
   	Email VARCHAR(20),
   	Telefono NUMERIC(15),
   	Asistencia_Personal BOOLEAN,
   	Edad INT,
   	PRIMARY KEY (id_cliente)
);
 
-- Dependientes table - Dependientes (id_cliente, nombreD, apellidoD_paterno, apellidoD_materno, edad, asistencia_personal, parentesco)
DROP TABLE IF EXISTS Dependientes;
CREATE TABLE Dependientes(
   	id_cliente VARCHAR(10),
   	NombreD VARCHAR(20),
   	ApellidoD_Paterno VARCHAR(20),
   	ApellidoD_Materno VARCHAR(20),
	Edad INT,
   	Asistencia_Personal BOOLEAN,
   	Parentesco VARCHAR(20),
   	PRIMARY KEY (id_cliente, NombreD, ApellidoD_Paterno),
   	FOREIGN KEY (id_cliente) REFERENCES Cliente (id_cliente) ON DELETE CASCADE
);
 
 -- Avion table - Avion (id_avion, Modelo, cant_Asientos)
DROP TABLE IF EXISTS Avion;
CREATE TABLE Avion(
   	id_avion VARCHAR(10),
   	Modelo VARCHAR(20),
   	cant_Asientos INT,
   	PRIMARY KEY (id_avion)
);
 
 -- Hotel table - Hotel (id_hotel, Direccion, cant_habitaciones)
DROP TABLE IF EXISTS Hotel;
CREATE TABLE Hotel(
   	id_hotel INTEGER,
   	Nombre VARCHAR (20),
   	Direccion VARCHAR(40),
   	cant_Habitaciones INT,
   	precioPorNoche INT,
   	PRIMARY KEY (id_hotel)
);
 
 -- Vuelo table - Vuelo (id_vuelo, Fecha, HoraPartida, HoraAbordaje, Origen, Destino, Duración, cantPasajeros, Piloto, PuertaAbordaje, precioBase)
DROP TABLE IF EXISTS Vuelo;
CREATE TABLE Vuelo(
   	id_vuelo VARCHAR(10),
   	Fecha DATE,
   	HoraPartida DATETIME,
   	HoraAbordaje DATETIME,
   	Origen VARCHAR(20),
   	Destino VARCHAR(20),
   	Duracion NUMERIC(15),
   	cantPasajeros INT,
   	Piloto VARCHAR(50),
   	PuertaAbordaje NUMERIC(10),
   	PrecioBase REAL(30),
   	PRIMARY KEY (id_vuelo)
); 	
 
-- ReservacionVuelo table - ReservacionVuelo (id_vuelo, id_cliente)
DROP TABLE IF EXISTS ReservacionVuelo;
CREATE TABLE ReservacionVuelo(
   	id_vuelo VARCHAR(10),
   	id_cliente VARCHAR(20),
   	PRIMARY KEY (id_vuelo, id_cliente),
   	FOREIGN KEY (id_vuelo) REFERENCES Vuelo (id_vuelo) ON DELETE CASCADE, 
   	FOREIGN KEY (id_cliente) REFERENCES Cliente (id_cliente) ON DELETE CASCADE
);
 
-- AvionUsado table - AvionUsado(id_vuelo, id_avion)
DROP TABLE IF EXISTS AvionUsado;
CREATE TABLE AvionUsado(
   	id_vuelo VARCHAR(10),
   	id_avion VARCHAR(10),
   	PRIMARY KEY (id_vuelo, id_avion),
   	FOREIGN KEY (id_vuelo) REFERENCES Vuelo (id_vuelo) ON DELETE CASCADE,
   	FOREIGN KEY (id_avion) REFERENCES Avion (id_avion) ON DELETE SET NULL
);
 
-- ReservacionHotel table - ReservacionHotel (id_cliente, id_hotel)
DROP TABLE IF EXISTS ReservacionHotel;
CREATE TABLE ReservacionHotel(
   	id_cliente VARCHAR(10),
   	id_hotel VARCHAR(10),
   	PRIMARY KEY (id_cliente, id_hotel),
   	FOREIGN KEY (id_cliente) REFERENCES Cliente (id_cliente) ON DELETE CASCADE,
   	FOREIGN KEY (id_hotel) REFERENCES Hotel (id_hotel) ON DELETE CASCADE
);
 
-- VueloDep table - VueloDep (id_cliente, nombreD, id_vuelo)
DROP TABLE IF EXISTS VueloDep;
CREATE TABLE VueloDep(
   	id_cliente VARCHAR(10),
   	nombreD VARCHAR(20),
   	id_vuelo VARCHAR(10),
   	PRIMARY KEY (id_cliente, nombreD, id_vuelo),
   	FOREIGN KEY (id_cliente) REFERENCES Cliente (id_cliente) ON DELETE CASCADE,
   	FOREIGN KEY (nombreD) REFERENCES Dependientes (nombreD) ON DELETE CASCADE,
   	FOREIGN KEY (id_vuelo) REFERENCES Vuelo (id_vuelo) ON DELETE CASCADE
);