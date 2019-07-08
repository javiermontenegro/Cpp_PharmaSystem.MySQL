-- 
-- mysql> CREATE DATABASE pharma CHARACTER SET latin1 COLLATE latin1_spanish_ci; 
-- mysql> USE pharma;
-- mysql> source /path/to/pharma.sql
-- 

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `pharma`
--

-- --------------------------------------------------------

--
-- Table structure for table `users`
--

CREATE TABLE IF NOT EXISTS `users` (
  `id` int(11) AUTO_INCREMENT,
  `username` text COLLATE latin1_general_ci NOT NULL,
  `password` text COLLATE latin1_general_ci NOT NULL,
  PRIMARY KEY (`id`)) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_general_ci;

--
-- Table structure for table `pharma_store`
--

CREATE TABLE IF NOT EXISTS `pharma_store` (
  `id` int(11) AUTO_INCREMENT,
  `product` text COLLATE latin1_general_ci NOT NULL,
  `presentation` text COLLATE latin1_general_ci NOT NULL,
  `price` double COLLATE latin1_general_ci NOT NULL,
  `drug` text COLLATE latin1_general_ci NOT NULL,
  `lab` text COLLATE latin1_general_ci NOT NULL,
  PRIMARY KEY (`id`)) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_general_ci;

INSERT INTO users (username, password) VALUES ('admin', '12345');


/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
