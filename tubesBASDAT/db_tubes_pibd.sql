-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Waktu pembuatan: 07 Jun 2024 pada 10.48
-- Versi server: 10.4.32-MariaDB
-- Versi PHP: 8.0.30

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `db_tubes_pibd`
--

-- --------------------------------------------------------

--
-- Struktur dari tabel `customer`
--

CREATE TABLE `customer` (
  `customer_id` varchar(100) NOT NULL,
  `nama` varchar(100) DEFAULT NULL,
  `no_hp` varchar(15) DEFAULT NULL,
  `email` varchar(100) DEFAULT NULL,
  `jenis_kelamin` varchar(10) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data untuk tabel `customer`
--

INSERT INTO `customer` (`customer_id`, `nama`, `no_hp`, `email`, `jenis_kelamin`) VALUES
('C001', 'Andhika', '081234567890', 'Andhika@example.com', 'Laki-laki'),
('C002', 'Rizqi', '081234567891', 'Rizqi@example.com', 'Perempuan'),
('C003', 'Raehan', '081234567892', 'Raehan@example.com', 'Perempuan'),
('C004', 'Rifqi', '081234567893', 'Rifqi@example.com', 'Laki-laki'),
('C005', 'Yobel', '081234567894', 'Yobel@example.com', 'Laki-laki'),
('C006', 'Alvino', '081234567895', 'Alvino@example.com', 'Perempuan'),
('C007', 'Kastanja', '081234567896', 'Kastanja@example.com', 'Perempuan'),
('C008', 'Emir', '081234567897', 'Emir@example.com', 'Laki-laki'),
('C009', 'Martin', '081234567898', 'Martin@example.com', 'Perempuan'),
('C010', 'Sabasti', '081234567899', 'Sabasti@example.com', 'Laki-laki');

-- --------------------------------------------------------

--
-- Struktur dari tabel `preference`
--

CREATE TABLE `preference` (
  `preference_id` varchar(100) NOT NULL,
  `customer_id` varchar(100) DEFAULT NULL,
  `warna` varchar(50) DEFAULT NULL,
  `ukuran` varchar(50) DEFAULT NULL,
  `model` varchar(50) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data untuk tabel `preference`
--

INSERT INTO `preference` (`preference_id`, `customer_id`, `warna`, `ukuran`, `model`) VALUES
('PR001', 'C001', 'Merah', '42', 'Sneakers'),
('PR002', 'C002', 'Biru', '40', 'Boots'),
('PR003', 'C003', 'Hitam', '41', 'Loafers'),
('PR004', 'C004', 'Putih', '39', 'Sneakers'),
('PR005', 'C005', 'Coklat', '43', 'Boots'),
('PR006', 'C006', 'Abu-abu', '42', 'Loafers'),
('PR007', 'C007', 'Hijau', '40', 'Sneakers'),
('PR008', 'C008', 'Kuning', '41', 'Boots'),
('PR009', 'C009', 'Merah', '39', 'Loafers'),
('PR010', 'C010', 'Biru', '43', 'Sneakers');

-- --------------------------------------------------------

--
-- Struktur dari tabel `product`
--

CREATE TABLE `product` (
  `product_id` varchar(100) NOT NULL,
  `warna` varchar(50) DEFAULT NULL,
  `ukuran` varchar(50) DEFAULT NULL,
  `model` varchar(50) DEFAULT NULL,
  `harga` int(11) DEFAULT NULL,
  `kategori` varchar(50) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data untuk tabel `product`
--

INSERT INTO `product` (`product_id`, `warna`, `ukuran`, `model`, `harga`, `kategori`) VALUES
('P001', 'Merah', '42', 'Sneakers', 500000, 'Sepatu Olahraga'),
('P002', 'Biru', '40', 'Boots', 750000, 'Sepatu Kasual'),
('P003', 'Hitam', '41', 'Loafers', 600000, 'Sepatu Formal'),
('P004', 'Putih', '39', 'Sneakers', 550000, 'Sepatu Olahraga'),
('P005', 'Coklat', '43', 'Boots', 800000, 'Sepatu Kasual'),
('P006', 'Abu-abu', '42', 'Loafers', 650000, 'Sepatu Formal'),
('P007', 'Hijau', '40', 'Sneakers', 520000, 'Sepatu Olahraga'),
('P008', 'Kuning', '41', 'Boots', 770000, 'Sepatu Kasual'),
('P009', 'Merah', '39', 'Loafers', 620000, 'Sepatu Formal'),
('P010', 'Biru', '43', 'Sneakers', 530000, 'Sepatu Olahraga');

-- --------------------------------------------------------

--
-- Struktur dari tabel `sale`
--

CREATE TABLE `sale` (
  `sale_id` varchar(100) NOT NULL,
  `customer_id` varchar(100) DEFAULT NULL,
  `tanggal_pembayaran` date DEFAULT NULL,
  `metode_pembayaran` varchar(50) DEFAULT NULL,
  `total_pembayaran` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data untuk tabel `sale`
--

INSERT INTO `sale` (`sale_id`, `customer_id`, `tanggal_pembayaran`, `metode_pembayaran`, `total_pembayaran`) VALUES
('SA001', 'C001', '2024-02-01', 'Kartu Kredit', 1500000),
('SA002', 'C002', '2024-02-02', 'Tunai', 2000000),
('SA003', 'C003', '2024-02-03', 'Transfer Bank', 1750000),
('SA004', 'C004', '2024-02-04', 'Kartu Kredit', 1600000),
('SA005', 'C005', '2024-02-05', 'Tunai', 1800000),
('SA006', 'C006', '2024-02-06', 'Transfer Bank', 1900000),
('SA007', 'C007', '2024-02-07', 'Kartu Kredit', 1700000),
('SA008', 'C008', '2024-02-08', 'Tunai', 1550000),
('SA009', 'C009', '2024-02-09', 'Transfer Bank', 1650000),
('SA010', 'C010', '2024-02-10', 'Kartu Kredit', 1850000);

-- --------------------------------------------------------

--
-- Struktur dari tabel `sale_item`
--

CREATE TABLE `sale_item` (
  `sale_item_id` varchar(100) NOT NULL,
  `product_id` varchar(100) DEFAULT NULL,
  `sale_id` varchar(100) DEFAULT NULL,
  `total_pembayaran` int(11) DEFAULT NULL,
  `jumlah` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data untuk tabel `sale_item`
--

INSERT INTO `sale_item` (`sale_item_id`, `product_id`, `sale_id`, `total_pembayaran`, `jumlah`) VALUES
('SI001', 'P001', 'SA001', 500000, 1),
('SI002', 'P002', 'SA002', 750000, 1),
('SI003', 'P003', 'SA003', 600000, 1),
('SI004', 'P004', 'SA004', 550000, 1),
('SI005', 'P005', 'SA005', 800000, 1),
('SI006', 'P006', 'SA006', 650000, 1),
('SI007', 'P007', 'SA007', 520000, 1),
('SI008', 'P008', 'SA008', 770000, 1),
('SI009', 'P009', 'SA009', 620000, 1),
('SI010', 'P010', 'SA010', 530000, 1);

-- --------------------------------------------------------

--
-- Struktur dari tabel `stock`
--

CREATE TABLE `stock` (
  `stock_id` varchar(100) NOT NULL,
  `product_id` varchar(100) DEFAULT NULL,
  `jumlah_stock` int(11) DEFAULT NULL,
  `tanggal_masuk` date DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data untuk tabel `stock`
--

INSERT INTO `stock` (`stock_id`, `product_id`, `jumlah_stock`, `tanggal_masuk`) VALUES
('S001', 'P001', 100, '2024-01-01'),
('S002', 'P002', 50, '2024-01-02'),
('S003', 'P003', 75, '2024-01-03'),
('S004', 'P004', 120, '2024-01-04'),
('S005', 'P005', 60, '2024-01-05'),
('S006', 'P006', 80, '2024-01-06'),
('S007', 'P007', 90, '2024-01-07'),
('S008', 'P008', 70, '2024-01-08'),
('S009', 'P009', 110, '2024-01-09'),
('S010', 'P010', 65, '2024-01-10');

--
-- Indexes for dumped tables
--

--
-- Indeks untuk tabel `customer`
--
ALTER TABLE `customer`
  ADD PRIMARY KEY (`customer_id`);

--
-- Indeks untuk tabel `preference`
--
ALTER TABLE `preference`
  ADD PRIMARY KEY (`preference_id`),
  ADD KEY `customer_id` (`customer_id`);

--
-- Indeks untuk tabel `product`
--
ALTER TABLE `product`
  ADD PRIMARY KEY (`product_id`);

--
-- Indeks untuk tabel `sale`
--
ALTER TABLE `sale`
  ADD PRIMARY KEY (`sale_id`),
  ADD KEY `customer_id` (`customer_id`);

--
-- Indeks untuk tabel `sale_item`
--
ALTER TABLE `sale_item`
  ADD PRIMARY KEY (`sale_item_id`),
  ADD KEY `product_id` (`product_id`),
  ADD KEY `sale_id` (`sale_id`);

--
-- Indeks untuk tabel `stock`
--
ALTER TABLE `stock`
  ADD PRIMARY KEY (`stock_id`),
  ADD KEY `product_id` (`product_id`);

--
-- Ketidakleluasaan untuk tabel pelimpahan (Dumped Tables)
--

--
-- Ketidakleluasaan untuk tabel `preference`
--
ALTER TABLE `preference`
  ADD CONSTRAINT `preference_ibfk_1` FOREIGN KEY (`customer_id`) REFERENCES `customer` (`customer_id`);

--
-- Ketidakleluasaan untuk tabel `sale`
--
ALTER TABLE `sale`
  ADD CONSTRAINT `sale_ibfk_1` FOREIGN KEY (`customer_id`) REFERENCES `customer` (`customer_id`);

--
-- Ketidakleluasaan untuk tabel `sale_item`
--
ALTER TABLE `sale_item`
  ADD CONSTRAINT `sale_item_ibfk_1` FOREIGN KEY (`product_id`) REFERENCES `product` (`product_id`),
  ADD CONSTRAINT `sale_item_ibfk_2` FOREIGN KEY (`sale_id`) REFERENCES `sale` (`sale_id`);

--
-- Ketidakleluasaan untuk tabel `stock`
--
ALTER TABLE `stock`
  ADD CONSTRAINT `stock_ibfk_1` FOREIGN KEY (`product_id`) REFERENCES `product` (`product_id`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
