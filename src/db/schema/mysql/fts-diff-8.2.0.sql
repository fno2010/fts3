--
-- FTS3 Schema 8.2.0
-- [FTS-1782] SE Throughput Limitation
--

DROP TABLE IF EXISTS `t_optimizer`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `t_optimizer` (
  `source_se` varchar(150) NOT NULL,
  `dest_se` varchar(150) NOT NULL,
  `datetime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `ema` double DEFAULT '0',
  `active` int(11) DEFAULT '2',
  `nostreams` int(11) DEFAULT '1',
  `actual_active` int(11) DEFAULT NULL,
  `throughput` double DEFAULT '0',
  `queue_size` int(11) DEFAULT NULL,
  PRIMARY KEY (`source_se`,`dest_se`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;


DROP TABLE IF EXISTS `t_netlink_stat`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `t_netlink_stat` (
  `netlink_id` char(36) NOT NULL,
  `head_ip` varchar(150) DEFAULT '*',
  `tail_ip` varchar(150) DEFAULT '*',
  `head_asn` int(32) DEFAULT '0',
  `tail_asn` int(32) DEFAULT '0',
  `head_rdns` varchar(253) DEFAULT NULL,
  `tail_rdns` varchar(253) DEFAULT NULL,
  PRIMARY KEY (`netlink_id`),
  CONSTRAINT `idx_ports` UNIQUE (`head_ip`, `tail_ip`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;


DROP TABLE IF EXISTS `t_netlink_trace`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `t_netlink_trace` (
  `trace_id` bigint(20) unsigned NOT NULL AUTO_INCREMENT,
  `source_se` varchar(255) NOT NULL,
  `dest_se` varchar(255) NOT NULL,
  `hop_idx` int(8) NOT NULL,
  `netlink` char(36) NOT NULL,
  PRIMARY KEY (`trace_id`),
  CONSTRAINT `idx_pair_hop` UNIQUE (`source_se`, `dest_se`, `hop_idx`),
  CONSTRAINT `fk_netlink` FOREIGN KEY (`netlink`) REFERENCES `t_netlink_stat` (`netlink_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

INSERT INTO t_schema_vers (major, minor, patch, message)
VALUES (8, 2, 0, 'FTS-1782: SE Throughput Limitation');
